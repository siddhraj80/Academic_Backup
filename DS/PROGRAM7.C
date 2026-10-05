#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
void main(){
  void insert(struct node **,int);
  int delete(struct node **);
  void traverse(struct node **);
  void modify(struct node **,int,int);
  struct node *h = NULL;
  int ch,val,rmval;
  do{
    printf("\nLinked List Menu\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Modify\n");
    printf("4.Traverse\n");
    printf("5.Exit\n");
    printf("Enter Your choice : ");
    scanf("%d",&ch);

    switch(ch){
      case 1:
	 printf("Enter Value To Insert : ");
	 scanf("%d",&val);
	 insert(&h,val);
	 break;
      case 2:
	 rmval = delete(&h);
	 if(rmval != -1)
	 printf("Deleted Value : %d\n",rmval);
	 break;
      case 3:
	 if(h != NULL){
	   traverse(&h);
	   printf("\nEnter Position of Node To Modify : ");
	   scanf("%d",&rmval);
	   printf("Enter New Value : ");
	   scanf("%d",&val);
	   modify(&h,rmval,val);
	}else{
	   modify(&h,0,0);
	}
	break;
     case 4:
	traverse(&h);
	break;
     case 5:
	printf("Exiting...\n");
	break;
     default:
	printf("Invalid choice! Please try again.\n");
	break;
     }
   }while( ch != 5);
}
void insert(struct node **h,int val){
   struct node *nn = (struct node *)malloc(sizeof(struct node));
   if(*h == NULL){
     nn->data = val;
     nn->next = NULL;
     *h = nn;
     printf("Value Inserted Successfully.\n");
   }else{
     nn->data = val;
     nn->next = *h;
     *h = nn;
     printf("Value Inserted Successfully.\n");
   }
}

int delete(struct node **h){
   struct node *t = *h;
   int dt;
   if(t == NULL){
     printf("Linked List is Empty,Can't Delete Any Value.\n");
     return -1;
   }else{
     while (t != NULL){
       *h = (*h)->next;
       dt = t->data;
       free(t);
       return dt;
     }
   }
}

void modify(struct node **h,int pos,int nval){
   struct node *t = *h;
   int i = 1;
   if (t == NULL){
      printf("Linked List is Empty, Can't Modify Any Value.\n");
   }else{
      while (t != NULL && i < pos){
	t = t->next;
	i++;
      }
      if(t != NULL){
	t->data = nval;
	printf("Value Modified Successfully.\n");
      }else{
	printf("This Postion of Node Not Found,Can't Modify.\n");
      }
   }
}

void traverse(struct node **h){
   struct node *t = *h;
   if(t == NULL){
      printf("Linked List is Empty,Can't Display Any Value.\n");
   }else{
      while (t != NULL){
	printf("%d -> ",t->data);
	t = t->next;
      }
      printf("Null\n");
   }
}