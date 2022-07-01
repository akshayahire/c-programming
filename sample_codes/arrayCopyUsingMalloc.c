/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 3

void printArr(int * arr, int size)
{
    int loop_idx;
    for(loop_idx=0; loop_idx < size; loop_idx++)
    {
        // printf("%d ", *arr++);
        printf("%d ", arr[loop_idx]);
    }
    printf("\n");
}

int main()
{
    int arr1[ARR_SIZE] = {0};
    int loop_idx;

    int *ptrArr2 = (int*) malloc(ARR_SIZE*sizeof(int));

    int print_method = 1;
    for(loop_idx=0; loop_idx < ARR_SIZE; loop_idx++)
    {
        arr1[loop_idx] = rand();
        // Copy arr1 to dyanamic array ptrArr2
        if(print_method == 1)
        {
            // printf("(ptrArr2+loop_idx)=%p\n", (ptrArr2+loop_idx));
            *(ptrArr2+loop_idx) = arr1[loop_idx]; // --> working
        }
        else if(print_method == 2)
        {
            // printf("ptrArr2=%p\n", ptrArr2);
            // *ptrArr2 = arr1[loop_idx]; // --> not working
            *(ptrArr2+loop_idx) = *(arr1+loop_idx); // --> not working
            ptrArr2++; // This is incorrect approach to increament pointer as printArr() will get incorrect address
        }
        else
        {
            printf("Method not defined");
            return 0;
        }
            
    }
    printArr(arr1, ARR_SIZE);
    printArr(ptrArr2, ARR_SIZE);
    free(ptrArr2);
    return 0;
}
