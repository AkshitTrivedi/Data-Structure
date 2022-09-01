#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*new_node, *temp, *head, *tail;


void create()
{
    
}

void insert_at_begin()
{
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for Node==> ");
    scanf("%d",&data);
    new_node->data = data;
    
    if(head==NULL)
    {
        new_node->next = new_node;
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
        tail->next = head;
    }
}

void insert_at_end()
{
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for Node==> ");
    scanf("%d",&data);
    new_node->data = data;
    
    if(head==NULL)
    {
        new_node->next = new_node;
        head = new_node;
        tail = new_node;
    }
    else
    {
        int data;
        temp = head;
        while(temp->next != head)  //Traversing to the end node
        {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        tail = new_node;
    }
}


void del_first()
{
    if(head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    if(head->next == head)
    {
        free(head);
        tail = NULL;
        head = NULL;
        return;
    }
    temp = head->next;
    free(head);
    head = temp;
    tail->next = head;
}

void del_last()
{
    struct node *preptr, *ptr;
    if(head == NULL) 
    {
        printf("LInked list is empty");
        return;
    }
    if(head->next==head)
    {
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }

    ptr = head;
    preptr = head;
    
    while(ptr->next != head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    preptr->next = head;
    tail = preptr;
}


void show()
{
    if(head==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    temp = head;
    
    do
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("NULL");
}

void insert_ascending()
{
    int data;
    struct node *ptr, *preptr;
    ptr = head;
    preptr = head;
    if(head == NULL)
    {
        create();
        return;
    }
    printf("Enter the data==> ");
    scanf("%d", &data);
    new_node = (struct node*)malloc(sizeof(struct node));
    while(ptr != NULL && ptr->data <= data )
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    new_node->data = data;
    new_node->next = ptr;
    if(head->data >= data)
    {
        head = new_node;
        return;
    }
    preptr->next = new_node;
}

void main()
{
    int op=0;
    while(op!=12)
    {
        printf("\n\n1==> Insert at begining");
        printf("\n2==> Insert at end");
        printf("\n3==> Delete First Node");
        printf("\n4==> Delete last Node");
        printf("\n5==> Show Linked List");
        printf("\n6==> Exit");
        printf("\nEnter your option==> ");
        scanf("%d",&op);
        switch (op)
        {
            case 1 : insert_at_begin();
                break;

            case 2 : insert_at_end();
                break;

            case 3 : del_first();
                break;
            
            case 4 : del_last();
                break;
            
            case 5 : show();
                break;

            case 6 : printf("\nExiting!!!");
                break;

            default : printf("\nInvalid Input");
                break;
        }
    }
}

