#ifndef _PRIORITY_QUEE_H
#define _PRIORITY_QUEE_H

#include "heap.h"

template<class T>
class PriorityQueue: public Heap<T> {
public:
    PriorityQueue(bool (*greater)(T, T));
    PriorityQueue(const PriorityQueue& pd);
    PriorityQueue(bool (*greater)(T, T), const PriorityQueue& pd);

    int size();             //获取优先级队列长度
    void insert(T t);       //插入新元素
    void delete_elem();     //删除元素
    void clear_all();       //清空优先级队列
    void destroy();         //销毁优先级队列
    T top();                //获取优先级队首元素
    bool empty();           //判断优先级队列是否为空
    bool full();            //判断优先级队列是否已满
};

#endif
