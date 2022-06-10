#include "contactfunc.hpp"

// Main function which will start the program Contact Manager
void program_contact_manager();

// Adds all information from the file to the Contacts array for the program
void cm_fill_contacts_data();

// Show all contacts information
void cm_show_all_contacts_info(Contact* &, const int &);

// After closing program, all new data is being inserted to the same file where it was taken from
// If closing was done by hand, the old data will be removed, but will be saved in reserve.txt
void cm_insert_data_to_file(Contact* &, const int &, const int &, std::ofstream &);

// Warn the user, that if the program will be closed without /exit command, all data will be lost. And information about reserve.txt file
void cm_warning_about_closing();

// Show all commands that user can use
void cm_show_commands();

// Add new contact to the Data
void cm_add_new_contact_to_contacts(Contact* &, const int &, Contact &);

// Add new contact (Will ask user to insert name, surname, birth_date, passport, phone), after rules passed will create new contact and will add to the data
void cm_add_contact(Contact* &, int &);

// Start to edit the Contact, Program will ask data from user to edit
void cm_start_editing_contact(Contact* &, const int& , Contact &);

// Edit Contact if the contact exists
void cm_edit_contact(Contact* &, const int &);

// Delete Contact if the contact exists
void cm_delete_contact(Contact* &, const int &);

// Count whitespaces needed to seperate information from each other
std::string cm_white_spaces(const std::string &, const int &);

// Check the rules of name or surname (Must start with capital, must not contain random symbols, numbers or capitals) range: [1...14]
bool cm_check_name_or_surname(const std::string &);

// Check the rules of birth date (Must contain only number and follow the rule month/day/year and be legit) range: [10]
bool cm_check_birth_date(const std::string &);

// Check the rules of passport number (Must contain numbers or capitals and must not repeat) range: [6...12]
bool cm_check_passport_number(const std::string &);

// Check the rules of phone number (Must contain numbers only and start with '+' exit code, also must not repeat) range: [8...20]
bool cm_check_phone_number(const std::string &);

// Do Search and Show information by INDEX
bool cm_search_by_index(Contact* &, const int &, const int &);

// Do Search and Show information by NAME
bool cm_search_by_name(Contact* &, const int &, const std::string &);

// Do Search and Show information by SURNAME
bool cm_search_by_name(Contact* &, const int &, const std::string &);

// Do Search and Show information by BIRTH_DATE
bool cm_search_by_birth_date(Contact* &, const int &, const std::string &);

// Do Search and Show information by PASSPORT_NUMBER
bool cm_search_by_passport_num(Contact* &, const int &, const std::string &);

// Do Search and Show information by PHONE_NUMBER
bool cm_search_by_phone_num(Contact* &, const int &, const std::string &);

// Start the Serch command, it will show the user what type of searches can be done and will ask to chose search_commands
bool cm_search_contact(Contact* &, const int &);

// Asking index of the contact from user, that must be edited (if index was given wrong, loop till index will be right)
bool cm_edit_contact_by_index(Contact* &, const int &, const int &);

// Asking index of the contact from user, that must be deleted (if index was given wrong, loop till index will be right) 
bool cm_delete_contact_by_index(Contact* &, const int &, const int &);