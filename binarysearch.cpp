/* 
 * 二分查找算法
 * 
 *  */

#include <iostream>
#include "utils.h"
#include <cstring>

using namespace std;

/* 
 * 二分查找
 *
 *  */
int bsearch(int data[], int len, int value)
{
    int low, high, mid;
    low = 0;
    high = len-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(data[mid] == value)
        {
            return mid;
        } else if (data[mid]<value)
        {
            low = mid+1;
        } else if(data[mid]>value)
        {
            high = mid -1;
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
    cout<<"index -- "<<bsearch(data, size, target)<<endl;
}
