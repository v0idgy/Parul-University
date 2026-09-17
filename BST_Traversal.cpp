#include <iostream>
#include <stack>
using namespace std;

// Node structure for the Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to insert a value into the BST
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

// -------------------------------------------------------------
// RECURSIVE TRAVERSALS
// -------------------------------------------------------------

// 1. Preorder Traversal (Root -> Left -> Right)
void preorderRecursive(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// 2. Inorder Traversal (Left -> Root -> Right) - Yields sorted order for BST
void inorderRecursive(Node *root)
{
    if (root == nullptr)
        return;
    inorderRecursive(root->left);
    cout << root->data << " ";
    inorderRecursive(root->right);
}

// 3. Postorder Traversal (Left -> Right -> Root)
void postorderRecursive(Node *root)
{
    if (root == nullptr)
        return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

// -------------------------------------------------------------
// ITERATIVE TRAVERSALS
// -------------------------------------------------------------

// 1. Iterative Preorder Traversal
void preorderIterative(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Push right first so left is processed first (LIFO order)
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}

// 2. Iterative Inorder Traversal
void inorderIterative(Node *root)
{
    stack<Node *> st;
    Node *curr = root;

    while (curr != nullptr || !st.empty())
    {
        // Reach the leftmost node of the current node
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        // Backtrack from stack
        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        // Visit right subtree
        curr = curr->right;
    }
}

// 3. Iterative Postorder Traversal (Using Two Stacks)
void postorderIterative(Node *root)
{
    if (root == nullptr)
        return;

    stack<Node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    // Output stored nodes in reverse order
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Helper function to free allocated tree memory
void destroyTree(Node *root)
{
    if (root == nullptr)
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main()
{
    /* Constructed BST:
            50
           /  \
          30   70
         /  \  / \
        20  40 60 80
    */
    Node *root = nullptr;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};

    for (int key : keys)
    {
        root = insert(root, key);
    }

    cout << "--- RECURSIVE TRAVERSALS ---\n";
    cout << "Preorder  (Root, L, R): ";
    preorderRecursive(root);
    cout << "\n";
    cout << "Inorder   (L, Root, R): ";
    inorderRecursive(root);
    cout << "\n";
    cout << "Postorder (L, R, Root): ";
    postorderRecursive(root);
    cout << "\n\n";

    cout << "--- ITERATIVE TRAVERSALS ---\n";
    cout << "Preorder  (Iterative):  ";
    preorderIterative(root);
    cout << "\n";
    cout << "Inorder   (Iterative):  ";
    inorderIterative(root);
    cout << "\n";
    cout << "Postorder (Iterative):  ";
    postorderIterative(root);
    cout << "\n";

    destroyTree(root);
    return 0;
}