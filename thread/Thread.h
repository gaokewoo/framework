#ifndef __THREAD_H__
#define __THREAD_H__


#include <pthread.h>
#include <unistd.h>

class Thread
{
    public:
        Thread();
        Thread(void * (*func)(void*));
        void makeThreadFunc(void * (*func)(void*));
        bool start();
        pthread_t getThreadID();
        void join();
    private:
        pthread_t tid;
        void * (*threadFunc)(void*);
};

#endif
