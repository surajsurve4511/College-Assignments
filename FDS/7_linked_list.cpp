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

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add President\n";
    cout << "2. Add Member\n";
    cout << "3. Add Secretary\n";
    cout << "4. Delete Member\n";
    cout << "5. Display Members\n";
    cout << "6. Display Members in Reverse\n";
    cout << "7. Count Members\n";
    cout << "8. Concatenate with Another Club\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    PinnacleClub divisionA;
    PinnacleClub divisionB;
    int choice;
    string prn, name;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();  // Ignore leftover newline character from previous input

        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                getline(cin, prn);
                cout << "Enter Name: ";
                getline(cin, name);
                divisionA.addPresident(prn, name);
                break;
            case 2:
                cout << "Enter PRN: ";
                getline(cin, prn);
                cout << "Enter Name: ";
                getline(cin, name);
                divisionA.addMember(prn, name);
                break;
            case 3:
                cout << "Enter PRN: ";
                getline(cin, prn);
                cout << "Enter Name: ";
                getline(cin, name);
                divisionA.addSecretary(prn, name);
                break;
            case 4:
                cout << "Enter PRN to delete: ";
                getline(cin, prn);
                divisionA.deleteMember(prn);
                break;
            case 5:
                cout << "Members of Division A:\n";
                divisionA.displayMembers();
                break;
            case 6:
                cout << "Members of Division A in Reverse:\n";
                divisionA.displayReverse();
                break;
            case 7:
                cout << "Total members in Division A: " << divisionA.countMembers() << endl;
                break;
            case 8:
                cout << "Concatenating with Division B:\n";
                divisionA.concatenate(divisionB);
                cout << "Division A Members after concatenation with Division B:\n";
                divisionA.displayMembers();
                break;
            case 9:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
