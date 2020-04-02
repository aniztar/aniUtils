#include "linkedList.h"

/*
  Function Description: Adding elements at the end of the list
  Parameters passed:    Head of the list and the element to be added
  Return value:         
*/
int append(intNode **head, int value)
{
  intNode *temp, *node;
  temp = *head;
  if(*head == NULL)
  {
    printf("List is empty! Creating one and adding the element to it..\n");
    *head = (intNode*) malloc(sizeof(intNode));
    (*head)->value = value;
    (*head)->next = NULL;
    printList(*head);
    return 0;
  }
  /*Traversing the list till the end*/
  while(temp->next != NULL) temp = temp->next;

  /*Creating a node and filling in values*/
  node = (intNode*) malloc(sizeof(intNode));
  node->value = value;
  node->next = NULL;

  /*Linking the node to the end of the list*/
  temp->next = node;
  printList(*head);

  return 0;
}

/*
  Function Name:        delete
  Function Description: Removing elements from the list
  Parameters passed:    Head of the list and the element to be removed
  Return value:         Returns the new head
*/
intNode* delete(intNode *head, int value)
{
  intNode *temp, *temp2;
  if(head == NULL)
  {
    printf("List is empty! Please insert something!\n");
    return 0;
  }
  if(head->value == value)
  {
    temp = head;
    head = head->next;
    free(temp);
    printList(head);
    return head;
  }
  temp = head->next;
  temp2 = head;
  while(temp != NULL)
  {
    if(temp->value == value)
    {
      temp2->next = temp->next;
      free(temp);
      printf("Deleted the number %d from the list!\n", value);
      printList(head);
      return head;
    }
    temp2 = temp;
    temp = temp->next;
  }
  printf("The element %d is not found in the list!\n", value);
  return head;
}

/*
  Function Name:        printList
  Function Description: Printing elements of the list and the number of elements
  Parameters passed:    Head of the list
  Return value:         Returns the number of elements in the list
*/
int printList(intNode *head)
{
  int count = 0;
  intNode *temp;
  temp = head;
  if(head == NULL)
  {
    printf("List is empty!\n");
    return 0;
  }
  printf("\nThe list: ");
  while (temp != NULL)
  {
    printf("%d ", temp->value);
    count++;
    temp = temp->next;
  }
  printf("\n");
  printf("Number of elements in the list: %d\n", count);
  return count;
}

/*
  Function Name:        reverseList
  Function Description: Reverses the elements of the list
  Parameters passed:    Pointer to the head of the list
  Return value:         Returns pointer to the new head of the list
*/

intNode* reverseList(intNode* head)
{
  intNode *newHead, *previous, *current, *next;
  if (head == NULL)
  {
    printf("List is empty!");
    return head;
  }

  previous = NULL;
  current = head;
  next = head->next;

  while(next != NULL)
  {
    current->next = previous;
    previous = current;
    current = next;
    next = next->next;
  }
  current->next = previous;
  newHead = current; 
  printf("List reversed!");
  printList(newHead);
  return newHead;
}

intNode* getMiddle(intNode* head) 
{
  if (head == NULL || head->next == NULL) return head;
  intNode *slow, *fast;
  slow = fast = head;
  while(fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
