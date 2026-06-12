#include <iostream>
using namespace std;

class Node {

public:
    string info;
    Node* leftChild;
    Node* rightChild;

    Node(string i, Node* l, Node* r) {
        info = i;
        leftChild = l;
        rightChild = r;
    }
};

class BinaryTree{

public:
    Node* ROOT;

    BinaryTree() {
        ROOT = nullptr;
    }

    void insert(string element) {

        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;
        newNode->leftChild = nullptr;
        newNode->rightChild = nullptr;

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode);

        if (parent == nullptr) {
            ROOT = newNode;
            return;
        }

        if (element < parent->info)
        {
            parent->leftChild = newNode;
        }
        else if (element > parent->info)
        {
            parent->rightChild = newNode;
        }
    }

    void search(string element, Node*& parent, Node*& currentNode) {
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {

            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftChild;
            else
                currentNode = currentNode->rightChild;
        }
    }

    void inorder(Node* ptr) {

        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }
        if (ptr != nullptr){
            inorder(ptr->leftChild);
            cout << ptr->info << " ";
            inorder(ptr->rightChild);
        }
    }

    void preorder(Node* ptr) {

        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;

        }
        if (ptr !=nullptr) {
                cout << ptr->info << " ";
                preorder(ptr->leftChild);
                preorder(ptr->rightChild);
        }
    }

    void postorder(Node* ptr){
        if (ROOT == nullptr) {
            cout << "Tree is empty" << endl;
            return;

        }
        if (ptr !=nullptr) {
            postorder(ptr->leftChild);
            postorder(ptr->rightChild);
            cout << ptr->info << " ";
        }
    }
};

int main()
{
    BinaryTree x;

    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perfotm Postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nenter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1': {
            cout << "Enter a word : ";
            string word;
            cin >> word;
            x.insert(word);
            break;
        }
        case '2': {
            x.inorder(x.ROOT);
            break;
        }
        case '3': {
            x.preorder(x.ROOT);
            break;
        }
        case '4': {
            x.postorder(x.ROOT);
            break;
        }
        case '5': {
            return 0;
        }
        default: {
            cout << "Invalid Option" << endl;
            break;
        }
        }
    }
}