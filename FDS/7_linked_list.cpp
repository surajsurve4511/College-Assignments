#include <iostream>
#include <string>

using namespace std;

// Define a struct for the node of the linked list
struct Node {
    string prn;
    string name;
    Node* next;
};

// Class to manage the linked list
class PinnacleClub {
private:
    Node* head;
    Node* tail;

    // Helper function to delete the entire list
    void deleteList(Node*& node) {
        if (node == nullptr) return;
        deleteList(node->next);
        delete node;
        node = nullptr;
    }

    // Recursive function to display list in reverse order
    void displayReverse(Node* node) const {
        if (node == nullptr) return;
        displayReverse(node->next);
        cout << "PRN: " << node->prn << ", Name: " << node->name << endl;
    }

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    ~PinnacleClub() {
        deleteList(head);
    }

    // Add a new member
    void addMember(const string& prn, const string& name) {
        Node* newNode = new Node{prn, name, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Add a president (at the beginning of the list)
    void addPresident(const string& prn, const string& name) {
        Node* newNode = new Node{prn, name, head};
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Add a secretary (at the end of the list)
    void addSecretary(const string& prn, const string& name) {
        Node* newNode = new Node{prn, name, nullptr};
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a member by PRN
    void deleteMember(const string& prn) {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->prn != prn) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) return; // PRN not found

        if (prev == nullptr) {
            head = current->next;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            prev->next = current->next;
            if (current->next == nullptr) {
                tail = prev;
            }
        }
        delete current;
    }

    // Compute total number of members
    int countMembers() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Display all members
    void displayMembers() const {
        Node* current = head;
        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    // Display list in reverse order
    void displayReverse() const {
        displayReverse(head);
    }

    // Concatenate two linked lists
    void concatenate(PinnacleClub& other) {
        if (tail != nullptr) {
            tail->next = other.head;
            if (other.tail != nullptr) {
                tail = other.tail;
            }
        } else {
            head = other.head;
            tail = other.tail;
        }
        other.head = nullptr;
        other.tail = nullptr;
    }
};

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;
    int choice;
    string prn, name;

    do {
        cout << "\nPinnacle Club Menu\n";
        cout << "1. Add President to Division A\n";
        cout << "2. Add Member to Division A\n";
        cout << "3. Add Secretary to Division A\n";
        cout << "4. Display Members of Division A\n";
        cout << "5. Display Members of Division A in Reverse Order\n";
        cout << "6. Delete Member from Division A\n";
        cout << "7. Add President to Division B\n";
        cout << "8. Add Member to Division B\n";
        cout << "9. Add Secretary to Division B\n";
        cout << "10. Display Members of Division B\n";
        cout << "11. Display Members of Division B in Reverse Order\n";
        cout << "12. Concatenate Division B to Division A\n";
        cout << "13. Display Total Members in Division A\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore any leftover newline character in the input buffer

        switch (choice) {
            case 1:
                cout << "Enter PRN for President: ";
                getline(cin, prn);
                cout << "Enter Name for President: ";
                getline(cin, name);
                divisionA.addPresident(prn, name);
                break;
            case 2:
                cout << "Enter PRN for Member: ";
                getline(cin, prn);
                cout << "Enter Name for Member: ";
                getline(cin, name);
                divisionA.addMember(prn, name);
                break;
            case 3:
                cout << "Enter PRN for Secretary: ";
                getline(cin, prn);
                cout << "Enter Name for Secretary: ";
                getline(cin, name);
                divisionA.addSecretary(prn, name);
                break;
            case 4:
                cout << "Members of Division A:\n";
                divisionA.displayMembers();
                break;
            case 5:
                cout << "Members of Division A in Reverse Order:\n";
                divisionA.displayReverse();
                break;
            case 6:
                cout << "Enter PRN to delete from Division A: ";
                getline(cin, prn);
                divisionA.deleteMember(prn);
                break;
            case 7:
                cout << "Enter PRN for President in Division B: ";
                getline(cin, prn);
                cout << "Enter Name for President in Division B: ";
                getline(cin, name);
                divisionB.addPresident(prn, name);
                break;
            case 8:
                cout << "Enter PRN for Member in Division B: ";
                getline(cin, prn);
                cout << "Enter Name for Member in Division B: ";
                getline(cin, name);
                divisionB.addMember(prn, name);
                break;
            case 9:
                cout << "Enter PRN for Secretary in Division B: ";
                getline(cin, prn);
                cout << "Enter Name for Secretary in Division B: ";
                getline(cin, name);
                divisionB
