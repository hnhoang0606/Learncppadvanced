#include<iostream>
using namespace std;

// Command Interface
class Command
{
    public:
        virtual void Execute() = 0;
};

//Receiver class

class Light
{
    public:
        void On()
        {
            cout << "The light is on \n";
        }
        void Off()
        {
            cout <<"The Light is off" <<endl;
        }
};

// command for turning on the light

class LightOffCommand: public Command
{
    private:
        Light *mLight;
    public:
        LightOffCommand(Light *light) : mLight(light) {}
        void Execute()
        {
            mLight -> Off();
        }
};

class LightOnCommand: public Command
{
    private:
        Light *mLight;
    public:
        LightOnCommand(Light *light) : mLight(light) {}
        void Execute()
        {
            mLight -> On();
        }
};

//Invoker

class RemoteControl
{
    private:
        Command *command;
    public:
        void SetCommand(Command *command1)
        {
            command = command1;
        }
        void ButtonPress()
        {
            command ->Execute();
        }
};

int main()
{
    //Receiver
    Light *light = new Light;

    // Concrete Command Object

    LightOnCommand *lightOn = new LightOnCommand(light);
    LightOffCommand *lightOff = new LightOffCommand(light);

    //involker Object
    RemoteControl *Control = new RemoteControl;

    //execute

    Control ->SetCommand(lightOn);
    Control ->ButtonPress();
    Control ->SetCommand(lightOff);
    Control ->ButtonPress();

    return 0;

}

