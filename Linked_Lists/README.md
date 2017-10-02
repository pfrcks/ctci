### Notes

#### Remove Duplicates (+)

Create a hash. Keep a pointer which holds the previous node. If the current node exists in hash then unlink it from the linked list.

#### Return Kth to Last (+)

Instead we can return (N-K+1) from the beginning ;)

#### Delete Middle Node

Swap the data with the next node. Delete next node.

#### Partition

Maintain three linked lists(equal, less and greater).

#### Sum Lists (+)

Traverse both linked lists and put the sum of the data of both as a new node of a new linked list. Keep track of carry through the iteration between nodes.

- [ ] TODO: Digits stored in forward order.

#### Palindrome (+)

```
- Find the middle node using the slow and fast pointer technique.
- Reverse the second half of the linked list.
- Compare both halves.
- Reverse the second half again and append back to the first half
```
#### Intersection (+)

```
- Find the difference in lengths of both linked lists.
- Traverse the difference in the longer linked list.
- Traverse in both linked lists simultaneously checking for equality of nodes.
```

The inuition for this lies in the fact that after the intersection both of the linked lists share the same nodes. Therefore if we exclude the extra nodes that the bigger linked list has, both the linked list will definitely test positive for common nodes.


#### Loop Detection (and Removal) (+)

```
- Find the loop using fast and slow pointers technique.
- Count the number of nodes in the loop by moving slow pointer and keeping fast stationary
- Initialize a new node advance to the head of the linked list and iterate using it (loop node) times.
- Iterate using both advance and slow pointer simultaneously and check for equality. They **will meet at the point where the loop begins**.Initialize a new point prev which tracks previous of slow pointer.
- When advance equals slow(the nodes not the values), change next of prev to NULL thereby breaking the loop.
```

