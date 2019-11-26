/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
    long key;
    node* left;
    node* right;
    node* parent;
};

int level_finder(node* this_node) {
    node* current_node = this_node;
    long counter = 0;
    while (current_node->parent != NULL) {
        current_node = current_node->parent;
        counter++;
    }
    return counter;
}

int main() {
    int length; cin >> length;
    long root; cin >> root;
    node* root_node = new node;
    root_node->key = root;
    root_node->left = NULL;
    root_node->right = NULL;
    root_node->parent = NULL;
    node* lowest_node;
    lowest_node = root_node;
    long counter = 0;
    cout << 0 << endl;
    for (int i = 1; i < length; i++) {
        long input; cin >> input;
        node* current_node = lowest_node;
        bool success = false;
        while (!success) {
            while (current_node->parent != NULL && (current_node->key < current_node->parent->key && input > current_node->key && input > current_node->parent->key)) {
                current_node = current_node->parent;
            }

            if (current_node->right == NULL && input > current_node->key) {
                node* new_node = new node;
                new_node->key = input;
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->parent = current_node;
                current_node->right = new_node;
                success = true;
                counter += level_finder(new_node);
            }
            else if (current_node->right != NULL && input > current_node->key) {
                current_node = current_node->right;
                while (current_node->left != NULL) {
                    current_node = current_node->left;
                }
            }
            else if (input < current_node->key) {
                node* new_node = new node;
                new_node->key = input;
                new_node->left = NULL;
                new_node->right = NULL;
                new_node->parent = current_node;
                current_node->left = new_node;
                success = true;
                counter += level_finder(new_node);
            }
        }
        lowest_node = root_node;
        while (lowest_node->left != NULL) {
            lowest_node = lowest_node->left;
        }
        //cout << lowest_node->key << endl;
        cout << counter << endl;
    }
}

