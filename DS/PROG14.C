#include <stdio.h>
#include <conio.h>

int linearSearch(int arr[], int size, int target);
int binarySearch(int arr[], int size, int target);

void main() {
    int arr[100];
    int n, i, target, choice, result;

    clrscr();

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    printf("\n Choose Search Algorithm \n");
    printf("1. Linear Search\n");
    printf("2. Binary Search (Requires elements to be sorted)\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
	case 1:
	    result = linearSearch(arr, n, target);
	    break;
	case 2:
	    result = binarySearch(arr, n, target);
	    break;
	default:
	    printf("Invalid choice!\n");
	    getch();
	    return;
    }

    if (result != -1) {
	printf("\nElement found at index: %d \n", result);
    } else {
	printf("\nElement not found\n");
    }

    getch();
}

int linearSearch(int arr[], int n, int target) {
    int i;
    for (i = 0; i < n; i++) {
	if (arr[i] == target) {
	    return i;
	}
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
	mid = (low + high) / 2;

	if (arr[mid] == target) {
	    return mid;
	}
	else if (arr[mid] < target) {
	    low = mid + 1;
	}
	else {
	    high = mid - 1;
	}
    }
    return -1;
}