#include <stdio.h>
#define MAX 5

void main() {

    void front_insert(int *, int *, int [], int);
    void rear_insert(int *, int *, int [], int);
    int front_delete(int *, int *, int []);
    int rear_delete(int *, int *, int []);
    void display(int *, int *, int []);

    int queue[MAX];
    int ch,value,rmval;
    int fval = -1, rval = -1;
    int *front = &fval;
    int *rear = &rval;

    do{
	printf("\nDouble Ended-Queue Menu\n");
	printf("1.Insert From Front\n");
	printf("2.Insert From Rear\n");
	printf("3.Delete From Front\n");
	printf("4.Delete From Rear\n");
	printf("5.Display\n");
	printf("0.Exit\n");

	printf("Enter Your Choice : ");
	scanf("%d",&ch);

	switch(ch){
	    case 1:
		printf("Enter Number : ");
		scanf("%d",&value);
		front_insert(front,rear,queue,value);
		break;
	    case 2:
		printf("Enter Num : ");
		scanf("%d",&value);
		rear_insert(front,rear,queue,value);
		break;
	    case 3:
		rmval = front_delete(front,rear,queue);
		if(rmval != -1){
		    printf("Deleted Value : %d\n",rmval);
		}
		break;
	    case 4:
		rmval = rear_delete(front,rear,queue);
		if(rmval != -1){
		    printf("Deleted Value : %d\n",rmval);
		}
		break;
	    case 5:
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

void rear_insert(int *front, int *rear,int queue[],int value){
    if (*rear == -1){
	*rear = *front = 0;
	queue[*rear] = value;
	printf("Value Inserted Successfully.\n");
    }else if (*rear < MAX - 1){
	*rear = *rear + 1;
	queue[*rear] = value;
	printf("Value Inserted Successfully.\n");
    }else{
	printf("Queue is Full.\n");
    }
}

void front_insert(int *front, int *rear,int queue[],int value){
    if (*front == -1){
	*front = *rear = 0;
	queue[*front] = value;
	printf("Value Inserted Successfully.\n");
    }else if (*front > 0){
	*front = *front - 1;
	queue[*front] = value;
	printf("Value Inserted Successfully.\n");
    }else{
	printf("Queue is Full.\n");
    }
}

int front_delete(int *front, int *rear, int queue[]){
    int rm;
    if (*front == *rear && *front != -1){
	rm = queue[*front];
	*front = *rear = -1;
	return rm;
    }else if (*front < *rear){
	rm = queue[*front];
	*front = *front + 1;
	return rm;
    }else{
	printf("Queue is Empty.\n");
	return -1;
    }
}

int rear_delete(int *front, int *rear, int queue[]){
    int rm;
    if (*rear == *front && *rear != -1){
	rm = queue[*rear];
	*rear = *front = -1;
	return rm;
    }else if (*rear > *front){
	rm = queue[*rear];
	*rear = *rear - 1;
	return rm;
    }else{
	printf("Queue is Empty.\n");
	return -1;
    }
}

void display(int *front, int *rear, int queue[]){
    int i;
    if (*front != -1){
	for ( i = *front; i <= *rear; i++){
	    if(i == *rear){
		printf("%d",queue[i]);
	    }else{
		printf("%d - ",queue[i]);
	    }
	}
	printf("\n");
    }else{
	printf("Queue is Empty,Can't Display Any Value.\n");
    }
}