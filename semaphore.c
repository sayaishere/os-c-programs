#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define Maxterms 5
#define BufferSize 5
sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer()
{
  for(int i=0;i<Maxterms;i++)
  {
     sem_wait(&empty);
     int item;
     printf("\nProducer\n");
     printf("\nEnter the item to store:");
     scanf("%d",&item);
     buffer[in]=item;
     in=(in+1)%BufferSize;
     pthread_mutex_unlock(&mutex);
     sem_post(&full);
   }
}
void *consumer()
{
   int item;
   for(int i=0;i<Maxterms;i++)
   {
      sem_wait(&full);
      pthread_mutex_lock(&mutex);
      printf("\nConsumer\n");
      item=buffer[out];
      printf("data at position %d is %d\n",out,item);
      out=(out+1)%BufferSize;
      pthread_mutex_unlock(&mutex);
      sem_post(&empty);
   }
}

void main()
{
  pthread_t p,c;
  pthread_mutex_init(&mutex,NULL);
  sem_init(&empty,0,BufferSize);
  sem_init(&full,0,0);
  pthread_create(&p,NULL,(void*)producer,(void*)&p);
  pthread_create(&c,NULL,(void*)consumer,(void*)&c);
  pthread_join(p,NULL);
  pthread_join(c,NULL);
  pthread_mutex_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
}
  
      










