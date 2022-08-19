#include <iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<iomanip>


using namespace std;

int main()
{
    int choice=0;
    main_menu:
        cout << setfill('*') << setw(100)   <<" " << endl;
        cout << setw(120)    << setfill('*')<<  endl;
        cout << setfill('*') << setw(60)    << "WELCOME TO MU E-LIBRARY" << setfill('*') << setw(40) << " \n" << endl;
        cout << setfill('*') << setw(100)   << " " << endl  << endl;
        cout << setfill(' ') << setw(30)    << "1. STUDENT "<< "\n"<<setw(30) << "2. LIBRARIAN" << "\n" << setw(30)
             << "3. MANAGER" << "\n"        << setw(30)     <<"4. EXIT\n\n\n";

        do
        {
            cout << "ENTER USER TYPE : ";
            getch();
            cin>>choice;
            system("cls");

        }
        while( !(choice == 1 || choice == 2 || choice==3 || choice==4) );
        
        if(choice==1)
        {
            //Student student1;
            //Book book1;

            cout << setfill('*') << setw(100)    << " " <<endl;
            cout << setfill('*') << setw(57)     << "WELCOME STUDENT" << setw(43) << " \n" << endl;
            cout << setw(100)    << setfill('*') << endl << " \n";
            cout << setfill(' ') << setw(30)     << "1. LIST BOOK "<<"\n"  << setw(30) <<"2. SEARCH BOOK"
                 << "\n"         << setw(30)     << "3. BACK TO MAIN MENU" << "\n"     << setw(30)   << "4. EXIT\n\n\n";
            
            do
            {
                cout << "ENTER YOUR CHOICE(1-4) : ";
                getch();
                cin>>choice;
                system("cls");
            }
            while( !(choice == 1 || choice == 2||choice==3||choice==4) );

            if(choice==1)
               {
    
			   }
            else if(choice==2)
               {
			   }
            else if(choice==3)
                goto main_menu;
            else if(choice==4)
                exit(0);

        }
        else if(choice==2)
        {
            cout<<setw(100)<<setfill('*')<<" \n"<<endl;
            cout<<setfill('*')<<setw(59)<<"WELCOME LIBRARIAN"<<setfill('*')<<setw(41)<<" /n"<<endl;
            cout<<setw(100)<<setfill('*')<<" \n"<<endl;
            cout<<setfill(' ')<<setw(30)<<"1. MANAGE BOOK "<<"\n"<<setw(30)<<"2. ISSUE AND RETURN BOOK"
                <<"\n"<<setw(30)<<"3. MANAGE STUDENT"<<"\n"<<setw(30)<<"4. MAIN MENU"<<endl<<setw(30)<<"5. EXIT "<<"\n\n\n";
        do{
            cout << "ENTER YOUR CHOICE(1-5) : ";
            getch();
            cin>>choice;
            system("cls");
            }
            while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5) );
            if(choice==1)
            {
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill('*')<<setw(70)<<"WELCOME LIBRARIAN FOR BOOK MANAGEMENT"<<setfill('*')<<setw(30)<<" \n"<<endl;
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill(' ')<<setw(30)<<"1. ADD BOOK "<<"\n"<<setw(30)<<"2. DELETE BOOK"<<"\n"<<setw(30)<<"3. LIST BOOK"
                    <<endl<<setw(30)<<"4. SEARCH BOOK"<<endl<<setw(30)<<"5. BACK TO MAIN MENU"<<"\n"<<setw(30)<<"6. EXIT\n\n\n";

                do
                {
                    cout << "ENTER YOUR CHOICE(1-6) : ";
                    getch();
                    cin>>choice;
                    system("cls");
                }
                while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5||choice==6) );
            
            switch (choice)
            {
                case 1:
                
                break;
                
                case 2:
                
                break;
                
                case 3:
                
                break;
               
                case 4:
                
                break;
                case 5:
                    goto main_menu;
                break;
                
                case 6:
                    exit(0);
                break;
                
                default:
                break;
            }
            }
            else if(choice==2)
            {
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill('*')<<setw(72)<<"WELCOME LIBRARIAN FOR ISSUE AND RETURN BOOK"<<setfill('*')<<setw(28)<<" \n"<<endl;
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill(' ')<<setw(30)<<"1. ISSUE BOOK "<<"\n"<<setw(30)<<"2. RETURN BOOK"<<"\n"<<setw(30)
                    <<"3. BACK TO MAIN MENU" <<"\n"<<setw(30)<<"4. EXIT\n\n\n";

                do
                {
                    cout << "ENTER YOUR CHOICE(1-4) : ";
                    getch();
                    cin>>choice;
                    system("cls");
                }
                while( !(choice == 1 || choice == 2||choice==3||choice==4) );
                if(choice==1)
                {

                }
                else if(choice==2)
                {

                }
                else if(choice==3)
                {

                }
                else if(choice==4)
                {
                    exit(0);

                }



            }
            else if(choice==3)
            {
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill('*')<<setw(68)<<"WELCOME LIBRARIAN FOR MANAGIING STUDENT"<<setfill('*')<<setw(32)<<" \n"<<endl;
                cout<<setw(100)<<setfill('*')<<" \n"<<endl;
                cout<<setfill(' ')<<setw(30)<<"1. ADD STUDENT "<<"\n"<<setw(30)<<"2. DELETE STUDENT"<<"\n"<<setw(30)
                <<"3. LIST STUDENT\n"<<setw(30)<<"4. SEARCH STUDENT\n"<<setw(30)<<"5. BACK TO MAIN MENU"<<"\n"<<setw(30)<<"6. EXIT\n\n\n";
                do
                {
                    cout << "ENTER YOUR CHOICE(1-6) : ";
                    getch();
                    cin>>choice;
                    system("cls");
                }
            while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5||choice==6) );
            
            switch (choice)
            {
                case 1:
                break;

                case 2:
                break;

                case 3:
                break;

                case 4:

                break;
                case 5:
                    goto main_menu;
                break;

                case 6:
                    exit(0);
                break;
                
                default:
                break;
            }


            }
            else if(choice==4)
            {
                goto main_menu;

            }
            else if(choice==5)
            {
                exit(0);

            }


        }
        else if(choice==3)
        {
            cout<<setw(100)<<setfill('*')<<" \n"<<endl;
            cout<<setw(58)<<"WELCOME MANAGER"<<setw(42)<<" \n"<<endl;
            cout<<setw(100)<<setfill('*')<<" \n"<<endl;
            cout<<setfill(' ')<<setw(30)<<"1. MANAGE LIBRARIAN "<<"\n"<<setw(30)<<"2. CHANGE SERVICE PASSWORD"<<"\n"<<setw(30)
                <<"3. BACK TO MAIN MENU"<<"\n"<<setw(30)<<"4. EXIT\n\n\n";
            do{
            cout << "ENTER YOUR CHOICE(1-4) : ";
            getch();
            cin>>choice;
            system("cls");
            }
            while( !(choice == 1 || choice == 2||choice==3||choice==4) );
            if(choice==1)
            {

            }
            else if(choice==2)
            {

            }
            else if(choice==3)
            {
                goto main_menu;

            }
            else if(choice==4)
            {
                exit(0);

            }


        }
        else if(choice==4)
        {
            exit(0);

        }

}

