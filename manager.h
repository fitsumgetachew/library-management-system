#ifndef MANAGER_H
#define MANAGER_H

#include "librarian.h"

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
        //delete line of librarian   
        void delete_librarian(class Librarian);
        //directly change password by random
        void change_service_password();
        //we need to add manager
        void add_manager();
        void delete_manager();
        void replace_manager(); 
        bool check_manager_password();
    
};


void Manager::add_librarian(Librarian lib)
{
	fstream file;

	cout  <<  main_manip << setw(62) << "FILL DETAIL OF EMPLOYEE\n\n" << endl;


		
		file.open("librarian_file.txt", ios::out | ios::app);
		if(file.is_open())
		{
			cout<< input_manip << " Enter librarian ID: ";					// Enter file on the librarian file source
			cin  >> lib.libraian_id;
			cout<< input_manip << " Enter librarian First name: ";
			cin  >> lib.librarian_fname;
			cout<< input_manip << " Enter librarian last name :";
			cin  >> lib.librarian_lname;
			cout<< input_manip << " Enter librarian librarian password :";
			cin  >> lib.librarian_pass;
			cout<< input_manip << " Enter librarian librarian sex :";
			cin  >>  lib.librarian_sex;
			
			file << lib.libraian_id    << "\t" << lib.librarian_fname << "\t" << lib.librarian_lname << "\t"  
                 << lib.librarian_pass << "\t" << lib.librarian_sex   << endl;
			file.close();
            cout<< input_manip << " LIBRARIAN SUCCESSFULLY ADDED"<< endl;
		}
	

}


void Manager::delete_librarian(Librarian lib)
{
	int id;

	cout << main_manip << setw(57) << "DELETING EMPLOYEE\n\n" <<endl;
	cout << input_manip << "Enter emplyee id : ";

    cin >>id;

    fstream file,file2,file3; // we open three file first to read ,second to store the deleted file and last one is to read except from deleted one
    file.open("librarian_file.txt",ios::in);
    file2.open("backup_librarian.txt",ios::out);
    bool check=false;
    while(file>>lib.libraian_id>>lib.librarian_fname>>lib.librarian_lname>>lib.librarian_pass>>lib.librarian_sex)
    {
        
        if(lib.libraian_id==id && check==false)
        {
            file3.open("deleted_librarian.txt",ios::out|ios::in|ios::app);
			file3<<lib.libraian_id<<"\t"<<lib.librarian_fname<<"\t"<<lib.librarian_lname<<"\t"
                 <<lib.librarian_pass<<"\t"<<lib.librarian_sex<<endl;

            cout <<"Deleting process is successfully done"<<endl;
            check=true;
            file3.close();

        }
        else
        {
			file2 << lib.libraian_id<<"\t"<<lib.librarian_fname<<"\t"<<lib.librarian_lname<<"\t"
                  << lib.librarian_pass<<"\t"<<lib.librarian_sex<<endl;
        }
        
    }
    file.close();
    file2.close();
    replace_librarian();
}



void Manager:: add_manager(){
	fstream file;
	cout << main_manip <<"ADDING OF MANAGER\n\n"<<endl;
		file.open("manager_file.txt",ios::out| ios::app);
		if(file.is_open())
		{
			cout << main_manip <<"ENTER DETAIL OF NEW MANAGER\n"<<endl;

			cout << input_manip << " Enter manager ID: ";							
			cin >>manager_id;
			cout << input_manip << " Enter First name: ";
			cin >>manager_fname;
			cout << input_manip << " Enter last name :";
			cin >>manager_lname;
			cout << input_manip << " Enter manager password :";
			cin >>manager_pass;
			cout << input_manip << " Enter manager sex :";
			cin >>manager_sex;
			
			file<<manager_id<<"\t"<<manager_fname<<"\t"<<manager_lname<<"\t"<<manager_pass<<"\t"<<manager_sex<<endl;
			file.close();
			cout <<"SUCCESSFULLY ADDED NEW MANAGER!"<<endl;

		}
}

void Manager :: replace_manager()
 {
	fstream file ,file2;
    string temp;
    
    file.open( "manager_file.txt",ios::out);
    file2.open( "backup_manager.txt", ios::in);
    
    while(!file2.eof())
    {
        getline( file2 , temp );
        file << temp << endl;
    }

    file.close();
    file2.close();
}

void Manager::delete_manager()
{
	int id;
	cout << main_manip <<"DELETING MANAGER\n\n"<<endl;
	cout << input_manip << " Enter emplyee id : ";
    cin >>id;
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
            cout << input_manip << "Deleting process is successfully done"<<endl;
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
    replace_manager();
}
void Manager::change_service_password()
{
	cout <<main_manip <<"WELLCOME MANAGER TO CHANGE PASSWORD\n\n"<<endl;
	int temp;
	servise_password=12345;
	password:
		cout <<"please enter old password :"<<endl;
		cin >>temp;
		if(temp==servise_password)
		{
			cout <<"please enter new password"<<endl;
			cin >>temp;
			servise_password=temp;
			cout <<"servse password successfully changed!!"<<endl;
			cout <<"your new password : "<<servise_password;
		}
		else
		{
			cout <<"wrong password!!"<<endl<<endl;
			goto password;
		}
	
}
bool Manager::check_manager_password()
{
	fstream file;
    int id,pass;
    cout <<input_manip<<"enter your id : ";
    cin >>id;
    cout << input_manip <<"enter your password : ";
    cin >>pass;
    system(" cls ");

        file.open("manager_file.txt",ios::in);
        if(file.is_open())
        {
            while(!file.eof())
            {
                file>>manager_id>>manager_fname>>manager_lname>>manager_pass>>manager_sex;
                if(manager_id==id && manager_pass==pass)
                return true;
            } 
         }
         else
         {
             cout<<"file is not opened:"<<endl;
         }
         file.close();
         return false;	
}

#endif