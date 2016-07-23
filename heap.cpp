#include <iostream>

#include "heap.h"

using namespace std;

template<class T>
Heap<T>::Heap(bool (*func)(T, T)){
    greater = func;
    this->list_init();
}

template<class T>
void Heap<T>::heap_insert_elem(T t){
    this->list_insert(this->len, t);        //将新增元素插入顺序表，也就是堆底
    int child_index = this->len-1;          
    int parent_index = (int)(child_index-1)/2;
    T temp = this->elem[child_index];
    while(child_index > 0){                 //通过循环向上调整堆
        if(greater(this->elem[parent_index], this->elem[child_index]))
            break;
        else{
            this->elem[child_index] = this->elem[parent_index];
            this->elem[parent_index] = temp;
            child_index = parent_index;
            parent_index = (int)(child_index-1)/2;
        }
    }
    this->elem[child_index] = temp;
}

template <class T>
T Heap<T>::heap_get_top() {
    return this->elem[0];
}

template <class T>
void Heap<T>::heap_delete_top() {    
    this->elem[0] = this->elem[--this->len];    //删除堆顶元素并将最后一个元素存入堆顶

    
    int parent_index = 0;
    int child_index = 1;
    while(child_index < this->len){             //通过循环为堆顶元素寻找合适位置
        
        if(child_index < this->len-1&& greater(this->elem[child_index], this->elem[child_index+1]) == false)
            ++child_index;                      //找出左右子节点中较大的子节点
        if(greater(this->elem[parent_index], this->elem[child_index]))
            break;                              //双亲节点已经不小于子节点，调整完成
        else{                                   //交换双亲节点与较大子节点        
            T temp = this->elem[parent_index];
            this->elem[parent_index] = this->elem[child_index];
            this->elem[child_index] = temp;
            parent_index = child_index;
            child_index = 2 * parent_index + 1;
        }
    }
}

template class Heap<Patient>;
