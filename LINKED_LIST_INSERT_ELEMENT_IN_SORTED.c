#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*start;

void add_element()
{
    int n;
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&n);
    temp->data=n;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        p=start;
        while(p->link!=NULL)
        p=p->link;
        p->link=temp;
    }
}

int node_search(int key)
{
    int n=0;
    struct node *p;
    p=start;
    while(p->data!=key&&p->link!=NULL)
    {
        p=p->link;
        n++;
    }
    if(p->link!=NULL)
       return(n);
    else
       return(-1);
}

void traverse()
{
    struct node *p;
    p=start;
    while(p->link!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("%d ",p->data);
}

void insert_at_any_position(int loc,int n,int k)
{
    struct node *temp,*p;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->data=n;
    temp->link=NULL;

    if(loc==0)
    {
        temp->link=start;
        start=temp;
    }
    else if(loc==k-1)
        add_element();
    else
    {
        int i=0;
        while(i<=loc-2)
        {
            p=p->link;
            i++;
        }
        temp->link=p->link;
        p->link=temp;
    }
}

void main()
{
    int n,k,i;start=NULL;
    printf("\nEnter the number of elements\n");
    scanf("%d",&k);
    printf("\nEnter the element\n");
    for(i=0;i<k;i++)
        add_element();

    printf("\nEnter an element to insert : ");
    scanf("%d",&n);

    printf("\nLIST BEFORE INSERTING\n");
    traverse();

    insert_at_any_position(node_search(n),n,k);

    printf("\nLIST AFTER INSERTING\n");
    traverse();
}
