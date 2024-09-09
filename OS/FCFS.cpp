#include<iostream>
using namespace std;

class Process{
    public:
     int pid;
     int bt;
     int tat;
     int wt;

    void get_data(){
        cout<<"Enter PID : ";
        cin>>this->pid;
        cout<<"Enter Burst Time : ";
        cin>>this->bt;
        this->wt=0;
        this->tat=0;

    };
};

void Calculate(Process p[],int n){
    p[0].tat= p[0].bt;
    for(int i=1;i<n;i++){
        p[i].tat = p[i-1].tat + p[i].bt;
        p[i].wt = p[i].tat + p[i].bt;
    }
}
int main(){
    
    int n;
    cout<<"Enter the Number of Processes : ";
    cin>>n;

    Process p[n];
    for(int i=0;i<n;i++){
        p[i]=Process();
        p[i].get_data();
    }

    Calculate(p,n);

    cout<<"pid\t"<<"bt\t"<<"tat\t"<<"wt\t"<<endl;
    
    for(int i = 0;i<n;i++){
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    
    }
    
    return 0;
}

