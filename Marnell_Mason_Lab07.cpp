//Mason Marnell - Data Structure Lab #7

//This program takes the pre-provided example tree and mirrors it along the y axis using
//post order traversal and swapping the left and right nodes.


#include <iostream>

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

void postOrderSwitch(node* nodeIn) { //changed return type to void
    if (nodeIn == NULL) {
        return;
    }

    node* temp2 = new node;

    postOrderSwitch(nodeIn->left);
    postOrderSwitch(nodeIn->right);
    temp2 = nodeIn->left;
    nodeIn->left = nodeIn->right;
    nodeIn->right = temp2;

}

void postOrder(node* nodeIn) {
    if (nodeIn == NULL) {
        return;
    }

    postOrder(nodeIn->left);
    postOrder(nodeIn->right);
    cout << nodeIn->val << " ";

}

void lab7() {
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7); // create the example tree that is given

    cout << "Original post-order traversal output: " << endl;
    postOrder(root);

    postOrderSwitch(root);
   
    cout << endl << endl << "Mirrored Tree post-order traversal output: " << endl;
    postOrder(root);

}

int main() {

    lab7();

    return 0;
}