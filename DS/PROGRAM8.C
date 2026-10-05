#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};

void main(){
  void insert_cll(struct node **,int);
  void delete(struct node **,int);
  void display(struct node **);
  struct node *h = NULL;
  int ch,val,rmval;
  do{
    printf("\nLinked List Menu\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Traverse\n");
    printf("4.Exit\n");
    printf("Enter Your choice : ");
    scanf("%d",&ch);
    switch(ch){
      case 1:
	printf("Enter Value To Insert : ");
	scanf("%d",&val);
	insert_cll(&h,val);
	break;
      case 2:
	printf("Enter Value To Delete : ");
	scanf("%d",&val);
	delete(&h,val);
	break;
      case 3:
	display(&h);
	break;
      case 4:
	printf("Exiting...\n");
	break;
      default:
	printf("Invalid choice! Please try again.\n");
      break;
     }
   }while( ch != 4);
}

void insert_cll(struct node **h,int val){
    struct node *c, *p,*nn;
    nn = (struct node *)malloc(sizeof(struct node));
    p = NULL;
    c = *h;
    if(c == NULL){
      nn->data = val;
      *h = nn;
      nn->next = *h;
      printf("Value Inserted in Linked List Successfully.\n");
    }else{
      while(c->data < val && c->next != *h){
	 p = c;
	 c = c->next;
      }
      if(p == NULL){
	if(c->data < val){
	   nn->data = val;
	   nn->next = c->next;
	   c->next = nn;
	   printf("Value Inserted in Linked List Successfully\n");
	}else{
	   nn->data = val;
	   nn->next = c;
	   while(c->next != *h){
	      c = c->next;
	   }
	   c->next = nn;
	   *h = nn;
	   printf("Value Inserted in Linked List Successfully\n");
	}
     }else if (c->next == *h && c->data < val){
	nn->data =val;
	nn->next = *h;
	c->next = nn;
	printf("Value Inserted in Linked List Successfully.\n");
     }else{
	p->next = nn;
	nn->next = c;
	nn->data = val;
	printf("Value Inserted in Linked List Successfully.\n");
     }
  }
}

void delete(struct node **h, int val){
   struct node *p, *c, *t;
   if(*h == NULL){
     printf("Linked List is Empty. Nothing to delete.\n");
     return;
   }
   c = *h;
   p = NULL;
   do{
     if(c->data == val){
       break;
     }
     p = c;
     c = c->next;
   }while(c != *h);
   if(c->data != val){
      printf("Element not found in the Linked List.\n");
   }else if(c == *h && c->next == *h){
      *h = NULL;
      free(c);
      printf("Element Deleted Successfully.\n");
   }else if(c == *h){
      t = *h;
      while(t->next != *h){
	 t = t->next;
      }
      *h = c->next;
      t->next = *h;
      free(c);
      printf("Element Deleted Successfully.\n");
   }else{
       p->next = c->next;
       free(c);
       printf("Element Deleted Successfully.\n");
   }
}

void display(struct node **h){
    struct node *c;
    c = *h;
    if(c == NULL){
      printf("Linked List is Empty.\n");
    }else{
      printf("The Elements in the Linked List are : ");
      while(c->next != *h){
	 printf("%d ->",c->data);
	 c = c->next;
      }
      printf("%d\n",c->data);
    }
}