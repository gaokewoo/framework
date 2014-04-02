#include "Thread.h"

Thread::Thread()
{
    tid = 0;
    threadFunc=NULL;
}

Thread::Thread(void * (*func)(void*))
{
    tid = 0;
    threadFunc=func;
}

void Thread::makeThreadFunc(void * (*func)(void*))
{
    threadFunc=func;
}

bool Thread::start()
{
    return pthread_create(&tid, NULL, threadFunc, this) == 0;
}

pthread_t Thread::getThreadID()
{
    return tid;
}

void Thread::join()
{
    if (tid > 0)
    {
        pthread_join(tid, NULL);
    }
}

