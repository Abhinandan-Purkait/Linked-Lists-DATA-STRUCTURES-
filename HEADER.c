/*
File Name : IT-6 DSA LAB VIVA- 1706477.c
Created : 14/8/18
Author : Deepak Kumar Sahoo
Description : Program for DSA LAB VIVA 1
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int key;
    struct node *link;
}*head1,*head2;
int unique(int arr[],int s)//to find the unique key
{
    int i,j,f=1;
    for(i=0;i<s-1;i++)
    {
        for(j=i+1;j<s;j++)
        {
            if(arr[i]==arr[j])
            {
                f=0;goto cond;
            }
        }
    }
    cond:if(f==0)
        return -1;
    else
        return 1;
}
void add_element(int k,int x)//adding elements in the linked list
{
    struct node *temp,*p;
    int f=1;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=k;
    temp->key=x;
    temp->link=NULL;

    if(head1==NULL)
        head1=temp;
    else
    {   p=head1;
        while(p->link!=NULL)
        p=p->link;
        p->link=temp;
    }
}
void split(int loc)//splitting the list
{

    int i;
    struct node *p;
    p=head1;
    for(i=0;i<(loc-1);i++)
    p=p->link;
    head2=p->link;
    p->link=NULL;

}
void traverse(struct node *x)//traversing of list
{
    struct node *p;
    p=x;
    while(p!=NULL)
    {
        printf("%d,%d ",p->data,p->key);
        p=p->link;
    }
}
void insertion1()//creation of first list's header
{
    struct node *new_node;
    new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = -1;
    new_node->link = head1;
    head1 = new_node;
}

void insertion2()//creation of second list's header
{
    struct node *new_node;
    new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = -1;
    new_node->link = head2;
    head2 = new_node;
}
void main()
{
    struct node q;
    head1=NULL;
    int num,n,i,key;
    printf("\nEnter the number of elements\n");
    scanf("%d",&n);
    int key_arr[n];
    printf("\nEnter the element and key\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&num,&key);
        key_arr[i]=key;
        if(unique(key_arr,n)==-1)
        {
            printf("\nEnter again key is not unique\n");
            i--;
        }
        else
        {
            add_element(num,key);
        }
    }
    printf("\nEnter the location from where you want to split\n");
    int loc;
    scanf("%d",&loc);
    printf("\nThe list before splitting\n");
    traverse(head1);
    split(loc);
    insertion1();
    head1->key=loc+1;
    insertion2();
    head2->key=n-loc+1;
    printf("\nThe list after splitting\n");
    printf("\nThe first list\n");
    traverse(head1);
    printf("\nThe number of nodes in first list = %d\n",head1->key);
    printf("\n\n");
    printf("\nThe second list\n");
    traverse(head2);
    printf("\nThe number of nodes in second list = %d\n",head2->key);
}
