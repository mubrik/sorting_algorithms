#include "sort.h"


/**
 * swap_l - swap_l
 * @first_n: the node that comes first in the list
 * @second_n: the node that comes after
 * @list: list to sort
 * Return: void
 */
void swap_l(listint_t *first_n, listint_t *second_n, listint_t **list)
{
	listint_t *tmp = NULL;
	/* swap */
	if (first_n->prev)
		/* if node_a prev is a node, point it to node_b  */
		first_n->prev->next = second_n;
	else
		/* start of list, make next head */
		*list = second_n;
	/* check 2nd node for next */
	if (second_n->next)
		second_n->next->prev = first_n;
	/* save the next of second node */
	tmp = second_n->next;
	/* config second node, override its next */
	second_n->next = first_n, second_n->prev = first_n->prev;
	/* config first node */
	first_n->prev = second_n, first_n->next = tmp;
	print_list(*list);
}

/**
 * foward_betty - foward_betty
 * @list: list
 * @head: head
 * @st_in: ptr to start index
 * @swp: ptr to swap
 * @end_in: end index
 * Return: listint_t
 * Description: Betty can be so annoying
 */
listint_t *foward_betty(listint_t **list, listint_t *head, int *st_in,
	int *swp, int end_in)
{
	listint_t *tmp = NULL;
	int i = 0;
	/*foward iter*/
	for (i = 0; head && (i <= end_in); head = head->next, i++)
	{
		/* start at start index */
		if (i < *st_in)
			continue;
		if (head->next) /* compare */
		{
			if (head->n > head->next->n)
				tmp = head->next, swap_l(head, head->next, list), *swp = 1, head = tmp;
		}
		else
		{
			*st_in = *st_in + 1;
			break;
		}
	}
	return (head);
}

/**
 * backward_betty - backward_betty
 * @list: list
 * @head: head
 * @st_in: start index
 * @swp: ptr to swap
 * @end_in: ptr to end index
 * Return: void
 * Description: Betty can be so annoying
 */
listint_t *backward_betty(listint_t **list, listint_t *head, int st_in,
	int *swp, int *end_in)
{
	listint_t *tmp = NULL;
	int j = 0;
	/* backward iter */
	for (j = *end_in; head && (j >= st_in); head = head->prev, j--)
	{
		if (head->prev) /* compare */
		{
			if (head->n < head->prev->n)
				tmp = head->prev, swap_l(head->prev, head, list), *swp = 1, head = tmp;
		}
		else
		{
			*end_in = *end_in + 1;
			break;
		}
	}
	return (head);
}

/**
 * cocktail_sort_list - cocktail_sort_list
 * @list: list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	int swap = 0, st_in = 0, len = 0, end_in = 0;

	if (!list)
		return;
	head = *list;
	while (head) /* get lst length & assign index */
		len++, head = head->next, end_in = len - 1;
	if (len < 2)
		return;
	do {	/* main loop to hold both iterations */
		swap = 0, head = *list;	/* make sure swap is false on each iteration */
		head = foward_betty(list, head, &st_in, &swap, end_in);
		if (!swap) /* break main loop if no swap */
			break;
		/* start index - 1 */
		head = head->prev;
		head = backward_betty(list, head, st_in, &swap, &end_in);
	} while (swap);
}
