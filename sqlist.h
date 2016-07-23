#ifndef SQLIST_H
#define SQLIST_H

#include "patient.h"

#define INITSIZE 1000
#define INCREMENT 10
#define MAXSIZE 999

template<class T>
class Sqlist
{
public:
    T* elem;        //顺序表数组元素指针
    int len;        //当前顺序表长度
    int list_size;  //顺序表最大长度

    void list_init();               //初始化顺序表
    void list_destroy();            //销毁顺序表
    void list_clear();              //清空顺序表
    bool list_is_empty();           //判断顺序表是否为空
    bool list_is_full();            //判断顺序表是否为满
    int list_get_len();             //获取顺序表长度
    void list_insert(int i, T t);   //在顺序表第i处插入元素
    void list_delete_elem(int i);   //删除顺序表第i处的元素
    T list_get_item(int i);         //返回顺序表第i处的元素

};

#endif // SQLIST_H
