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

void read(int n)
{
    struct node *q;
    q=start;
    int i=0,j=n-1,k=0,temp;
    int a;
    printf("\nEnter the location which you want to read from end\n");
    scanf("%d",&a);
    if(a<1||a>n)
        printf("\nINVALID LOCATION\n");
    else
    {
        while(i<a)
        {
            k=0;
            while(k<j)
            {
                q=q->link;
                k++;
            }
            i++;j--;
            temp=q->data;
            q=start;
        }
    }
    printf("\nTHE ELEMENT REQUIRED IS : %d",temp);
}
void main()
{
    int n,i;start=NULL;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
    for(i=0;i<n;i++)
        add_element();

    printf("\nTHE ELEMENTS IN THE LIST ARE\n");
    traverse();
    printf("\n\n");
    read(n);

}
