#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    (*head) = newNode;
}

void insertAfter(struct Node* prev, int data)
{
    if (prev == NULL)
    {
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

void appendAfter(struct Node** head, int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct Node* last = (*head);
    while(last->next !=NULL)
        last = last->next;
    last->next = newnode;
    return;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}

void deleteFirstOccurence(struct Node** head, int data)
{
	if(*head == NULL)
		return;
    struct Node* temp = *head, *prev;
    if((*head)->data == data)
    {
        (*head) = (*head)->next;
        free(temp);
        return;
    }
    while(temp->data != data && temp!=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int compareLists(struct Node* first, struct Node* second)
{
    while(first && second)
    {
        if(first->data == second->data)
        {
            first = first->next;
            second = second->next;
        }
        else
            return 1;
    }
    if(first == NULL && second == NULL)
        return 0;
    return 1;
}

int length(struct Node* list)
{
    struct Node* tmp = list;
    int count =0;
    while(tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}
