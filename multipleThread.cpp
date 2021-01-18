#include<iostream>
#include<thread>
using namespace std;

void foo(int z)
{
    for(int i=0; i < z; i++ )
    {
        cout <<"Thread using funtion pointer as callable\n";
    }
}

class thread_object
{
    public:
        void operator() (int x)
        {
            for (int i =0; i< x; i++)
            {
                cout << "Thread using funtion object as callable\n ";
            }
        }
};

int main()
{
    thread th1(foo,3);
    thread th2(thread_object(),3);

    auto f = [] (int x)
    {
        for (int i =0; i < x;i ++)
        {
            cout<<"Thread using lampda expresstion as callable\n";
        }
    };
    thread th3(f,3);
    th1.join();
    th2.join();
    th3.join();
    return 0;
}