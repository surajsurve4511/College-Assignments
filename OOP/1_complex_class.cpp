/*QUESTION -
Implement a class Complex which represents the Complex Number data type. Implement the
following
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overload operator+ to add two complex numbers.
3. Overload operator* to multiply two complex numbers.
4. Overload operators << and >> to print and read Complex Numbers.*/


#include<iostream>
using namespace std;

class complex {
    private :
      int rl ;
      int img;
     

    public :
     void get_data(){
        cout<<"Enter real part of complex number "<<"\n";
        cin>>rl;
        cout<<"Enter imaginary part of complex number";
        cin>>img;
     }
     void display_data(){
        cout<<"The complex number is : "<<"\t"<<rl<<" + "<<img<<"i"<<"\n";
     }
     complex(){
        rl = 0;
        img = 0 ;
        
     }
     void add(complex x, complex y){
        rl = x.rl + y.rl;
        img = x.img + y.img ;
        cout<<"The complex number is : "<<"\t"<<rl<<" + "<<img<<"i"<<"\n";
     }
     void substract(complex x, complex y){
        rl = x.rl - y.rl;
        img = x.img - y.img ;
        cout<<"The complex number is : "<<"\t"<<rl<<" + "<<img<<"i"<<"\n";
     }
};


int main (){
    complex c1 , c2, c3;
    c1.display_data();
    c1.get_data();
    c2.get_data();
    c1.display_data();
    c2.display_data();
    c3.add(c1,c2);
    c3.substract(c1,c2);
}
