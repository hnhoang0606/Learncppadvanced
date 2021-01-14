#include<iostream>
using namespace std;

class Button
{
    public:
       Button()
       {
           cout << "this is original Button"<<endl;
       }
};
class SBar
{

};

class LightButton: public Button
{
    public:
        LightButton()
        {
            cout << " this is Light Button" <<endl;
        }
};

class DarkButton: public Button
{

};

class LightSBar: public SBar
{
    public:
        LightSBar()
        {
            cout << " this is Light SBar" <<endl;
        }
};

class DarkSBar: public SBar
{

};

class WightFactory
{
    public:
        virtual Button* CreateButton() = 0;
        virtual SBar* CreateSBar() = 0;
};
class LightWightFactory: public WightFactory
{
    public:
        Button* CreateButton()
        {
            cout <<" this is Create Button" <<endl;
            return new LightButton();
        }
        SBar* CreateSBar()
        {
            cout <<" this is Create SBar" <<endl;
            return new LightSBar();
        }
}; 

int main()
{

    //LightWightFactory lightWightFactory;
    WightFactory *wightFactory = new LightWightFactory;
    Button *button = wightFactory ->CreateButton();
    SBar *SBar = wightFactory ->CreateSBar();
    return 0;
}