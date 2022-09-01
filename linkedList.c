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
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for Node==> ");
    scanf("%d",&data);
    new_node->data = data;
    new_node->next=NULL;
    head = new_node;
    tail = new_node;
}

void insert_at_begin()
{
    int data;
    if(head==NULL)
    {
        create();
    }
    else
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for Node==> ");
        scanf("%d",&data);
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_end()
{
    if(head==NULL)
    {
        create();
    }
    else
    {
        int data;
        temp = head;
        while(temp->next != NULL)  //Traversing to the end node
        {
            temp = temp->next;
        }
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for Node==> ");
        scanf("%d",&data);
        new_node->data = data;
        new_node->next = NULL;
        temp->next = new_node; 
    }
}

struct node* node_at_index(int index)
{
    //We are not checking if the linked list is empty or not. We will have to deal with it in the function we callig from
    // Nor do we consider if the index is 0 that being head
    int count = 1;
    temp = head;
    if(index!=0)
    {
        while (count<=index & temp->next!=NULL)     //We are assuming that if the index is out of bound
        {                                            // we return the last node instead of creating error
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL) return NULL;
        // printf("\n%d index doesn't exist hence pointing towards last node", index);
    }
    return temp;
}

void insert_at_index()
{
    int index,data;         
    if(head==NULL)          // Incase the linked list is empty
    {
        printf("Linked list is null.");   
        create();
        return;
    } 
    printf("\nEnter the index you want to insert your data at==> ");
    scanf("%d", &index);
    if(index==0)
    {
        insert_at_begin();
        return;
    }
    temp = node_at_index(index-1);
    if(temp==NULL)                      //Incase if the index doesn't exist
    {
        printf("This index doesn't exist");
        return;
    }

    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for Node==> ");
    scanf("%d", &data);
    new_node->data = data;
    if(temp->next==NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = temp->next;
    }
    temp->next=new_node;
}

void insert_before()
{
    int val_search, data, flag=0;
    struct node *ptr_prev, *ptr;
    new_node = (struct node*)malloc(sizeof(struct node));
    ptr_prev = head;
    ptr = head;
    printf("Enter the value you want to insert before==> ");
    scanf("%d",&val_search);

    if(val_search==ptr->data)
    {
        insert_at_begin();
        return;
    }

    while(ptr!=NULL)
    {
        if(ptr->data==val_search)
        {
            flag=1;
            break;
        }
        ptr_prev = ptr;
        ptr = ptr->next;
    }

    if(flag==0)
    {
        printf("%d does not exist in the linked list", val_search);
        return;
    }

    printf("Enter the data==> ");
    scanf("%d", &data);
    new_node->data = data;
    ptr_prev->next = new_node;
    new_node->next = ptr;
}

void insert_after()
{
    int val_search, data, flag=0;
    struct node *ptr;
    new_node = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    printf("Enter the value you want to insert after==> ");
    scanf("%d",&val_search);

    while(ptr!=NULL)
    {
        if(ptr->data==val_search)
        {
            flag=1;
            break;
        }
        ptr = ptr->next;
    }

    if(flag==0)
    {
        printf("%d does not exist in the linked list", val_search);
        return;
    }
    
    printf("Enter the data==> ");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void del_first()
{
    if(head==NULL)
    {
        printf("Linked list is empty");
        return;
    }
    temp = head->next;
    free(head);
    head = temp;
}

void del_last()
{
    struct node *preptr, *ptr;
    if(head == NULL) 
    {
        printf("LInked list is empty");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }

    ptr = head;
    preptr = head;
    
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    free(ptr);
    preptr->next = NULL;
}

void del_data()
{
    int data, flag=0;
    struct node *ptr, *preptr;
    if(head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    printf("Enter the data==> ");
    scanf("%d",&data);
    if(head->data == data)
    {
        del_first();
    }
    ptr = head;
    preptr = head;

    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            preptr->next = ptr->next;
            free(ptr);
            flag=1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    if(flag==0) printf("%d doesn't exist in the linked list", data);
}

void count()
{
    int count=0;
    temp = head;
    if(head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Count==> %d", count);
}

void show()
{
    if(head==NULL)
    {
        printf("Linked List is empty");
        return;
    }
    temp = head;
    while(temp!=NULL)
    {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
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
        printf("\n3==> Insert at Position");
        printf("\n4==> Insert Before");
        printf("\n5==> Insert After");
        printf("\n6==> Delete First Node");
        printf("\n7==> Delete last Node");
        printf("\n8==> Delete given Node");
        printf("\n9==> Show Linked List");
        printf("\n10==> Count the number of nodes");
        printf("\n11==> Insert in ascending order");
        printf("\n12==> Exit");
        printf("\nEnter your option==> ");
        scanf("%d",&op);
        switch (op)
        {
            case 1 : insert_at_begin();
                break;

            case 2 : insert_at_end();
                break;

            case 3 : insert_at_index();
                break;

            case 4 : insert_before();
                break;

            case 5 : insert_after();
                break;
            
            case 6 : del_first();
                break;
            
            case 7 : del_last();
                break;
            
            case 8 : del_data();
                break;

            case 9 : show();
                break;

            case 10 : count();
                break;

            case 11 : insert_ascending();
                break;

            case 12 : printf("\nExiting!!!");
                break;

            default : printf("\nInvalid Input");
                break;
        }
    }
}

