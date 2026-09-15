#include <iostream>
using namespace std;
// Class representing a single node in the linked list
class Node {
public:
    int data;       // Stores the value of the element
    Node* next;     // Pointer to the next node in the sequence
    // Constructor to initialize the node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Class managing the overall linked list structure
class LinkedList {
private:
    Node* head;     // Pointer to the first node of the list
public:
    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }
    // Destructor to free dynamically allocated memory (prevents leaks)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    // 1. Insert a node at the beginning (Head) of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert a node at the end (Tail) of the list
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // 3. Delete a node by its value
    void deleteValue(int value) {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        // If the head node itself holds the value to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Traverse to find the node to delete
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        // Value was not found in the list
        if (current == nullptr) {
            std::cout << "Value " << value << " not found in the list." << std::endl;
            return;
        }

        // Unlink the node from the linked list and free memory
        prev->next = current->next;
        delete current;
    }

    // 4. Print/Traverse the list
    void display() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;

    // Test Insertions
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtHead(5);
    list.insertAtTail(30);

    std::cout << "Created Linked List: ";
    list.display(); // Expected Output: 5 -> 10 -> 20 -> 30 -> NULL

    // Test Deletion
    std::cout << "Deleting 20..." << std::endl;
    list.deleteValue(20);

    std::cout << "Updated Linked List: ";
    list.display(); // Expected Output: 5 -> 10 -> 30 -> NULL
    return 0;
}
