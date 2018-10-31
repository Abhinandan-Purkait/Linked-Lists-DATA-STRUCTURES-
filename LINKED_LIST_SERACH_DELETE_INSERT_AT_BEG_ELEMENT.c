#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*start;
int flag=0;
void add_element()
{
    int n;
    scanf("%d",&n);
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
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

void insert_at_beg(int n)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;

    temp->link=start;
    start=temp;

}
void delete_at_Key(int key)
{
    struct node *temp=start , *p;
    if (temp == start && temp->data == key)
    {
    start= temp->link;
    return;
    }

    while (temp != NULL && temp->data != key)
    {
    p = temp;
    temp = temp->link;
    }

    if (temp == NULL)
    {printf("\nELEMENT NOT FOUND\n");flag=1;return;}

    p->link = temp->link;
}

void main()
{
    int key,k,i;
    printf("Enter the number of elements : ");
    scanf("%d",&k);
    printf("\nEnter the element\n");
    for(i=0;i<k;i++)
        add_element();
    printf("\nTHE LIST BEFORE CHANGES\n");
    traverse();

    printf("\nEnter a number to search : ");
    scanf("%d",&key);

    delete_at_Key(key);
    if(flag!=1)
    insert_at_beg(key);

    printf("\nTHE LIST AFTER CHANGES\n");
    traverse();
}
