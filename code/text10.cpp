#include <semaphore.h> // 需要手动包含信号量头文件

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

