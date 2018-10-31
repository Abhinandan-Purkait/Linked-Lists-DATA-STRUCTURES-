//PROGRAM

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
    printf("\nEnter the element\n");
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
int count_nodes()
{
    int n=0;
    struct node *p=NULL;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
        n++;
    }
    return n+1;

}
void node_search()
{
    int key;
    printf("\nEnter the element to search\n");
    scanf("%d",&key);
    int n=0;
    struct node *p;
    p=start;
    while(p->data!=key&&p->link!=NULL)
    {
        p=p->link;
        n++;
    }
    if(p->link!=NULL)
        printf("\nTHE ELEMENT WAS FOUND AT %d NODE\n",n);
    else
        printf("\nNO SUCH ELEMENT FOUND\n");

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
void insert_at_any_position()
{
    int n,k=count_nodes();
    struct node *temp,*p;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the index to insert (0-FOR BEGINING AND (SIZE-1)-FOR END) : ");
    int loc;
    scanf("%d",&loc);

    printf("\nEnter an element to insert : ");
    scanf("%d",&n);

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
void delete_at_any_position()
{
    int n,i=0,k=count_nodes();
    printf("\nEnter the index to delete (0-FOR BEGINING AND (SIZE-1)-FOR END) : ");
    int loc;
    scanf("%d",&loc);
    struct node *p,*temp;
    p=start;
    if(loc==0)
        start=p->link;
    else if(loc==k-1)
    {
        while(i<=loc-1)
        {
            p=p->link;
            i++;
        }
        p->link=NULL;
    }
    else
    {
        int i=0;temp=p;
        while(i<=loc-2)
        {
            p=p->link;
            temp=temp->link;
            i++;
        }
        p->link=temp->link;
    }
}
void delete_at_Key()
{
    printf("\nEnter the key to delete : ");
    int key;
    scanf("%d",&key);
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
    {printf("\nELEMENT NOT FOUND\n");return;}

    p->link = temp->link;
}

void isEmpty()
{
    if(start==NULL)
        printf("\nThe list is empty\n");
    else
        printf("\nThe list is not empty\n");
}
void main()
{
    int n;start=NULL;
    while(1)
    {
        printf("\n1:ADD ELEMENTS\n2:TRAVERSE\n3:CHECK IF LIST EMPTY\n4:INSERT NODE AT CERTAIN INDEX\n5:DELETE NODE AT CERTAIN INDEX\n6:DELETE A NODE FOR A GIVEN KEY\n7:TOTAL NO OF NODES\n8:SEARCH FOR AN ELEMENT\n9:EXIT\nENTER YOUR CHOICE : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            add_element();break;
            case 2:
            traverse();break;
            case 3:
            isEmpty();break;
            case 4:
            insert_at_any_position();break;
            case 5:
            delete_at_any_position();break;
            case 6:
            delete_at_Key();break;
            case 7:
            printf("\nTHE TOTAL NUMBER OF NODES IS : %d\n",count_nodes());break;
            case 8:
            node_search();break;
            case 9:
            exit(0);
            default:
            printf("\nWrong Choice select from list\n");
        }
    }
}
/*
OUTPUT


1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 1

Enter the element
22

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 1

Enter the element
33

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 1

Enter the element
44

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 2
22 33 44
1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 3

The list is not empty

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 4

Enter the index to insert (0-FOR BEGINING AND (SIZE-1)-FOR END) : 0

Enter an element to insert : 23

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 2
23 22 33 44
1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 5

Enter the index to delete (0-FOR BEGINING AND (SIZE-1)-FOR END) : 2

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 2
23 22 44
1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 6

Enter the key to delete : 22

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 2
23 44
1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 7

THE TOTAL NUMBER OF NODES IS : 2

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 8

Enter the element to search
44

THE ELEMENT WAS FOUND AT 1 NODE

1:ADD ELEMENTS
2:TRAVERSE
3:CHECK IF LIST EMPTY
4:INSERT NODE AT CERTAIN INDEX
5:DELETE NODE AT CERTAIN INDEX
6:DELETE A NODE FOR A GIVEN KEY
7:TOTAL NO OF NODES
8:SEARCH FOR AN ELEMENT
9:EXIT
ENTER YOUR CHOICE : 9
*/
