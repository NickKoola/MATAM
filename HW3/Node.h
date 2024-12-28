//
// Created by Bar Kalandarov on 12/12/2022.
//

#ifndef EX3_NODE_H
#define EX3_NODE_H

template <class T>
class Node {
    T m_data;
    Node<T>* m_next;

public:
    explicit Node(T data);
    //Node(const Node& other);
    //~Node() = default;
    T& getData();
    Node<T>* getNext() const;
    void setNext(Node<T>* node);
};

template <class T>
Node<T>::Node(T data) : m_data(data) {
    this->m_next = nullptr;
}

template <class T>
T& Node<T>::getData() {
    return this->m_data;
}

template <class T>
Node<T> *Node<T>::getNext() const {
    return this->m_next;
}

template <class T>
void Node<T>::setNext(Node<T> *node) {
    this->m_next = node;
}



#endif //EX3_NODE_H
