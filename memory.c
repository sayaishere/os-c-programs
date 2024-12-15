#include<stdio.h>
#include<stdlib.h>

struct pro{
  int pid;
  int psize;
  int alloc;
}p[20];

struct block{
  int size;
  int in;
  int bro;
}q[20],temp;

int a[20];

void swap1(int n)
{
   for(int j=0;j<n;j++)
   {
     for(int i=0;i<n-1;i++)
     {
        if(q[i].size>q[i+1].size)
        {
           temp=q[i];
           q[i]=q[i+1];
           q[i+1]=temp;
        }
     }
    }
 }
void swap2(int n)
 {
     for(int j=0;j<n;j++)
     {
       for(int i=0;i<n-1;i++)
       {
         if(q[i].size<q[i+1].size)
         {
            temp=q[i];
            q[i]=q[i+1];
            q[i+1]=temp;
          }
        }
      }
 }
void first(int m, int n) {
for (int i = 0; i < m; i++) {
q[i].size = a[i];
q[i].bro = i;
}

for (int i = 0; i < n; i++) {
p[i].alloc = -1;
}
printf("Pro No.\tProcess\tBro No.\tBlock\tFrag\n");
for (int i = 0; i < m; i++) {
for (int j = 0; j < n; j++) {
if ((q[i].size >= p[j].psize) && (p[j].alloc == -1)) {
printf("%d\t%d\t%d\t%d\t%d\n", p[j].pid,p[j].psize, q[i].bro, q[i].size, q[i].size - p[j].psize);
p[j].alloc = 1;
q[i].size = q[i].size - p[j].psize;
q[i].in = p[j].pid;
}
}
}

for (int j = 0; j < n; j++) {
if (p[j].alloc == -1) {
printf("%d\t%d\tNot Allocated\n", p[j].pid,p[j].psize);
}
}
}

 void best(int m,int n)
 {
   for(int i=0;i<m;i++)
   {
     q[i].size=a[i];
     q[i].bro=i;
   }
   
   for(int i=0;i<n;i++)
   {
     p[i].alloc=-1;
   }
   
   printf("Pro No.\tProcess\tBlock No.\tBlock\tFrag\n");
   swap1(m);
   
   for(int i=0;i<m;i++)
   {
     for(int j=0;j<n;j++)
     {
        if((q[i].size>=p[j].psize)&&(p[j].alloc==-1))
        {
          printf("%d\t%d\t%d\t%d\t%d\n",p[j].pid,p[j].psize,q[i].bro,q[i].size,q[i].size-p[j].psize);
           
           p[j].alloc=1;
           q[i].size=q[i].size-p[j].psize;
           q[i].in=p[j].pid;
           swap1(m);
        }
      }
   }
   for(int j=0;j<n;j++)
   {
      if(p[j].alloc==-1)
      {
      printf("%d\t%d\t Not Allocated",p[j].pid,p[j].psize);
      }
   }
 }
 void worst(int m,int n)
 {
   for(int i=0;i<m;i++)
   {
     q[i].size=a[i];
     q[i].bro=i;
   }
   
   for(int i=0;i<n;i++)
   {
     p[i].alloc=-1;
   }
   
   printf("Pro No.\tProcess\tBlock No.\tBlock\tFlag\n");
   swap2(m);
   
   for(int i=0;i<m;i++)
   {
     for(int j=0;j<n;j++)
     {
       if((q[i].size>p[j].psize)&&(p[i].alloc==-1))
       {
          printf("%d\t%d\t%d\t%d\t%d\n",p[j].pid,p[j].psize,q[i].bro,q[i].size,q[i].size-p[j].psize);
          
          p[j].alloc=1;
          q[i].size=q[i].size-p[j].psize;
          q[i].in=p[j].pid;
          swap2(m);
       }
    }
 }
 for(int j=0;j<n;j++)
 {
   if(p[j].alloc==-1)
   {
   printf("%d\t%d\t Not Allocated",p[j].pid,p[j].psize);
   }
 }
 }
int main()
{
 int m,n,o,x;
 
 printf("Enter the number of process:\n");
 scanf("%d",&n);
 
 for(int i=0;i<n;i++)
 {
   printf("Enter the process size of p[%d]\n",i);
   p[i].pid=i;
   scanf("%d",&p[i].psize);
   p[i].alloc=-1;
 }
 
 printf("Enter the number of blocks:\n");
 scanf("%d",&m);
 
   printf("Enter the block size:\n");
   for(int i=0;i<m;i++)
   {
      scanf("%d",&q[i].size);
      a[i]=q[i].size;
      q[n].in=-1;
   }
   
   do
   {
     printf("Enter the fit to be performed:\n");
     printf("1.First Fit\n2.Best Fit\n3.Worst Fit\n");
     
     scanf("%d",&x);
     
     switch(x)
     {
       case 1:
             first(m,n);
             break;
       case 2:
             best(m,n);
             break;
       case 3:
             worst(m,n);
             break;
       default:
             printf("Invalid Choice\n");
             break;
      }
      printf("For continue press 1\n");
      scanf("%d",&o);
  }while(o==1);
  return 0;
}
     
   
 
           
         
       
     
     
           
 
      
