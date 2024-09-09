
#include <iostream>
using namespace std;

class Process {
public:
    int pid;
    int bt;
    int tat;
    int wt;
    int priority;
    Process *next;
    
    Process() : pid(0), bt(0), tat(0), wt(0), priority(0), next(nullptr) {}

    void getData() {
        cout << "Enter Pid : ";
        cin >> this->pid;
        cout << "Enter Burst time: ";
        cin >> this->bt;
        cout << "Enter priority: ";
        cin >> this->priority;
        this->wt = 0;
        this->tat = 0;
    }

    void show_data() const {
        cout << pid << "\t" << bt << "\t" << tat << "\t" << wt << endl;
    }
};

int main() {
    int n;
    cout << "Enter the Number of Processes : ";
    cin >> n;

    Process *head = nullptr;
    Process *tail = nullptr;

    // Create the linked list of processes
    for (int i = 0; i < n; i++) {
        Process *newProcess = new Process();
        newProcess->getData();
        
        if (head == nullptr) {
            // First process
            head = newProcess;
            tail = newProcess;
        } else {
            // Add to the end of the list
            tail->next = newProcess;
            tail = newProcess;
        }
    }
        
    // Display the process data
    Process *temp = head;
    cout << "pid\t" << "bt\t" << "tat\t" << "wt\t" << endl;
    while (temp != nullptr) {
        temp->show_data();
        temp = temp->next;
    }

    // Free allocated memory
    temp = head;
    while (temp != nullptr) {
        Process *next = temp->next;
        delete temp;
        temp = next;
    }
    
    return 0;
}
