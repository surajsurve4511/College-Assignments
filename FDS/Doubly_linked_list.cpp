#include<iostream>

using namespace std;

struct node{
	int digit;
	node *next;
	node *prev;
	
	node(){
		next=prev=NULL;
	}
};

class dtb{
	node *head;
	node *tail;
public:
	dtb(){
		head = NULL;
	}
	
	void create_linked_list(int num){
		
		while(num>0){
			int rem = num%2;
			node* new_node = new node;
			new_node->digit=rem;
			num=num/2;
			
			if(head==NULL){
				head = new_node;
				tail = head;
			}
			else{
				new_node->next=head;
				head->prev=new_node;
				head=new_node;
			}
			
		}
		
	}
	
	void display(){
		node* temp = head;
		
		while(temp!=NULL){
			cout<<temp->digit;
			temp=temp->next;
		}
	}
	
	void ones_compliment(){
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
	
	int len(){
		int i=0;
		node* temp= head;
		
		while(temp!=NULL){
			i++;
			temp=temp->next;
		}
		return i;
	}
	
	dtb operator+(dtb a){
		
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
				new_node->next = head;
				head->prev=new_node;
				head=new_node;
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
		
		
		
		
		return c;
	}
	
};

int main(){
	int num;
	dtb dtb_number = dtb();
	
	cout<<"Enter the number : ";
	cin>>num;
	dtb_number.create_linked_list(num);
	
	cout<<"dtbary of "<<num<<" is : ";
	dtb_number.display();
	
	cout<<endl<<"Ones Compliment : ";
	
	
	dtb_number.ones_compliment();
	dtb_number.display();
	
	dtb e =dtb();
	dtb f =dtb();
	
	dtb g = e+f;
	
	return 0;
}
