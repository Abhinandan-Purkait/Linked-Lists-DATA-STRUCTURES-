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

int occurences(int k)
{
    int i=0;
    struct node *p;
    p=start;
    while(p->link!=NULL)
    {
        if(p->data==k)
            i++;
        p=p->link;
    }
    if(p->data==k)
        i++;
    return i;
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
    int key,k,i;
    printf("Enter the number of elements : ");
    scanf("%d",&k);
    printf("\nEnter the element\n");
    for(i=0;i<k;i++)
        add_element();
    printf("\nTHE LIST BEFORE CHANGES\n");
    traverse();

    printf("\nEnter the element to search and find frequency : ");
    scanf("%d",&key);

    if(occurences(key)==0)
        printf("\nNOT FOUND\n");
    else
        printf("\nTHE FREQUENCY IS : %d\n",occurences(key));
}
