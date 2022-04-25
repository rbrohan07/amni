#include <stdio.h>
#include <stdlib.h>
#define max 9
int stack[max];
int top = -1;
int data, i;
void push()
{
    if (top == max-1)
    {
        printf("stack overflow");
    }
    else
    {
        printf("enter data");
        scanf("%d", &data);
        top++;
        stack[top] = data;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("STACK UNDER FLOW ");
    }
    else
    {
        printf("poped element =%d ", stack[top]);
        top--;
    }
}
void displaylist()
{
    if (top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
}

int main()
{
    int choice;

  
    while (1)
    {  printf("\nenter choice \n");
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
        break;
    }
}

return 0;
}