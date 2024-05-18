#include "../treeListPassword.h"

listPassword *delete_data_from_tree(listPassword *root, infotype nama) {
    // Base case
    if (root == NULL) {
        return root;
    }
    
    //If the key to be deleted is smaller than the root's key, then it lies in the left subtree
    if (nama < root -> nama) {  
        root -> left = delete_data_from_tree(root -> left, nama);
    }

    // If the key to be deleted is greater than the root's key, then it lies in the right subtree
 else if (nama > root -> nama) {
        root -> right = delete_data_from_tree(root -> right, nama);
        return root;
    }

    // If key is same as root's key, then this is the node to be deleted
    // Node with only one child or no child
    if (root -> left == NULL) {
        listPassword *temp = root -> right;
        delete root;
        return temp;
    }
    else if (root -> right == NULL) {
        listPassword *temp = root -> left;
        delete root;
        return temp;
    }

    // Node with two children: Get the inorder successor (smallest in the right subtree)
    listPassword *nextSibling = root;
    listPassword *child = root ->right;
    while (child -> left != NULL) {
        nextSibling = child;
        child = child -> left;
    }

    // Copy the inorder successor's content to this node
    root -> nama = child -> nama;

    // Delete the inorder successor
    if (nextSibling -> left == child) {
        nextSibling -> left = child -> right;
    }
    else {
        nextSibling -> right = child -> right;
    }
    
    delete child;
    return root;

}