#include "ll.h"
#include <iostream>

using namespace std;



int checkPalindrome(struct Node* list)
{
    struct Node* fast = list;
    struct Node* slow = list;
    struct Node* slow_prev, *midnode=NULL;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow_prev = slow;
        slow = slow->next;
    }
    if(fast != NULL)
    {
        midnode = slow;
        slow = slow->next;
    }
    struct Node* second = slow;
    slow_prev->next = NULL;
    reverse(&second);
    int res = compareLists(list, second);
    reverse(&second);
    if(midnode != NULL)
    {
        slow_prev->next = midnode;
        midnode->next = second;
    }
    else
        slow_prev->next = second;
    return res;

}

int main()
{

    struct Node* head = NULL;
    push(&head, 10);
    push(&head, 5);
    push(&head, 15);
    push(&head, 16);
    push(&head, 15);
    push(&head, 5);
    push(&head, 10);
    printList(head);
    std::cout << endl ;
    cout << checkPalindrome(head);
    printList(head);
}


