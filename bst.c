/*
 *Author: Elisha Ishaal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {
    //if pointer to root is empty then return
    if (root == 0) return;
    //if node is empty, add to the node
    if (*root == 0){
        (*root) = (bst_node *)malloc(sizeof(bst_node));
        (*root)->data = word;
        (*root)->left = NULL;
        (*root)-> right = NULL;
        return;
    }

    //printf("   %s,  %s", (*root)->data, word);

    //if word precedes root, add to empty left child
    if (strcmp(word, (*root)->data) < 0) add(&((*root)->left), word);

    //if root precedes word, add to empty right child
    else if (strcmp(word, (*root)->data) > 0) add(&((*root)->right), word);

    //if they are the same word, return
    else return;

}


void inorder ( bst_node * root ) {
    if(root == 0) return;

    //print left
    inorder(root -> left);

    //print parent
    printf("%s ", root -> data);

    //print right
    inorder(root -> right);
}


char * removeSmallest (  bst_node ** root ){
    struct bst_node* n;
    if ((*root) != 0 ){
        if((*root)->left == 0){
            n = (*root);
            char* word = n->data;
            (*root) = (*root)->right;
            free(n);
            n = NULL;
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
        if((*root)->right == 0){
            n = (*root);
            char* word = n->data;
            (*root) = (*root)->left;
            free(n);
            n = NULL;
            return word;
        }
        else{
            removeLargest(&((*root)->right));
        }
    }
    return NULL;
}