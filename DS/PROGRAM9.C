#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
   int roll_no;
   char name[50];
   float marks;
   struct student *prev;
   struct student *next;
};

int main(void){
   void insert(struct student **);
   void delete_student(struct student **, int);
   void display(struct student *);
   struct student *h = NULL;
   int ch, roll_no;
   do{
     printf("\nDouble Circular Linked List Menu\n");
     printf("1. Insert\n");
     printf("2. Delete\n");

     printf("4. Display\n");
     printf("5. Exit\n");
     printf("Enter Your choice : ");
     scanf("%d", &ch);
     switch(ch){
       case 1:
	  insert(&h);
	  break;
       case 2:
	  printf("Enter Roll Number To Delete : ");
	  scanf("%d", &roll_no);
	  delete_student(&h, roll_no);
	  break;
       case 3:
	  display(h);
	  break;
       case 4:
	  printf("Exiting...\n");
	  break;
       default:
	  printf("Invalid choice! Please try again.\n");
     }
   }while(ch != 4);
   return 0;
}

void insert(struct student **h){
    struct student *nn, *c;
    nn = (struct student *)malloc(sizeof(struct student));
    if(nn == NULL){
       printf("Memory allocation failed.\n");
       return;
    }
    printf("Enter Roll Number : ");
    scanf("%d", &nn->roll_no);
    printf("Enter Student Name : ");
    scanf(" %49[^\n]", nn->name);
    printf("Enter Marks : ");
    scanf("%f", &nn->marks);
    if(*h == NULL){
       nn->next = nn;
       nn->prev = nn;
       *h = nn;
    }else{
       c = *h;
       while(c->next != *h && c->roll_no < nn->roll_no)
	   c = c->next;
       if(c == *h && c->roll_no >= nn->roll_no){
	  nn->next = *h;
	  nn->prev = (*h)->prev;
	  (*h)->prev->next = nn;
	  (*h)->prev = nn;
	  *h = nn;
       }else if(c->next == *h && c->roll_no < nn->roll_no){
	  nn->next = *h;
	  nn->prev = c;
	  c->next = nn;
	 (*h)->prev = nn;
       }else{
	 nn->next = c;
	 nn->prev = c->prev;
	 c->prev->next = nn;
	 c->prev = nn;
       }
    }
     printf("Student Inserted Successfully.\n");
}

void delete_student(struct student **h, int roll_no){
   struct student *c;
   if(*h == NULL){
     printf("Linked List is Empty. Nothing to delete.\n");
     return;
   }
   c = *h;
   do{
     if(c->roll_no == roll_no)
	break;
     c = c->next;
   }while(c != *h);
   if(c->roll_no != roll_no){
     printf("Student not found in the Linked List.\n");
   }else if(c->next == c){
     *h = NULL;
     free(c);
     printf("Student Deleted Successfully.\n");
   }else{
     c->prev->next = c->next;
     c->next->prev = c->prev;
     if(c == *h)
       *h = c->next;
	free(c);
	printf("Student Deleted Successfully.\n");
      }
}

void display(struct student *h){
   struct student *c;
   if(h == NULL){
     printf("Linked List is Empty.\n");
     return;
   }
   printf("\nRoll No\tName\t\tMarks\n");
   c = h;
   do{
      printf("%d\t%-15s %.2f\n", c->roll_no, c->name, c->marks);
      c = c->next;
   }while(c != h);
}