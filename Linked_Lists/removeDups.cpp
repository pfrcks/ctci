#include "ll.h"
#include <unordered_set>
#include <iostream>

using namespace std;

void removeDups(struct Node** head)
{
    unordered_set<int> seen;

    struct Node* curr = *head;
    struct Node* prev = NULL;
    while(curr != NULL)
    {
        if(seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete(curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
}

int main()
{

    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 5);
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 15);
    printList(head);
    std::cout << endl ;
    removeDups(&head);
    printList(head);

}


