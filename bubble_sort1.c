#include <stdio.h>
#include "linked_list.c"



void bubble_sort(linked_list* ll)
{
	for(int i = 0; i < len(ll) - 1; i++)
	{
		linked_list* cur_el = ll->next;
		linked_list* prev = ll;
    
		while (cur_el->next != NULL)
		{
			if ((cur_el->el) > (cur_el->next->el))
			{
				prev->next = prev->next->next;
				cur_el->next = cur_el->next->next;
				prev->next->next = cur_el;
			}
			else
			{ 
				cur_el = cur_el->next;
				prev = prev->next;
				continue;
			}	
			prev = prev->next; 
		}
	}
}

int main()
{

	linked_list* cur_el = calloc(1, sizeof(linked_list));

	if (cur_el == NULL)
	{
		return 0;
	}

	int cur = 0;
	while (!feof(stdin))
	{
		if (fscanf(stdin, "%d", &cur) != 1)
			break;
		push(cur_el, cur);
	}

	bubble_sort(cur_el);
	print(cur_el);
	
	return 0;
}
