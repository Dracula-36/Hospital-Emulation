#include <iostream>

#include "sqlist.h"
using namespace std;

template<class T>
void Sqlist<T>::list_init()
{
    elem = new T[INITSIZE];
    len = 0;
    list_size = INITSIZE;
    if(elem == NULL)
        return;
}

template<class T>
void Sqlist<T>::list_destroy()
{
    delete[] elem;
    elem = NULL;
}

template<class T>
void Sqlist<T>::list_clear()
{
    len = 0;
}

template<class T>
bool Sqlist<T>::list_is_empty()
{
    if (len == 0)
        return true;
    else
        return false;
}

template<class T>
bool Sqlist<T>::list_is_full()
{
    if (len == MAXSIZE)
        return true;
    else
        return false;
}

template<class T>
int Sqlist<T>::list_get_len()
{
    return len;
}

template<class T>
void Sqlist<T>::list_insert(int i, T t)
{
    if(i < 0 || i > len)
        return;

    if(len >= INITSIZE)    //原有数需表存储空间不够
    {
        T* temp = new T[list_size + INCREMENT];
        if(!temp)
            return;
        for(int j=0,k=0; k<len; ++j, ++k)
        { // 将elem中元素复制至temp中，同时插入新元素
            if (i == j)
                temp[j] = t;
            else
                temp[j] = elem[k];
        }
        delete[] elem;
        elem = temp;
        list_size += INCREMENT;
        len++;
    }
    else
    {
        for(int j=len-1; j>=i; ++j)
        {
            elem[j+1] = elem[j];
        }
        elem[i] = t;
        len++;
    }
}

template<class T>
void Sqlist<T>::list_delete_elem(int i)
{
    for(int j=i; j<len-1; ++j)
        elem[j] = elem[j+1];
    --len;
}

template<class T>
T Sqlist<T>::list_get_item(int i)
{
    return elem[i];
}


template class Sqlist<Patient>;
