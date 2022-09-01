#include<stdio.h>
#include<conio.h>
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue_rear()
{
    int val;
    if(front == rear + 1 || (front == 0 && rear == SIZE-1))
    {
        printf("Queue is Overflow");
        return;
    }

    if(front == -1 && rear == -1)
    {
        front++;
    }
    printf("Enter the value to insert==> ");
    scanf("%d", &val);
    //when rear becomes 4 ==> (4+1) % 5 will not happen because the full condition is fulfiled
    rear = (rear + 1) % SIZE;
    queue[rear] = val;
}


void enqueue_front()
{
    int val;
    if(front == rear + 1 || (front == 0 && rear == SIZE-1))
    {
        printf("Queue is Overflow");
        return;
    }
    printf("Enter the value to insert==> ");
    scanf("%d", &val);
    //when rear becomes 4 ==> (4+1) % 5 will not happen because the full condition is fulfiled
    if(front == -1 && rear == -1)
    {
        rear++;
        front++;
    }
    else if(front==0) 
    {
        front = SIZE-1;
    }
    else
    {
        front--;
    }
    queue[front] = val;
}

void dequeue_front()
{
    if(front==-1 && rear ==-1)
    {
        printf("Underflow");
        return;
    }
    printf("Dequeued element==> %d", queue[front]);
    if(front==rear) // When only one element exist in the queue
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void dequeue_rear()
{
    if(front==-1 && rear ==-1)
    {
        printf("Underflow");
        return;
    }
    printf("Dequeued element==> %d", queue[rear]);
    if(front==rear) // When only one element exist in the queue
    {
        front = -1;
        rear = -1;
    }
    else if(rear==0)
    {
        rear = SIZE-1;
    }
    else
    {
        rear = rear-1;
    }
}

void display()
{
    int i = front;

    printf("Elements in the queue are==> ");
    while(i != rear)
    {
        printf("%d ",queue[i]);
        i = (i+1) % SIZE;
    }
    printf("%d ",queue[i]);

    printf("\nFront==> %d", front);
    printf("\nRear==> %d", rear);
}


void main()
{
    int op = 0;
    while(op != 6)
    {
        printf("\n\n1==> Enqueue from front");
        printf("\n2==> Enqueue from rear");
        printf("\n3==> Dequeue from front");
        printf("\n4==> Dequeue from rear");
        printf("\n5==> Display");
        printf("\n6==> Exit");
        printf("\nEnter your option==> ");
        scanf("%d",&op);

        switch(op)
        {
            case 1: 
                    enqueue_front();
                    break;
            
            case 2: 
                    enqueue_rear();
                    break;

            case 3: 
                    dequeue_front();
                    break;

            case 4: 
                    dequeue_rear();
                    break;

            case 5: 
                    display();
                    break;

            case 6: 
                    printf("Exiting!!!");
                    break;

            default:
                    printf("Enter valid option");
                    break;
        }
    }
    
}