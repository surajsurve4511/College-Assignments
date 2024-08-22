/*QUESTION  -
Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
Contact address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic memory
allocation operators-new and delete as well as exception handling*/



#include<iostream>
#include<string>
using namespace std;

class Student
{
 private:
 int rollno;
 string mobileno;
 int lino;
 string name;
 string bloodgrp;
 string address;
 int class_;
 string div ;
 string dob ;
 static count ;
 public:
  void getdata()
  {
    cout << "Enter the name of student: ";
    getline(cin, name);  // Use getline to read full name with spaces
    cout << "Enter roll number: ";
    cin >> rollno;
    cout << "Enter class: ";
    cin >> class_;
    cout << "Enter division: ";
    cin >> div;
    cout << "Enter date of birth: ";
    cin >> dob;
    cout << "Enter mobile number: ";
    cin >> mobileno;
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter blood group: ";
    cin >> bloodgrp;
    cout << "Enter driving license number: ";
    cin >> lino;
  }
  
  void showdata()
  {
    cout << "Name: " << name << endl
         << "Roll Number: " << rollno << endl
         << "Class: " << class_ << endl
         << "Division: " << div << endl
         << "Date of Birth: " << dob << endl
         << "Mobile Number: " << mobileno << endl
         << "Address: " << address << endl
         << "Blood Group: " << bloodgrp << endl
         << "Driving License Number: " << lino << endl;
  }


      // Default constructor
    Student();

    // Parameterized constructor
    Student(int rollno, const string& name, const string& mobileno, int lino,
            const string& bloodgrp, const string& address, int class_, const string& div, const string& dob);

    // Copy constructor
    Student(const Student& other);

    // Destructor
    ~Student();

};

// Implementations of Student class
Student::Student() : rollno(0), mobileno("0000000000"), lino(0),
    name(""), bloodgrp("INVALID"), address("INVALID"), class_(0), div("INVALID"), dob("INVALID") {}

Student::Student(int rollno, const string& name, const string& mobileno, int lino,
                 const string& bloodgrp, const string& address, int class_, const string& div, const string& dob)
    : rollno(rollno), mobileno(mobileno), lino(lino), name(name), bloodgrp(bloodgrp),
      address(address), class_(class_), div(div), dob(dob) {}

Student::Student(const Student& other) : rollno(other.rollno), mobileno(other.mobileno), lino(other.lino),
    name(other.name), bloodgrp(other.bloodgrp), address(other.address), class_(other.class_),
    div(other.div), dob(other.dob) {}

Student::~Student() {
    // Destructor logic if needed
}



//constructor, default constructor, copy constructor,destructor, static member functions, friend class, this pointer, inline code and dynamic memory
//allocation operators-new and delete as well as exception handling.




int main()
{
    int n;  
    cout<<"Enter number of students";
    cin >>n;
    Student s1[n];
    for (int i=0;i<n;i++)
    {
       s1[i].getdata();
    }
    for (int i=0;i<n;i++)
    {
       s1[i].showdata();
    }
    Student s2.();
    Student s3.(15,abc);
    Student s4.

    return 0;
}
