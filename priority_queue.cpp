#include <iostream>

#include "priority_queue.h"

using namespace std;

template<class T>
PriorityQueue<T>::PriorityQueue(bool (*greater)(T, T)) :  Heap<T>(greater){
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &pd):  Heap<T>(pd.greater){

    this->len = pd.len;
    this->list_size = pd.list_size;
    this->elem = new T[this->list_size];
    for(int i=0; i < this->list_size; ++i)
        this->elem[i] = pd.elem[i];
}

template<class T>
PriorityQueue<T>::PriorityQueue(bool (*greater)(T, T), const PriorityQueue &pd):  Heap<T>(greater){

    this->len = pd.len;
    this->list_size = pd.list_size;
    this->elem = new T[this->list_size];
    for(int i=0; i < this->list_size; ++i)
        this->elem[i] = pd.elem[i];
}

template<class T>
void PriorityQueue<T>::insert(T t){
    //调用堆的插入
    this->heap_insert_elem(t);
}

template<class T>
void PriorityQueue<T>::delete_elem(){
    //调用堆的删除，删除堆顶元素
    this->heap_delete_top();
}

template<class T>
void PriorityQueue<T>::clear_all(){
    //调用线性表的清空
    this->list_clear();
}

template<class T>
void PriorityQueue<T>::destroy(){
    //调用线性表的删除
    this->destroy();
}

template<class T>
int PriorityQueue<T>::size(){
    return this->list_get_len();
}

template<class T>
T PriorityQueue<T>::top(){
    return this->heap_get_top();
}

template<class T>
bool PriorityQueue<T>::empty(){
    return this->list_is_empty();
}

 template<class T>
bool PriorityQueue<T>::full(){
    return this->list_is_full();
}

template class PriorityQueue<Patient>;
