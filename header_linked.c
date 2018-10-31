#include<stdio.h>
#include<stdlib.h>

struct node
{
    int r,c,ele;
    struct node *next;
};

struct head
{
    int tr,tc,tele;
    struct node *next;
};

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int present(struct head *h,int a,int b,int c)
{
    struct node *t;int F=0;
    t=h->next;
    while(t!=NULL)
    {
        if(t->r==a&&t->c==b)
        {
            return 1;F=1;
        }
        t=t->next;
    }
    if(F==0)
        return -1;
}

void create_head(struct head **h,int a,int b,int c)
{
    struct head *temp;
    temp=(struct head*)malloc(sizeof(struct head));
    temp->tr=a;temp->tc=b;temp->tele=c;
    temp->next=NULL;
    (*h)=temp;
}

void create_list(struct head *h,int a,int b,int c)
{
    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));

    temp->r=a;temp->c=b;temp->ele=c;
    temp->next=NULL;

    if(h==NULL)
        return;
    if(h->next==NULL)
        h->next=temp;
    else
    {
        p=h->next;
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
}

void display(struct head *h)
{
    struct node *p;
    p=h->next;
    printf("\n%d %d %d\n",h->tr,h->tc,h->tele);
    while(p!=NULL)
    {
        printf("%d %d %d\n",p->r,p->c,p->ele);
        p=p->next;
    }
}

void add(struct head *h1,struct head *h2,struct head **h3)
{
    struct node *p,*q,*s;
    p=h1->next;
    create_head(h3,0,0,0);
    int c=0;
    while(p!=NULL)
    {
        q=h2->next;
        while(q!=NULL)
        {
            if(p->r==q->r&&p->c==q->c)
            {
                create_list(*h3,p->r,p->c,((p->ele)+(q->ele)));c++;
            }
            else
            {
                if((present(*h3,p->r,p->c,p->ele)==-1))
                {
                    create_list(*h3,p->r,p->c,(p->ele));
                    c++;
                }
                if((present(*h3,q->r,q->c,q->ele)==-1))
                {
                    create_list(*h3,q->r,q->c,(q->ele));
                    c++;
                }
            }
            q=q->next;
        }
        p=p->next;
    }
    (*h3)->tc=h1->tc;
    (*h3)->tr=h1->tr;
    (*h3)->tele=c;
}

void transpose(struct head *h)
{
    struct node *p,*q;
    p=h->next;

    while(p!=NULL)
    {
        q=p;
        while(q!=NULL)
        {
            if((q->c<p->c)||((q->r<p->r)&&(q->c==p->c)))
            {
                    swap(&(q->r),&(p->r));
                    swap(&(q->c),&(p->c));
                    swap(&(q->ele),&(p->ele));
            }
            q=q->next;
        }
        p=p->next;
    }
    p=h->next;
    swap(&(h->tr),&(h->tc));

    while(p!=NULL)
    {
        swap(&(p->r),&(p->c));
        p=p->next;
    }
}

void main()
{
    int i,x,y,z;
    struct head *h1,*h2,*h3;

    printf("\nEnter the number of rows cols and elements\n");
    scanf("%d%d%d",&x,&y,&z);
    create_head(&h1,x,y,z);

    printf("\nEnter the row col and value\n");
    for(i=0;i<h1->tele;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        create_list(h1,x,y,z);
    }

    printf("\nEnter the number of rows cols and elements\n");
    scanf("%d%d%d",&x,&y,&z);
    create_head(&h2,x,y,z);

    printf("\nEnter the row col and value\n");
    for(i=0;i<h2->tele;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        create_list(h2,x,y,z);
    }

    printf("\n\n");
    display(h1);
    printf("\n\n");
    //transpose(h1);
    display(h2);
    add(h1,h2,&h3);
    printf("\n\n");
    display(h3);
}
