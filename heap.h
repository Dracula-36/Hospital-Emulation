#ifndef HEAP_H
#define HEAP_H

#include "sqlist.h"

template<class T>
class Heap: public Sqlist<T> {
public:
    bool (*greater)(T t1, T t2);        //优先级比较函数

    Heap(bool (*func)(T t1, T t2));

    void heap_insert_elem(T t);         //向堆中插入元素
    T heap_get_top();                   //获取堆顶元素
    void heap_delete_top();             //删除堆顶的元素

};

#endif // HEAP_H
