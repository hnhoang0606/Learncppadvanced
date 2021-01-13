#include<string>
#include<iostream>
using namespace std;

class Monster
{
    public:
        virtual void Appear() = 0;
};

class LION: public Monster
{
    public:
    void Appear()
    {
        cout <<" this is LION" << endl;
    }
};

class DRAGON: public Monster
{
    public:
    void Appear()
    {
        cout <<" this is DRAGON" << endl;
    }
};


enum eMonster
{
    lION,
    dRAGON
};

class MonsterFactory
{
    public:
        MonsterFactory();
        ~MonsterFactory();
        static Monster *CreateMonster(eMonster _emonster)
        {
            switch (_emonster)
            {
            case lION:
                return new LION();
                break;
            
            case dRAGON:
                return new DRAGON();
                break;
            }
        };
};

int main()
{
    Monster *monster = MonsterFactory :: CreateMonster(eMonster:: lION);
    monster ->Appear();
    return 0;
}