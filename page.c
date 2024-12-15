#include<stdio.h>
#include<stdlib.h>
int main()
{
 int pages,frames,i,j,ch,count,next,pf,min;
 printf("Enter the number of pages:");
 scanf("%d",&pages);
 int *rs=(int*)malloc(pages* sizeof(int));
 printf("Enter the reference string:\n");
 for(i=0;i<pages;i++)
 {
   scanf("%d",&rs[i]);
 }
 printf("Enter the number of frames:");
 scanf("%d",&frames);
 int *m=(int*)malloc(frames* sizeof(int));
 do
 {
   count=0;
   next=1;
   pf=0;
   
   printf("\nSelect the choice\n1.FIFO\n2.LRU\n3.LFU\n4.EXIT\nEnter the choice:\n");
   scanf("%d",&ch);
   for(i=0;i<frames;i++)
   {
     m[i]=-1;
   }
   
   switch(ch)
   {
     case 1:
     {
       printf("\nPhysical Memory\n");
       for(i=0;i<pages;i++)
       {
         for(j=0;j<frames;j++)
         {
           if(rs[i]==m[i])
           { 
             break;
           }
         }
      if(j==frames)
      {
        m[count]=rs[i];
        count++;
        pf++;
      }
      if(count==frames)
      {
        count=0;
      }
      for(j=0;j<frames;j++)
      {
        printf("%d\t",m[j]);
      }
      printf("\n");
   }
   printf("The number of page fault is %d",pf);
   break;
 }
 case 2:
 {
   int *count1=(int*)malloc(frames* sizeof(int));
   int *flag=(int*)malloc(pages* sizeof(int));
   for(i=0;i<pages;i++)
   {
     flag[i]=0;
   }
   for(j=0;j<frames;j++)
   {
     count1[j]=0;
   }
   printf("\nPhysical Memory\n");
   for(i=0;i<pages;i++)
   {
     for(j=0;j<frames;j++)
     {
       if(rs[i]==m[j])
       {
         flag[i]=1;
         count1[j]=next;
         next++;
       }
     }
     if(flag[i]==0)
     {
       if(i<frames)
       {
         m[i]=rs[i];
         count1[i]=next;
         next++;
       }
       else
       {
         min=0;
         for(j=0;j<frames;j++)
         {
            if(count1[min]>count1[j])
            {
              min=j;
            }
         }
        m[min]=rs[i];
        count1[min]=next;
        next++;
        }
        pf++;
    }
    for(j=0;j<frames;j++)
    {
      printf("%d\t",m[j]);
    }
    printf("\n");
  }
  printf("The number of page fault is %d",pf);
  
  free(count1);
  free(flag);
  break;
 }
 case 3:
 {
   int *count2=(int*)malloc(frames* sizeof(int));
   for(i=0;i<frames;i++)
   {
     count2[i]=0;
   }
   printf("\nPhysical Memory\n");
   for(i=0;i<pages;i++)
   {
     for(j=0;j<frames;j++)
     {
       if(rs[i]==m[j])
       {
         count2[j]++;
         break;
       }
     }
    if(j==frames)
    {
      min=0;
      for(j=0;j<frames;j++)
      {
         if(count2[min]>count2[j])
         {
            min=j;
         }
      }
      count2[min]++;
      m[min]=rs[i];
      pf++;
   }
    for(j=0;j<frames;j++)
      {
        printf("%d\t",m[j]);
      }
      printf("\n");
   }
   printf("The number of page fault is %d",pf);
   free(count2);
   break;
 }
 case 4:
      break;
  default:
  printf("Invalid choice.Please enter the valid option.\n");
 }
 }while(ch!=4);
 free(rs);
 free(m);
 return 0;
 }
    
               
        
