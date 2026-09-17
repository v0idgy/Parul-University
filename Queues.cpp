#include <iostream>

using namespace std;

// -------------------------------------------------------------
// 1. ARRAY-BASED CIRCULAR QUEUE
// -------------------------------------------------------------
class ArrayQueue
{
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    ArrayQueue(int size = 5)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~ArrayQueue()
    {
        delete[] arr;
    }

    bool isFull() { return count == capacity; }
    bool isEmpty() { return count == 0; }

    // Enqueue: Add element to rear
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "[ArrayQueue] Overflow! Cannot enqueue " << val << "\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
        cout << "[ArrayQueue] Enqueued: " << val << "\n";
    }

    // Dequeue: Remove element from front
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "[ArrayQueue] Underflow! Queue is empty.\n";
            return;
        }
        cout << "[ArrayQueue] Dequeued: " << arr[front] << "\n";
        front = (front + 1) % capacity;
        count--;
    }

    // Traverse: Print all queue elements
    void traverse()
    {
        if (isEmpty())
        {
            cout << "[ArrayQueue] Queue is empty.\n";
            return;
        }
        cout << "[ArrayQueue] Elements: ";
        for (int i = 0; i < count; ++i)
        {
            int idx = (front + i) % capacity;
            cout << arr[idx] << " ";
        }
        cout << "\n";
    }

    // Search: Find 0-based position relative to front
    int search(int target)
    {
        for (int i = 0; i < count; ++i)
        {
            int idx = (front + i) % capacity;
            if (arr[idx] == target)
            {
                return i; // Found at relative position i from front
            }
        }
        return -1; // Not found
    }
};

// -------------------------------------------------------------
// 2. LINKED LIST-BASED QUEUE
// -------------------------------------------------------------
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue
{
private:
    Node *front;
    Node *rear;

public:
    LinkedListQueue() : front(nullptr), rear(nullptr) {}

    ~LinkedListQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() { return front == nullptr; }

    // Enqueue: Append node to rear
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "[ListQueue] Enqueued: " << val << "\n";
    }

    // Dequeue: Remove node from front
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "[ListQueue] Underflow! Queue is empty.\n";
            return;
        }
        Node *temp = front;
        cout << "[ListQueue] Dequeued: " << temp->data << "\n";
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }

    // Traverse: Print elements from front to rear
    void traverse()
    {
        if (isEmpty())
        {
            cout << "[ListQueue] Queue is empty.\n";
            return;
        }
        cout << "[ListQueue] Elements: ";
        Node *curr = front;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    // Search: Find 0-based position from front
    int search(int target)
    {
        Node *curr = front;
        int index = 0;
        while (curr != nullptr)
        {
            if (curr->data == target)
            {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }
};

int main()
{
    cout << "=== ARRAY-BASED CIRCULAR QUEUE ===\n";
    ArrayQueue aq(5);

    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);
    aq.traverse();

    int pos = aq.search(20);
    if (pos != -1)
        cout << "[ArrayQueue] Target 20 found at position " << pos << " from front.\n";
    else
        cout << "[ArrayQueue] Target 20 not found.\n";

    aq.dequeue();
    aq.traverse();

    cout << "\n=== LINKED LIST-BASED QUEUE ===\n";
    LinkedListQueue lq;

    lq.enqueue(100);
    lq.enqueue(200);
    lq.enqueue(300);
    lq.traverse();

    pos = lq.search(300);
    if (pos != -1)
        cout << "[ListQueue] Target 300 found at position " << pos << " from front.\n";
    else
        cout << "[ListQueue] Target 300 not found.\n";

    lq.dequeue();
    lq.traverse();

    return 0;
}