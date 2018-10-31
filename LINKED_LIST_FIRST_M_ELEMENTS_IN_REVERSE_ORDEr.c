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

void reverse(int n)
{
    struct node *q,*p;
    p=q=start;
    int i=0,j=n-1,k=0,temp;
    while(i<j)
    {
        k=0;
        while(k<j)
        {
            q=q->link;
            k++;
        }
        temp=p->data;
        p->data=q->data;
        q->data=temp;
        i++;j--;
        p=p->link;
        q=start;
    }
}
void main()
{
    int n,m,i;start=NULL;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);

    printf("\nEnter the element\n");
    for(i=0;i<n;i++)
        add_element();

    printf("\nEnter the position of element from where you want to reverse\n");
    scanf("%d",&m);

    printf("\nLIST BEFORE REVERSING\n");
    traverse();

    reverse(m);
    printf("\nLIST AFTER REVERSING\n");

    traverse();
}
