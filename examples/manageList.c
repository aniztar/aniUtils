#include "linkedList.h"
int main()
{
  int choice;
  intNode *head = NULL;
  while(1)
  {
    printf("\nWhat do you want to do?\n\n");
    printf("1. Create a List\n2. Append Elements\n3. Delete node\n4. Reverse list\n5. Print list\n6. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
      int value;
      printf("Enter the value of the first element: \n");
      scanf("%d", &value);
      head = (intNode*) malloc(sizeof(intNode));
      head->value = value;
      head->next = NULL;
      printf("List created!");
    }
    else if (choice == 2)
    {
      int value;
      printf("Enter the element you want to add: \n");
      scanf("%d", &value);
      append(&head, value);
    }
    else if (choice == 3)
    {
      int number;
      printf("Enter the number to be deleted: \n");
      scanf("%d", &number);
      head = delete(head, number);
    }
    else if (choice == 4)
    {
      head = reverseList(head);
    }
    else if(choice == 5)
    {
      printList(head);
    }

    else if(choice == 6)
    {
      printf("Exiting!\n");
      exit(1);
    }
  }
  return 0;
}
