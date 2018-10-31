#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  struct type
  {
            int number;
            struct subrand
            {
                int no;
                char *name;
            }*sb;
    };
void main()
{
    printf("\nEnter the type\n");
    struct type *wine,*whisky,*rum,*cognac,*gin,*vodka;
    wine->sb=(struct subrand*)malloc(5*sizeof(struct subrand));
    wine->number=50;
    wine->sb[0].name="champange";
    wine->sb[0].no=10;
    wine->sb[1].name="sherry";
    wine->sb[1].no=5;
    wine->sb[2].name="red";
    wine->sb[2].no=20;
    wine->sb[3].name="white";
    wine->sb[3].no=10;
    wine->sb[4].name="sparkling";
    wine->sb[4].no=5;

    whisky->sb=(struct subrand*)malloc(3*sizeof(struct subrand));
    whisky->number=15;
    whisky->sb[0].name="rye";
    whisky->sb[0].no=6;
    whisky->sb[1].name="scotch";
    whisky->sb[1].no=5;
    whisky->sb[2].name="bourbon";
    whisky->sb[2].no=3;

    rum->number=10;
    cognac->number=5;
    gin->number=7;
    vodka->number=5;

    int i;
    char input[30];
    scanf("%s",&input);

    if(strcmp(input,"wine")!=0)
    {
        printf("\nThe number of brands are %d\n",wine->number);
        printf("\nThe name of subrands\n");
        for(i=0;i<5;i++)
            printf("%d brands of %s",wine->sb[i].no,wine->sb[i].name);
    }

}
