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

void reverse(){
struct node *ptr1=start,*ptr2;
if(start==NULL)
return;
ptr2=ptr1->link;
while(ptr2!=NULL){
ptr1->link=ptr2->link;
ptr2->link=start;
start=ptr2;
ptr2=ptr1->link;
}}

void main()
{
    int n,i;start=NULL;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    printf("\nEnter the element\n");
    for(i=0;i<n;i++)
        add_element();

    printf("\nLIST BEFORE REVERSING\n");
    traverse();

    reverse(n);
    printf("\nLIST AFTER REVERSING\n");

    traverse();
}
