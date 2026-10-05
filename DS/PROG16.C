#include<stdio.h>

struct iterativeBst {

  struct iterativeBst *lptr;
  int data;
  struct iterativeBst *rptr;

};

void insert(struct iterativeBst **root, int data){

  struct iterativeBst *newNode, *curr, *prev;

  newNode = (struct iterativeBst *)malloc(sizeof(struct iterativeBst));

  curr = *root;
  prev = curr;

  newNode->data = data;
  newNode->lptr = NULL;
  newNode->rptr = NULL;

  if(curr != NULL){

    while(curr != NULL){

      prev = curr;

      if(curr->data > data){

	curr = curr->rptr;
      }else{

	curr = curr->lptr;
      }
    }
    if(prev->data > data){

      prev->rptr = newNode;
      printf("\nInserted successfully");
    }else{

      prev->lptr = newNode;
      printf("\nInserted successfully");
    }

  }else{

    *root = newNode;
    printf("\n Inserted successfully (root)");
  }
}

void deleteNode(struct iterativeBst **root, int dval){

  int found;

  struct iterativeBst *curr, *prev, *foundNode;
  curr = *root;
  prev = curr;

  if(curr != NULL){
    while(curr != NULL){

      prev = curr;

      if(curr->data > dval){

	curr = curr->rptr;
      }else if(curr->data < dval){

	curr = curr->lptr;
      }else{

	foundNode = curr;
	found = 1;
	break;
      }
    }

    if(found == 1){
      char direction;

      printf("\nfound :- %d",foundNode->data);

      if(prev->data > dval){

	direction = 'r';
      }else{

	direction = 'l';
      }

      //leaf node
      if(foundNode->lptr == NULL && foundNode->rptr == NULL){

	if(direction == 'r'){

	  prev->rptr = NULL;
	  printf("\n node deleted");
	}else{

	  prev->lptr = NULL;
	  printf("\n Node deleted");
	}
      }

      //one child node



    } else{

      printf("Node not found");
    }
  }
}

void display(struct iterativeBst **root){

  struct iterativeBst *curr;

  curr = *root;

  while( curr != NULL){

   printf("\n %d",curr->data);
   curr = curr->rptr;

  }
}

void main(){

  struct iterativeBst *root = NULL;

  int ch,data,dval;

  do{

   printf("\n\n Iterative Bst menu\n ");
   printf("\n 1. Insert");
   printf("\n 2. Display");
   printf("\n 3. Delete");
   printf("\n 0. Exit");
   printf("\n Enter your choice:");
   scanf("%d",&ch);

   switch(ch){

     case 1:
	    printf("\nenter value to insert:");
	    scanf("%d",&data);
	    insert(&root,data);
	    break;

     case 2:
	    printf("Display");
	    display(&root);
	    break;

     case 3:
	    printf("Enter value to delete : ");
	    scanf("%d",&dval);
	    deleteNode(&root,dval);
	    break;

     case 0:
	    printf("\nEXIT");
	    break;

     default :
	     printf("\nInvalid choic ");
	     break;
   }

  }while(ch != 0);

  getch();
  clrscr();
}





