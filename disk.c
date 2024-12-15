#include<stdio.h>
#include<stdlib.h>
int main()
{
  int thm=0,k=0,ch,c,pos,n,i,j,initial;
  printf("Enter the number of request:");
  scanf("%d",&n);
  int r[n],order[n];
  printf("Enter the requests:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&r[i]);
  }
  printf("Enter the initial position of head:\n");
  scanf("%d",&initial);
  do
  {
    printf("\nSelect choice\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.EXIT\nEnter the choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      {
        int t;
        t=initial;
        for(i=0;i<n;i++)
        {
          thm+=abs(r[i]-initial);
          initial=r[i];
        }
        initial=t;
        printf("The total head movement is %d\n",thm);
        printf("The order of head movement:%d",initial);
        for(i=0;i<n;i++)
        {
         printf(",%d",r[i]);
        }
      }
      break;
      case 2:
      {
        int t1,temp;
        thm=0;
        t1=initial;
        printf("Enter the number of cylinders:");
        scanf("%d",&c);
        for(i=0;i<n;i++)
        {
          for(j=0;j<n-i-1;j++)
          {
            if(r[j]>r[j+1])
            {
              temp=r[j];
              r[j]=r[j+1];
              r[j+1]=temp;
            }
          }
        }
        for(i=0;i<n;i++)
        {
          if(r[i]>initial)
          {
            pos=i;
            break;
          }
        }
        for(j=pos;j<n;j++)
        {
          thm+=abs(r[j]-initial);
          initial=r[j];
          order[k]=r[j];
          k++;
       }
       initial=c-1;
       thm+=abs((c-1)-r[n-1]);
       for(i=pos-1;i>=0;i--)
       {
         thm+=abs(r[i]-initial);
         initial=r[i];
         order[k]=r[i];
         k++;
       }
       initial=t1;
       printf("The total head movement is %d\n",thm);
       printf("The order of head movement %d",initial);
       for(i=0;i<n;i++)
       {
         printf(",%d",order[i]);
       }
     }
     break;
     case 3:
      {
        int t2,temp1;
        thm=0;
        k=0;
        pos=0;
        t2=initial;
        printf("Enter the number of cylinders:");
        scanf("%d",&c);
       for(i=0;i<n;i++)
       {
        for(j=0;j<n-i-1;j++)
        {
          if(r[j]>r[j+1])
          {
           temp1=r[j];
           r[j]=r[j+1];
           r[j+1]=temp1;
          }
        }
      }
      for(i=0;i<n;i++)
      {
        if(r[i]>initial)
        {
          pos=i;
          break;
        }
      }
      for(j=pos;j<n;j++)
      {
        thm+=abs(r[j]-initial);
        initial=r[j];
        order[k]=r[j];
        k++;
     }
     initial=0;
     thm+=abs((c-1)-r[n-1])+(c-1);
     for(i=0;i<pos;i++)
     {
        thm+=abs(r[i]-initial);
        initial=r[i];
        order[k]=r[i];
        k++;
     }
     initial=t2;
     printf("The total head movement is %d\n",thm);
     printf("The order of head movement %d",initial);
       for(i=0;i<n;i++)
       {
         printf(",%d",order[i]);
       }
     }
     break;
     case 4:
     {
       printf("Exiting....\n");
     }
     break;
    }
    }while(c!=4);
    return 0;
  }
         
        
  
     
  
 
