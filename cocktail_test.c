#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list, *listb, *listc, *listd, *liste, *listf, *listg;

    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    int arrayb[] = {1, 1};
    int arrayc[] = {2, 1};
    int arrayd[] = {2, -48, 99, -71, -13, -52, 96, -73, 86, -1};
    int arraye[] = {0, -48, 99, -71, -13, -52, 96, -73, -2, 0};
    int arrayf[] = {20};
    int arrayg[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    size_t n = sizeof(array) / sizeof(array[0]);
    list = create_listint(array, n);
    if (!list)
        return (1);
    printf("testing:\n");
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arrayb) / sizeof(arrayb[0]);
    listb = create_listint(arrayb, n);
    if (!listb)
        return (1);
    print_list(listb);
    printf("\n");
    cocktail_sort_list(&listb);
    printf("\n");
    print_list(listb);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arrayc) / sizeof(arrayc[0]);
    listc = create_listint(arrayc, n);
    if (!listc)
        return (1);
    print_list(listc);
    printf("\n");
    cocktail_sort_list(&listc);
    printf("\n");
    print_list(listc);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arrayd) / sizeof(arrayd[0]);
    listd = create_listint(arrayd, n);
    if (!listd)
        return (1);
    print_list(listd);
    printf("\n");
    cocktail_sort_list(&listd);
    printf("\n");
    print_list(listd);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arraye) / sizeof(arraye[0]);
    liste = create_listint(arraye, n);
    if (!liste)
        return (1);
    print_list(liste);
    printf("\n");
    cocktail_sort_list(&liste);
    printf("\n");
    print_list(liste);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arrayf) / sizeof(arrayf[0]);
    listf = create_listint(arrayf, n);
    if (!listf)
        return (1);
    print_list(listf);
    printf("\n");
    cocktail_sort_list(&listf);
    printf("\n");
    print_list(listf);
    /* test case  */
    printf("testing:\n");
    n = sizeof(arrayg) / sizeof(arrayg[0]);
    listg = create_listint(arrayg, n);
    if (!listg)
        return (1);
    print_list(listg);
    printf("\n");
    cocktail_sort_list(&listg);
    printf("\n");
    print_list(listg);
    return (0);
}
