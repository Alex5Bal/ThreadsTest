#include "stdlib.h"
#include "tthreads.h"
#include "stdio.h"
#include "mutex.h"

int buffer;
int count = 0;

void put(int value)
{
    if(count == 0)
    {
        count = 1;
        buffer = value;
    }
}

int get()
{
    if(count == 1)
    {
        count = 0;
        return buffer;
    }
    return 0;
    
}

void *producer(void *arg)
{
    int i;
    int loops = (int) arg;
    
    for(int i = 0; i < loops; i++)
    {
        put(i);
    }
}

void *consumer(void *arg)
{
    while(1)
    {
        int tmp = get();
        printf("%d\n", tmp);
    }
}

int main()
{
    int numThreads = 2;
    int loopCount = 10;
    
    makeThreads(numThreads);
    
    createThread((void (*)(void *))producer, &loopCount);
    createThread((void (*)(void *))consumer, &loopCount);
    
    startThreads();
    
    printf("Threads Terminated\n");
    
}