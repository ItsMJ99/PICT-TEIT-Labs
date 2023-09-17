#!/bin/bash
while true; do
    echo "1.CREATE DATABASE"
    echo "2.INSERT"
    echo "3.SEARCH"
    echo "4.DISPLAY"
    echo "5.DELETE"
    echo "6.UPDATE"
    echo "7.EXIT"
    echo "Enter your choice:"
    read d
    case $d in
    1)
        echo "Enter the name of the database:"
        read db
        if [ -f "$db" ]; then #-f checks if the file exists
            echo "$db exists"
        else
            touch $db
            echo "File created successfully!:"
        fi
        ;;
    2)
        echo "Enter the name of the database in which you have to insert:"
        read db
        echo "Enter the student id:"
        read sd
        echo "Enter the student name:"
        read na
        echo "Enter the student department:"
        read dp
        while true; do
            echo "Enter the student phone number:"
            read ph
            if [[ ! "$ph" =~ ^[0-9]{10}$ ]]; then
                echo "Invalid phone number. Please enter 10 digits."
            else
                break
            fi
        done
        echo "Enter the student email address:"
        read em
        record="$sd $na $dp $ph $em"
        echo $record >>$db
        echo "Data Inserted!"
        ;;
    3)
        echo "Enter the name of the database in which you want to search:"
        read db
        echo "Enter the student id to search:"
        read search_id
        if [ -f "$db" ]; then #-f checks if the file exists
            data=$(grep "^$search_id " $db)
            if [ -z "$data" ]; then #-z checks if the string is empty
                echo "Record not found."
            else
                echo "Record found:"
                echo "Student ID | Name | Department | Phone | Email"
                echo "$data"
            fi
        else
            echo "$db does not exist."
        fi
        ;;
    4)
        echo "Enter the name of the database to display:"
        read db
        if [ -f "$db" ]; then #-f checks if the file exists
            cat $db
        else
            echo "$db does not exist."
        fi
        ;;
    5)
        echo "Enter the name of the database from which you want to delete a record:"
        read db
        echo "Enter the student id to delete:"
        read delete_id
        if [ -f "$db" ]; then                    #-f checks if the file exists
            if grep -q "^$delete_id " "$db"; then #-q it is quit mode or silent mode, it does
                not return any output so here it only check it exists or not
                grep -v "^$delete_id " "$db" >temp_db && mv temp_db "$db" #invert
                match, except that lines it select other lines
                echo "Record with Student ID $delete_id has been deleted."
            else
                echo "Record not found."
            fi
        else
            echo "$db does not exist."
        fi
        ;;
    6)
        echo "Enter the name of the database in which you want to update a record:"
        read db
        echo "Enter the student id to update:"
        read update_id
        if [ -f "$db" ]; then                     #-f:- wheteher the file exists
            if grep -q "^$update_id " "$db"; then #-
                echo -e "Record found. Enter the field you want to
update:\nName\nDepartment\nPhone\nEmail\n"
                read field
                case "$field" in
                name)
                    echo "Enter the new student name:"
                    read na
                    sed -i "s/^$update_id [^ ]*/$update_id $na/" "$db" #-i:- make changes in the file
                    directly
                    echo "Student name has been updated."
                    ;;
                department)
                    echo "Enter the new student department:"
                    read dp
                    sed -i "s/^$update_id [^ ]* [^ ]*/$update_id $dp/" "$db" #-i:- make changes in the file
                    directly
                    echo "Student department has been updated."
                    ;;
                phone)
                    while true; do
                        echo "Enter the new student phone number:"
                        read ph
                        if [[ ! "$ph" =~ ^[0-9]{10}$ ]]; then
                            echo "Invalid phone number. Please enter 10 digits."
                        else
                            sed -i "s/^$update_id [^ ]* [^ ]* [^ ]*/$update_id $ph/" "$db" #-i:- make
                            changes in the file directly
                            echo "Student phone number has been updated."
                            break
                        fi
                    done
                    ;;
                email)
                    echo "Enter the new student email address:"
                    read em
                    sed -i "s/^$update_id [^ ]* [^ ]* [^ ]* [^ ]*/$update_id $em/" "$db" #-i:- make
                    changes in the file directly
                    echo "Student email address has been updated."
                    ;;
                *)
                    echo "Invalid field. No updates performed."
                    ;;
                esac
            else
                echo "Record not found."
            fi
        else
            echo "$db does not exist."
        fi
        ;;
    7)
        echo "Exiting..."
        exit 0
        ;;
    esac
done
