//
// Created by Bar Kalandarov on 22/12/2022.
//

//
// Created by Bar Kalandarov on 12/12/2022.
//

#ifndef EX3_Queue_H
#define EX3_Queue_H

#include "Node.h"
#include <iostream>
using std::string;

//~Queue Declaration~//
template <class T>
class Queue {
    Node<T>* m_head;
    Node<T>* m_end;
    int m_size;

    template<class S, class Transformation>
    friend void transform(Queue<S>& queue, Transformation t);

    static void deleteQueue(Node<T>* head);

public:
    Queue();
    Queue(const Queue& other);
    ~Queue();
    Queue& operator=(const Queue& other);

    class Iterator;
    Iterator begin();
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

    void pushBack(T data);
    T& front();
    const T& front() const;
    void popFront();
    int size() const;
    string toString();

    class EmptyQueue{};
};

//~Iterator Declaration~//
template <class T>
class Queue<T>::Iterator {
    Queue<T>* queue;
    Node<T>* node;

    Iterator(Queue<T>* queue, Node<T>* node);

    friend class Queue<T>;

public:
    T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& it) const;
    class InvalidOperation{};
};

//~ConstIterator Declaration~//

template <class T>
class Queue<T>::ConstIterator {
    const Queue<T>* queue;
    Node<T>* node;

    ConstIterator(const Queue<T>* queue, Node<T>* node);

    friend class Queue<T>;

public:
    const T& operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    bool operator!=(const ConstIterator& it) const;
    class InvalidOperation{};
};


//~Queue Implementation~//

template <class T>
Queue<T>::Queue() : m_size(0) {
    this->m_head = nullptr;
    this->m_end = nullptr;
}

template <class T>
Queue<T>::Queue(const Queue<T> &other) : m_size(0){
    if (other.m_head == nullptr) {
        this->m_head = nullptr;
        this->m_end = nullptr;
        return;
    }

    try {
        this->m_head = nullptr;
        for (T data: other) {
            if (this->m_head == nullptr) {
                this->m_head = new Node<T>(data);
                this->m_end = this->m_head;
            } else {
                Node<T> *temp = new Node<T>(data);
                this->m_end->setNext(temp);
                this->m_end = temp;
            }
        }
    } catch (const std::bad_alloc& e) {
        if (this->m_head != nullptr) {
            deleteQueue(this->m_head);
        }
        throw e;
    }

    this->m_size = other.m_size;
}

template<class T>
void Queue<T>::deleteQueue(Node<T>* head) {
    Node<T>* nodeToDelete = head;
    Node<T>* nextNode;

    while (nodeToDelete != nullptr) {
        nextNode = nodeToDelete->getNext();
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }
}


template<class T>
Queue<T>::~Queue() {
    if (this->m_head == nullptr) {
        return;
    }
    deleteQueue(this->m_head);
}


template<class T>
Queue<T> &Queue<T>::operator=(const Queue &other) {
    if (this == &other) {
        return *this;
    }

    //Other queue is empty
    if (other.m_head == nullptr) {
        if (this->m_head != nullptr) {
            deleteQueue(this->m_head);
            this->m_head = nullptr;
            this->m_end = nullptr;
            this->m_size = 0;
        }
        return *this;
    }

    Node<T>* prevHead = this->m_head;
    Node<T>* prevEnd = this->m_end;

    try {
        this->m_head = nullptr;
        for (T data: other) {
            if (this->m_head == nullptr) {
                this->m_head = new Node<T>(data);
                this->m_end = this->m_head;
            } else {
                Node<T> *temp = new Node<T>(data);
                this->m_end->setNext(temp);
                this->m_end = temp;
            }
        }
        this->m_size = other.m_size;
    } catch (const std::bad_alloc& e) {
        //If failed on first allocation, no need to delete anything.
        if (prevHead != this->m_head) {
            deleteQueue(this->m_head);
            this->m_head = prevHead;
            this->m_end = prevEnd;
        }
        throw e;
    }

    if (prevHead != nullptr) {
        deleteQueue(prevHead);
    }

    return *this;
}

template <class T>
void Queue<T>::pushBack(T data) {
    if (this->m_head == nullptr) {
        this->m_head = new Node<T>(data);
        this->m_end = this->m_head;
        this->m_size++;
        return;
    }

    Node<T>* temp = new Node<T>(data);
    this->m_end->setNext(temp);
    this->m_end = temp;
    this->m_size++;
}

template <class T>
T& Queue<T>::front() {
    if (this->m_head == nullptr) {
        throw EmptyQueue();
    }
    return this->m_head->getData();
}

template <class T>
const T& Queue<T>::front() const {
    if (this->m_head == nullptr) {
        throw EmptyQueue();
    }
    return this->m_head->getData();
}

template <class T>
void Queue<T>::popFront() {
    if (this->m_head == nullptr) {
        throw EmptyQueue();
        return;
    }

    Node<T>* temp = this->m_head;
    this->m_head = this->m_head->getNext();

    if (this->m_head == nullptr) {
        this->m_end = nullptr;
    }

    delete(temp);
    this->m_size--;
}

template <class T>
int Queue<T>::size() const {
    return this->m_size;
}

template <class T>
string Queue<T>::toString() {
    string str;
    Node<T>* temp = m_head;

    while (temp != nullptr) {
        str += std::to_string(temp->getData());
        str += ", ";
        temp = temp->getNext();
    }

    return str;
}

//~Iterator Implementation~//
template <class T>
Queue<T>::Iterator::Iterator(Queue<T>* queue, Node<T>* node) : queue(queue), node(node) {}

template <class T>
T& Queue<T>::Iterator::operator*() const {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    return node->getData();
}

//it2 = ++it1;
template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    node = node->getNext();
    return *this;
}

//it2 = it1++;
template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    Iterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& i) const {
    return node != i.node;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::begin() {
    return Iterator(this, this->m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() {
    return Iterator(this, nullptr);
}


//~ConstIterator Implementation~//

template <class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, Node<T>* node) : queue(queue), node(node) {}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    return node->getData();
}

//it2 = ++it1;
template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    node = node->getNext();
    return *this;
}

//it2 = it1++;
template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int) {
    if (node == nullptr) {
        throw InvalidOperation();
    }

    ConstIterator result = *this;
    ++*this;
    return result;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& i) const {
    return node != i.node;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const {
    return ConstIterator(this, this->m_head);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const {
    return ConstIterator(this, nullptr);
}


template<class S, class Transformation>
void transform(Queue<S> &queue, Transformation transformation) {
    for (S& data : queue) {
        transformation(data);
    }
}


template<class T, class Condition>
Queue<T> filter(const Queue<T> &queue, Condition condition) {
    Queue<T> result;

    for (T value : queue) {
        if(condition(value)) {
            result.pushBack(value);
        }
    }

    return result;
}


#endif //EX3_Queue_H
