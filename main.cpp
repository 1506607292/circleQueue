#include <iostream>
#include <cmath>
#include "qarray.h"
using namespace std;

int main() {
    QArray<int> q;
    for (int i = 0; i < 4; i++) {
        q.pushBack(i);
    }
    for (int i = 0; i < 4; i++) {
        q.pushFront(i+10);
    }
    cout<<q[1]<<endl;
    cout<<q[-1]<<endl;
    cout<<"============="<<endl;

    while(q.size()>0){
        cout<<q.popFront()<<endl;
    }
    return 0;
}
