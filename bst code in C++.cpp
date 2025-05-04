#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *findMin(Node *root)
{
    while (root->left)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

bool findNode(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
    {
        return true;
    }

    if (root->data < key)
        return findNode(root->right, key);

    return findNode(root->left, key);
}

void printPostOrder(Node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);

        cout << root->data << " ";
    }
}

void printPreOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(Node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

void deleteTree(Node *root)
{
    if (root != nullptr)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int getHeight(Node *root)
{
    if (root == nullptr)
        return -1;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node *root = nullptr;

    while (true)
    {
        cout<<endl;

        cout<<"==========BST=========="<<endl;
        cout<<endl;
        cout << "Select an option: " << endl;
        cout << "1. Insert Node(s)" << endl;
        cout << "2. Delete a Node" << endl;
        cout << "3. Search a Node" << endl;
        cout << "4. Show current Tree Traversals " << endl;
        cout << "5. Show height of this tree " <<endl;
        cout << "6. Exit" << endl;
        cout<<endl;


        int choice;
        cin >> choice;

        if (choice == 1)
        {

            cout << "How many nodes you want to insert?" << endl;
            int nodes;
            cin >> nodes;

            if (nodes == 1)
            {
                cout << "Enter the Node value: " << endl;
            }
            else
            {
                cout << "Enter Node values: " << endl;
            }

            for (int i = 0; i < nodes; i++)
            {
                int value;
                cin >> value;

                root = insert(root, value);
            }

            cout << nodes << " node(s) has been inserted." << endl;
            cout<<endl;
        }
        else if (choice == 2)
        {

            if (root == nullptr)
            {
                cout << "Tree is empty. Cannot delete." << endl;
            }
            else
            {
                cout << "Enter the node you want to delete: " << endl;
                int node;
                cin >> node;

                if(findNode(root,node)){
                    root = deleteNode(root, node);
                     cout << node << " has been deleted." << endl;
                }else{
                    cout<<"This node doesn't exist in this tree"<<endl;
                }
            }
            cout<<endl;
        }
        else if (choice == 3)
        {

            cout << "Enter the node you want to search: " << endl;

            int key;
            cin >> key;

            if (findNode(root, key))
            {
                cout << key << " exists in this tree." << endl;
            }
            else
            {
                cout << key << " doesn't exist in this tree." << endl;
            }
            cout<<endl;
        }
        else if (choice == 4)
        {


            if (root != nullptr)
            {

                cout << "Pre-order traversal: ";
                printPreOrder(root);
                cout << endl;

                cout << "In-order traversal: ";
                printInOrder(root);
                cout << endl;

                cout << "Post-order traversal: ";
                printPostOrder(root);
                cout << endl;
            }
            else
            {
                cout << "Empty tree.\n" << endl;
            }

            cout<<endl;
        }else if(choice == 5){
            int height=getHeight(root);

            if(height<0){
                cout<<"Empty tree"<<endl;
            }else{
                cout<<"Height of this tree: "<<height<<endl;
            }

            cout<<endl;
        }
        else if (choice == 6)
        {
            deleteTree(root);
            cout << "Exiting..." << endl;
            break;

        }else{
            cout<<"Wrong number selected. "<<endl;
            cout<<endl;
        }

    }

    return 0;
}

