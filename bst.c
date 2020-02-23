/*
 *Author: Elisha Ishaal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {
    if ((*root) == 0){
        struct bst_node *n = (struct bst_node *)malloc(sizeof(struct bst_node));
        n->data = word;
    }
    if (strcmp(word, (*root)->data) < 0) add((*root)->left, word);
    else add((*root)->right, word);
}


void inorder ( bst_node * root ) {
    if(root == 0) return;
    inorder(root -> left);
    printf("%s", root -> data);
    inorder(root -> left);
}

char * removeSmallest (  bst_node ** root ){
    struct bst_node* n;
    if ((*root) != 0 ){
        if((*root)->left->left == 0){
            n = (*root)->left;
            char* word = n->data;
            (*root)->left = (*root)->left->right;
            free(n);
            return word;
        }
        else{
            removeSmallest(&((*root)->left));
        }
    }
    return NULL;
}


char * removeLargest (  bst_node ** root ){
    struct bst_node* n;
    if ((*root) != 0 ){
        if((*root)->right->right == 0){
            n = (*root)->right;
            char* word = n->data;
            (*root)->right = (*root)->right->left;
            free(n);
            return word;
        }
        else{
            removeLargest(&((*root)->right));
        }
    }
    return NULL;
}