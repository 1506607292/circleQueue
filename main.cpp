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
//    std::queue<long> q;
//    for(long i=0;i<10000000;i++){
//        q.push(i);
//    }
//    for(long i=0;i<q.size();i++){
//        std::cout<<q.front()<<std::endl;
//        q.push(q.front());
//        q.pop();
//    }
    DCQueue<long> qq;
    for (long i = 0; i < 10000000; i++) {
        qq.pushAsPrevious(i);
    }
    for (long i = 0; i < qq.getSize(); i++) {
        std::cout << qq.getThisData() << std::endl;
        qq.moveToNext();
//        qq.pushAsPrevious(qq.getSize());
//        qq.popToNext();
    }
    endTime = clock();//计时结束
    std::cout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    return 0;
}
