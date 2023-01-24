#include "sort.h"


/**
 * swap_l - swap_l
 * @first_n: the node that comes first in the list
 * @second_n: the node that comes after
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
 * cocktail_sort_list - cocktail_sort_list
 * @list: list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = NULL, *tmp = NULL;
	int swap = 0, i = 0, j = 0, st_in = 0, len = 0, end_in = 0;

	if (!list)
		return;
	/* get lst length */
	head = *list;
	while (head)
		len++, head = head->next;
	/* assign index */
	st_in = 0, end_in = len - 1;
	/* quick check */
	if (len < 2)
		return;
	head = *list;
	/* main loop to hold both iterations */
	do
	{
		/* make sure swap is false on each iteration */
		swap = 0;
		/* aways start from head */
		head = *list;
		/* iteration going foward */
		for (i = 0; head && (i <= end_in); head = head->next, i++)
		{
			/* start at stin */
			if (i < st_in)
				continue;
			/* compare */
			if (head->next)
			{
				if (head->n > head->next->n)
					tmp = head->next, swap_l(head, head->next, list), swap = 1, head = tmp;
			}
			else
			{
				st_in++;
				break;
			}
		}
		/* break main loop if no swap */
		if (!swap)
			break;
		/* start index -1 */
		head = head->prev;
		/* iteration going backwards */
		for (j = end_in; head && (j >= st_in); head = head->prev, j--)
		{
			/* compare */
			if (head->prev)
			{
				if (head->n < head->prev->n)
					tmp = head->prev, swap_l(head->prev, head, list), swap = 1, head = tmp;
			}
			else
			{
				end_in--;
				break;
			}
		}
	} while (swap);

}
