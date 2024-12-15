#include<stdio.h>
int main()
{
  int p,r,allocation[20][20],max[20][20],need[20][20],available[10],work[20],finish[20],t,counter,instances[20];
  int s[10],sum[20],i,j;
  printf("Enter the number of process:\n");
  scanf("%d",&p);
  printf("Enter the number of types of resources:\n");
  scanf("%d",&r);
  printf("Enter the number of instances of each resources:\n");
  for(i=0;i<r;i++)
  {
    printf("Instance %d:",i);
    scanf("%d",&instances[i]);
    sum[i]=0;
    
  }
  
  printf("Enter the Allocation matrix:\n");
  for(i=0;i<p;i++)
  {
    printf("Enter the P%d:" ,i);
    for(j=0;j<r;j++)
    {
       scanf("%d",&allocation[i][j]);
    }
  }
  
  printf("Enter the Max matrix:\n");
  for(i=0;i<p;i++)
  {
    printf("Enter the P%d: ",i);
    for(j=0;j<r;j++)
    {
       scanf("%d",&max[i][j]);
    }
 }
 for(i=0;i<p;i++)
 {
   for(j=0;j<r;j++)
   {
     sum[j]+=allocation[i][j];
   }
 }
 for(i=0;i<r;i++)
 {
   available[i]=instances[i]-sum[i];
 }
 for(i=0;i<p;i++)
 {
   for(j=0;j<r;j++)
   {
      need[i][j]=max[i][j]-allocation[i][j];
    }
}
printf("\n....Allocation....\n");
for(i=0;i<p;i++)
{
  for(j=0;j<r;j++)
  {
    printf("%d\t",allocation[i][j]);
  }
  printf("\n");
}

printf("\n....Max....\n");
for(i=0;i<p;i++)
{
 for(j=0;j<r;j++)
 {
    printf("%d\t",max[i][j]);
  }
 printf("\n");
}

printf("\n....NEED....\n");
for(i=0;i<p;i++)
{
  for(j=0;j<r;j++)
  {
    printf("%d\t",need[i][j]);
   }
   printf("\n");
}
printf("\nAvailable resources:\n");
for(i=0;i<r;i++)
{
  printf("%d\n",available[i]);
}
for(i=0;i<r;i++)
{
  work[i]=available[i];
}
for(i=0;i<p;i++)
{
  finish[i]=0;
}
counter=p;
int l=0;
int found=0;
while(counter!=0)
{
  found=0;
 for(i=0;i<p;i++)
 {
   if(finish[i]==0)
   {
    t=0;
    for(j=0;j<r;j++)
    {
      if(need[i][j]>work[j])
      {
        t=1;
        break;
      }
    }
    if(t==0)
    {
       counter--;
       s[l++]=i;
       finish[i]=1;
       for(j=0;j<r;j++)
       {
         work[j]+=allocation[i][j];
         found=1;
       }
     }
    }
   }
   if(found==0)
   {
     break;
   }
}
int flag=0;
for(i=0;i<p;i++)
{
  if(finish[i]==0)
  {
     flag=1;
     printf("Not Safe");
     break;
  }
 }
 if(flag==0)
 {
   printf("System is safe.\n");
   printf("Safe sequence:");
   for(i=0;i<p;i++)
   {
     printf("P%d ",s[i]);
   }
   printf("\n");
}
return 0;
}

