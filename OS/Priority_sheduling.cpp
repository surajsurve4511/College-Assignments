#include <iostream>

using namespace std;

class Process{
    public:
        int pid;
        int bt;
        int tat;
        int wt;
        int priority;
    
    void getData(){
    cout<<"Enter Pid : ";
    cin>>this->pid;
    cout<<"Enter Burst time";
    cin>>this->bt;
    cout<<"Enter priority: ";
    cin>>this->priority;
    this->wt=0;
    this->tat=0;
}


    
};

void Calculate (Process p[],int n){
    p[0].tat = p[0].bt;
    for(int i=1;i<n;i++){
        p[i].tat = p[i-1].tat+p[i].bt;
        p[i].wt = p[i].tat - p[i].bt;
    }
    
}

void sort(Process p[],int n){
    
    Process temp[n];
    
    for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
        if(p[j].priority < p[i].priority) {
            // Swap p[i] and p[j]
            Process temp = p[j];
            p[j] = p[i];
            p[i] = temp;
        }
    }
}

    

}

int main(){
    

    
    int n;
    cout<<"Enter the Number of Processes : ";
    cin>>n;
    
    Process p[n];
    for(int i=0;i<n;i++){
        p[i]=Process();
        p[i].getData();
    }
    sort(p,n);
    Calculate(p,n);
    
    cout<<"pid\t"<<"bt\t"<<"tat\t"<<"wt\t"<<"priority\t"<<endl;
    
    for(int i = 0;i<n;i++){
        cout<<p[i].pid<<"\t"<<p[i].bt<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].priority<<endl;
    
    }

    int tsum=0;
    int wtsum=0;

    for(int i=0;i<n;i++){
        tsum = tsum+p[i].tat;
        wtsum = wtsum+p[i].wt;
    }

    cout<<"Total turn around time : "<<tsum<<endl;
    cout<<"Total waiting time : "<<wtsum<<endl;

    return 0;
}
