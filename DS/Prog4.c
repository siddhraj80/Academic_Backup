#include <stdio.h>
#define MAX 5

void main() {

    void insert(int *, int *, int [], int);
    int delete(int *, int *, int []);
    void display(int *, int *, int []);

    int que[MAX];
    int fval = -1;
    int rval = -1;
    int *f = &fval;
    int *r = &rval;
    int ch,val,rmval;

    do{
        printf("\n------- Queue Menu -------\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");

        printf("Enter Your Choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter Num : ");
                scanf("%d",&val);
                insert(f,r,que,val);
                break;
            case 2:
                rmval = delete(f,r,que);
                if(rmval != -1){
                    printf("Deleted Value : %d\n",rmval);
                }
                break;
            case 3:
                display(f,r,que);
                break;
            case 4 :
                 printf("Exting....");
                break;
            default:
                printf("invalid choice!\n");
                break;
        }
        
    }while (ch != 4);
}

void insert(int *f, int *r,int que[],int val){
    if (*r == -1){
        *r = *f = 0;
        que[*r] = val;
        printf("Value Inserted Successfully.\n");
    }else if (*r < MAX - 1){
        *r = *r + 1;
        que[*r] = val;
        printf("Value Inserted Successfully.\n");    
    }else{
        printf("Queue is Full,Can't Insert New Value.\n");
    }
}

int delete(int *f, int *r, int que[]){
    int rm;
    if (*f == *r && *f != -1){
        rm = que[*f];
        *f = *r = -1;
        return rm;
    }else if (*f < *r){
        rm = que[*f];
        *f = *f + 1;
        return rm;
    }else{
        printf("Queue is Empty, Can't Delete Any Value.\n");
        return -1;
    }
}

void display(int *f, int *r, int que[]){
    if (*f != -1 && *r != -1){
        int i;
        for ( i = *f; i <= *r; i++){
            if(i == *r){
                printf("%d",que[i]);
            }else{
                printf("%d <- ",que[i]);
            }
        }
        printf("\n");
    }else{
        printf("Queue is Empty,Can't Display Any Value.\n");
    }
}