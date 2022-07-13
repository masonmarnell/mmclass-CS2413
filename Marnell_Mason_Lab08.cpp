//Mason Marnell - Data Structure Lab #8

// To check if the tree is a binary tree, I just check if any node in the tree is empty (or NULL) since
// regular trees cannot have empty nodes.

// To check whether or not tree is balanced I recursively compare heights

#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* newNode(int data) {
    node* temp = new node;
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//gets max of two values
int maxVal(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int height(node* node) {
    if (node == NULL)
        return 0;

    //returns height of tree/subtree
    return 1 + maxVal(height(node->left), height(node->right));
}

bool isTreeBalanced(node* root){

    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (isTreeBalanced(root->left) && isTreeBalanced(root->right) && abs(leftHeight - rightHeight) <= 1) {
        return 1;
    }

    //0 returned means tree is not balanced
    return 0;
}

int isBinaryTree = 0;

void postOrder(node* nodeIn) {
    if (nodeIn == NULL) {
        isBinaryTree = 1; // added this to determine if the tree is a binary tree
        return;
    }

    postOrder(nodeIn->left);
    postOrder(nodeIn->right);
    cout << nodeIn->val << " ";
}

void lab8() {
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3); // create the example tree that is given

    cout << "Post order traversal of the tree: " << endl;
    postOrder(root);

    if (isBinaryTree == 1) {
        cout << endl << "This tree is a binary tree." << endl;
    }
    else {
        cout << "This tree is not a binary tree." << endl;
    }

    if (isTreeBalanced(root) == 1) {
        cout << "Tree is balanced" << endl;
    }
    else {
        cout << "Tree is not balanced" << endl;
    }

}

int main() {

    lab8();

    return 0;
}