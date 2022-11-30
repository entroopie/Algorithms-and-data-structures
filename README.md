# Algorithms-and-data-structures
Simple algorithms and data structures implemented during laboratory classes.

# Heap
Implement a max/min heap and the following operations:
+ v (add a number v to the heap)
- (remove the maximum from the max heap (minimum from the min heap respectively) and write it on the screen)
p (write all elements of the heap in the order in which they are stored in an array)
r n v1 ...vn (remove all elements from the heap and create a heap out of n new elements, of the values given by v1 ...vn)
s (change the orientation of the heap – from max to min or from min to max; s operation can be requested multiple times)
q (exit the program)

Additional remarks:
Operation 'r' is not the same as a sequence of '+' operations.
If both children are equal the child of the lesser index is swapped.
Using the std::vector class is forbidden.

# BST
Implement a binary search tree (BST). Each element of a tree should have a key (unsigned integer).

Your program should support the following operations:
+ - add a new element with a given key to the tree,
- - remove an element with a given key from the tree (ignore this operation if there is no such an element in the tree),
? - search the tree for an element with a given key, write '1' if the element was found, or '0' if not,
m - write the key of the minimum element in the tree,
M - write the key of the maximum element in the tree,
q - quit the program.

# Linked list FIFO
Implement a linked list. Every element of the list should contain a key of type int (signed integer), and some pointers that are required by your linked list implementation.

Your program should support the following operations:
i - insert a new element to the end of your list,
d - delete an element from the beginning of your list,
s - search for an element of the list with a given key, and return its index or -1 if the element was not found (if there are multiple elements with the same key, the smallest of the indices should be returned),
q - deallocate memory and quit the program.

The first element (head) of your list should be interpreted as an element on position 0, the second element is on position 1, etc.
