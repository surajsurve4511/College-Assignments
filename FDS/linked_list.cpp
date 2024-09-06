#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete the linked list and free memory
void deleteList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    int n;

    cout << "Linked List Tutorial" << endl;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of nodes must be positive." << endl;
        return 1; // Exit with an error code
    }

    Node* head = nullptr;
    Node* temp = nullptr;
    
    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;

        Node* newNode = new Node; // Allocate memory for a new node
        newNode->data = value;    // Set the data for the new node
        newNode->next = nullptr;  // Initialize the next pointer to null

        if (head == nullptr) {
            head = newNode; // The first node becomes the head
            temp = head;    // Temp points to the head node
        } else {
            temp->next = newNode; // Link the new node to the end of the list
            temp = newNode;       // Move temp to the new node
        }
    }

    // Print the linked list
    cout << "Linked list: ";
    printList(head);

    // Clean up memory
    deleteList(head);

    return 0;
}
