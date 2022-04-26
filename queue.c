#include<stdio.h>
#include<stdlib.h>
#define max 50
int front=-1;
int rear=-1;
int queue[max];

void enqueue()
{
    int data;
    printf("enter data ");
    scanf("%d", &data);
    if(rear>=(max-1))
    {
        printf(" queue overflow");
    }
    else if(rear==-1 && front==-1)
    {
        front=0;
        rear=0;
        queue[rear]=data;
    }
    else{
        rear=rear+1;
          queue[rear]=data;
    }

}
void dequeue()
{if((rear==-1 && front==-1)|| front>rear)
    {
        printf("queue underflow \n");
    }
    else
    {
        printf("%d: value  is deleted \n",queue[front]);
        front++;
    }
}
void displaylist()
{
    for (int  i = front; i <= rear; i++)
    {
        printf("%d: ",queue[i]);       
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
            enqueue();
            break;
        case 3:
            displaylist();
            break;
        case 2:
            dequeue();
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