#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int arrayb[] = {1, 1};
    int arrayc[] = {2, 1};
    int arrayd[] = {2, -48, 99, -71, -13, -52, 96, -73, 86, -1};
    int arraye[] = {0, -48, 99, -71, -13, -52, 96, -73, -2, 0};
    int arrayf[] = {20};
    int arrayg[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    size_t n = sizeof(array) / sizeof(array[0]);
    /* test 1 */
    printf("testing:\n");
    print_array(array, n);
    printf("\n");
    printf("Expected: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99\n");
    selection_sort(array, n);
    print_array(array, n);
    printf("testing:");
    n = sizeof(arrayb) / sizeof(arrayb[0]);
    print_array(arrayb, n);
    printf("\n");
    printf("Expected: 1, 1\n");
    selection_sort(arrayb, n);
    printf("\n");
    print_array(arrayb, n);
    printf("testing:\n");
    n = sizeof(arrayc) / sizeof(arrayc[0]);
    print_array(arrayc, n);
    printf("\n");
    printf("Expected: 1, 2\n");
    selection_sort(arrayc, n);
    printf("\n");
    print_array(arrayc, n);
    printf("testing:\n");
    n = sizeof(arrayd) / sizeof(arrayd[0]);
    print_array(arrayd, n);
    printf("\n");
    printf("Expected: -73, -71, -52, -48, -13, -1, 2, 86, 96, 99\n");
    selection_sort(arrayd, n);
    printf("\n");
    print_array(arrayd, n);
    printf("testing:\n");
    n = sizeof(arraye) / sizeof(arraye[0]);
    print_array(arraye, n);
    printf("\n");
    printf("Expected: -73, -71, -52, -48, -13, -2, 0, 0, 96, 99\n");
    selection_sort(arraye, n);
    printf("\n");
    print_array(arraye, n);
    printf("testing:\n");
    n = sizeof(arrayf) / sizeof(arrayf[0]);
    print_array(arrayf, n);
    printf("\n");
    printf("Expected: 20\n");
    selection_sort(arrayf, n);
    printf("\n");
    print_array(arrayf, n);
    printf("testing no swap:\n");
    n = sizeof(arrayg) / sizeof(arrayg[0]);
    print_array(arrayg, n);
    printf("\n");
    printf("Expected: 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1\n");
    selection_sort(arrayg, n);
    printf("\n");
    print_array(arrayg, n);
    return (0);
}
