#! /bin/bash

createDB(){
    echo "Enter the name of the Database to Create or Open "
    read db
    if [ -f $db ]; then #-f checks if file exists
        echo "$db Opened Successfully !!! "
    else
        touch $db
        echo "Database Created Successfully !!!"
    fi
}

addRecords(){
    if [ -f $db ]; then
        echo "Enter UID : "
        read uid
        echo "Enter First Name : "
        read fn
        echo "Enter Middle Name : "
        read mn
        echo "Enter Last Name : "
        read ln
        while true;
        do
            echo "Enter Phone Number : "
            read phone
            if [[ ! "$phone" =~ ^[0-9]{10}$ ]]; then
                echo "Invalid Phone Number. Please Enter a Valid Phone Number"
            else
                break
            fi
        done
        echo "Enter Email ID : "
        read ed
        echo "$uid $fn $mn $ln $phone $ed">>$db
        echo "Record Inserted Successfully !!!"
    else
        echo "Database is not selected please select the database first to add the records"
    fi
}

listRecords(){
    if [ -f $db ]; then
        echo "Records : "
        cat $db
    else
        echo "Database is not selected please select the database first to display the records"
    fi
}

searchRecord(){
    if [ -f $db ]; then
        echo "Enter the UID to Search : "
        read s_uid
        data=$(grep "^$s_uid" "$db") 
        if [ -z "^$data" ]; then #-z checks if the string is empty
            echo "No Matching Record was found"
        else
            echo "Record found:"
            echo "$data"
        fi
    else
        echo "Database is not selected please select the database first to search the record"
    fi
}

deleteRecord(){
    if [ -f "$db" ]; then
        echo "Enter the UID to delete Record : "
        read d_uid
        if grep -q "$d_uid" "$db" ; then #-q gives status 0=found 
            grep -v -w "$d_uid" "$db">>temp.txt #-w whole word match -v excludes lines matching the word
            rm $db
            mv temp.txt $db
            echo "Record Deleted Successfully"
        else
            echo "No Matching Record was found"
        fi
    else
        echo "Database is not selected please select the database first to delete the record"
    fi
}

modifyRecord() {
    if [ -f "$db" ]; then
        echo "Enter UID to modify record: "
        read m_uid
        if grep -q "^$m_uid" "$db"; then
            echo "Enter New First Name : "
            read n_fn 
            echo "Enter New Middle Name : "
            read n_mn
            echo "Enter New Last Name : "
            read n_ln
            while true; do
                echo "Enter New Phone Number : "
                read n_phone
                if [[ ! "$n_phone" =~ ^[0-9]{10}$ ]]; then
                    echo "Invalid Phone Number. Please Enter a Valid Phone Number."
                else
                    break
                fi
            done
            echo "Enter New Email : "
            read n_em
            grep -v -w "$m_uid" "$db">>temp.txt
            echo "$m_uid $n_fn $n_mn $n_ln $n_phone $n_em">>temp.txt
            rm $db
            mv temp.txt $db
        else
            echo "No Matching Record was found"
        fi
    else
        echo "Database is not selected. Please select the database first to modify the record."
    fi
}


main(){
    c=0
    while [ $c -eq 0 ];
    do
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
        0) c=1 ;;
        1) createDB ;;
        2) addRecords ;;
        3) listRecords ;;
        4) searchRecord ;;
        5) deleteRecord ;;
        6) modifyRecord ;;
        *) echo "Invalid Input !!!" ;;
    esac
    done
}
main