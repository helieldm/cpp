#include <iostream>
using namespace std;

float addArray(int index, int size, int *array)
{
    if (size <= 0)
    {
        return 0;
    }
    if (index != size - 1)
    {
        return array[index] + addArray(++index, size, array);
    }
    else
    {
        return array[index];
    }
}
float betterAddArray(int size, int *array)
{
    if (size <= 0)
    {
        return 0;
    }
    return array[--size] + betterAddArray(size, array);
    /*
    if (size == 0)
    {
        return array[size];
    }
    else
    {
        return array[--size] + betterAddArray(size, array);
    }*/
}

int main(int argc, char **argv)
{

    int a[] = {3, 4, 5};
    int b[] = {3, 3, 3, 12, 12, 12};
    cout << betterAddArray( 3, a) << endl;
    cout << betterAddArray(6, b) << endl;
}