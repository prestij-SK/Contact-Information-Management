# Contact-Information-Management
<h4>Contact Information Management System</h4>


Start the program, having two '.txt' type files in the same directory where the program is placed.
file1: contacts.txt
file2: reserve.txt
(the path can be changed in contactfunc.hpp)
<br></br>

Program gives the User a place, to organize contact information.
Contact's informations are: <br>Name    Surname     Birth_Date    Passport_Number    Phone_Number</br>
<br></br>

User will be able to insert commands, used to organize contact information with the program.
After inserting command's number or name, the following actions will be executed:
<br>[1] Add a new Contact.</br>
[2] Show all contacts.
<br>[3] Search for contact.</br>
[4] Edit a Contact.
<br>[5] Delete a Contact.</br>
[/help] Show all commands.
<br>[/exit] Save and exit the program.</br>
<br></br>

The first token of the file must be a number, it will show how many contacts are written in the file data.
It's important that file content will be empty or will have fields contained like <br>Example:  Marlon  Brando  04/15/1924  871AL53AA1  +17491641568</br>
<br></br>
If the file does not match to required parameters, program will delete content of the file and will ask the user to create first contact information.
Before deleting file content, program will ask the User to choose: Continue by deleting file content and create first contact or just quit the program.
<br></br>


