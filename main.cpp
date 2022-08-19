
#include "manager.h"

using namespace std;

int main()
{
    int choice=0;
    Book book1;
    Student student1;
    Librarian librarian1;
    Manager manager1;
    system(" color 06	");

    main_menu:
        cout << main_manip<< "WELCOME TO MU E-LIBRARY\n\n"<< endl;
        cout <<list_manip<< "1. STUDENT "<< "\n" <<list_manip<< "2. LIBRARIAN" << "\n"
             <<list_manip<< "3. MANAGER" << "\n"     <<list_manip<<"4. EXIT\n\n\n";

        do
        {
            cout <<input_manip<< "ENTER USER TYPE : ";
            cin>>choice;
            system("cls");

        }
        while( !(choice == 1 || choice == 2 || choice==3 || choice==4) );
        
        if(choice==1)
        {

            bool pass = student1.check_student_password(student1);
            if(pass)
            {

                student:
                    cout << main_manip  << "WELCOME STUDENT\n\n"  << endl;
                    cout << list_manip  << "1. LIST BOOK "<<"\n"  << list_manip <<"2. SEARCH BOOK" << "\n"   
                         << list_manip  << "3. BACK TO MAIN MENU" << "\n"       << list_manip      << "4. EXIT\n\n\n";
                    
                    do
                    {
                        cout << input_manip<<"ENTER YOUR CHOICE(1-4) : ";
                       
                        cin>>choice;
                        system("cls");
                    }
                    while( !(choice == 1 || choice == 2||choice==3||choice==4) );

                    if(choice==1){
                        student1.list_of_book(book1);
                        cout<<input_manip<<"Enter any key to go student :";
                        getch();
                        system("cls");
                        goto student;}

                    else if(choice==2){
                        student1.search_book(book1);
                        cout<<input_manip<<"Enter any key to go student :";
                        getch();
                        system("cls");
                        goto student;}

                    
                    else if(choice==3){
                        system("cls");
                        goto main_menu;}
                    
                    else if(choice==4)
                        exit(0);
            }

            else
            {
                cout<<input_manip<<"WRONG PASS WORD OR UN REGISTERD ID"<<endl;
                cout<<input_manip<<"Press Any Key To Goto Main menu :";
                getch();
                system("cls");
                goto main_menu;
            }

            

        }
        else if(choice==2)
        {
            
            bool pass = librarian1.check_Librarian_password(librarian1);
            
            if( pass )
            {
                librarian:
                        cout<<main_manip<<"WELCOME LIBRARIAN\n\n\n"<<endl;
                        cout<<list_manip<<setw(30)<<"1. MANAGE BOOK "<<"\n"<<list_manip<<"2. ISSUE AND RETURN BOOK"<<endl
                            <<list_manip<<"3. MANAGE STUDENT"<<"\n"<<list_manip<<"4. MAIN MENU"<<endl<<list_manip<<"5. EXIT ";
                        do
                        {
                            cout <<input_manip<< "ENTER YOUR CHOICE(1-5) : ";
                          
                            cin>>choice;
                            system("cls");
                        }
                        while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5) );
                        if(choice==1)
                        {
                            book:
                                    cout<<main_manip<<"WELCOME LIBRARIAN FOR BOOK MANAGEMENT\n\n"<<endl;
                                    cout<<list_manip<<"1. ADD BOOK "<<endl<<list_manip<<"2. DELETE BOOK"<<endl<<list_manip<<"3. LIST BOOK"
                                        <<endl<<list_manip<<"4. SEARCH BOOK"<<endl<<list_manip<<"5. BACK TO MAIN MENU"<<"\n"<<list_manip<<"6. EXIT";

                                    do
                                    {
                                        cout << input_manip<< "ENTER YOUR CHOICE(1-6) : ";
                                       
                                        cin>>choice;
                                        system("cls");
                                    }
                                    while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5||choice==6) );
                                
                                switch (choice)
                                {
                                
                                    case 1:
                                        librarian1 . add_book ( book1 );
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto book;
                                        
                                    break;
                                        
                                    case 2:
                                        librarian1.delete_book( book1);
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto book;
                                    break;
                                    
                                    case 3:
                                        librarian1.list_of_book( book1);
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto book;
                                    break;
                                
                                    case 4:
                                        librarian1.search_book( book1);
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto book;
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
                            issue_and_return:

                                cout<<main_manip<<"WELCOME LIBRARIAN FOR ISSUE AND RETURN BOOK\n\n\n"<<endl;

                                cout<<list_manip<<"1. ISSUE BOOK "<<"\n"<<list_manip<<"2. RETURN BOOK"<<"\n"<<list_manip
                                    <<"3. BACK TO MAIN MENU" <<"\n"<<list_manip<<"4. EXIT";

                                do
                                {
                                    cout <<input_manip<< "ENTER YOUR CHOICE(1-4) : ";
                                    
                                    cin>>choice;
                                    system("cls");
                                }
                                while( !(choice == 1 || choice == 2||choice==3||choice==4) );
                                
                                        if(choice==1)
                                        {
                                            librarian1.issue_book ( book1);
                                            cout<<input_manip<<"Enter Any Key To Back : ";
                                            getch();
                                            system("cls");
                                            goto issue_and_return;
                                                    

                                        }
                                        else if(choice==2)
                                        {
                                            librarian1.return_book( book1);
                                            cout<<input_manip<<"Enter Any Key To Back : ";
                                            getch();
                                            system("cls");
                                            goto issue_and_return;
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
                        else if(choice==3)
                        {
                            manage_student:

                                    cout<<main_manip<<"WELCOME LIBRARIAN FOR MANAGIING STUDENT\n\n\n"<<endl;
                                    cout<<list_manip<<"1. ADD STUDENT "<<"\n"<<list_manip<<"2. DELETE STUDENT"<<"\n"<<list_manip
                                        <<"3. LIST STUDENT\n"<<list_manip<<"4. SEARCH STUDENT\n"<<list_manip<<"5. BACK TO MAIN MENU"
                                        <<"\n"<<list_manip<<"6. EXIT\n\n\n";
                                    do
                                    {
                                        cout << input_manip<<"ENTER YOUR CHOICE(1-6) : ";
                                        
                                        cin>>choice;
                                        system("cls");
                                    }
                                while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5||choice==6) );
                                
                                switch (choice)
                                {
                                    case 1:
                                        librarian1.add_student(student1);
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto manage_student;
                                        break;

                                    case 2:
                                        librarian1.delete_student( student1 );
                                        librarian1.add_student(student1);
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto manage_student;
                                    break;

                                    case 3:
                                        librarian1.search_student( student1 );
                                        cout<<input_manip<<"Enter Any Key To Back : ";
                                        getch();
                                        system("cls");
                                        goto manage_student;
                                        
                                    break;

                                    case 4:
                                        goto main_menu;
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

            else
            {
                cout<<" WRONG PASSWORD OR UNREGISTERED ID" << endl;
                cout<<input_manip<<"Enter Any Key To Main Menu : ";
                getch();
                system("cls");
                goto main_menu;
            }

        }
        else if(choice==3)
        {
            bool pass= manager1.check_manager_password();
            
            if( pass)
            {
                manager:

                    cout<<main_manip<<"WELCOME MANAGER\n\n\n"<<endl;
                    cout<<list_manip<<"1. MANAGE LIBRARIAN "<<"\n"<<list_manip<<"2. ADD MANAGER"<<"\n"<<list_manip
                        << "3. DELETE MANAGER"<<"\n"<<list_manip<<"4. CHANGE SERVICE PASSWORD"<<"\n"<< list_manip
                        <<"5. BACK TO MAIN MENU"<<"\n"<<list_manip<<"6. EXIT";
                    do{
                    cout <<input_manip<< "ENTER YOUR CHOICE(1-6) : ";
                    cin>>choice;
                    system("cls");
                    }
                    while( !(choice == 1 || choice == 2||choice==3||choice==4||choice==5||choice==6) );
                    if(choice==1)
                    {
                        manage_librarian:

                            cout<<main_manip<<"WELCOME  MANAGER FOR MANAGIING LIBRARIAN\n\n"<<endl;
                            cout<<list_manip<<"1. ADD LIBRARIAN "<<"\n"<<list_manip<<"2. DELETE LIBRARIAN"<<"\n"<<list_manip
                                    <<"3. BACK TO MAIN MENU"<<" \n "  << list_manip <<"4. BACK TO MANAGER";
                            do
                            {
                            cout <<input_manip<< "ENTER YOUR CHOICE(1-4) : ";
                          
                            cin>>choice;
                            system("cls");
                            }

                            while( !(choice == 1 || choice == 2||choice==3||choice==4) );
                            {
                                if(choice==1)
                                {
                                    manager1.add_librarian(librarian1);
                                    cout<<input_manip<<"Enter Any Key To Back : ";
                                    getch();
                                    system("cls");
                                    goto manage_librarian;


                                }
                                
                                else if(choice==2)
                                {
                                    manager1.delete_librarian(librarian1);
                                    cout<<input_manip<<"Enter Any Key To Back : ";
                                    getch();
                                    system("cls");
                                    goto manage_librarian;

                                }
                                else if(choice==3)
                                {
                                    goto main_menu;

                                }
                                else if(choice==4)
                                {
                                    goto manager;

                                }
                            }


                        
                    }
                    else if(choice==2)
                    {
                        manager1.add_manager();
                        cout<<input_manip<<"Enter Any Key To Back : ";
                        getch();
                        system("cls");
                        goto manager;

                    }
                    else if(choice==3)
                    {
                        manager1.delete_manager();
                        cout<<input_manip<<"Enter Any Key To Back : ";
                        getch();
                        system("cls");
                        goto manager;
                        

                    }
                    else if(choice==4)
                    {
                        //we will add here another funtion which can change service password    
                        cout<<input_manip<<"Enter Any Key To Back : ";
                        getch();
                        system("cls");
                        goto manager;
                    }  

                    else if(choice==5)
                    {
                        goto main_menu;

                    }
                    else if(choice==6)
                    {
                    exit(0);

                    }
            }

            else
            {
                cout<<"WRONG PASSWORD OR UNREGISTER ID "<<endl;
                goto main_menu;
            }
        }

        else if(choice==4)
        {
            exit(0);

        }

}

