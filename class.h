#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;


class Book
{
    public:
        int servise_password;
        int book_id;
        string book_name;
        string book_author;
        int publication;
        float price;
        int no_book;
        
};
class Student : public Book
{
    public:
        int student_id;
        int student_pass;
        string student_fname;
        string student_lname;
        string student_sex;
        string student_stream;
         // display book detail after search 
        void list_of_book(class Book);
        //search by using name
        void search_book(class Book);
        void replace_student();
        //to replace or copy one file from another
        void replace_book();
        bool check_student_password(class Student);
        
};

class Librarian :public Student
                  
{
    public:
        string librarian_fname;
        string librarian_lname;
        string librarian_sex;
        int libraian_id;
        int librarian_pass;
    public:
        // add book by name,id to the end of _________ file
        void add_book(class Book);
        
        //delete all book data
        void delete_book(class Book);
        // add student by name,id and password
        // by random to end of______ file
        void add_student(class Student stu);
        //delete all student data
        void delete_student(class Student);
        //issue book for student
        void search_student(class Student);
        void issue_book(class Book);
        void return_book(class Book);
        void replace_librarian();
        bool check_Librarian_password(class Librarian);

};
class Manager : public Librarian
                
{

    private:
        string manager_fname;
        string manager_lname;
        string manager_sex;
        int manager_pass;
        int manager_id;
        
    public:
        // add librarian by name, id ,and pass 
        //to the end of_______file
        void add_librarian(class Librarian);
        
        //delete 3line of librarian   
        void delete_librarian(class Librarian);
        //directly change password by random
        void change_service_password();
        //we need to add manager
        void add_manager();
        void delete_manager();
        void replace_manager(); 
        bool check_manager_password();
    
};
