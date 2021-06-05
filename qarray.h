//
// Created by 孙文礼 on 2021/6/2.
//

#ifndef CIRCLEQUEUE_QARRAY_H
#define CIRCLEQUEUE_QARRAY_H

#include "iostream"

using namespace std;

template<class T>
class QArray {
private:
    struct Link {
        Link *next{}, *previous{};
        T data{};
    };
    Link *_head, *_tail;
    int _size;
public:
    QArray() {
        _size = 0;
        _head = _tail = nullptr;
    }

    inline T &operator[](int index) {
        Link *item;
        if(index>=0){
            item = _head;
            for (int i = 0; i < index; i++) {
                if (item == nullptr) {
                    break;
                }
                item = item->next;
            }
        }
        else{
            item = _tail;
            for (int i = 0; i > index; i--) {
                if (item == nullptr) {
                    break;
                }
                item = item->previous;
            }
        }
        return item->data;
    };

    bool pushBack(T newData) {
        if (_head == nullptr && _tail == nullptr) {
            _tail = _head = new Link;
            _tail->next = _head->next = nullptr;
            _tail->previous = _head->previous = nullptr;
            _tail->data = _head->data = newData;
            _size++;
            return true;
        } else if ((_head == nullptr && _tail != nullptr) || (_head != nullptr && _tail == nullptr)) {
            return false;
        } else {
            _tail->next = new Link;
            _tail->next->data = newData;
            _tail->next->previous = _tail;
            _tail->next->next = nullptr;
            _tail = _tail->next;
            _size++;
            return true;
        }
    }

    bool pushFront(T newData) {
        if (_head == nullptr && _tail == nullptr) {
            _tail = _head = new Link;
            _tail->next = _head->next = nullptr;
            _tail->previous = _head->previous = nullptr;
            _tail->data = _head->data = newData;
            _size++;
            return true;
        } else if ((_head == nullptr && _tail != nullptr) || (_head != nullptr && _tail == nullptr)) {
            return false;
        } else {
            _head->previous = new Link;
            _head->previous->data = newData;
            _head->previous->next = _head;
            _head->previous->previous = nullptr;
            _head = _head->previous;
            _size++;
            return true;
        }
    }

    T popFront() {
        if (_head == nullptr || _tail == nullptr) {
            return {};
        } else {
            T item = _head->data;
            if(_head->next == nullptr){
                delete _head;
                _head = nullptr;
                _size--;
                return item;
            }
            _head = _head->next;
            delete _head->previous;
            _head->previous = nullptr;
            _size--;
            return item;
        }
    }

    T popBack() {
        if (_head == nullptr || _tail == nullptr) {
            return {};
        } else {
            T item = _tail->data;
            if(_tail->previous == nullptr){
                delete _tail;
                _tail = nullptr;
                _size--;
                return item;
            }
            _tail = _tail->previous;
            delete _tail->next;
            _tail->next = nullptr;
            _size--;
            return item;
        }
    }

    int size() {
        return _size;
    }
};

#endif //CIRCLEQUEUE_QARRAY_H
