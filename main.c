#include <stdio.h>
#include "char_count.h"
#include "fahr_celsius_print.h"
#include "point-and-array.h"
#include "struct.h"

void print_arr(int*, int);

int main(int argc, char *argv[]) {
    // struct_and_function();
    int arr[] = {1,2,3,4,5};
    int size = 5;
    print_arr(arr, size);
    return 0;
}

void print_arr(int* arr, int arrSize) {
    int i = 0;

    while (arrSize > i) {
        printf("%d", *arr);
        arr++;
        i++;
    }
}




