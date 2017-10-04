#include "tree.h"
#include <iostream>

using namespace std;

struct node* createMinimalTree(int arr[], int low, int high)
{
    if(low > high)
        return NULL;
    int mid = (low+high)/2;
    struct node* root = newNode(arr[mid]);

    root->left = createMinimalTree(arr, low, mid-1);
    root->right = createMinimalTree(arr, mid+1, high);

    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct node* root = createMinimalTree(arr, 0, n-1);
    printLevelOrder(root);
    return 0;
}
