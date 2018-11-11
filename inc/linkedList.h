#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int value;
   struct node *next;
}intNode;

int append(intNode **head, int value);

intNode* delete(intNode *head, int value);

intNode* reverseList(intNode* head);

int printList(intNode *head);
