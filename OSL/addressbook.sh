#!/bin/bash

createDB() {
    echo "Enter the name of the database:"
    read db
    if [ -f "$db" ]; then #-f checks if file exists
        echo "$db Opened Successfully !"
    else
        touch $db
        echo "Database created successfully !!!"
    fi
}

add() {
    echo "Enter Unique ID : "
    read uid
    echo "Enter Full Name : "
    read fname
     while true; do
            echo "Enter Phone Number : "
            read phone
            if [[ ! "$phone" =~ ^[0-9]{10}$ ]]; then
                echo "Invalid phone number. Please enter 10 digits."
            else
                break
            fi
        done
    echo "Enter Email Address:"
    read em
    echo "$uid $fname $phone $em" >>$db
    echo "Record Inserted Successfully !!!"
}

list() {
    echo "Records :"
    cat $db
}

search() {
    echo "Enter UID to Search Record :"
    read search_id
            data=$(grep "^$search_id " $db)
        if [ -z "$data" ]; then #-z checks if the string is empty
            echo "Record not found."
        else
            echo "Record found:"
            echo "$data"
        fi
}

delete() {
 echo "Enter UID to Delete Record Record :"
    read delid
    if grep -q $delid $db; then
        grep -v -w $delid $db>>temp.txt
        rm $db
        mv temp.txt $db
        echo "Record Deleted Successfully"
    else 
        echo "Record Not Found"
    fi
}

modify() {
    echo "Enter the Unique ID to update:"
    read update_id                    
        if grep -q "$update_id " "$db"; then 
            echo -e "Record found. Enter the field you want to update: Name\Phone\Email"
            read field
            case "$field" in
            name)
                echo "Enter the new Name:"
                read na
                sed -i "s/^$update_id [^ ]*/$update_id $na/" "$db" #-i:- make changes in the file directly
                echo "Name updated Successfully !!!"
                ;;
            phone)
                while true; do
                    echo "Enter the new phone number :"
                    read ph
                    if [[ ! "$ph" =~ ^[0-9]{10}$ ]]; then
                        echo "Invalid phone number. Please enter 10 digits."
                    else
                        sed -i "s/^$update_id [^ ]* [^ ]* [^ ]*/$update_id $ph/" "$db"
                        echo "Phone number updated Successfully !!!"
                        break
                    fi
                    done
                    ;;
                email)
                    echo "Enter the new email address :"
                    read email
                    sed -i "s/^$update_id [^ ]* [^ ]* [^ ]* [^ ]*/$update_id $email/" "$db" 
                    echo "Email address updated Successfully !!!"
                    ;;
                *)
                    echo "Invalid field. No updates performed."
                    ;;
                esac
        else
            echo "Record not found."
        fi
}

main() {
    e=0
    while [ $e -eq 0 ]; do
        echo "========== MENU =========="
        echo "0. Exit"
        echo "1. Create/Open Database"
        echo "2. Add Record"
        echo "3. List Records"
        echo "4. Search Record"
        echo "5. Delete Record"
        echo "6. Modify Record"
        echo "Enter Choice : "
        read ch
        case $ch in
        0) e=1 ;;
        1) createDB ;;
        2) add ;;
        3) list ;;
        4) search ;;
        5) delete ;;
        6) modify ;;
        *) echo "Invalid Input !!!" ;;
        esac
    done
}

main
