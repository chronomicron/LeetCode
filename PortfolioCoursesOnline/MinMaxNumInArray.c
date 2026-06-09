#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMin(int *arr, int size);
int findMax(int *arr, int size);

int main() {
    int ArraySize;
    printf("Enter the number of elements in the array: ");


    while (1) {
        scanf("%d", &ArraySize);

        if (ArraySize <= 0) {
            printf("Array size must be greater than 0.\n");
            continue;
        }
        else {
            break;
        }
    }

    int arr[ArraySize];
    int minIndex = 0; // Initialize minIndex to 0
    int maxIndex = 0; // Initialize maxIndex to 0
    srand(time(0)); // Seed the random number generator

    printf("Generating an array of %d random integers...\n", ArraySize);
    printf("Array = [");
    for (int i = 0; i < ArraySize; i++) {
        int randomNum = rand() % 1000; // Generate a random integer between 0 and 999
        printf("%d ", randomNum);
        arr[i] = randomNum; // Store the random number in the array
    }
    printf("] \n");

    if (ArraySize == 0) {
        printf("Array is empty. No minimum value.\n");
        return 0;
    }
    else if (ArraySize == 1) {
        minIndex = 0; // The only element is the minimum
        maxIndex = 0; // The only element is the maximum
    }
    else {
        minIndex = findMin(arr, ArraySize);
        maxIndex = findMax(arr, ArraySize);
    }

    printf("The minimum number in the array is: %d\n", arr[minIndex]);
    printf("The maximum number in the array is: %d\n", arr[maxIndex]);
    return 0;
}

/***********************************************/
/* Start Your Code Here */

// returns the index of the minimum element in the array
int findMin(int *arr, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// returns the index of the maximum element in the array
int findMax(int *arr, int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

/***********************************************/
