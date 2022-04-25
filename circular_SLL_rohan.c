#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} node;
node *head = NULL;

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
    }
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
    temp->next = head;
}
void displayList()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("No data found.\n");
        return;
    }

    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}
void insertatanyposition()
{
    struct node *newnode, *temp = head->next;
    int data, position, count = 1;
    newnode = (node *)malloc(sizeof(node));

    printf("enter postion for insert ");
    scanf("%d", &position);
    while (temp != head)
    {
        temp = temp->next;
        count++;
    }
    if (position > count)
    {
        printf("you have entered wrong position");
    }
    //   else if(position==1)
    //   {
    //     insertatfirst();
    //   }

    else
    {
        printf("enter data for insert ");

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
void insert_at_last()
{
    int data,count=0;
    struct node*temp=head->next,*newnode;
         printf("enter data for insert ");

        scanf("%d", &data);
          while (temp ->next!= head)
    {
        temp = temp->next;
        
    }
    
    newnode = (node *)malloc(sizeof(node));
      newnode->data = data;

       newnode->next = temp->next;
        temp->next = newnode;
}
int main()
{
    createlist();
    displayList();

    insertatanyposition();
   
    insert_at_last(); 
    displayList();
    return 0;
}
