#! /bin/bash

main(){
    c=0
    while [ $c -eq 0];
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
        switch $ch in
        esac
    done
}