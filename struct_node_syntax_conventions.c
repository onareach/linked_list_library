#include <stdio.h>

// People have asked why the word "struct node" appears twice in the struct declaration below – both
// before the {} and inside the {}. From what I can gather, the "struct node" inside the {}
// is not recursive – that is, it is not calling itself. Instead, you can think of it as a 
// qualifier of the "*next" member. In short, it's telling you that the *next member is the
// pointer variable for the struct. In other words, *next is not just any pointer, but THE
// pointer in struct that points to the next node. I prefer to think of "struct node *" as
// the datatype declaration for whatever variable name it appears in front of. In other words,
// "struct node *" is to "next" as "int" is to "value".
// It's useful to know that in C++ the need for the "struct" keyword inside the {} was eliminated. 
// However, in C++, you still see "struct" inside the "struct node" declaration in C++ either 
// because it is ignorantly copied or, better, because it makes the code backward-compatible with C.
typedef struct node {
    int value;
    stuct node * next;
} Node


void main()
{
    // In the declaration below, the Node (struct) datatype is followed by a declaration of the 
    // name of a pointer to its head node. Later, if you want to operate on the list, you
    // simply place the phrase " list1_head = " (with no *) before the name of the function
    // that operates on it. There's nothing special about the name "list1_head" but the naming
    // identifies this as "list 1" out of possibly many lists used in the code, and "head" is a
    // reminder that this variable points to the head node of list1. Why the = sign? Again, 
    // mainly out of convention. The = sign is simply an efficient way of linking the list1_head
    // pointer to the function that is going to operate on it. Personally, I might use the 
    // symbol <=> as a way of associating the list with the function that is to operate on it,
    // but that would involve three characters ( < and = and > )instead of one (=).
    Node *list1_head = NULL;

    return 0;
}
