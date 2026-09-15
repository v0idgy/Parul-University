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
        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
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
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
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
        if (tail == head)
        {
            delete head;
            tail = nullptr;
        }
        else
        {
            tail->next = head->next;
            delete head;
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

        if (tail == head)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            Node *curr = head;
            while (curr->next != tail)
            {
                curr = curr->next;
            }
            curr->next = tail->next;
            delete tail;
            tail = curr;
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

        Node *curr = tail->next;
        std::cout << "Circular Linked List: ";
        do
        {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);
        std::cout << "(back to start)\n";
    }
};

int main()
{
    CircularLinkedList cll;

    // 1. Insert 10 elements (values 10, 20, ..., 100)
    std::cout << "--- Inserting 10 Elements ---\n";
    for (int i = 1; i <= 10; ++i)
    {
        cll.insertAtEnd(i * 10);
    }
    cll.display();

    // 2. Remove 2 elements from the beginning
    std::cout << "\n--- Deleting 2 Elements from Beginning ---\n";
    cll.deleteFromBeginning();
    cll.deleteFromBeginning();
    cll.display();

    // 3. Remove 2 elements from the end
    std::cout << "\n--- Deleting 2 Elements from End ---\n";
    cll.deleteFromEnd();
    cll.deleteFromEnd();
    cll.display();

    return 0;
}