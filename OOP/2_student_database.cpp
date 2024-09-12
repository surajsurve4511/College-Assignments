/*QUESTION  -
Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group,
Contact address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic memory
allocation operators-new and delete as well as exception handling*/

#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

// Forward declaration of Friend class
class Student;

// Address class to store contact information
class Address {
private:
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;

public:
    Address() : contactAddress("Unknown"), phoneNumber("Unknown"), drivingLicenseNo("Unknown") {}

    Address(string addr, string phone, string license) 
        : contactAddress(addr), phoneNumber(phone), drivingLicenseNo(license) {}

    // Friend class declaration
    friend class Student;

    void display() const {
        cout << "Address: " << contactAddress << "\nPhone: " << phoneNumber << "\nDriving License: " << drivingLicenseNo << endl;
    }
};

// Student class definition
class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dob;
    string bloodGroup;
    Address* address; // dynamically allocated
    static int studentCount;

public:
    // Default constructor
    Student() : name("Unknown"), rollNumber(0), studentClass("Unknown"), division('X'), dob("Unknown"), bloodGroup("Unknown") {
        address = new Address();
        studentCount++;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, char div, string d, string blood, string addr, string phone, string license) 
        : name(n), rollNumber(roll), studentClass(cls), division(div), dob(d), bloodGroup(blood) {
        address = new Address(addr, phone, license);
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        studentClass = other.studentClass;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        address = new Address(*other.address); // deep copy
        studentCount++;
    }

    // Destructor
    ~Student() {
        delete address;
        studentCount--;
    }

    // Static member function to get student count
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function to display student info
    inline void display() const {
        cout << "Name: " << name << "\nRoll Number: " << rollNumber << "\nClass: " << studentClass << "\nDivision: " << division
             << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup << endl;
        address->display();
    }

    // Dynamic memory allocation 
    void setDynamicDetails() {
 
            string addr, phone, license;
            cout << "Enter Address: ";
            getline(cin, addr);
            cout << "Enter Phone Number: ";
            getline(cin, phone);
            cout << "Enter Driving License Number: ";
            getline(cin, license);

            address = new Address(addr, phone, license);  
        
    }

    // Friend function to access private members
    friend void displayFriend(const Student&);

    // 'this' pointer demonstration
    Student& setRollNumber(int roll) {
        this->rollNumber = roll;
        return *this; // returns reference to current object
    }
};

// Static member initialization
int Student::studentCount = 0;

// Friend function definition
void displayFriend(const Student& s) {
    cout << "Friend accessing private data of Student:\n";
    cout << "Name: " << s.name << "\nRoll Number: " << s.rollNumber << "\nClass: " << s.studentClass << endl;
}

int main() {
    // Using parameterized constructor
    Student s1("John", 101, "12th", 'A', "01/01/2004", "O+", "123 Street", "1234567890", "DL12345");
    s1.display();
    
    // Using default constructor and setting dynamic details
    Student s2;
    s2.setDynamicDetails();
    s2.display();

    // Using copy constructor
    Student s3(s1);
    s3.display();

    // Static member function usage
    cout << "Total Students: " << Student::getStudentCount() << endl;

    // Demonstrating 'this' pointer
    s2.setRollNumber(102).display();

    // Friend function access
    displayFriend(s1);

    return 0;
}
