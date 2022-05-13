#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
node *front = NULL;
node *rear = NULL;
void insert()
{
    node *temp;
    int data;

    if (front == NULL)
    {
        printf("enter data ");
        scanf("%d", &data);
        temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        front = temp;
        rear = temp;
    }
    else
    {
        printf("enter data ");
        scanf("%d", &data);
        temp = (node *)malloc(sizeof(node));
        temp->data = data;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
}
void display()
{
    if (front == NULL)
    {
        printf("queue underflow \n");
    }
    else
    {
        node *temp;
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void delete_data()
{
    if (front == NULL)
    {
        printf("queue underflow \n");
    }
    else
    {
        node *temp;
        temp = front;
        printf(" \nvalue  is deleted %d:\n", temp->data);
        front = front->next;
        free(temp);
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
            insert();
            break;
        case 3:
            display();
            break;
        case 2:
            delete_data();
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