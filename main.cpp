#include <iostream>
#include "dcqueue.h"
#include<queue>

void test(DCQueue<int> &q) {
    q.setThisData(10000);
    for (int i = 0; i < q.getSize(); i++) {
        std::cout << q.getThisData() << std::endl;
        q.pushAsPrevious(q.getThisData());
        q.popToNext();
    }
}

void test2(DCQueue<int> q) {
    q.setThisData(10000);
    for (int i = 0; i < q.getSize(); i++) {
        std::cout << q.getThisData() << std::endl;
        q.pushAsPrevious(q.getThisData());
        q.popToNext();
    }
}

int main() {
    clock_t startTime, endTime;
    startTime = clock();//计时开始
    DCQueue<long> qq;
    for (long i = 0; i < 5; i++) {
        qq.pushAsPrevious(i);
    }
    qq.remove(4);
    qq.remove(3);
//    qq.remove(2);
    qq.remove(1);
    qq.remove(0);
    for (long i = 0; i < qq.getSize(); i++) {
        std::cout << qq.getThisData() << std::endl;
        qq.moveToNext();
    }
    endTime = clock();//计时结束
    std::cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    return 0;
}
