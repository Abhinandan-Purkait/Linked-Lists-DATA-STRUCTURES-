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

void delete_node(struct node *node)
{
     struct node *tmp = NULL;

     if (start == NULL || start == NULL) return;

     if(start == node)
     {
      start = start->link;
      return;
     }

     tmp = start;

     while(tmp->link && tmp->link != node) tmp = tmp->link;

     if(tmp->link)
        tmp->link = tmp->link->link;
}

void duplicate()
{
     struct node *tmp = NULL;
     struct node *tmp1 = NULL;
     struct node *tmp2 = NULL;

     if (start == NULL) return;

     tmp = start;
     while(tmp)
     {
      tmp1 = tmp->link;

      while(tmp1)
      {
        tmp2 = tmp1;
        tmp1 = tmp1->link;

        if(tmp->data == tmp2->data) delete_node(tmp2);
      }

      tmp = tmp->link;
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

void main()
{
    int n,i;start=NULL;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    printf("\nEnter the element\n");
    for(i=0;i<n;i++)
        add_element();

    printf("\nLIST BEFORE REMOVING DUPLICATES\n");
    traverse();

    duplicate();

    printf("\nLIST AFTER REMOVING DUPLICATES\n");
    traverse();
}
