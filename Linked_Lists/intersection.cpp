#include "ll.h"
#include <iostream>

using namespace std;

struct Node* findNode(struct Node* longer, struct Node* shorter, int diff)
    {
        while(diff--)
        {
            longer = longer->next;
        }
        while(longer && shorter)
        {
            if(longer == shorter)
                return longer;
			longer = longer->next;
			shorter = shorter->next;
        }
        return NULL;
    }

struct Node* intersecting(struct Node* list1, struct Node* list2)
{
    int len1 = length(list1);
    int len2 = length(list2);
    int diff = abs(len1 - len2);
	if(len1 > len2)
		return findNode(list1, list2, diff);
	else
		return findNode(list2, list1, diff);
}

int main()
{
	struct Node* newNode;
	struct Node* head1 =
			(struct Node*) malloc(sizeof(struct Node));
	head1->data  = 10;

	struct Node* head2 =
			(struct Node*) malloc(sizeof(struct Node));
	head2->data  = 3;

	newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = 6;
	head2->next = newNode;

	newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next  = newNode;

	newNode = (struct Node*) malloc (sizeof(struct Node));
	newNode->data = 30;
	head1->next->next= newNode;

	head1->next->next->next = NULL;
	cout << intersecting(head1, head2)->data;
	return 0;
}
