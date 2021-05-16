//
// Created by 孙文礼 on 2021/5/15.
//

#ifndef CIRCLEQUEUE_DCQUEUE_H
#define CIRCLEQUEUE_DCQUEUE_H
template<class T>
class Link {
    Link *next{}, *previous{};
    T data{};
public:
    explicit Link(T data) {
        this->data = data;
    }

    ~Link() = default;;

    void setNext(Link *next) { this->next = next; }

    Link *getNext() { return this->next; }

    Link *getPrevious() { return this->previous; }

    void setPrevious(Link *previous) { this->previous = previous; }

    void setData(T data) { this->data = data; }

    T getData() { return this->data; }
};

template<class T>
class DCQueue {
    Link<T> *head{};
    int size{};
public:
    DCQueue() {
        this->head = nullptr;
        this->size = 0;
    }

    ~DCQueue() {
        this->clear();
    };

    void pushAsPrevious(T data) {
        if (this->head == nullptr) {
            auto *temp = new Link<T>(data);
            temp->setNext(temp);
            temp->setPrevious(temp);
            this->head = temp;
            this->size++;
        } else {
            auto *temp = new Link<T>(data);
            this->head->getPrevious()->setNext(temp);
            temp->setNext(this->head);
            temp->setPrevious(this->head->getPrevious());
            this->head->setPrevious(temp);
            this->size++;
        }
    }

    void pushAsNext(T data) { //push the new data as head's next
        if (this->head == nullptr) {
            auto *temp = new Link<T>(data);
            temp->setNext(temp);
            temp->setPrevious(temp);
            this->head = temp;
            this->size++;
        } else {
            auto *temp = new Link<T>(data);
            this->head->getNext()->setPrevious(temp);
            temp->setPrevious(this->head);
            temp->setNext(this->head->getNext());
            this->head->setNext(temp);
            this->size++;
        }
    }

    void clear() {
        while(this->size){
            this->popToNext();
        }
    }

    void setThisData(T data) {
        this->head->setData(data);
    }

    T getThisData() {
        return this->head->getData();
    }

    void popToNext() { //pop head->data and head=head->next
        auto *temp = this->head;
        this->head->getPrevious()->setNext(this->head->getNext());
        this->head->getNext()->setPrevious(this->head->getPrevious());
        this->head = this->head->getNext();
        delete (temp);
        this->size--;
    }

    void popToPrevious() {
        auto *temp = this->head;
        this->head->getPrevious()->setNext(this->head->getNext());
        this->head->getNext()->setPrevious(this->head->getPrevious());
        this->head = this->head->getPrevious();
        delete (temp);
        this->size--;
    }

    void moveToNext() { //move head to head->next
        this->head = this->head->getNext();
    }

    void moveToPrevious() {
        this->head = this->head->getPrevious();
    }

    int getSize(){
        return this->size;
    }
};
#endif //CIRCLEQUEUE_DCQUEUE_H
