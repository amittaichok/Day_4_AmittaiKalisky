/*------------------------------------------------------
* Filename: median.c
* Description: exercise
* Author: Amittai Kalisky
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
void print_median(int *array_of_numbers, int len);

/*------------------------------------------------------
* Function Name - print_median
*
* Function Purpose - compute and print the median of an integer list.
*
* Parameters – array_of_numbers - pointer to integers. len - numebr of integers.
*
* Return Values - void
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
void print_median(int *array_of_numbers, int len){
    /*sort half of the array*/
    int min_index;
    int holder;
    for(int i = 0; i < ((len / 2) + 1); i++){
        min_index = i;
        for(int j = i; j < len; j++){
            if(array_of_numbers[j] < array_of_numbers[min_index]){
                min_index = j;
            }
        }
        /*swap min with array_of_numbers[i]*/
        holder = array_of_numbers[min_index];
        array_of_numbers[min_index] = array_of_numbers[i];
        array_of_numbers[i] = holder;
    }
    printf("The median is %d\n", array_of_numbers[len/2]);
}

/*------------------------------------------------------
* Function Name - main
*
* Function Purpose - get numbers until we get a non-number. Then print thaem all and their median.
*
* Parameters –  nothing.
*
* Return Values - 0 if finished. 1 if exception,
*
* Author - Amittai Kalisky
-------------------------------------------------------*/
int main() {
    int *numbers = NULL; 
    int count = 0; /*counts how many numbers where taken*/
    int x; /*vairable to get the numbers*/
    int *tmp;

    printf("Please enter numbers (non-number to proceed):\n");
    while (scanf("%d", &x) == 1){
        tmp = realloc(numbers, (count + 1)*sizeof(int));
        if (tmp == NULL){
            printf("Bad memmory allocation!\n");
            return 1;
        }

        tmp[count] = x;
        numbers = tmp;
        count++;
    }   

    /*print numbers*/
    printf("Here are the numbers you entered:\n");
    for(int i = 0; i < count; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    /*compute and print median*/
    print_median(numbers, count);

    return 0;
}