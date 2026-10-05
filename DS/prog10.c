#include <stdio.h>  

void merge(int a[], int l, int m, int h){
    
    int i,j,k,temp[100];      
    i = l;     
    j = m;     
    k = l;      
    
    while (i < m && j < h){         
        if (a[i] < a[j]){             
            temp[k] = a[i];             
            i++;         
        }else{             
            temp[k] = a[j];             
            j++;         
        }         
        
        k++;     
    }      
    
    while (i < m){         
        temp[k] = a[i];         
        i++;         
        k++;     
    }      
    
    while (j < h){         
        temp[k] = a[j];         
        j++;         
        k++;     
    }      
    
    for (i = l; i < h; i++){         
        a[i] = temp[i];     
    } 
}  

void mergesort(int a[], int l, int h){     
    int m;      
    if (l >= h - 1){         
        return;     
    }      
    
    m = (l + h) / 2;     
    mergesort(a,l,m);     
    mergesort(a,m,h);     
    merge(a,l,m,h); 
}  

int main(void){     
    
    int a[100],n,i;      
    printf("Enter the number of elements : ");     
    scanf("%d",&n);     
    printf("\n");     
    
    for(i=0;i<n;i++){        
         printf("Enter element %d value : ",i+1);         
         scanf("%d",&a[i]);     
        
    }      
    
    mergesort(a,0,n);     
    
    printf("\nMerge Sort - Sorted Array : ");    
    
    for(i=0;i<n;i++){         
        printf("%d ",a[i]);     
    }      
    
    return 0; 
}