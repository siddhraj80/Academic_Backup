#include<stdio.h>

struct avlTree{
  struct avlTree *lptr;
  int data;
  struct avTree *rptr;
}

checkBalance(struct avlTree **root){

  struct avlTree *curr;
  curr = *root;
  int balance=0;

  while(curr != NULL){
    curr = curr ->lptr;
  }

}

void insertNode(struct avlTree **root, int data){

  struct avlTree *newnode,*curr;

  newnode = (struct avlTree *)malloc(sizeof(struct avlTree));
  curr = *root;

  int balanceFactor = checkBalance(&root);

}

void main(){

  struct avlTree *root = NULL;

  insertNode(&root,45);


}