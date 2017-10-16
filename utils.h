/* 
 * 随机数生成类
 *  */
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Rander{
    public:
        Rander(int r);
        int range;
        int genNumber();
        int* genIntArray(int size);
};

int* Rander::genIntArray(int size)
{
    int* data = new int[size];
    for(int i = 0; i < size; i++)
    {
        data[i] =  genNumber();
    }
    return data;
}

Rander::Rander(int r):range(r){
    srand((unsigned)time(0));
}

int Rander::genNumber()
{
    return rand() % range;
}

/* 
 * 验证数组里面是否顺序存储了数字 由小到大
 *  */
bool validateOrderedArray(int numberlist[], int len )
{
    bool result = true;
    for(int i=0; i<(len-1); i++)
    {
        if(numberlist[i] > numberlist[i+1])
        {
            result = false;
            break;
        }
    }
    return result;
}

/* 
 * 打印输出int型数组
 *  */
void printArrayint(int numbers[], int len)
{
    for(int i=0; i < len; i++)
    {
        cout<<numbers[i]<<"  ";
    }
    cout<<endl;
}

/* 
 * 交换数组中的两个元素
 *  */
void arraySwap(int* data, int x, int y)
{
    int temp = data[y];
    data[y] = data[x];
    data[x] = temp;
}
