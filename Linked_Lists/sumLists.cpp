#include "ll.h"
#include <iostream>

using namespace std;

struct Node* sumLists(struct Node* list1, struct Node* list2)
{
    struct Node* tmp, *prev=NULL;
    struct Node* res = NULL;
    int sum = 0;
    int carry = 0;
    while( list1 != NULL || list2 != NULL)
    {
        sum = (list1 ? list1->data : 0) + (list2 ? list2->data : 0) + carry;
        if(sum >=10)
            carry = 1;
        else
            carry = 0;
        sum = sum % 10;
        tmp = newNode(sum);
        if(res == NULL)
            res = tmp;
        else
            prev->next = tmp;
        prev = tmp;
        if(list1)
            list1 = list1->next;
        if(list2)
            list2 = list2->next;
    }
    if(carry)
        prev->next = newNode(1);
    return res;
}


int main()
{

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    push(&list1, 5);
    push(&list1, 9);
    push(&list1, 4);
    printList(list1);
    push(&list2, 4);
    push(&list2, 6);
    push(&list2, 7);
    printList(list2);
    std::cout << endl;
    printList(sumLists(list1, list2));
    std::cout << endl ;


}
