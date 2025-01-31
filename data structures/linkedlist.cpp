#include <iostream>
#include <string>
#include <vector>  
#include <array> 
#include <list>  
#include <map>  
#include <unordered_map>  
#include <algorithm>  
#include <cmath>  

using namespace std;

struct Node {
    int data;          // Data of the node
    Node* next;        // Pointer to the next node

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);  // Create a new node
    newNode->next = head;           // New node points to the current head
    head = newNode;                 // Update head to new node
}
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {           // If list is empty
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;            // Link last node to new node
}
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) return;   // List is empty
    Node* temp = head;
    head = head->next;             // Update head to next node
    delete temp;                   // Free memory
}

void deleteAtEnd(Node*& head) {
    if (head == nullptr) return;   // List is empty
    if (head->next == nullptr) {   // Single node case
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {  // Traverse to second last node
        temp = temp->next;
    }
    delete temp->next;             // Free last node
    temp->next = nullptr;
}
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;  // Key found
        temp = temp->next;
    }
    return false;                            // Key not found
}
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;   // Store next
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move pointers one position ahead
        curr = next;
    }
    head = prev;
}
void insertBeforeValue(Node*& head, int val, int beforeVal) {
    Node* newNode = new Node(val);   // Create a new node
    
    // Case 1: List is empty
    if (head == nullptr) {
        std::cout << "List is empty. Value " << beforeVal << " not found." << std::endl;
        delete newNode;
        return;
    }
    
    // Case 2: Inserting before the first node (head)
    if (head->data == beforeVal) {
        newNode->next = head;        // New node points to current head
        head = newNode;              // Update head to new node
        return;
    }

    // Case 3: Traverse to find the node before 'beforeVal'
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != beforeVal) {
        temp = temp->next;
    }

    // Case 4: If 'beforeVal' is not found in the list
    if (temp->next == nullptr) {
        std::cout << "Value " << beforeVal << " not found in the list." << std::endl;
        delete newNode;
        return;
    }

    // Insert the new node before 'beforeVal'
    newNode->next = temp->next;   // New node points to node with 'beforeVal'
    temp->next = newNode;         // Previous node points to new node
}

int main() {
    Node* head = nullptr;  // Create an empty list

    // Insert elements
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);

    // Display list
    display(head);

    // Delete elements
    deleteAtBeginning(head);
    deleteAtEnd(head);

    // Search for an element
    std::cout << (search(head, 30) ? "Found" : "Not Found") << std::endl;

    // Reverse and display list
    reverse(head);
    display(head);

    return 0;
}
