#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "student.h"

class Librarian :public Student
                  
{
    public:
        string librarian_fname;
        string librarian_lname;
        string librarian_sex;
        int libraian_id;
        int librarian_pass;
    public:
        void add_book(class Book);
        
        //delete all book data
        void delete_book(class Book);
        // add student by name,id and password
        // by random to end of______ file
        void add_student(class Student stu);
        //delete all student data
        void list_of_student(class Student);
        void delete_student(class Student);
        //issue book for student
        void search_student(class Student);
        void issue_book(class Book);
        void return_book(class Book);
        void replace_librarian();
        bool check_Librarian_password(class Librarian);

};

// add book by name,id to the end of _________ file
void Librarian ::add_book(Book book)
{
	fstream file;

	file.open("book_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout << main_manip << setw(57) << "FILL BOOK DETAIL\n\n"<< endl;
			cout << input_manip<< " Enter book ID : ";							// Enter file on the librarian filesource
            cin  >> book.book_id;
			cout << input_manip<< " Enter book name: ";
			cin  >> book.book_name;
			cout << input_manip<< " Enter Author name :";
			cin  >> book.book_author;
			cout << input_manip<< " Enter year of publication :";
			cin  >> book.publication;
			cout << input_manip<< " Enter price of the book :";
			cin  >> book.price;
			cout << input_manip<< " Enter number of book: ";
			cin  >> book.no_book;
			
			file << book.book_id << "\t" << book.book_name << "\t" << book.book_author << "\t" << book.publication << "\t"
                 << book.price   << "\t" << book.no_book   << endl;
			file.close();

			cout << setw(50) << "SUCCECCFULLY ADDED THE BOOK !!";
		}

		else
		{
			cout << "book file is not opened! ";
		}

}


void Librarian:: issue_book (Book book)
{
	fstream file3;
    int id;
    
    cout << input_manip<< " Enter book ID : ";
    cin  >> id;
    file3.open( "book_file.txt", ios::in);
    bool found = false;
    while(!found)
    {
        file3 >> book.book_id >> book.book_name >> book.book_author >> book.publication >> book.price >> book.no_book;
        
        if( book.book_id == id && book.no_book >= 1)
        {
			cout << setw(60) << "BOOK DETAIL"    << endl << endl;
			cout << std::setw(20) << " " << std::left     <<setw(10)   << "BOOK ID"    << setw(20)<<"BOOK NAME"
                 << setw(20) << "AUTHOR NAME" << setw(15) << "PUBLICATION" << setprecision(3)
                 << setw(10)  << "PRICE"      <<setw(15)  <<"AVAILABLE BOOK"  << endl;		

		    cout << setw(20)   << " " << std::left << setw(10) << book.book_id << setw(20) << book.book_name
                 << setw(20)   << book.book_author      << setw(15)  << book.publication << setprecision(3) << setw(10) 
                 << book.price << setw(15) << book.no_book << endl;	
            
            int code;
            found=true;

            cout << input_manip<< " Enter service code: " << endl;
            cin >> code;
            
            if(code==12345)
            {
                 fstream file,file2;
                 bool check= false;
                 file.open("book_file.txt", ios::in);
                 file2.open("backup_book.txt",ios::out);

                while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
                {
                    if(book.book_id==id && check==false)
                    {
                        book.no_book=book.no_book-1;
                        file2 << book.book_id     << "\t" << book.book_name << "\t" << book.book_author << "\t" 
                              << book.publication << "\t" << book.price     << "\t" << book.no_book     << endl;
                        check=true;
                        //cout<<"successfully issued :"<<endl;
                    }
                    
                    else
                    {
                        file2 << book.book_id     << "\t" << book.book_name << "\t" << book.book_author << "\t"
                              << book.publication << "\t" << book.price     << "\t" << book.no_book << endl;
                    }

                }
                file.close();
                file2.close();
                replace_book();

                cout <<"\n\n" << list_manip << " SUCCESSFULLY ISSUED !!"<<endl;
            
            }
            else
            {
            	cout<<list_manip<<"wrong pass word!"<<endl;
			}
        }
        if(file3.eof()&& found==false)
        {
                    cout<<input_manip<<"the book is not found";
                    break;
        }

    }
    file3.close();
}
void Librarian::return_book(Book book)
{
	fstream file3;
    int id;
    
    cout << input_manip << "enter book ID : ";
    cin >> id;
    file3.open("book_file.txt", ios::in);
    bool found=false;
    while(!found)
    {
        file3 >> book.book_id >> book.book_name >> book.book_author >> book.publication >> book.price >> book.no_book;

        if(book.book_id==id)
        {
			cout << main_manip << "BOOK DETAIL\n\n"<<endl;
			cout << std::setw(20) << " " << std::left     <<setw(10)   << "BOOK ID"    << setw(20)<<"BOOK NAME"
                 << setw(20) << "AUTHOR NAME" << setw(15) << "PUBLICATION" << setprecision(3)
                 << setw(10)  << "PRICE"      <<setw(15)  <<"AVAILABLE BOOK"  << endl;		

		    cout << setw(20)   << " " << std::left << setw(10) << book.book_id << setw(20) << book.book_name
                 << setw(20)   << book.book_author      << setw(15)  << book.publication << setprecision(3) << setw(10) 
                 << book.price << setw(15) << book.no_book << endl;	
            
            int code;
            found=true;

            cout<< input_manip<< "enter service code: "<<endl;
            cin>>code;
            if(code==12345)
            {
                 fstream file,file2;
                 bool check= false;
                 file.open("book_file.txt", ios::in);
                 file2.open("backup_book.txt",ios::out);
                while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
                {
                    if(book.book_id && check==false)
                    {
                        book.no_book=book.no_book+1;
                        file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"
                             <<book.price<<"\t"<<book.no_book<<endl;
                        check=true;
                    }
                    else
                    {
                        file2 << book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"
                              << book.price<<"\t"<<book.no_book<<endl;
                    }

                }
                file.close();
                file2.close();
                replace_book();
                cout<<list_manip<<"SUCCESSFULLY RETURNED !!"<<endl;
            
            }
            else
            {
            	cout<<list_manip<<"WRONG PASSWORD!!"<<endl;
			}
        }
        if(file3.eof()&& found==false)
        {
                    cout<<"THE BOOK IS NOT FOUND !!"<<endl;
                    break;
        }

    }
    file3.close();

}




void Librarian::delete_book(Book book)
{
	int id;
	cout<<main_manip<<"DELETING BOOK\n\n"<<endl;
	cout<<input_manip<<"enter book id : ";
    cin>>id;
    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("book_file.txt",ios::in);
    file2.open("backup_book.txt",ios::out);
    bool check=false;
    while(!(file.eof()))
    {
        file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book;
        if(book.book_id==id && check==false)
        {
            file3.open("deleted_book.txt",ios::out|ios::in|ios::app);
			file3<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
            cout<<"deleting process is succesfully done"<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
        }
        
    }
    file.close();
    file2.close();
    replace_book();

}

void Librarian::add_student(Student stu)
{
	fstream file;
	cout<< main_manip <<"FILL DETAIL OF STUDENT\n\n" << endl;
		
		file.open("student_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout << input_manip<< " Enter ID: ";	            cin >> stu.student_id;
			cout << input_manip<< " Enter First name: ";	    cin>>stu.student_fname;
			cout << input_manip<< " Enter last name :";        cin>>stu.student_lname;
			cout << input_manip<< " Enter student stream:";    cin >> stu.student_stream;
			cout << input_manip<< " Enter student password :"; cin>>stu.student_pass;
			cout << input_manip<< " Enter student sex :";      cin >> stu.student_sex;

			file << stu.student_id << "\t"   << stu.student_fname << "\t" << stu.student_lname << "\t" << stu.student_stream
                 << "\t" << stu.student_pass << "\t"<<stu.student_sex << endl;			
			file.close();
			cout << input_manip << "REGISTRATION OF STUDENT  SUCCESSFULLY DONE!" << endl;
		}
		else
		{
			cout << "STUDENT FILE DOES NOT OPEN !!" << endl;
		}


}

void Librarian:: list_of_student( Student stu) //under this function we list all our book
{
	 fstream file;

        file.open("student_file.txt", ios::in);

        if(file.is_open())

        {
			cout << setw(60) << "student DETAIL\n\n" << endl;
			cout << setw(20) <<" " << left << setw(10) << "student ID" << setw(20) << "FIRST NAME" << setw(20)
                 <<  "LAST NAME"   << setw(15) << "STREAM"     <<setw(10)   << "PASSWORD" << setw(10) << "GENDER" <<endl;		
					
		

            while(file >>stu.student_id>>stu.student_fname>>stu.student_lname>>stu.student_stream>>stu.student_pass>>stu.student_sex)
            {
                cout << setw(20) << " "<< left << setw(10) << stu.student_id << setw(20) << stu.student_fname << setw(20)
                     <<    stu.student_lname   << setw(15) << stu.student_stream << setw(10) << stu.student_pass <<setw(10)
                     <<    stu.student_sex     <<endl;		
                
            }
        }

        file.close();

}


void Librarian::delete_student(Student stu)
{
	int id;
	cout<< main_manip  << "DELETING STUDENT\n\n"<<endl;
	cout<< input_manip << "ENTER STUDENT ID : ";
    cin>>id;
    fstream file,file2,file3; 
    file.open("student_file.txt",ios::in);
    file2.open("backup_student.txt",ios::out);
    bool check=false;
    while(file>>stu.student_id>>stu.student_fname>>stu.student_lname>>stu.student_stream>>stu.student_pass>>stu.student_sex)
    {
        if(stu.student_id==id && check==false)
        {
            file3.open("deleted_student.txt",ios::out|ios::in|ios::app);
			file3 << stu.student_id << "\t" << stu.student_fname << "\t" << stu.student_lname << "\t" << stu.student_stream
                  << "\t" << stu.student_pass << "\t" << stu.student_sex << endl;			
            cout<< input_manip << "DELETING  PROCESS IS SUCCESSFULLY DONE "<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2 << stu.student_id<<"\t"<<stu.student_fname<<"\t"<<stu.student_lname<<"\t"<<stu.student_stream
                  << "\t" << stu.student_pass<<"\t"<<stu.student_sex<<endl;			
        }
        
    }
    file.close();
    file2.close();
    replace_student();

}

void Librarian::search_student(Student stu)
{
	fstream file;
    string f_name;
	string l_name;
    int id;
	cout << main_manip <<"SEARCH STUDENT\n\n" << endl;

    cout << input_manip << " ENTER STUDENT FIRST NAME : " ;
    cin  >> f_name;
	cout << input_manip << " ENTER STUDENT LAST NAME  :";
	cin>>l_name;

        file.open("student_file.txt",ios::in);
        if(file.is_open())
        {
            bool found=false;
            while(!found)	//until found=true we get file from file
			{
				file>>stu.student_id>>stu.student_fname>>stu.student_lname>>stu.student_stream>>stu.student_pass>>stu.student_sex;
               
                if(stu.student_fname==f_name && stu.student_lname==l_name)
                {
					cout<< main_manip << "student DETAIL\n\n" << endl;
					cout<< setw( 20 ) << " " << left <<setw(10)<<"student ID"<<setw(20)<<"FIRST NAME"<<setw(20)
                        <<" LAST NAME"<<setw(15)<<"STREAM"<<setw(10)<<"PASSWORD"<<setw(10)<<"SEX"<<endl;	

					cout<< setw (20) << " " << left <<setw(10)<<stu.student_id<<setw(20)<<stu.student_fname
                        <<setw(20) <<stu.student_lname<<setw(15)<<stu.student_stream<<setw(10)
                        <<stu.student_pass<<setw(10)<<stu.student_sex<<endl;		

                    found=true; //when we find one value found= true this mean when found=true -> !found=false ,this stop while loop.
                }

                if(file.eof()&& found==false)
                {
                    cout<<"the student is not registered";
                    break;
                }
            }


		} 
		else
		{
			cout<<"Sorry student file is not opened "<<endl;
		}
file.close();  

}


bool Librarian::check_Librarian_password(Librarian lib)
{
	fstream file;
    int id,pass;
    cout<<input_manip<<"Enter your Id : ";
    cin>>id;
    cout<<input_manip<<"Enter Your Password : ";
    cin>>pass;
    system("cls");

        file.open("librarian_file.txt",ios::in);
        if(file.is_open())
        {
            while(!file.eof())
            {
                file>>lib.libraian_id>>lib.librarian_fname>>lib.librarian_lname>>lib.librarian_pass>>lib.librarian_sex;
                if(lib.libraian_id==id && lib.librarian_pass==pass)
                return true;
            } 
         }
         file.close();
         return false;

}

void Librarian::replace_librarian()
{
	fstream file ,file2;
    string temp;
    file.open("librarian_file.txt",ios::out);
    file2.open("backup_librarian.txt", ios::in);
    while(!file2.eof())
    {
        getline(file2,temp);
        file<<temp<<endl;
    }
    file.close();
    file2.close();

}


#endif
