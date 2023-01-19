#include "sort.h"


/**
 * insertion_sort_list - insertion_sort_list
 * @list: array to sort
 * Return: ptr to arr or null
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL, *prev = NULL, *nxt = NULL, *tmp = NULL, *prv = NULL;

	if (!list)
		return;
	head = *list;
	/* main loop */
	while (head)
	{
		prev = head->prev, nxt = head->next;
		while (prev)
		{
			prv = prev->prev;
			if (prev->n > prev->next->n)
			{
				/* swap */
				if (prev->prev)
					/* if prev prev is a node, point it to next  */
					prev->prev->next = prev->next;
				else
					/* start of list, make next head */
					*list = prev->next;
				if (prev->next->next)
					/*  */
					prev->next->next->prev = prev;
				tmp = prev->next->next;
				/* config next */
				prev->next->next = prev, prev->next->prev = prev->prev;
				/* config prev */
				prev->prev = prev->next, prev->next = tmp;
				print_list(*list);
			}
			/* code */
			prev = prv;
		}
		if (!nxt)
			break;
		head = nxt;
	}

}
