/* 
 * 快速排序
 *  */
#include "utils.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

inline int partition(int* data, int left, int right)
{
    int index = left;
    //此处比较元素的选取直接使用的是right
    //这种方法过于简单 经过测试 当数据
    //分布范围较小的情况下性能退化严重
    //需要使用更好方法选择比较元素
    int flag = data[right];

    for(int i=left; i<right; i++)
    {
        if(data[i] < flag)
        {
            int temp = data[i];
            data[i] = data[index];
            data[index] = temp;
            index++;
        }
    }
    data[right] = data[index];
    data[index] = flag;
    return index;
}

int arraySize = 10;

void quicksort(int* data, int left, int right)
{
    if(right > left)
    {
        int pivotposition = partition(data, left, right);
        // printArrayint(data, arraySize);
        // cout<<"~~"<<pivotposition<<endl;
        quicksort(data, left, pivotposition-1);
        quicksort(data, pivotposition+1, right);
    }
}

int cmp ( const void *a , const void *b  ) 
{ 
    return *(int *)a - *(int *)b; 
}


void mysort(int size)
{
    Rander dataGenerator(1000000);
    int * data = dataGenerator.genIntArray(size);
    time_t t_start ;
    time_t t_end;
    cout<<"for myself  " <<endl;
    time(&t_start);
    quicksort(data, 0, arraySize-1);
    time(&t_end);
    cout<<"耗时 -- "<<difftime(t_end, t_start)<<endl;
    printArrayint(data, arraySize);
}

void forqsort(int size)
{
    Rander dataGenerator(1000000);
    time_t t_start ;
    time_t t_end;
    int * data = dataGenerator.genIntArray(size);
    cout<<"for qsort " <<endl;
    time(&t_start);
    qsort(data, arraySize, sizeof(int), cmp);
    time(&t_end);
    cout<<"耗时 -- "<<difftime(t_end, t_start)<<endl;
    // printArrayint(data, arraySize);
}

int main(int argc, char* argv[])
{
    arraySize = atoi(argv[2]);
    if(argv[1][0] == 'm')
    {
        mysort(arraySize);
    } else if(argv[1][0] == 'q')
    {
        forqsort(arraySize);
    } else 
    {
        mysort(arraySize);
        forqsort(arraySize);
    }
}
