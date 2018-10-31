#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coefficient;
    int power;
    struct node *next;
};

int present(struct node *p,int pw)
{
    struct node *x;
    x=p;
    if(x==NULL)
        return -1;

    while(x!=NULL)
    {
        if((x->power)==pw)
        return 1;
        x=x->next;
    }
    return -1;
}

void create(struct node **p,int c,int pw)
{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->coefficient=c;
    temp->power=pw;
    temp->next=NULL;
    if((*p)==NULL)
        (*p)=temp;
    else
    {
        q=(*p);
        while(q->next!=NULL)
        q=q->next;
        q->next=temp;
    }
}

void add(struct node *p1,struct node *p2,struct node **p3)
{
    struct node *p,*q;
    p=p1;
    while(p!=NULL)
    {
        q=p2;
        while(q!=NULL)
        {
            if((present(*p3,(p->power))==-1)&&((p->power)==(q->power)))
                create(p3,((p->coefficient)+(q->coefficient)),(p->power));
            else if((present(*p3,(p->power))==-1)&&((p->power)>(q->power)))
                create(p3,(p->coefficient),(p->power));
            else if((present(*p3,(q->power))==-1)&&((p->power)<(q->power)))
                create(p3,(q->coefficient),(q->power));
            q=q->next;
        }
        p=p->next;
    }
}

void multiply(struct node *p1,struct node *p2,struct node **p3)
{
    struct node *p,*q;
    p=p1;
    while(p!=NULL)
    {
        q=p2;
        while(q!=NULL)
        {
            int cf=((p->coefficient)*(q->coefficient));
            int exp=((p->power)+(q->power));

            if(present((*p3),exp)==-1)
                create(p3,cf,exp);
            else
            {
                struct node *x;
                x=*p3;
                for(x=(*p3);(x->power)!=((p->power)+(q->power));x=x->next);
                x->coefficient=(x->coefficient)+cf;
            }
            q=q->next;
        }
        p=p->next;
    }
}

void display(struct node *p)
{
    struct node *x;
    x=p;
    while(x->next!=NULL)
    {
        printf("%dX^%d + ",x->coefficient,x->power);
        x=x->next;
    }
    printf("%dX^%d",x->coefficient,x->power);
}

void main()
{
    struct node *p1,*p2,*p3;
    p1=NULL;p2=NULL;p3=NULL;

    int n,c,p,i;
    printf("\nEnter the number of nodes in first polynomial : ");
    scanf("%d",&n);
    printf("\nEnter the coefficient and power\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&c,&p);
        create(&p1,c,p);
    }
    printf("\nEnter the number of nodes in first polynomial : ");
    scanf("%d",&n);
    printf("\nEnter the coefficient and power\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&c,&p);
        create(&p2,c,p);
    }
    while(1)
    {
        printf("\n1: ADD\n2: MULTIPLY\nENTER KAR GANDU : ");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            add(p1,p2,&p3);
            display(p3);
            p3=NULL;
        }
        else if(ch==2)
        {
            multiply(p1,p2,&p3);
            display(p3);
            p3=NULL;
        }
        else
        {
            printf("\nCHUP GANDU !!\n");
            exit(0);
        }
    }
}
