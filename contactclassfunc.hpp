#ifndef CONTACTCLASSFUNC_HPP
#define CONTACTCLASSFUNC_HPP

#include "contactclass.hpp"

Contact::Contact() 
        
        : c_index{}, c_name{}, c_surname{}, c_birth_date{}, c_passport_num{}, c_phone_num{}
{}



Contact::Contact(const int& index, const std::string &name, const std::string &surname, const std::string &birth_date, const std::string &passport_num, const std::string &phone_num)
                
                : c_index{index}, c_name{name}, c_surname{surname}, c_birth_date{birth_date}, c_passport_num{passport_num}, c_phone_num{phone_num}
{}



void Contact::get_info(){

    std::cout << "\nname:  " << c_name << "\nsurname:  " << c_surname << "\nbirth_date:  " << c_birth_date 
              << "\npassport_num:  " << c_passport_num << "\nphone_num:  " << c_phone_num << std::endl;
}



void Contact::set_index(const int &index){

    c_index = index;
}

void Contact::set_name(const std::string &name){

    c_name = name;
}

void Contact::set_surname(const std::string &surname){

    c_surname = surname;
}

void Contact::set_birth_date(const std::string &date){

    c_birth_date = date;
}

void Contact::set_passport_number(const std::string &passport){

    c_passport_num = passport;
}

void Contact::set_phone_number(const std::string &phone){

    c_phone_num = phone;
}



int Contact::get_index(){

    return c_index;
}

std::string Contact::get_name(){

    return c_name;
}

std::string Contact::get_surname(){

    return c_surname;
}

std::string Contact::get_birth_date(){

    return c_birth_date;
}

std::string Contact::get_passport_number(){

    return c_passport_num;
}

std::string Contact::get_phone_number(){

    return c_phone_num;
}



Contact::~Contact(){}

#endif