#include<iostream>

using namespace std;

struct node{                    //defining a structure data variables for pointers
	int digit;
	node *next;                 //pointer for forward traversing 
	node *prev;                 // pointer for forward traversing
	
	node(){
		next=prev=NULL;         //setting both pointer to null
	}
};

class dtb{                      //class containing data members and member functions for 
	node *head;                 //head pointer       
	node *tail;                 //tail pointer
public:
	dtb(){
		head = NULL;           //setting head pointer to NULL initially
        tail =NULL;
    }
	
	void create_linked_list(int num) {
        if (num == 0) {
            head = new node();
            head->digit = 0;
            tail = head;
            return;
        }

        while (num > 0) {
            int rem = num % 2;
            node* new_node = new node();
            new_node->digit = rem;
            if (head == nullptr) {
                head = new_node;
                tail = new_node;
            } else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            num = num / 2;
        }
    }
	
	void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->digit;
            temp = temp->next;
        }
    }
	
	void ones_compliment(){                //calculates one's compliment
		if(head==NULL){
			cout<<"First Create dtbary number! ";
		}
		else{
			node* temp =head;
			while(temp!=NULL){
				temp->digit=temp->digit>0?0:1;
				temp=temp->next;
			}
		}
	}
	
	int len(){                             //calculates lenght of the list
		int i=0;
		node* temp= head;
		
		while(temp!=NULL){
			i++;
			temp=temp->next;
		}
		return i;
	}
	
	dtb operator+(dtb a){                 //adding binary numbers using operator overloading
		
		dtb c = dtb();
		
		int carry = 0;
		
		node* temp1 = this->tail;
		node* temp2 = a.tail;
		
		while(temp1!=NULL && temp2!=NULL){
			int temp;
			temp = temp1->digit + temp2->digit+carry;
			node* new_node = new node;
			new_node->digit = 0;
			if(c.head==NULL){
				c.head=new_node;
			}
			else{
				new_node->next = c.head;
				c.head->prev=new_node;
				c.head=new_node;
			}
			
			switch(temp){
			case 0:
				new_node->digit=0;
				carry = 0;
				break;
				
			case 1:
				new_node->digit=1;
				carry = 0;
				break;
				
			case 2:
				new_node->digit=0;
			    carry = 1;
				break;
				
			case 3:
				new_node->digit=1;
				carry = 1;
				break;
			}
			
			temp1=temp1->prev;
			temp2=temp2->prev;
         
		}

        while(temp1!=NULL){
            cout<<"Dusra error"<<endl;
			int temp;
			temp = temp1->digit + carry;
			node* new_node = new node;
			new_node->digit = 0;


			if(c.head==NULL){
				c.head=new_node;
			}
			else{
				new_node->next = c.head;
				c.head->prev=new_node;
				c.head=new_node;
			}
			
			switch(temp){
			case 0:
				new_node->digit=0;
				carry = 0;
				break;
				
			case 1:
				new_node->digit=1;
				carry = 0;
				break;
				
			case 2:
				new_node->digit=0;
			    carry = 1;
				break;
				
			case 3:
				new_node->digit=1;
				carry = 1;
				break;
			}
			
			temp1=temp1->prev;
		}
      
        while(temp2!=NULL){
            cout<<"Tisra error"<<endl;
			int temp;
			temp = temp2->digit + carry;
			node* new_node = new node;
			new_node->digit = 0;

     		if(c.head==NULL){
				c.head=new_node;
			}
			else{
				new_node->next = c.head;
				c.head->prev=new_node;
				c.head=new_node;
			}
			
			switch(temp){
			case 0:
				new_node->digit=0;
				carry = 0;
				break;
				
			case 1:
				new_node->digit=1;
				carry = 0;
				break;
				
			case 2:
				new_node->digit=0;
			    carry = 1;
				break;
				
			case 3:
				new_node->digit=1;
				carry = 1;
				break;
			}

			temp2=temp2->prev;
		}
		
        if(carry>0){

			node* new_node = new node;
			new_node->digit = 1;
            if(c.head==NULL){
				c.head=new_node;
			}
			else{
				new_node->next = c.head;
				c.head->prev=new_node;
				c.head=new_node;
			}
        }
        return c;
	}
	
};

int main(){
	int num;
	dtb dtb_number;
	
	cout<<"Enter number :";
	cin>>num;
	dtb_number.create_linked_list(num);
	
	cout<<"Binary form of "<<num<<" is : ";
	dtb_number.display();
	
	cout<<endl<<"Ones Compliment : ";
	
	
	dtb_number.ones_compliment();
	dtb_number.display();
	
	// Test binary addition
    dtb e, f;
    int num1,num2;
    cout<<"\n"<<"Enter number :";
	cin>>num1;
    cout<<"\n""Enter number :";
	cin>>num2;
    e.create_linked_list(num1); 
    f.create_linked_list(num2); 

    dtb g = e + f;

    cout << "Sum of ";
    e.display();
    cout << " + ";
    f.display();
    cout << " = ";
    g.display();
    cout << endl;
	
	return 0;
}
