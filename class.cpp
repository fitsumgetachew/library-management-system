#include "class.h"
void Student::list_of_book( Book book) //under this function we list all our book
{
	 fstream file;
        file.open("book_file.txt", ios::in);
        if(file.is_open())
        {
			cout << setfill('*') << setw(57)<<"LIST OF BOOK"<<setw(43)<<setfill('*')<<" \n"<<endl;
			cout<< setiosflags(ios::left) <<setw(10) << "BOOK ID"     << setw(20)<<"BOOK NAME"
                << setw(20)<<"AUTHOR NAME"<<setw(10) << "PUBLICATION" << setprecision(3)
                << setw(10)<<"price"<<setw(15)<<"AVAILABLE BOOK"<<endl;		

            while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
            {
                
				cout<<setiosflags(ios::left)<<setw(10)<<book.book_id<<setw(20)<<book.book_name<<setw(20)<<book.book_author<<setw(10)<<book.publication<<setprecision(3)<<setw(10)<<book.price<<setw(15)<<book.no_book<<endl;		

                
            }
        }
        file.close();

}
void Student::search_book(Book book)
{
	fstream file;
    string name;
	cout<<setfill('*')<<setw(57)<<"SEARCH BOOK"<<setw(43)<<setfill('*')<<" \n"<<endl;

    cout<<"Enter book name 'please use uppercase' : ";
    cin>>name;
        file.open("book_file.txt",ios::in);
        if(file.is_open())
        {
            bool found=false;
            while(!found)	//until found=true we get file from file
			{
				file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book;
               
                if(book.book_name==name)
                {
					cout<<setw(60)<<"BOOK DETAIL"<<endl<<endl;
					cout<<setiosflags(ios::left)<<setw(10)<<"BOOK ID"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR NAME"<<setw(10)<<"PUBLICATION"<<setprecision(3)<<setw(10)<<"price"<<setw(15)<<"AVAILABLE BOOK"<<endl;		
					cout<<setiosflags(ios::left)<<setw(10)<<book.book_id<<setw(20)<<book.book_name<<setw(20)<<book.book_author<<setw(10)<<book.publication<<setprecision(3)<<setw(10)<<book.price<<setw(15)<<book.no_book<<endl;		

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
    cout<<"enter your id : ";
    cin>>id;
    cout<<"enter your password : ";
    cin>>pass;

        file.open("student_file.txt",ios::in);
        if(file.is_open())
        {
            while(!file.eof())
            {
                file>>stu.student_id>>stu.student_fname>>stu.student_lname>>stu.student_stream>>stu.student_pass>>stu.student_sex;
                if(stu.student_id==id && stu.student_pass==pass)
                return true;
            } 
         }
         file.close();
         return false;
}


void Librarian ::add_book(Book book)
{
	fstream file;
	file.open("book_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout<<setfill('*')<<setw(57)<<"FILL BOOK DETAIL"<<setw(43)<<setfill('*')<<" \n"<<endl;
			cout<<"Enter book ID : ";							// Enter file on the librarian filesource
			cin>>book.book_id;
			cout<<"Enter book name: ";
			cin>>book.book_name;
			cout<<"Enter Author name :";
			cin>>book.book_author;
			cout<<"Enter year of pubooklication :";
			cin>>book.publication;
			cout<<"Enter price of the book :";
			cin>>book.price;
			cout<<"Enter number of book: ";
			cin>>book.no_book;
			
			file<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
			file.close();
			cout<<setw(50)<<"SUCCECCFULLY ADDED THE BOOK !!";
		}
		else
		{
			cout<<"book file is not opened! ";
		}

}
void Student::replace_book()
{
	fstream file ,file2;
    string temp;
    file.open("book_file.txt",ios::out);
    file2.open("backup_book.txt", ios::in);
    while(!file2.eof())
    {
        getline(file2,temp);
        file<<temp<<endl;
    }
    file.close();
    file2.close();


}
void Librarian::issue_book(Book book)
{
	fstream file3;
    int id;
    
    cout<<"enter book ID : ";
    cin>>id;
    file3.open("book_file.txt", ios::in);
    bool found=false;
    while(!found)
    {
        file3>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book;
        if(book.book_id==id && book.no_book >=1)
        {
			cout<<setw(60)<<"BOOK DETAIL"<<endl<<endl;
			cout<<setiosflags(ios::left)<<setw(10)<<"BOOK ID"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR NAME"<<setw(10)<<"PUBLICATION"<<setprecision(3)<<setw(10)<<"price"<<setw(15)<<"AVAILABLE BOOK"<<endl;		
			cout<<setiosflags(ios::left)<<setw(10)<<book.book_id<<setw(20)<<book.book_name<<setw(20)<<book.book_author<<setw(10)<<book.publication<<setprecision(3)<<setw(10)<<book.price<<setw(15)<<book.no_book<<endl<<endl;
            
            int code;
            found=true;

            cout<<"enter service code: "<<endl;
            cin>>code;
            if(code==12345)
            {
                 fstream file,file2;
                 bool check= false;
                 file.open("book_file.txt", ios::in);
                 file2.open("backup_file.txt",ios::out);
                while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
                {
                    if(book.book_id && check==false)
                    {
                        book.no_book=book.no_book-1;
                        file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
                        check=true;
                    }
                    else
                    {
                        file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
                    }

                }
                file.close();
                file2.close();
                replace_book();
                cout<<endl<<endl<<endl;
                cout<<"success full issued !!"<<endl;
            
            }
            else
            {
            	cout<<"wrong pass word!"<<endl;
			}
        }
        if(file3.eof()&& found==false)
        {
                    cout<<"the book is not found";
                    break;
        }

    }
    file3.close();
}
void Librarian::return_book(Book book)
{
	fstream file3;
    int id;
    
    cout<<"enter book ID : ";
    cin>>id;
    file3.open("book_file.txt", ios::in);
    bool found=false;
    while(!found)
    {
        file3>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book;
        if(book.book_id==id)
        {
			cout<<setw(60)<<"BOOK DETAIL"<<endl<<endl;
			cout<<setiosflags(ios::left)<<setw(10)<<"BOOK ID"<<setw(20)<<"BOOK NAME"<<setw(20)<<"AUTHOR NAME"<<setw(10)<<"PUBLICATION"<<setprecision(3)<<setw(10)<<"price"<<setw(15)<<"AVAILABLE BOOK"<<endl;		
			cout<<setiosflags(ios::left)<<setw(10)<<book.book_id<<setw(20)<<book.book_name<<setw(20)<<book.book_author<<setw(10)<<book.publication<<setprecision(3)<<setw(10)<<book.price<<setw(15)<<book.no_book<<endl<<endl;
            
            int code;
            found=true;

            cout<<"enter service code: "<<endl;
            cin>>code;
            if(code==12345)
            {
                 fstream file,file2;
                 bool check= false;
                 file.open("book_file.txt", ios::in);
                 file2.open("backup_file.txt",ios::out);
                while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
                {
                    if(book.book_id && check==false)
                    {
                        book.no_book=book.no_book+1;
                        file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
                        check=true;
                    }
                    else
                    {
                        file2<<book.book_id<<"\t"<<book.book_name<<"\t"<<book.book_author<<"\t"<<book.publication<<"\t"<<book.price<<"\t"<<book.no_book<<endl;
                    }

                }
                file.close();
                file2.close();
                replace_book();
                cout<<endl<<endl<<endl;
                cout<<"success full returned !!"<<endl;
            
            }
            else
            {
            	cout<<"wrong pass word!"<<endl;
			}
        }
        if(file3.eof()&& found==false)
        {
                    cout<<"the book is not found";
                    break;
        }

    }
    file3.close();

}




void Librarian::delete_book(Book book)
{
	int id;
	cout<<setfill('*')<<setw(57)<<"DELETING BOOK"<<setw(43)<<setfill('*')<<" \n"<<endl;
	cout<<"enter book id : ";
    cin>>id;
    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("book_file.txt",ios::in);
    file2.open("backup_book_.txt",ios::out);
    bool check=false;
    while(file>>book.book_id>>book.book_name>>book.book_author>>book.publication>>book.price>>book.no_book)
    {
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
	cout<<setfill('*')<<setw(57)<<"FILL DETAIL OF STUDENT"<<setw(43)<<setfill('*')<<" \n"<<endl;
		
		file.open("student_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout<<"Don't forget to uses uppercase for alphabet !"<<endl;
			cout<<"Enter ID: ";							
			cin>>stu.student_id;
			cout<<"Enter First name: ";
			cin>>stu.student_fname;
			cout<<"Enter last name :";
			cin>>stu.student_lname;
			cout<<"Enter student stream:";
			cin>>stu.student_stream;
			cout<<"Enter student password :";
			cin>>stu.student_pass;
			cout<<"Enter student sex :";
			cin>>stu.student_sex;
			file<<stu.student_id<<"\t"<<stu.student_fname<<"\t"<<stu.student_lname<<"\t"<<stu.student_stream<<"\t"<<stu.student_pass<<"\t"<<stu.student_sex<<endl;			
			file.close();
			cout<<"Registering Student Successfully Done!"<<endl;
		}
		else
		{
			cout<<"Student file does not opened!"<<endl;
		}


}
void Student::replace_student()
{
	fstream file ,file2;
    string temp;
    file.open("student_file.txt",ios::out);
    file2.open("backup_student.txt", ios::in);
    while(!file2.eof())
    {
        getline(file2,temp);
        file<<temp<<endl;
    }
    file.close();
    file2.close();


}

void Librarian::delete_student(Student stu)
{
	int id;
	cout<<setfill('*')<<setw(57)<<"DELETING STUDENT"<<setw(43)<<setfill('*')<<" \n"<<endl;
	cout<<"enter student id : ";
    cin>>id;
    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("student_file.txt",ios::in);
    file2.open("backup_student.txt",ios::out);
    bool check=false;
    while(file>>stu.student_id>>stu.student_fname>>stu.student_lname>>stu.student_stream>>stu.student_pass>>stu.student_sex)
    {
        if(stu.student_id==id && check==false)
        {
            file3.open("deleted_student.txt",ios::out|ios::in|ios::app);
			file3<<stu.student_id<<"\t"<<stu.student_fname<<"\t"<<stu.student_lname<<"\t"<<stu.student_stream<<"\t"<<stu.student_pass<<"\t"<<stu.student_sex<<endl;			
            cout<<"deleting process is succesfully done"<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2<<stu.student_id<<"\t"<<stu.student_fname<<"\t"<<stu.student_lname<<"\t"<<stu.student_stream<<"\t"<<stu.student_pass<<"\t"<<stu.student_sex<<endl;			
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
	cout<<setfill('*')<<setw(57)<<"SEARCH STUDENT"<<setw(43)<<setfill('*')<<" \n"<<endl;

    cout<<"Enter student first name 'please use uppercase' : ";
    cin>>f_name;
	cout<<"Enter student last name :";
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
					cout<<setw(60)<<"student DETAIL"<<endl<<endl;
					cout<<setiosflags(ios::left)<<setw(10)<<"student ID"<<setw(20)<<"student first NAME"<<setw(20)<<"student last NAME"<<setw(15)<<"STREAM"<<setw(10)<<"PASSWORD"<<setw(10)<<"SEX"<<endl;		
					cout<<setiosflags(ios::left)<<setw(10)<<stu.student_id<<setw(20)<<stu.student_fname<<setw(20)<<stu.student_lname<<setw(15)<<stu.student_stream<<setw(10)<<stu.student_pass<<setw(10)<<stu.student_sex<<endl;		

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
    cout<<"enter your id : ";
    cin>>id;
    cout<<"enter your password : ";
    cin>>pass;

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



void Manager::add_librarian(Librarian lib)
{
	fstream file;
	cout<<setfill('*')<<setw(62)<<"FILL DETAIL OF EMPLOYEE"<<setw(38)<<setfill('*')<<" \n"<<endl;


		
		file.open("librarian_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout<<"Enter ID: ";							// Enter file on the librarian filesource
			cin>>lib.libraian_id;
			cout<<"Enter First name: ";
			cin>>lib.librarian_fname;
			cout<<"Enter last name :";
			cin>>lib.librarian_lname;
			cout<<"Enter librarian password :";
			cin>>lib.librarian_pass;
			cout<<"Enter librarian sex :";
			cin>>lib.librarian_sex;
			
			file<<lib.libraian_id<<"\t"<<lib.librarian_fname<<"\t"<<lib.librarian_lname<<"\t"<<lib.librarian_pass<<"\t"<<lib.librarian_sex<<endl;
			file.close();
		}
	

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

void Manager::delete_librarian(Librarian lib)
{
	int id;
	cout<<setfill('*')<<setw(57)<<"DELETING EMPLOYEE"<<setw(43)<<setfill('*')<<" \n"<<endl;
	cout<<"enter emplyee id : ";
    cin>>id;
    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("librarian_file.txt",ios::in);
    file2.open("backup_librarian.txt",ios::out);
    bool check=false;
    while(file>>lib.libraian_id>>lib.librarian_fname>>lib.librarian_lname>>lib.librarian_pass>>lib.librarian_sex)
    {
        
        if(lib.libraian_id==id && check==false)
        {
            file3.open("deleted_librarian.txt",ios::out|ios::in|ios::app);
			file3<<lib.libraian_id<<"\t"<<lib.librarian_fname<<"\t"<<lib.librarian_lname<<"\t"<<lib.librarian_pass<<"\t"<<lib.librarian_sex<<endl;
            cout<<"deleting process is successfully done"<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2<<lib.libraian_id<<"\t"<<lib.librarian_fname<<"\t"<<lib.librarian_lname<<"\t"<<lib.librarian_pass<<"\t"<<lib.librarian_sex<<endl;
        }
        
    }
    file.close();
    file2.close();
    replace_librarian();
}



void Manager:: add_manager(){
	fstream file;
	cout<<setfill('*')<<setw(57)<<"ADDING OF MANAGER"<<setw(43)<<setfill('*')<<" \n"<<endl;
		file.open("manager_file.txt",ios::out| ios::app);
		if(file.is_open())
		{
			cout<<setfill(' ')<<setw(60)<<"ENTER DETAIL OF NEW MANAGER\n"<<endl;

			cout<<"Enter manager ID: ";							
			cin>>manager_id;
			cout<<"Enter First name: ";
			cin>>manager_fname;
			cout<<"Enter last name :";
			cin>>manager_lname;
			cout<<"Enter manager password :";
			cin>>manager_pass;
			cout<<"Enter manager sex :";
			cin>>manager_sex;
			
			file<<manager_id<<"\t"<<manager_fname<<"\t"<<manager_lname<<"\t"<<manager_pass<<"\t"<<manager_sex<<endl;
			file.close();
			cout<<"SUCCESSFULLY ADDED NEW MANAGER!"<<endl;

		}
}
void Manager::delete_manager()
{
	int id;
	cout<<setfill('*')<<setw(57)<<"DELETING MANAGER"<<setw(43)<<setfill('*')<<" \n"<<endl;
	cout<<"enter emplyee id : ";
    cin>>id;
    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("manager_file.txt",ios::in);
    file2.open("backup_manager.txt",ios::out);
    bool check=false;
    while(file>>manager_id>>manager_fname>>manager_lname>>manager_pass>>manager_sex)
    {
        
        if(manager_id==id && check==false)
        {
            file3.open("deleted_managers.txt",ios::out|ios::in|ios::app);
			file3<<manager_id<<"\t"<<manager_fname<<"\t"<<manager_lname<<"\t"<<manager_pass<<"\t"<<manager_sex<<endl;
            cout<<"deleting process is successfully done"<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2<<manager_id<<"\t"<<manager_fname<<"\t"<<manager_lname<<"\t"<<manager_pass<<"\t"<<manager_sex<<endl;
        }
        
    }
    file.close();
    file2.close();
    replace_librarian();
}
void Manager::change_service_password()
{
	cout<<setfill('*')<<setw(67)<<"WELLCOME MANAGER TO CHANGE PASSWORD"<<setw(33)<<setfill('*')<<" \n"<<endl;
	int temp;
	servise_password=12345;
	password:
		cout<<"please enter old pass word :"<<endl;
		cin>>temp;
		if(temp==servise_password)
		{
			cout<<"please enter new password"<<endl;
			cin>>temp;
			servise_password=temp;
			cout<<"servse password successfully changed!!"<<endl;
			cout<<"your new password : "<<servise_password;
		}
		else
		{
			cout<<"wrong password!!"<<endl<<endl;
			goto password;
		}
	
}
bool Manager::check_manager_password()
{
	fstream file;
    int id,pass;
    cout<<"enter your id : ";
    cin>>id;
    cout<<"enter your password : ";
    cin>>pass;

        file.open("librarian_file.txt",ios::in);
        if(file.is_open())
        {
            while(!file.eof())
            {
                file>>manager_id>>manager_fname>>manager_lname>>manager_pass>>manager_sex;
                if(manager_id==id && manager_pass==pass)
                return true;
            } 
         }
         file.close();
         return false;	
}