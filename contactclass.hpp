#ifndef CONTACTCLASS_HPP
#define CONTACTCLASS_HPP

#include <string>

class Contact{

private:

    int c_index;
    std::string c_name;
    std::string c_surname;
    std::string c_birth_date;
    std::string c_passport_num;
    std::string c_phone_num;


public:

    // Default Constructor for Contact
    Contact();

    // Constructor with name, surname, birth_date, passport_num, phone_num
    Contact(const int&, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);


    

    // Show information about the contact
    void get_info();

    // Set index
    void set_index(const int &);

    // Set name
    void set_name(const std::string &);

    // Set surname
    void set_surname(const std::string &);

    // Set birth date
    void set_birth_date(const std::string &);

    // Set passport number
    void set_passport_number(const std::string &);

    // Set phone number
    void set_phone_number(const std::string &);




    // Get index
    int get_index();

    // Get name
    std::string get_name();

    // Get surname
    std::string get_surname();

    // Get birth date
    std::string get_birth_date();

    // Get passport number
    std::string get_passport_number();

    // Get phone number
    std::string get_phone_number();



    // Destructor
    ~Contact();

};

#endif