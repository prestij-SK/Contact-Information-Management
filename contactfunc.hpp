#ifndef CONTACTFUNC_HPP
#define CONTACTFUNC_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "contactclassfunc.hpp"



bool cm_check_name_or_surname(const std::string &name){

    if(name.length() > 14){

        std::cout << "\nName/Surname range is too big, Uvuvwevwevwe Onyetenyevwe Ugwemuhwem Osas names are not supported in this program !\n";
        return false;
    }

    if(name[0] < 'A' || name[0] > 'Z'){

        std::cout << "\nName/Surname must start with the capital !\n";
        return false;
    }

    for(int i = 1; i < name.length(); ++i){

        if(name[i] < 'a' || name[i] > 'z'){

            std::cout << "\nName/Surname must not have numbers, capitals or other symbols in it !\n";
            return false;
        }
    }

    return true;
}

bool cm_check_birth_date(const std::string &date){

    if(date.length() != 10){

        std::cout << "\nBirth Date data is given wrong, range is too big/small !\n";
        return false;
    }

    for(int i = 0; i < date.length(); ++i){

        if(date[i] == '/'){
            continue;
        }

        if(date[i] < '0' || date[i] > '9'){

            std::cout << "\nBirth Date data must contain only numbers and '/' seperators !\n";
            return false;
        }
    }

    std::string month = date.substr(0, 2);
    std::string day = date.substr(3, 2);
    std::string year = date.substr(6, 4);

    if(std::stoi(month) < 1 || std::stoi(month) > 12){

        std::cout << "\nMonth must be in range of [1...to...12] !\n";
        return false;
    }
    
    if(std::stoi(day) < 1 || std::stoi(day) > 31){

        std::cout << "\nDay must be in range of [1...to...31] !\n";
        return false;
    }

    if(std::stoi(year) < 1900 || std::stoi(year) > 2022){

        std::cout << "\nYear must be in range of [1900...to...2022] !\n";
        return false;
    }

    return true;
}

bool cm_check_passport_number(Contact* &contacts, const int &contact_count, const std::string &passport){

    if(passport.length() > 12 || passport.length() < 6){

        std::cout << "\nPassport Number data is given wrong, range is too small/big !\n";
        return false;
    }

    for(int i = 0; i < passport.length(); ++i){

        if((passport[i] < '0' || passport[i] > '9') && (passport[i] < 'A' || passport[i] > 'Z')){

            std::cout << "\nPassport Number must contain only numbers or capital characters !\n";
            return false;
        }        
    }

    for(int i = 0; i < contact_count; ++i){

        if(contacts[i].get_passport_number().compare(passport) == 0){

            std::cout << "\nPassport Number already exists !\n";
            return false;
        }
    }

    return true;
}

bool cm_check_phone_number(Contact* &contacts, const int &contact_count, const std::string &phone){

    if(phone[0] != '+'){

        std::cout << "\nPhone Number data is given wrong, exit code '+' is missing !\n";
        return false;
    }

    if(phone.length() < 8 || phone.length() > 20){

        std::cout << "\nPhone Number data is given wrong, range is too big/small !\n";
        return false;
    }

    for(int i = 1; i < phone.length(); ++i){

        if(phone[i] < '0' || phone[i] > '9'){

            std::cout << "\nPhone Number must contain numbers only !\n";
            return false;
        }
    }

    for(int i = 0; i < contact_count; ++i){

        if(contacts[i].get_phone_number().compare(phone) == 0){

            std::cout << "\nPhone Number already exists !\n";
            return false;
        }
    }

    return true;
}



void cm_fill_contacts_data(Contact* &contacts, int &contact_count, std::ifstream &fin){

    int counter = 1;

    while(counter <= contact_count){

        std::string name;
        fin >> name;

        // Checking name rules from the file
        if(!(cm_check_name_or_surname(name))){
            
            std::cout << "\nError with contact NAME at line [" << counter << "] of the file !\n";
            std::cout << "\n-----Please check the file and restart the programm !-----\n\n";
            exit(0);
        }

        std::string surname;
        fin >> surname;

        // Checking surname rules from the file
        if(!(cm_check_name_or_surname(surname))){
            
            std::cout << "\nError with contact SURNAME at line [" << counter + 1<< "] of the file !\n";
            std::cout << "\n-----Please check the file and restart the programm !-----\n\n";
            exit(0);
        }

        std::string birth_date;
        fin >> birth_date;

        // Checking birth date rules from the file
        if(!(cm_check_birth_date(birth_date))){

            std::cout << "\nError with contact BIRTH_DATE at line [" << counter + 1 << "] of the file !\n";
            std::cout << "\n-----Please check the file and restart the programm !-----\n\n";
            exit(0);
        }

        std::string passport_num;
        fin >> passport_num;

        // Checking passport number rules from the file
        if(!(cm_check_passport_number(contacts, contact_count, passport_num))){

            std::cout << "\nError with contact PASSPORT_NUMBER at line [" << counter + 1 << "] of the file !\n";
            std::cout << "\n-----Please check the file and restart the programm !-----\n\n";
            exit(0);
        }

        std::string phone_num;
        fin >> phone_num;

        // Checking phone number rules from the file
        if(!(cm_check_phone_number(contacts, contact_count, phone_num))){

            std::cout << "\nError with contact PHONE NUMBER at line [" << counter + 1 << "] of the file !\n";
            std::cout << "\n-----Please check the file and restart the programm !-----\n\n";
            exit(0);
        }

        Contact contact(counter, name, surname, birth_date, passport_num, phone_num);

        contacts[counter - 1] = contact;
        
        ++counter;
    }
}



std::string cm_white_spaces(const std::string &str, const int &size){

    std::string spaces = "";
    int count = size - str.length();

    for(int i = 0; i < count+7; ++i){

        spaces += " ";
    }

    return spaces;
}



void cm_show_all_contacts_info(Contact* &contacts, const int &contacts_count){

    std::cout << "\n=========================================== All Contacts =================================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   "
              << "|Passport number|   " << "|::::Phone number::::|   " << "|:status:|" << "\n\n";

    for(int i = 0; i < contacts_count; ++i){

        std::string name = contacts[i].get_name();
        std::string surname = contacts[i].get_surname();;
        std::string birth_date = contacts[i].get_birth_date();
        std::string passport_num = contacts[i].get_passport_number();
        std::string phone_num = contacts[i].get_phone_number();

        std::cout << " [" << contacts[i].get_index() << "]      ";

        std::string spaces = cm_white_spaces(name, 12);
        std::cout << name << spaces;

        spaces = cm_white_spaces(surname, 13);
        std::cout << surname << spaces;

        spaces = cm_white_spaces(birth_date, 9);
        std::cout << birth_date << spaces;

        spaces = cm_white_spaces(passport_num, 13);
        std::cout << passport_num << spaces;

        spaces = cm_white_spaces(phone_num, 18);
        std::cout << phone_num << spaces;

        if(contacts[i].get_index() == 0){

            std::cout << "DELETED";
        }

        std::cout << "\n";
    }

    std::cout << "\n==========================================================================================================\n";
}



void cm_insert_data_to_file(Contact* &contacts, const int &contacts_count, const int &contacts_count_last, std::ofstream &fout){

    int counter = 1;
    
    fout << contacts_count_last << "\n";

    while (counter <= contacts_count){

        if(contacts[counter - 1].get_index() == 0){
            ++counter;
            continue;
        }
        
        fout << contacts[counter - 1].get_name() << " " << contacts[counter - 1].get_surname() << " " << contacts[counter - 1].get_birth_date()
             << " " << contacts[counter - 1].get_passport_number() << " " << contacts[counter - 1].get_phone_number() << "\n";

        ++counter;
    }
    
}



void cm_add_new_contact_to_contacts(Contact* &contacts, const int &contacts_count, Contact &new_contact){

    Contact* temp = new Contact[contacts_count];

    for(int i = 0; i < contacts_count - 1; ++i){

        temp[i] = contacts[i];
    }

    temp[contacts_count - 1] = new_contact;

    delete [] contacts;
    contacts = temp;
}



void cm_add_contact(Contact* &contacts, int &contacts_count){

    std::cout << "\n===== Creating New Contact =====\n";

    std::string name;
    std::string surname;
    std::string date;
    std::string passport;
    std::string phone;

    do{

        std::cout << "\nName: ";
        std::cin >> name;

    }while(!(cm_check_name_or_surname(name)));


    do{

        std::cout << "\nSurname: ";
        std::cin >> surname;

    }while(!(cm_check_name_or_surname(surname)));


    do{

        std::cout << "\nBirth_Date (example 04/05/2002): ";
        std::cin >> date;

    }while(!(cm_check_birth_date(date)));


    do{

        std::cout << "\nPassport_Number: ";
        std::cin >> passport;

    }while(!(cm_check_passport_number(contacts, contacts_count, passport)));


    do{

        std::cout << "\nPhone_Number: ";
        std::cin >> phone;

    }while(!(cm_check_phone_number(contacts, contacts_count, phone)));

    ++contacts_count;
    Contact new_contact(contacts_count, name, surname, date, passport, phone);

    cm_add_new_contact_to_contacts(contacts, contacts_count, new_contact);

    std::cout << "\n-----A New Contact is created and has been added to the Data !-----\n";
}



bool cm_search_by_index(Contact* &contacts, const int &contacts_count, const int &index){

    std::cout << "\n============================== Search by Index [" << index << "] Results =================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_index() == index){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }
    
    if(!found){

        std::cout << "\nContact Index Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }

    std::cout << "\n==========================================================================================================\n";

    return true;
}

bool cm_search_by_name(Contact* &contacts, const int &contacts_count, const std::string &name){

    std::cout << "\n============================== Search by Name [" << name << "] Results ===================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_name().compare(name) == 0){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }

    if(!found){

        std::cout << "\nContact Name Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }

    return true;
    
    std::cout << "\n==========================================================================================================\n";

    return true;
}

bool cm_search_by_surname(Contact* &contacts, const int &contacts_count, const std::string &name){

    std::cout << "\n============================== Search by Surname [" << name << "] Results ===================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_surname().compare(name) == 0){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }

    if(!found){

        std::cout << "\nContact Surname Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }
    
    std::cout << "\n==========================================================================================================\n";
        
    return true;
}

bool cm_search_by_birth_date(Contact* &contacts, const int &contacts_count, const std::string &name){

    std::cout << "\n============================== Search by Birth_Date [" << name << "] Results ===================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_birth_date().compare(name) == 0){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }

    if(!found){

        std::cout << "\nContact Birth_Date Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }
    
    std::cout << "\n==========================================================================================================\n";

    return true;
}

bool cm_search_by_passport_num(Contact* &contacts, const int &contacts_count, const std::string &name){

    std::cout << "\n============================== Search by Passport_Number [" << name << "] Results ===================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_passport_number().compare(name) == 0){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }

    if(!found){

        std::cout << "\nContact Passport_Number Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }
    
    std::cout << "\n==========================================================================================================\n";
    
    return true;
}

bool cm_search_by_phone_num(Contact* &contacts, const int &contacts_count, const std::string &name){

    std::cout << "\n============================== Search by Phone_Number [" << name << "] Results ===================================\n\n";
    std::cout << "|Index|  " << "|:::::Name:::::|   " << "|::::Surname::::|   "  << "|:::Birth:::|   " 
              << "|Passport number|   " << "|::::Phone number::::|" << "\n\n";

    bool found = false;

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() != 0 && contacts[i].get_phone_number().compare(name) == 0){
            
            std::string name = contacts[i].get_name();
            std::string surname = contacts[i].get_surname();;
            std::string birth_date = contacts[i].get_birth_date();
            std::string passport_num = contacts[i].get_passport_number();
            std::string phone_num = contacts[i].get_phone_number();

            std::cout << " [" << contacts[i].get_index() << "]      ";

            std::string spaces = cm_white_spaces(name, 12);
            std::cout << name << spaces;

            spaces = cm_white_spaces(surname, 13);
            std::cout << surname << spaces;

            spaces = cm_white_spaces(birth_date, 9);
            std::cout << birth_date << spaces;

            spaces = cm_white_spaces(passport_num, 13);
            std::cout << passport_num << spaces;

            std::cout << phone_num << "\n";

            found = true;
        }

    }

    if(!found){

        std::cout << "\nContact Phone_Number Was Not Found!\n";
        std::cout << "\n==========================================================================================================\n";
        return false;
    }
    
    std::cout << "\n==========================================================================================================\n";

    return true;
}

bool cm_search_contact(Contact* &contacts, const int &contacts_count){

    std::cout << "\n===== Do Search By =====\n";
    std::cout << "[1] Index.\n";
    std::cout << "[2] Name.\n";
    std::cout << "[3] Surnames.\n";
    std::cout << "[4] Birth_Date.\n";
    std::cout << "[5] Passport_Number.\n";
    std::cout << "[6] Phone_Number.\n";
    std::cout << "========================\n";

    std::string search;
    std::cout << "\nSearch_command : ";
    std::cin >> search;
    
    if(search.compare("1") == 0){

        std::cout << "\nIndex: ";
        std::cin >> search;
        if(cm_search_by_index(contacts, contacts_count, std::stoi(search))){

            return true;
        }
    }
    else if(search.compare("2") == 0){
        
        std::cout << "\nName: ";
        std::cin >> search;
        if(cm_search_by_name(contacts, contacts_count, search)){

            return true;
        }
    }
    else if(search.compare("3") == 0){

        std::cout << "\nSurName: ";
        std::cin >> search;
        if(cm_search_by_surname(contacts, contacts_count, search)){

            return true;
        }
    }
    else if(search.compare("4") == 0){

        std::cout << "\nBirth_Date: ";
        std::cin >> search;
        if(cm_search_by_birth_date(contacts, contacts_count, search)){

            return true;
        }
    }
    else if(search.compare("5") == 0){

        std::cout << "\nPassport_Number: ";
        std::cin >> search;
        if(cm_search_by_passport_num(contacts, contacts_count, search)){

            return true;
        }
    }
    else if(search.compare("6") == 0){

        std::cout << "\nPhone_Number: ";
        std::cin >> search;
        if(cm_search_by_phone_num(contacts, contacts_count, search)){

            return true;
        }
    }
    else{

        std::cout << "\nUnknown Command !\n";
    }

    return false;
}



void cm_start_editing_contact(Contact* &contacts, const int& contacts_count, Contact &contact){

    std::cout << "\n===== Editing Contact =====";

    contact.get_info();

    std::cout << "\nWrite down 'pass' if you don't want to change current field\n";

    std::string name;
    std::string surname;
    std::string date;
    std::string passport;
    std::string phone;

    do{

        std::cout << "\nName: ";
        std::cin >> name;

    }while(!(name.compare("pass") == 0) && !(cm_check_name_or_surname(name)));

    if(!(name.compare("pass") == 0)){

        contact.set_name(name);
    }



    do{

        std::cout << "\nSurname: ";
        std::cin >> surname;

    }while(!(surname.compare("pass") == 0) && !(cm_check_name_or_surname(surname)));

    if(!(surname.compare("pass") == 0)){

        contact.set_surname(surname);
    }



    
    do{

        std::cout << "\nBirth_Date (example 04/05/2002): ";
        std::cin >> date;

    }while(!(date.compare("pass") == 0) &&!(cm_check_birth_date(date)));

    if(!(date.compare("pass") == 0)){

        contact.set_birth_date(date);
    }



    do{

        std::cout << "\nPassport_Number: ";
        std::cin >> passport;

    }while(!(passport.compare("pass") == 0) &&!(cm_check_passport_number(contacts, contacts_count, passport)));

    if(!(passport.compare("pass") == 0)){

        contact.set_passport_number(passport);
    }



    do{

        std::cout << "\nPhone_Number: ";
        std::cin >> phone;

    }while(!(phone.compare("pass") == 0) &&!(cm_check_phone_number(contacts, contacts_count, phone)));

    if(!(phone.compare("pass") == 0)){

        contact.set_phone_number(phone);
    }

}

bool cm_edit_contact_by_index(Contact* &contacts, const int &contacts_count, const int &index){

    if(index <= 0){

        std::cout << "\nThe index is given wrong !\n";
        return false;
    }

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() == index){
            
            cm_start_editing_contact(contacts, contacts_count, contacts[i]);
            return true;
        }
    }

    std::cout << "\nThe index is given wrong !\n";
    return false;
}

void cm_edit_contact(Contact* &contacts, const int &contacts_count){

    std::cout << "\n===== Check if Contact Exists =====\n";
    if(cm_search_contact(contacts, contacts_count)){

        int index;

        do{

            std::cout << "\nChoose Contact's index to Edit: ";
            std::cin >> index;

        }while(!(cm_edit_contact_by_index(contacts, contacts_count, index)));

        std::cout << "\n-----Contact Has Been Changed-----\n";
    }
    else{

        std::cout << "\nContact Doesn't Exists !\n";
    }
}



bool cm_delete_contact_by_index(Contact* &contacts, const int &contacts_count, const int &index){

    if(index <= 0){

        std::cout << "\nThe index is given wrong !\n";
        return false;
    }

    for(int i = 0; i < contacts_count; ++i){

        if(contacts[i].get_index() == index){
            
            contacts[i].set_index(0);
            for(int j = index; j < contacts_count; ++j){
                
                if(contacts[j].get_index() != 0){

                    contacts[j].set_index(contacts[j].get_index() - 1);
                }
            }
            return true;
        }
    }

    std::cout << "\nThe index is given wrong !\n";
    return false;
}

void cm_delete_contact(Contact* &contacts, const int &contacts_count){

    std::cout << "\n===== Check if Contact Exists =====\n";
    if(cm_search_contact(contacts, contacts_count)){

        int index;

        do{

            std::cout << "\nChoose Contact's index to Delete: ";
            std::cin >> index;

        }while(!(cm_delete_contact_by_index(contacts, contacts_count, index)));

        std::cout << "\n-----Contact Has Been Deleted-----\n";
    }
    else{

        std::cout << "\nContact Doesn't Exists !\n";
    }
}



void cm_warning_about_closing(){

    std::cout << "\n!!! Please be sure that you close the program with '/exit' command, to save the data before closing.          !!!" 
              << "\n!!! If you don't, Your Edits won't be done and your file data will be lost.                                   !!!"
              << "\n!!! You will have file called 'reserve.txt', where the information will be stored, before closing the program.!!!" 
              << "\n!!! If you wish to save old data, you can just close the program by hand (without /exit command).             !!!\n";
}

void cm_show_commands(){

    std::cout << "\n====== User Commands ======\n\n";

    std::cout << "[1] Add a new Contact.\n";
    std::cout << "[2] Show all contacts.\n";
    std::cout << "[3] Search for contact.\n";
    std::cout << "[4] Edit a Contact.\n";
    std::cout << "[5] Delete a Contact.\n";
    std::cout << "[/exit] Save and exit the program.\n";
    std::cout << "\n===========================\n"; 
}



void program_contact_manager(){

    std::string path = "contacts.txt"; // <<----  Path can be changed here 

    std::ifstream fin; // Read from file stream
    std::ofstream fout; // Insert to file stream

    fin.open(path);


    std::cout << "\n->> Checking the path\n";


    if(fin.is_open()){

        std::cout << "\n====== File is open ======\n";

        std::cout << "\n->> Managing the contacts...\n";

        // Creating contacts data field
        Contact* contacts;

        // Token to read the first line, which will contain information about contacts_number
        std::string token;
        fin >> token;

        // Contacts number (The first number in the file shows how many contacts exists in data)
        int contacts_count = 0;
        int contacts_count_last = 0;
        
        if(token[0] < '1' || token[0] > '9'){

            std::cout << "\nFile is new or empty for the program, must adjust and manage new data field for User\n";
            std::cout << "\n!!!             WARNING           !!!\n";
            std::cout << "\n!!! FILE CONTENCT WILL BE DELETED !!!\n";
            std::cout << "\nARE YOU SURE YOU WANT TO CONTINUE ? (Y/N) : ";
            
            std::string answer;
            std::cin >> answer;

            if(answer.compare("Y") != 0){
                
                std::cout << "\n-----Program will be closed !-----\n\n";
                exit(0);
            }

            cm_add_contact(contacts, contacts_count);
            ++contacts_count_last;

            // Clean the file where contacts were taken (in this field it means that file is totaly new)
            fout.open(path, std::ofstream::out | std::ofstream::trunc);
            fout.close();
        }
        else{

            // Contacts number (The first number in the file shows how many contacts exists in data)
            contacts_count = std::stoi(token);
            contacts_count_last = contacts_count;


            // Create Contacts array for the program
            contacts = new Contact[contacts_count];
            cm_fill_contacts_data(contacts, contacts_count, fin);
        }

        
        std::cout << "\n->> Contacts data has been managed.\n";
        cm_warning_about_closing();

        std::cout << "\nContacts count: " << contacts_count << "\n\n";
        cm_show_all_contacts_info(contacts, contacts_count);


        // Create RESERVED place for user, so the current data won't be lost, if the program will be closed accidently
        // Or if User decided to save old data
        std::string path_reserve = "reserve.txt";
        fout.open(path_reserve, std::ofstream::out | std::ofstream::trunc);
        fout.close();
        fout.open(path_reserve);
        cm_insert_data_to_file(contacts, contacts_count, contacts_count, fout);
        fout.close();

        // Clean the file where contacts were taken
        fout.open(path, std::ofstream::out | std::ofstream::trunc);
        fout.close();

        // Command string for the User
        std::string com = "";
        
        
        cm_show_commands();

        // User can Edit the data now
        while(!(com.compare("/exit") == 0)){
            
            std::cout << "\nWaiting_for_command_number : ";
            std::cin >> com;

            // Add
            if(com.compare("1") == 0){

                cm_add_contact(contacts, contacts_count);
                ++contacts_count_last;

            } // Show all
            else if(com.compare("2") == 0){

                cm_show_all_contacts_info(contacts, contacts_count);

            } // Search
            else if(com.compare("3") == 0){
                
                if(!(cm_search_contact(contacts, contacts_count))){

                    std::cout << "\nContact Doesn't Exists !\n";
                }

            } // Edit
            else if(com.compare("4") == 0){
                
                cm_edit_contact(contacts, contacts_count);

            } // Delete
            else if(com.compare("5") == 0){
                
                cm_delete_contact(contacts, contacts_count);
                --contacts_count_last;

            } // Help
            else if(com.compare("/help") == 0){
                
                cm_show_commands();
            }// Wrong Command
            else{
                
                std::cout << "\nCommand is Unknown, please write '/help' to show information about the commands.\n";
            }

        }

        std::cout << "\ninserting\n";

        fout.open(path);

        // Insert all contacts data to the same file before closing
        cm_insert_data_to_file(contacts, contacts_count, contacts_count_last, fout);


        std::cout << "\n-----Contacts file is refreshed ! Program will be closed with success !-----\n\n";


        fout.close();
    }
    else{

        std::cout << "\n-----The file was not found or path is given wrong. The program will be closed !-----\n\n";
    }

    fin.close();
}

#endif