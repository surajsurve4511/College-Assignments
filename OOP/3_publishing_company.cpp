/*QUESTION -
Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which adds
a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and displays
the data members. If an exception is caught, replace all the data member values with zero
values.*/


#include<iostream>
#include<string>
using namespace std;


class publication {
    protected :
     string title;
     float price;
    
    public :
     void get_data(){
        cout << "Title: ";
        cin>>title;
        cout<<"Price: ";
        cin>>price;
     }
     void display_data(){
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
     }
     
     publication(){
        title = "No title" ;
        price = 0 ;
     }
     ~publication() {}
};

class book : public publication {
    
    private :
     int page_count;
    public :
     void get_data(){
        publication :: get_data();
        cout<<"Count of pages: ";
        cin>>page_count;
     }
     void display_data(){
        publication :: display_data();
        cout<<"Count of pages"<<page_count<<"\n";
     }
     book(){
        page_count = 0 ;
     }
};

int main(){
    book b1, b2;

    cout << "Details of Book 1 before input:" << endl;
    b1.display_data();

    cout << "\nEnter details for Book 1:" << endl;
    b1.get_data();
    cout << "\nDetails of Book 1 after input:" << endl;
    b1.display_data();

    cout << "\nEnter details for Book 2:" << endl;
    b2.get_data();
    cout << "\nDetails of Book 2 after input:" << endl;
    b2.display_data();

    return 0;
}
