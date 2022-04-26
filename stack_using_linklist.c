#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} node;
node *top = NULL;
void push()
{
    int data;
    node *newnode;
        printf("enter data");
        scanf("%d", &data);
        newnode = (node *)malloc(sizeof(node));

        if (newnode == NULL)
        {printf("MEmory allocation not possible\\stack FULL!!! ");}
// /not mandatory 

        newnode->data = data;
        newnode->next = top;
        top = newnode;
    
}

void pop()
{
    if (top == NULL)
    {
        printf("stack underflow!!! ");
    }
    else
    {    printf("deleteed  data is: %d",top->data);

        node *temp;
        temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
    }
}
void displaylist()
{
    if (top == NULL)
    {
        printf("stack Underflow!!! ");
    }
    else
    {
        node *temp;

        temp = top;
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\nenter choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 3:
            displaylist();
            break;
        case 2:
            pop();
            break;
        case 0:
            exit(0);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}