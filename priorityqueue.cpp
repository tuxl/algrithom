/* 
 * 基于最大堆的优先队列
 *  */

#include "utils.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;;

typedef  struct {
    int size;    //队列长度
    int len;     //已使用的长度
    int* data;
}   p_queue;


bool floatDown(int* data, int len, int* current);
bool validateBigHeap(p_queue*);

/* 
 * 验证最大堆正确性
 *  */
bool validateBigHeap(p_queue* q)
{
    int* data = q->data;
    int len = q->len;
    for(int i=1; i<len; i++)
    {
        int c_left = 2*i;
        int c_right = 2*i+1;
        if(c_left<=len)
        {
            if(data[c_left] > data[i])
            {
                return false;
            }
        }
        if(c_right<=len)
        {
            if(data[c_right] > data[i])
            {
                return false;
            }
        }
    }
    return true;
}

/* 
 * 判断队列是否已满
 * 队列满返回true
 * 否则返回 false
 * 
 *  */
bool fullQueue(p_queue* q)
{
    if(q->size == q->len)
    {
        return true;
    } else 
    {
        return false;
    }
}

/* 
 * 判断队列是否为空 
 * 如果为空 则为true
 * 否则为 false
 *  */
bool emptyQueue(p_queue* q)
{
    if(q->len == 0)
    {
        return true;
    } else {
        return false;
    }
}

/* 
 * 添加元素
 *  */
bool add(p_queue* q, int v)
{
    if(fullQueue(q))
    {
        cout<<"队列已满,无法添加新元素"<<endl;
        return false;
    }
    q->len++;
    q->data[q->len] = v;

    //因后面需要频繁使用data指针
    //此处先取出data指针以提高性能
    int* data = q->data;

    int current = q->len;
    while(current != 1)
    {
        int parent = current/2;
        if(data[parent] < data[current])
        {
            //父元素小于子元素 则元素上浮
            int temp = data[current];
            data[current] = data[parent];
            data[parent] = temp;
            current = parent;
        } else 
        {
            //如果父元素大于当前元素 则跳出循环
            break;
        }
    }
}

/* 
 * 删除队列元素
 *  */
bool popOut(p_queue* q, int* v)
{
    if(emptyQueue(q))
    {
        cout<<"空队列,没有更多元素"<<endl;
        return false;
    }
    int* data = q->data;
    *v = data[1];
    data[1] = data[q->len];
    data[q->len] = 0;
    q->len--;
    int current = 1;
    while(1)
    {
        // printArrayint(q->data, q->size+1);
        if(floatDown(data, q->len, &current) == false)
        {
            break;
        }
        // printArrayint(q->data, q->size+1);
    }
    return true;
}

/* 
 * 元素下沉
 * 可以下沉 返回true 否则返回false
 *  */
bool floatDown(int* data, int len, int* current)
{
    int c_left = (*current)*2;
    int c_right = (*current)*2 + 1;
    // cout<<"L - "<<c_left<<" R -- "<<c_right<<endl;
    int maxnode = 0;
    if(c_left <= len && c_right <= len)
    {
        if(data[c_left]>data[c_right])
        {
            maxnode = c_left;
        } else 
        {
            maxnode = c_right;
        }
    } else if(c_left <= len)
    {
        maxnode = c_left;
    } else if(c_right <= len)
    {
        maxnode = c_right;
    }
    if(maxnode != 0)
    {
        if(data[maxnode]>data[*current])
        {
            arraySwap(data, *current, maxnode);
            *current = maxnode;
            return true;
        }
    }
    return false;
}

/* 
 * 获取队列最大元素
 *  */
bool get(p_queue* q, int* v)
{
    if(emptyQueue(q))
    {
        cout<<"空队列,没有更多元素"<<endl;
        return false;
    }
    *v = q->data[1];
    return true;
}

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    // size = 5;
    p_queue p1;
    p1.size = size;
    p1.len = 0;
    p1.data = new int[size+1];
    memset(p1.data, 0, sizeof(int)*(size+1));
    Random r(100);
    int d[] = {69,75,23,11,9};
    for(int i=1; i<=size; i++)    
    {
        int x = r.genNumber();
        // x = d[i-1];
        cout<<"insert -- "<< x <<endl;
        add(&p1, x);
        // printArrayint(p1.data, size+1);
    }
    if(validateBigHeap(&p1) == false)
    {
        cout<<"wrong heap"<<endl;
    } else 
    {
        cout<<"good heap"<<endl;
    }
    for(int i=0; i<size; i++)
    {
        int x;
        popOut(&p1, &x);
        cout<<"get -- "<<x<<endl;
        // printArrayint(p1.data, size+1);
        if(validateBigHeap(&p1) == false)
        {
            cout<<"wrong heap"<<endl;
            break;
        }
    }
    if(validateBigHeap(&p1) == false)
    {
        cout<<"wrong heap"<<endl;
    } else 
    {
        cout<<"good heap"<<endl;
    }

}

