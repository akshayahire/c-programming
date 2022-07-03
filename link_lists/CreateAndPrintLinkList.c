/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LLSIZE 5 //link list size
typedef struct linkedListNode_t linkedListNode_t;
struct linkedListNode_t
{
    int data;
    linkedListNode_t *next;
};

/*
* @brief Create link list nodes
*/
linkedListNode_t* createLLNode(int data)
{
    linkedListNode_t* node = (linkedListNode_t*) malloc(sizeof(linkedListNode_t));
    node->data = data;
    node->next = NULL;
}

/*
* @brief Deallocate memory of link list nodes
*/

void freeLLNode(linkedListNode_t* node)
{
    while(node != NULL)
    {
        linkedListNode_t* temp;
        temp = node;
        node = node->next;
        free(temp);
    }
}

/*
* @brief Print all link list nodes
*/
void printLLNode(linkedListNode_t* node)
{
    while(node != NULL)
    {
        printf("%d--> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

int main()
{
    // Create head node
    linkedListNode_t* head = createLLNode(0);
    // Create link list
    linkedListNode_t* currentNode;
    currentNode = head;
    for(int node_idx=1; node_idx < LLSIZE; node_idx++)
    {
        linkedListNode_t* temp = createLLNode(node_idx);
        currentNode->next = temp; // Update next pointer to link list
        currentNode = temp; // Set next LL node as current node
    }
    
    // print nodes
    printLLNode(head);
    // Free nodes
    freeLLNode(head);
    return 0;
}
