#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void main() {

    void insert(int *, int *, int [], int);
    int delete(int *, int *, int []);
    void display(int *, int *, int []);

    int queue[MAX];
    int ch,value,rmval;
    int fval = -1;
    int rval = -1;
    int *front = &fval;
    int *rear = &rval;


    do{
	printf("\nCircular Queue Menu\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display\n");
	printf("4.Exit\n");

	printf("Enter Your Choice : ");
	scanf("%d",&ch);

	switch(ch){
	    case 1 :
		printf("Enter Number : ");
		scanf("%d",&value);
		insert(front,rear,queue,value);
		break;
	    case 2 :
		rmval = delete(front,rear,queue);
		if(rmval != -1){
		    printf("Deleted Value : %d\n",rmval);
		}
		break;
	    case 3 :
		display(front,rear,queue);
		break;
	    case 0 :
		 printf("Exit");
		break;
	    default:
		printf("Invalid choice\n");
		break;
	}

    }while (ch != 0);
}

void insert(int *front, int *rear,int queue[],int value){
    if((*front == 0 && *rear == MAX - 1) || (*front > *rear && abs(*front-*rear) == 1)){
	printf("Queue is Full\n");
    }else{
	if(*rear == MAX - 1){
	    *rear= 0;
	    queue[*rear] = value;
	    printf("Value Inserted Successfully.\n");
	}else{
	    if (*front == *rear && *front == -1){
		*front = *rear = 0;
		queue[*rear] = value;
		printf("Value Inserted Successfully.\n");
	    }else{
		*rear = *rear + 1;
		queue[*rear] = value;
		printf("Value Inserted Successfully.\n");
	    }
	}
    }
}

int delete(int *front, int *rear, int queue[]){
    int rm;
    if (*front == -1 && *rear == -1){
	printf("Queue is Empty.\n");
    }else{
	if (*front == MAX -1){
	    rm = queue[*front];
	    *front = 0;
	    return rm;
	}else{
	    if(*front == *rear){
		rm = queue[*front];
		*front = *rear = -1;
		return rm;
	    }else{
		rm = queue[*front];
		*front = *front + 1;
		return rm;
	    }
	}
    }
}

void display(int *front, int *rear, int queue[]){
    int i;
    if (*front == -1 && *rear == -1){
	printf("Queue is Empty.\n");
    }else if(*front <= *rear){
	for ( i = *front; i <= *rear; i++){
	    if(i == *rear){
		printf("%d",queue[i]);
	    }else{
		printf("%d - ",queue[i]);
	    }
	}
	printf("\n");
    }else{
	for ( i = *front; i < MAX; i++){
	    printf("%d - ",queue[i]);
	}
	for ( i = 0; i <= *rear;i++){
	    if(i == *rear){
		printf("%d",queue[i]);
	    }else{
		printf("%d - ",queue[i]);
	    }
	}
	printf("\n");
    }
}