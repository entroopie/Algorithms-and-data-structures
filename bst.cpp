#include <iostream>
using namespace std;

struct Node {
    unsigned int data;
    Node* left;
    Node* right;
};

Node* minimum(Node* root) {
    Node* tmp = root;
    while (tmp && tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

Node* maximum(Node* root) {
    Node* tmp = root;
    while (tmp && tmp->right != NULL) {
        tmp = tmp->right;
    }
    return tmp;
}

Node* insert(Node* root, unsigned int data) {
    if (root == NULL) {
        Node* tmp = new Node;
        tmp->data = data;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    else {
        Node* tmp;
        if (data <= root->data) {
            tmp = insert(root->left, data);
            root->left = tmp;
        }
        else {
            tmp = insert(root->right, data);
            root->right = tmp;
        }
        return root;
    }
}

Node* pop(Node* root, unsigned int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = pop(root->left, key);
    else if (key > root->data) root->right = pop(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* tmp = minimum(root->right);
        root->data = tmp->data;
        root->right = pop(root->right, tmp->data);
    }
    return root;
}

Node* search(Node* root, unsigned int key) {
    if (root == NULL) {
        cout << "0" << endl;
        return root;
    }
    if (root->data == key) {
        cout << "1" << endl;
        return root;
    }
    if (root->data < key) return search(root->right, key);
    else return search(root->left, key);
}

int main() {
    unsigned int data;
    Node* root = NULL;
    Node* tmp = NULL;
    char command;
    while (cin >> command) {
        switch (command) {
        case '+':
            cin >> data;
            root = insert(root, data);
            break;
        case '-':
            cin >> data;
            root = pop(root, data);
            break;
        case '?':
            cin >> data;
            search(root, data);
            break;
        case 'M':
            tmp = maximum(root);
            cout << tmp->data << endl;
            break;
        case 'm':
            tmp = minimum(root);
            cout << tmp->data << endl;
            break;
        case 'q':
            return 0;
            break;
        }
    }
    return 0;