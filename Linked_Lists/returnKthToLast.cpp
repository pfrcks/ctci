#include "ll.h"
#include <iostream>

using namespace std;

struct Node* returnKthToLast(struct Node* head, int k)
{
    struct Node* tmp = head;
    int i = 0;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    int j = i - k ;
    for(int i = 0; i < j ; i++)
        head = head->next;

    return head;
}


int main()
{

    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 5);
    push(&head, 15);
    push(&head, 9);
    push(&head, 4);
    push(&head, 14);
    printList(head);
    std::cout << endl ;
    cout << returnKthToLast(head, 5)->data;

}
