#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
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

//USER DEFINE MANIPULATOR

ostream& main_manip(ostream& output)
{
    output << std::setw(50) << " " << std::left;
    return output;
}
ostream& list_manip(ostream& output)
{
    output << std::setw(40) << " " << std::left;
    return output;
}
ostream& input_manip(ostream& output)
{
    output << "\n\n"<<std::setw(20) << " " << std::left;
    return output;
}




#endif
/*1	OODP	E-BALAGURUSAMY	2005	300	10
2	LINEAR-ALGEBRA	PAVISH	2010	450	20*/