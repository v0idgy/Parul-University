#include <iostream>
using namespace std;
// Definition of a Node
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Circular Linked List Class
class CircularLinkedList
{
private:
    Node *tail; // Tracks the last node of the list

public:
    CircularLinkedList()
    {
        tail = nullptr;
    }

    // 1. Insert a node at the beginning
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);

        // If the list is empty
        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail; // Points to itself
        }
        else
        {
            newNode->next = tail->next; // New node points to the current head
            tail->next = newNode;       // Tail points to the new head
        }
        std::cout << val << " inserted at the beginning.\n";
    }

    // 2. Insert a node at the end
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next; // New node points to head
            tail->next = newNode;       // Old tail points to new node
            tail = newNode;             // Update tail to be the new node
        }
        std::cout << val << " inserted at the end.\n";
    }

    // 3. Delete the first node
    void deleteFromBeginning()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node *head = tail->next;

        // Case where there is only one node in the list
        if (tail == head)
        {
            delete head;
            tail = nullptr;
        }
        else
        {
            tail->next = head->next; // Bypass the old head
            delete head;             // Free memory
        }
        std::cout << "Deleted node from the beginning.\n";
    }

    // 4. Delete the last node
    void deleteFromEnd()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node *head = tail->next;

        // Case where there is only one node in the list
        if (tail == head)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            Node *curr = head;
            // Traverse to find the second-to-last node
            while (curr->next != tail)
            {
                curr = curr->next;
            }
            curr->next = tail->next; // Second-to-last node points to head
            delete tail;             // Free old tail memory
            tail = curr;             // Update tail pointer
        }
        std::cout << "Deleted node from the end.\n";
    }

    // 5. Traverse and display the list
    void display()
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty.\n";
            return;
        }

        Node *curr = tail->next; // Start from the head node
        std::cout << "Circular Linked List: ";
        do
        {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next); // Stop when we loop back to head
        std::cout << "(back to start)\n";
    }
};

int main()
{
    CircularLinkedList cll;

    // Perform Insertion Operations
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.insertAtEnd(30);
    cll.display(); // Output: 5 -> 10 -> 20 -> 30 -> (back to start)

    // Perform Deletion Operations
    cll.deleteFromBeginning();
    cll.display(); // Output: 10 -> 20 -> 30 -> (back to start)

    cll.deleteFromEnd();
    cll.display(); // Output: 10 -> 20 -> (back to start)

    return 0;
}
