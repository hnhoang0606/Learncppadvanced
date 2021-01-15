#include<iostream>
#include<vector>
#include<string>
using namespace std;

class IObserver
{
    public:
        virtual void Update(string operation, string record) = 0;
};

class ISubject
{
    public:
        virtual void RegisterObserver(IObserver *o) = 0;
        //virtual void RemoveObserver(IObserver *o) = 0;
        virtual void NotifyObserver() = 0;
};


class Database: public ISubject
{
    private:
        vector <IObserver *> mObservers;
        string mOperation;
        string mRecord;
    public:
        Database() {}
        void RegisterObserver(IObserver *o)
        {
            mObservers.push_back(o);
        }
        // void RemoveObserver(IObserver *o)
        // {
        //    auto observer = find(mObservers.begin(), mObservers.end(), o);
        //     if(observer!=mObservers.end())
        //     {
        //         mObservers.erase(observer,observer +1);
        //     }
        // }
        void NotifyObserver()
        {
            for(auto &o : mObservers)
            {
                o ->Update(mOperation,mRecord);
            }
        }

        void EditRecord(string Operator, string Record)
        {
            mOperation = Operator;
            mRecord = Record;
            NotifyObserver();
        }
};

class Client: public IObserver
{
    void Update(string operation, string record)
    {
        cout << "client:   " <<operation << "  operation was performed on " << record <<endl;
    }
};

class Boss: public IObserver
{
    void Update(string operation, string record)
    {
        cout << "Boss: " << operation << " operation was performed on "<< record <<endl;
    }
};

int main()
{
    Database database;
    Client client;
    Boss boss;


    database.RegisterObserver(&client);
    database.RegisterObserver(&boss);

    database.EditRecord("Delete", "record1");
    return 0;
}