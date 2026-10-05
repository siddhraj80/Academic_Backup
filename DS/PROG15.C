#include<stdio.h>
#include<conio.h>

struct bntree{
  struct bntree *lptr;
  int data;
  struct bntree *rptr;
};

void insertNode(struct bntree **root, int val){

  struct bntree *new_node, *curr, *prev;
  new_node = (struct bntree *)malloc(sizeof(struct bntree));

  curr = *root;
  new_node->data = val;
  new_node->lptr = NULL;
  new_node->rptr = NULL;

  if(*root == NULL){

    *root = new_node;

    printf("Node Successfully Inserted");

  }else{

    while(curr != NULL){

      if(val > curr->data){
	prev = curr;
	curr = curr->rptr;
      }else{
	prev = curr;
	curr = curr->lptr;
      }
    }

    if(prev->data >= val){
      prev->lptr = new_node;
      printf("\nNode Successfully Inserted");
    }else{
      prev->rptr = new_node;
      printf("\n\nnode Successfully Inserted");
    }
  }

}

void preorder(struct bntree **root){

  struct bntree *curr;
  curr = *root;

  if(curr != NULL){
    printf("\n%d",curr->data);
    preorder(&curr->lptr);
    preorder(&curr->rptr);

  }

}

void inorder(struct bntree **root){

  struct bntree *curr;
  curr = *root;

  if(curr != NULL){
    inorder(&curr->lptr);
    printf("%d\n",curr->data);
    inorder(&curr->rptr);
  }
}

void postorder(struct bntree **root){

  struct bntree *curr;
  curr = *root;

  if(curr != NULL){
    postorder(&curr->lptr);
    postorder(&curr->rptr);
    printf("%d\n",curr->data);
  }
}


void main(){

  struct bntree *root = NULL;
  int ch,data;

  do{
    printf("\n1. Insert");
    printf("\n2. Preorder Traverse");
    printf("\n3. Inorder Traverse");
    printf("\n4. Postorder Traverse");
    printf("\n0. Exit");
    printf("\nEnter choice");
    scanf("%d",&ch);

    switch(ch){
      case 1:
	     printf("\nEnter Number to insert in tree: ");
	     scanf("%d",&data);
	     insertNode(&root,data);
	     break;

      case 2:
	     preorder(&root);
	     break;

      case 3:
	     inorder(&root);
	     break;

      case 4:
	     postorder(&root);
	     break;

      case 0:
	     printf("\nExit");
	     break;

      default:
	      printf("\nInvalid choice");
	      break;

    }
  }while(ch != 0);


  getch();
  clrscr();
}