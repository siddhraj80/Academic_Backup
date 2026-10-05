#include <stdio.h>

void quicksort(int a[],int l, int h){
    
    int i,j,temp,key;      
    
    if (l >= h - 1){ 
        
        return;     
    }      
    key = a[l];     
    i = l + 1;     
    j = h - 1;               
    
    while (i <= j){         
        while (i < h && a[i] < key){
            
            i++;         
        }         
        while (j > l && a[j] > key){
            
            j--;         
        }          
        if (i <= j){             
            temp = a[i];             
            a[i] = a[j];            
            a[j] = temp;             
            i++;             
            j--;         
        }     
    }     
    
    temp = a[l];     
    a[l] = a[j];     
    a[j] = temp;      
    quicksort(a,l,j);     
    quicksort(a,j+1,h); 
}  
void main(){
    
    int a[100],n,i;      
    printf("Enter the number of elements : ");     
    scanf("%d",&n);     
    printf("\n");      
    
    for(i=0;i<n;i++){         
        printf("Enter element %d value : ",i+1);         
        scanf("%d",&a[i]);     
    }      
    
    quicksort(a,0,n);      
    printf("\nQuick Sort - Sorted Array : ");    
    
    for(i=0;i<n;i++){         
        printf("%d ",a[i]);     
    }      
    
    getch();
}