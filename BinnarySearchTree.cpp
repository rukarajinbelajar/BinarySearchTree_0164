#include <iostream>
using namespace std;

class Node {

public:
    string info;
    Node* leftChild;
    Node* rightChild;

    Node(string i, Node* 1, Node* r) {
        info = i;
        leftChild = 1;
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
    }
}