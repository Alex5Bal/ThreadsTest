#include "stdlib.h"
#include "tthreads.h"
#include "stdio.h"
#include "mutex.h"

#define MAX = 10;

int buffer[MAX];
int max = 10
int fill = 0;
int use = 0;
int count = 0;
int loops = 99;
Mutex mutex;

void put(int value)
{
    buffer[fill] = value;
    fill = (fill + 1) % max;
    count++;
}

int get()
{
    int temp = buffer[use];
    use = (use + 1) % max;
    count--;
    return temp;
    
}

mutexInit(mutex, max);

void *producer(void *arg)
{
    int i;
    for (i = 0; i < loops; i++) {
    	mutexLock(&mutex);
    	while (count == max)
    		yield();
    	put(i);
    	mutexUnlock(&mutex);
    }
}

void *consumer(void *arg)
{
    int i;
    for (i = 0; i < loops; i++) {
    	mutexLock(&mutex);
    	while (count == 0)
    		yield();
    	int temp = get();
    	mutexUnlock(&mutex);
    }
}

int main()
{
    int numThreads = 5;
    int loopCount = 10;
    
    makeThreads(numThreads);
    
    createThread((void (*)(void *))producer, NULL);
    createThread((void (*)(void *))producer, NULL);
    createThread((void (*)(void *))producer, NULL);
    createThread((void (*)(void *))producer, NULL);
    createThread((void (*)(void *))consumer, NULL);
    
    startThreads();
    
    printf("Threads Terminated\n");
    
}
