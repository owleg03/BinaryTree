//
//  main.cpp
//  BinaryTree
//
//  Created by Oleh Sivak on 23/05/2023.
//

#include <iostream>
#include <queue>

using std::queue, std::cout, std::endl;

struct Node {
    int value;
    Node* left;
    Node* right;
    
public:
    Node(int value) {
        this->value = value;
    }
};

class BinaryTree {
    Node* head;
    
    void invertFrom(Node* node) {
        // End of recursion
        if (!node) {
            return;
        }
        
        // Swap subtrees
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        // Recursion calls
        invertFrom(node->left);
        invertFrom(node->right);
    }
    
    void printDFS(Node* node) {
        // End of recursion
        if (!node) {
            return;
        }
        
        cout << node->value << ' ';
        
        // Recursive calls
        printDFS(node->left);
        printDFS(node->right);
    }
    
    void printBFS(queue<Node> queue) {
        // End of the recursion
        if (queue.empty()) {
            return;
        }
        
        Node current = queue.front();
        cout << current.value << ' ';
        queue.pop();
        
        // Add new nodes
        if (current.left) {
            queue.push(*current.left);
        }
        if (current.right) {
            queue.push(*current.right);
        }
        
        
        // Recursive call
        printBFS(queue);
    }
    
public:
    BinaryTree(Node* node) {
        this->head = node;
    }
    
    void addNode(Node* node) {
        Node* current = head;
        
        // Find the node's position
        Node* previous = nullptr;
        while (current != nullptr) {
            if (current->value > node->value) {
                previous = current;
                current = current->left;
            } else {
                previous = current;
                current = current->right;
            }
        }
        
        // Add the node
        if (previous->value > node->value) {
            previous->left = node;
        } else {
            previous->right = node;
        }
    }
    
    void invert() {
        invertFrom(head);
        cout << endl;
    }
    
    void print(bool isDFS = true) {
        if (isDFS) {
            printDFS(head);
        } else {
            queue<Node> queue;
            queue.push(*head);
            printBFS(queue);
        }
        
        cout << endl;
    }
};

int main(int argc, const char * argv[]) {
    // Create nodes
    Node* node1 = new Node(5);
    Node* node2 = new Node(3);
    Node* node3 = new Node(8);
    Node* node4 = new Node(1);
    Node* node5 = new Node(4);
    Node* node6 = new Node(-3);
    Node* node7 = new Node(2);
    
    // Create a binary tree
    BinaryTree binaryTree = BinaryTree(node1);
    
    // Add nodes
    binaryTree.addNode(node2);
    binaryTree.addNode(node3);
    binaryTree.addNode(node4);
    binaryTree.addNode(node5);
    binaryTree.addNode(node6);
    binaryTree.addNode(node7);
    
    // Print the binary tree
    cout << "DFS: ";
    binaryTree.print();
    cout << "BFS: ";
    binaryTree.print(false);
    
    // Invert the binary tree
    binaryTree.invert();
    
    // Print the binary tree
    cout << "BFS (after inversion): ";
    binaryTree.print(false);
    
    return 0;
}
