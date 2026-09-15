#include <iostream>
using namespace std;
// Class representing a single node in the list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // Constructor to initialize a node
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
// Class managing the Doubly Linked List operations
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
public:
    // Constructor initializes an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    // Destructor to free dynamically allocated memory
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }
    // Insert a new node at the front (beginning) of the list
    void insertFront(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // Insert a new node at the end of the list
    void insertEnd(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    // Delete the first node of the list
    void deleteFront()
    {
        if (head == nullptr)
        {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr; // List became empty
        }
        delete temp;
    }

    // Delete the last node of the list
    void deleteEnd()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr; // List became empty
        }
        delete temp;
    }

    // Display list elements from head to tail
    void displayForward() const
    {
        Node *temp = head;
        std::cout << "Forward List: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Display list elements from tail to head
    void displayBackward() const
    {
        Node *temp = tail;
        std::cout << "Backward List: ";
        while (temp != nullptr)
        {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "NULL\n";
    }
};

// Main function to test the implementation
int main()
{
    DoublyLinkedList dll;

    // Test Insertions
    dll.insertEnd(10);
    dll.insertEnd(20);
    dll.insertFront(5);
    dll.insertEnd(30);

    // Expected order: 5 <-> 10 <-> 20 <-> 30
    dll.displayForward();
    dll.displayBackward();

    // Test Deletions
    std::cout << "\nDeleting from front and end...\n";
    dll.deleteFront(); // Removes 5
    dll.deleteEnd();   // Removes 30

    // Expected order: 10 <-> 20
    dll.displayForward();

    return 0;
}
