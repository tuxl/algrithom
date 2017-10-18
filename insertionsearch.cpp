/* 
 * 插值查找
 * 二分查找变种 优化对比元素的选择
 *  */
#include <iostream>
#include "utils.h"

using namespace std;


int insertionsearch(int data[], int len, int value)
{
    int mid, low, high;
    low = 0;
    high = len-1;
    while(low <= high)
    {
        mid = low + ((value-data[low])/(data[high]-data[low]))*(high-low);
        if (data[mid] == value)
        {
            return mid;
        } else if (data[mid]<value)
        {
            low = mid + 1;
        } else if(data[mid]>value)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[])
{
    int size = atoi(argv[1]);
    int target = atoi(argv[2]);
    int* data = new int[size];
    for(int i=0; i<size; i++)
    {
        data[i] = i;
    }
    // printArrayint(data, size);
    cout<<"index -- "<<insertionsearch(data, size, target)<<endl;
   
}

