#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
  int data;
  struct nodes *prev;
  struct nodes *next;
} node;
node *head = NULL;
node *last = NULL;

void displaylist(void)
{
  node *temp;
  //   temp=(node*)malloc(sizeof(node));
  temp = head;
  do
  {

    printf("%d  ", temp->data);
    temp = temp->next;

  } while (temp != NULL);
}

void create_list()
{
  node *newnode;
  int data, no_of_node;
  head = (node *)malloc(sizeof(node));
  printf("the number of nodes : ");

  scanf("%d", &no_of_node);
  printf("enter first data ");
  scanf("%d", &data);

  head->data = data;
  head->prev = NULL;
  head->next = NULL;
  last = head;
  for (int i = 0; i < no_of_node - 1; i++)
  {
    newnode = (node *)malloc(sizeof(node));
    printf("enter data ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->prev = last;
    newnode->next = NULL;
    last->next = newnode;
    last = newnode;
  }
}

void displayFromLast()
{
  node *temp = last;
  printf("\n");
  while (temp != NULL)
  {
    printf("%d  ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}
void insert_at_any_position()
{
  int data, pos, i, count = 0;
  node *newnode, *temp = head;

  printf("enter data");
  scanf("%d", &data);
  printf("enter position(except 1");
  scanf("%d", &pos);
  while (temp != NULL)
  {
    temp = temp->next;
    count++;
  }
  if (count < pos)
  {
    printf(" wrong position :!!!!!");
  }
  else
  {
    temp = head;
    for (i = 2; i < pos; i++)
    {
      temp = temp->next;
    }
    newnode = (struct nodes *)malloc(sizeof(struct nodes));

    newnode->data = data;
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;

    printf("\n");
  }
}
void insert_at_first()
{
  int data;
  node *newnode;
  printf("enter data");
  scanf("%d", &data);
  newnode = (struct nodes *)malloc(sizeof(struct nodes));

  newnode->data = data;
  newnode->prev = NULL;
  newnode->next = head;
  head->prev = newnode;
  head = newnode;
}
void deleteanynode()
{
  int pos, len = 0;
  node *temp = head, *p;
  printf("\nenter position for deletion ");
  scanf("%d", &pos);
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  if (pos > len)
  {
    printf("!!!!!!!!!!!!♥wrong choice!!!!!!!!!!!!!!");
  }

  else if (pos == 1)
  {
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
  }

  else
  {
    for (int i = 2; i < pos; i++)
    {
      p = temp;
      temp = temp->next;
    }
    p = temp->next;
    // not working logic--------->>>----->>..'.'.'.'.'.'.'.'.'.'.'.'.'_')'
    // p=temp;
    // temp=temp->next;
    // temp->prev=p->prev;
    // // temp=p;

    temp->next = (temp->next)->next;
    temp = temp->next;
    temp->prev = (temp->prev)->prev;
    temp = p;
    temp->next = NULL;
    free(temp);
    free(p);
  }
}
void delete_last()
{
  node *temp;
  temp = last;
  last = last->prev;
  last->next = NULL;
  temp->prev = NULL;
  free(temp);
}

int main()
{
  int choice;
  printf("enter\n1 for create list \n2 for displaylist \n3 for  insert at first\n4 for display from last\n5 for insert at any position\n6 for delete last node\n9 for delete any node\n0  for exit \n");

  while (1)

  {
    printf("\nenter choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      create_list();
      break;
    case 2:
      displaylist();
      break;
    case 3:
      insert_at_first();
      break;
    case 4:
      displayFromLast();
      break;
    case 5:
      insert_at_any_position();
      break;
    case 6:
      delete_last();
      break;
    case 9:
      deleteanynode();
      break;
    case 0:
      exit(0);
      break;
    default:
      exit(0);
      break;
    }
  }
  return 0;
}
