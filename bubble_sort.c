#include <stdio.h>
#include "linked_list.c"



void bubble_sort(linked_list* ll)
{
	int len_ll = len(ll);
	for (int i = 0; i < len_ll - 1; i++)
	{
		linked_list* cur_el = ll->next;
		linked_list* next_el = ll->next->next;
		linked_list* prev = ll;
    
		while (next_el != NULL)
		{
			if ((cur_el->el) > (next_el->el))
			{  
				cur_el->next = next_el->next;
				next_el->next = cur_el;
				prev->next = next_el;
			}
			else
			{ 
				cur_el = cur_el->next; 
				next_el = next_el->next; 
				prev = prev->next;
				continue;
			}
      
			cur_el = next_el->next;	
			next_el = cur_el->next;
			prev = prev->next;
		}
	}
}

int main()
{

	int cur = 0;
	linked_list* cur_el = calloc(1, sizeof(linked_list));

	if (cur_el == NULL)
	{
		return 0;
	}


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
