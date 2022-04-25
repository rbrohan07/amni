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
    temp=head;
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
{int data;
  node *newnode;
  printf("enter data");
  scanf("%d", &data);
    newnode = (struct nodes *)malloc(sizeof(struct nodes));

    newnode->data = data;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;



}
int main()
{
  create_list();

  displaylist();

  printf("");
  insert_at_any_position();
  insert_at_first();
  // create_list();
  displaylist();
  displayFromLast();
  
  return 0;
}