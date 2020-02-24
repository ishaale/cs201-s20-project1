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
    //if tree is empty, add to the tree
    if (*root == 0){
        (*root) = (bst_node *)malloc(sizeof(bst_node));
        (*root)->data = word;
        (*root)->left = NULL;
        (*root)-> right = NULL;
        return;
    }

    //printf("   %s,  %s", (*root)->data, word);

    //if word precedes or equal to root, add to empty left child
    if (strcmp(word, (*root)->data) <= 0) add(&((*root)->left), word);

    //if root precedes word, add to empty right child
    else add(&((*root)->right), word);

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
    if ((*root) != NULL ){
        if((*root)->left == NULL){
            //create copy of pointer to delete and whose value to return
            bst_node *n = (*root);
            char* word = n->data;
            //set the current node to its right child if it exists
            (*root) = (*root)->right;
            //delete and return min
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
    if ((*root) != 0 ){
        if((*root)->right == 0){
            //create copy of pointer to delete and whose value to return
            bst_node *n = (*root);
            char* word = n->data;
            //set the current node to its left child if it exists
            (*root) = (*root)->left;
            //delete and return max
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