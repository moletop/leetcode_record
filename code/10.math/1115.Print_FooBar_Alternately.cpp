#include <semaphore.h> // 需要手动包含信号量头文件


/*
int sem_init(sem_t *sem, int pshared, unsigned int value);
其中sem是要初始化的信号量，pshared表示此信号量是在进程间共享还是线程间共享，
value是信号量的初始值。

int sem_destroy(sem_t *sem);,其中sem是要销毁的信号量。
只有用sem_init初始化的信号量才能用sem_destroy销毁。

int sem_wait(sem_t *sem);等待信号量，如果信号量的值大于0,将信号量的值减1,立即返回。
如果信号量的值为0,则线程阻塞。相当于P操作。成功返回0,失败返回-1。

int sem_post(sem_t *sem); 释放信号量，让信号量的值加1。相当于V操作。

int sem_getvalue(sem_t *sem, int *sval);
取回信号量sem的当前值，把该值保存到sval中。
若有1个或更多的线程或进程调用sem_wait阻塞在该信号量上，该函数返回两种值：

返回0
返回阻塞在该信号量上的进程或线程数目
linux采用返回的第一种策略。
*/
代码


class FooBar {
private:
    int n;
    sem_t foo_done, bar_done;
public:
    FooBar(int n) : n(n) {
        sem_init(&foo_done, 0 , 0);
        sem_init(&bar_done, 0 , 1);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&bar_done);
            printFoo();
            sem_post(&foo_done);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&foo_done);
            printBar();
            sem_post(&bar_done);
        }
    }
};

