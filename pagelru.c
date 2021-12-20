#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int count=0,r=1;
struct Page
{
    int data;
    int rank;
};
 struct Page* createpage(int size)
 {
     int i;
     struct Page* page=(struct Page*)malloc(sizeof(struct Page));
     for(i=0;i<size;i++)
     {
         page[i].data=-1;
         page[i].rank=99;
     }
     return page;

 }
 int findpage(struct Page* page,int item)
 {
     int fl=0,i;
     if(count==0)
        return 0;
    else
        for(i=0;i<count;i++)
        {
            if(page[i].data==item)
            {
                fl=1;
                r++;
                page[i].rank=r;
                break;
            }
        }
        if(fl)
           return 1;
        else
           return 0;
 }

 void replace(struct Page* page,int item)
 {
     int minr=page[count-1].rank,index=count-1,i;
     for(i=0;i<count;i++)
     {
         if(page[i].rank<minr)
         {
             minr=page[i].rank;
             index=i;
         }
     }
     page[index].data=item;
     page[index].rank=r;
     r++;
 }
 void display(struct Page* page,int f)
 {
     int i;
     for(i=0;i<f;i++)
     {
         printf("%d ",page[i].data);
     }
     printf("\n");
 }
 int main()
 {
     int n,pl[10],i,flag=0,miss=0,hit=0,f;
     printf("Enter no of page requests\n");
     scanf("%d",&n);
     printf("Enter the number of frames\n");
     scanf("%d",&f);
     struct Page* page=createpage(f);
     printf("Enter page requests\n");
     for(i=0;i<n;i++)
     {
         scanf("%d",&pl[i]);
     }
     for(i=0;i<n;i++)
   {  flag=findpage(page,pl[i]);
     if(flag==1)
      { hit++;
        printf("%d : Hit\n",pl[i]);
        display(page,f);
      }

    else
     {  miss++;
        if(count<f)
        {
            page[count].data=pl[i];
            page[count].rank=r;
            r++;
            count++;
            printf("%d : Miss\n",pl[i]);
            display(page,f);
        }
        else
        {
            replace(page,pl[i]);
            printf("%d : Miss\n",pl[i]);
            display(page,f);
        }
     }
   }
   printf("Hits %d Misses %d",hit,miss);
   realloc(page,0);
 }