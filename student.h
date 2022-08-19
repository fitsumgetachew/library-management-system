#ifndef STUDENT_H
#define STUDENT_H


#include "book.h"
using namespace std;

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

void Student::list_of_book( Book book) //under this function we list all our book
{
	 fstream file;
        file.open("book_file.txt", ios::in);
        if(file.is_open())
        {
			cout << main_manip<<"LIST OF BOOK\n\n" << endl;
			cout << std::setw(20) << " " << std::left     <<setw(10)   << "BOOK ID"    << setw(20)<<"BOOK NAME"
                 << setw(20) << "AUTHOR NAME" << setw(15) << "PUBLICATION" << setprecision(3)
                 << setw(10)  << "PRICE"      <<setw(15)  <<"AVAILABLE BOOK"  << endl;		

            while(file >> book.book_id >> book.book_name >> book.book_author >> book.publication >> book.price >> book.no_book)
            {
                
				cout << std::setw(20) << " " << std::left << setw(10) << book.book_id << setw(20) << book.book_name
                     << setw(20)  <<book.book_author      << setw(15)  << book.publication << setprecision(3) << setw(10) 
                     << book.price << setw(15) << book.no_book << endl;		

                
            }
        }
        file.close();

}

void Student::search_book(Book book)
{
	fstream file;
    string name;
	cout << main_manip<< "SEARCH BOOK\n\n" << endl;

    cout << input_manip << "Enter Book Name  : ";
    cin  >> name;
    system("cls");
        
        file.open("book_file.txt",ios::in);
        
        if( file.is_open() )
        {
            bool found = false;
            while( !found )	//until found=true we get file from file
			{
				file >> book.book_id >> book.book_name >> book.book_author >> book.publication 
                     >> book.price >> book.no_book;
               
                if( book.book_name == name )
                {
					cout << main_manip << "BOOK DETAIL\n\n" <<endl;
					cout << setw(20) << " "<< left << setw(10) << "BOOK ID" << setw(20) << "BOOK NAME" << setw(20)
                         << "AUTHOR NAME" <<setw(15)  << "PUBLICATION" <<setprecision(3)   <<setw(10)     <<"PRICE"
                         <<  setw(15)     << "AVAILABLE BOOK" << endl;		
					cout <<  setw(20) << " " <<left  <<setw(10)  << book.book_id     << setw(20)  << book.book_name 
                         << setw(20)  << book.book_author << setw(15) << book.publication << setprecision(3) <<setw(10)
                         << book.price <<setw(15) << book.no_book << endl;		

                    found=true; //when we find one value found= true this mean when found=true -> !found=false ,this stop while loop.
                }

                if(file.eof()&& found==false)
                {
                    cout<<"the book is not found";
                    break;
                }
            }


		} 
		else
		{
			cout<<"Sorry book file is not opened "<<endl;
		}

file.close();   
}


bool Student::check_student_password(Student stu)
{
	fstream file;
    int id,pass;
    cout<<"\n\n\n\n\n\n"<< list_manip<<"Enter Student Id : ";
    cin>>id;
    cout<<"\n\n" << list_manip<<"Enter Student Password : ";
    cin>>pass;
    system("cls");

        file.open("student_file.txt",ios::in);

        if(file.is_open())
        {
            while(!file.eof())
            {
                file >> stu.student_id   >> stu.student_fname >> stu.student_lname >> stu.student_stream
                     >> stu.student_pass >> stu.student_sex;
                
                if( stu.student_id == id && stu.student_pass == pass )
                
                return true;
            } 
        }
         file.close();
         return false;
}

void Student:: replace_student()
{
	fstream file ,file2;
    string temp;
    
    file.open( "student_file.txt",ios::out);
    file2.open( "backup_student.txt", ios::in);
    
    while(!file2.eof())
    {
        getline( file2 , temp );
        file << temp << endl;
    }

    file.close();
    file2.close();
}


void Student:: replace_book ()
{
	fstream file ,file2;
    string temp;

    file.open( "book_file.txt" , ios::out);
    file2.open( "backup_book.txt" , ios::in);
    
    while(!file2.eof())
    {
        getline( file2 , temp );
        file << temp << endl;
    }
    
    file.close();
    file2.close();



}

#endif
