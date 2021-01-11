#include <iostream>
#include<string>
using namespace std;

class Array
{
    private:
        int *_pData;
        int _n;
    public:
        Array(int n)
        {
            _pData = new int[n];
            _n = n;
        }
    const Array &Assign()
}