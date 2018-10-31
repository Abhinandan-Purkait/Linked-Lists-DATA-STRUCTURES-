#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*start,*tail;

int count()
{
    struct node *p;
    p=start;
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void insert_at_end()
{
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a value : ");
    scanf("%d",&(temp->data));
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
        tail=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
        temp->prev=p;
        tail=temp;
    }
}

void insert_at_beg()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a value : ");
    scanf("%d",&(temp->data));
    temp->next=NULL;
    if(start==NULL)
    {
        temp->prev=NULL;
        start=temp;
        tail=temp;
    }
    else
    {
        temp->prev=NULL;
        start->prev=temp;
        temp->next=start;
        start=temp;
        while(temp->next!=NULL)
            temp=temp->next;
        tail=temp;
    }
}

void insert_at_pos_from_beg()
{
    printf("\nEnter the insert index : ");
    int n,i;
    scanf("%d",&n);
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    if(n==0)
        insert_at_beg();
    else if(n<(count()-1))
    {
        printf("\nEnter a value : ");
        scanf("%d",&(temp->data));
        p=start;
        for(i=0;i<n;i++)
            p=p->next;
        temp->prev=p;
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
    }
    else if(n==(count()-1))
        insert_at_end();
    else
    printf("\nInvalid Location !!\n");

}

void insert_at_pos_from_end()
{
    printf("\nEnter the insert index : ");
    int n,i;
    scanf("%d",&n);
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->prev=NULL;
    if(n==0)
        insert_at_end();
    else if(n<(count()-1))
    {
        printf("\nEnter a value : ");
        scanf("%d",&(temp->data));
        p=tail;
        for(i=0;i<n;i++)
            p=p->prev;
        temp->next=p;
        temp->prev=p->prev;
        p->prev->next=temp;
        p->prev=temp;
    }
    else if(n==(count()-1))
        insert_at_beg();
    else
    printf("\nInvalid Location !!\n");

}

void delete_from_beg()
{
    struct node *temp;
    temp=start;
    start=temp->next;
    start->prev=NULL;
    free(temp);
    printf("\nDeleted  +_._+\n");
}

void delete_from_end()
{
    struct node *temp;
    temp=tail;
    temp->prev->next=NULL;
    tail=temp->prev;
    free(temp);
    printf("\nDeleted  +_._+\n");
}

void delete_a_pos()
{
    int n,i;
    printf("\nEnter the index to delete : ");
    scanf("%d",&n);
    struct node *temp;
    temp=start;
    if(n==0)
        delete_from_beg();
    else if(n<(count()-1))
    {
        for(i=0;i<n;i++)
        temp=temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        printf("\nDeleted  +_._+\n");
    }
    else if(n==(count()-1))
        delete_from_end();
    else
        printf("\nInvalid index !!\n");

}
void traversal_forward()
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void traversal_reverse()
{
    struct node *p;
    p=tail;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->prev;
    }
}

void reverse()
{
    struct node *q,*p;
    p=start;q=tail;
    int c=count();
    c=c/2;
    while(c!=0)
    {
        int temp=p->data;
        p->data=q->data;
        q->data=temp;
        p=p->next;
        q=q->prev;
        c--;
    }
    printf("\nReverse Sucessful\n");
}

void sort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void main()
{
    start=NULL;tail=NULL;
    int n,num,i;
    printf("\n__________________________DOUBLY LINKED LIST_______________________");
    while(1)
    {
        printf("\n1 : Add Elements From Beginning\n2 : Add Elements from End");
        printf("\n3 : Add Element at a Particular Index From Begining\n4 : Add Element at a Particular Index From End");
        printf("\n5 : Forward Traversal\n6 : Reverse Traversal\n7 : Delete a Node From Begining");
        printf("\n8 : Delete a Node from End\n9 : Delete a Node at a Particular Index");
        printf("\n10 : Reverse the linked list\n11 : Sort the list\n12 : Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                insert_at_beg();
            }
            break;
            case 2:
            {
                insert_at_end();
            }
            break;
            case 3:
            {
                insert_at_pos_from_beg();
            }
            break;
            case 4:
            {
                insert_at_pos_from_end();
            }
            break;
            case 5:
            {
                traversal_forward();
            }
            break;
            case 6:
            {
                traversal_reverse();
            }
            break;
            case 7:
            {
                delete_from_beg();
            }
            break;
            case 8:
            {
                delete_from_end();
            }
            break;
            case 9:
            {
                delete_a_pos();
            }
            break;
            case 10:
            {
                reverse();
            }
            break;
            case 11:
            {
                sort();
            }
            break;
            case 12:
            {
                goto here;
            }
            break;
            default:
            printf("\nWrong Choice......\n");
        }
    }
    here:printf("\n_____________________________________________________________________\n");
}
