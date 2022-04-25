#include <stdio.h>
#include <stdlib.h>
void createlist();
void displaylist();
void insertatfirst();
void insertatlast();
void insertatanyposition();
void deletefirst();

typedef struct node
{
  int data;
  struct node *next;

} node;
node *head=NULL;

void createlist()
{
  int data, num;
  node *temp, *newnode;
  temp = (node *)malloc(sizeof(node));

  head = (node *)malloc(sizeof(node));
  if (head == NULL)
  {
    printf("MEmory allocation not possible ");
  }
  else
  {
    printf("enter how many value you want to enter ");

    scanf("%d", &num);
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;
    //  printf("%d",temp->data);
    for (int i = 0; i < num - 1; i++)

    {
      scanf("%d", &data);
      newnode = (node *)malloc(sizeof(node));
      if (newnode == NULL)
      {
        printf("MEmory allocation not possible ");
      }
      else
      {
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
      }
    }
  }
}

// ***********************************************************************

void displaylist(void)
{
  node *temp;
  //   temp=(node*)malloc(sizeof(node));
  if (head == NULL)
  {
    printf("no data");
  }
  else
  {
    temp = head;
    do
    {

      printf("%d  ", temp->data);
      temp = temp->next;

    } while (temp != NULL);
  }
}

// ***********************************************************************

void insertatfirst()
{

  int data;
  node *newnode;
  newnode = (node *)malloc(sizeof(node));
  if (newnode == NULL)
  {
    printf("MEmory allocation not possible ");
  }
  else
  { printf("enter data :");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = head;
    head = newnode;
  }
  //  printf("2");

  // ***********************************************************************
}
void insertatlast(void)
{
  int data;
  node *temp, *lastnode, *newnode;
  newnode = (node *)malloc(sizeof(node));
  if (newnode == NULL)
  {
    printf("MEmory allocation not possible ");
  }
  else
  {

    temp = head;
    while (temp != NULL)
    {
      lastnode = temp;
      temp = temp->next;
    }
    lastnode->next = newnode;
    printf("enter data :");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
  }
}
void insertatanyposition()
{
  struct node *newnode, *temp = head;
  int data, position, count = 0;
  newnode = (node *)malloc(sizeof(node));


  printf("enter postion for insert ");
  scanf("%d", &position);
  while (temp != NULL)
  {
    temp = temp->next;
    count++;
  }
  if (position > count)
  {
    printf("you have entered wrong position");
  }
  else if(position==1)
  {
    insertatfirst();
  }

  else
  { printf("enter data for insert ");

  scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    for (int i = 2; i < position; i++)
    {
      temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
  }
}

void deletefirst()
{
  if (head == NULL)
  {
    printf("NO DATA");
  }
  else
  {
    node *temp;
    temp = head;

    head = head->next;
    temp->next = NULL;
    free(temp);
  }
}

void deletelast()
{
  if (head == NULL)
  {
    printf("NO DATA");
  }
  else
  {
    node *temp, *p;
    temp = head;
    while (temp->next != NULL)
    {
      p = temp;
      temp = temp->next;
    }
    p->next = NULL;
    free(temp);
  }
}
void deleteatany()
{
  if (head == NULL)
  {
    printf("NO DATA");
  }
  else
  {
    int pos;
    struct node *temp = head, *p;
    printf("enter the position :");
    scanf("%d", &pos);
    if (pos == 1)
    {
      deletefirst();
    }
    else
    {
      for (int i = 1; i < pos; i++)
      {
        p = temp;
        temp = temp->next;
      }
      p->next = temp->next;
      temp->next = NULL;
      free(temp);
    }
  }
}
void deleteall()
{
  struct node *temp;
  if (head == NULL)
  {
    printf("NO DATA");
  }
  else
  {

    while (head != NULL)
    {
      temp = head;
      head = temp->next;
      temp->next = NULL;
      free(temp);
    }
  }
}

// -___---_____----___---_---__----__---__---___----_______-----_____

int main()
{
  int choice;
  printf("enter\n1 for create list \n2 for displaylist \n3 for  insert at first\n4 for insert at last\n5 for insert at any position \n6 for delete at first\n7 for delete at last\n8 for delete all nodes\n9 for delete any node\n0  for exit \n");

  while (1)

  {
    printf("\nenter choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      createlist();
      break;
    case 2:
      displaylist();
      break;
    case 3:
      insertatfirst();
      break;
    case 4:
      insertatlast();
      break;
    case 5:
      insertatanyposition();
      break;
    case 6:
      deletefirst();
      break;
    case 7:
      deletelast();
      break;
    case 8:
      deleteall();
      break;
    case 9:
      deleteatany();
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