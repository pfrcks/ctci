#include "ll.h"
#include <iostream>

using namespace std;

int detectLoop(struct Node* list)
{
    struct Node* slow = list;
    struct Node* fast = list;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            int count = 0;
            slow = slow->next;
            while(slow != fast)
			{
				count++;
				slow = slow->next;
			}
            return count+1;
        }
    }
    return 0;
}

void removeLoop(struct Node* list, int k)
{
    struct Node* advance = list;
    struct Node* normal = list;
    struct Node* prev = NULL;
	while(k--)
	{
		prev = advance;
		advance = advance->next;
	}
	while(normal && advance)
	{
		if(normal != advance)
		{
			prev = advance;
		}
		else
		{
			prev->next = NULL;
		}
		advance = advance->next;
		normal = normal->next;
	}
}

int main()
{

    struct Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    /* Create a loop for testing */
    head->next->next->next->next = head;
	int k = detectLoop(head);
	removeLoop(head, k);
	printList(head);
    return 0;
}
