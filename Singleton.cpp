#include<string>
#include<iostream>
#include<Mutex>
using namespace std;
class Database
{
    private:
        static Database* mInstancePTr;
        int mRecord;
        string mName;
        static mutex mLocker;
        Database(string filename)
        {
            mRecord = 0;
            mName = filename;
        }
    public:

        void editRecord(string operation)
        {
            cout << "this is example of singleton parttenr: "<< operation <<"---"<<"operation on record" << mRecord << "in Database" << mName << endl ;

        }

        string getName()
        {
            return mName;
        }
        static Database* GetInstant(string filename)
        {
            mLocker.lock();
            if(mInstancePTr == nullptr)
            {
                mInstancePTr = new Database(filename);
            }
            mLocker.unlock();
            return mInstancePTr;
        }
};
Database* Database :: mInstancePTr = nullptr;

int main()
{

    Database *database;
    database = Database :: GetInstant("product");
    cout << "this is the: "<<database ->getName() << endl;
    database = Database :: GetInstant("Employee");
    cout << " this is the "<< database ->getName() << endl;

    return 0;

}