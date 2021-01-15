#include <iostream>
using namespace std;

class RentalRobot
{
    private:
        enum eSTATE
        {
            STATE_WAITING = 0,
            STATE_RECEIVING_FORM,
            STATE_RENT_APARTMENT,
            STATE_FULL_RENTED
        };
        int mNumberOfDepartments;
        int mState;
    public:
        RentalRobot(int numberOfDepartment)
        {
            mNumberOfDepartments = numberOfDepartment;
            mState = STATE_WAITING;
        }
        void getForm()
        {
            switch (mState)
            {
            case STATE_WAITING:
                mState = STATE_RECEIVING_FORM;
                cout <<"thansk for the form"<<endl;
                break;
            case STATE_RECEIVING_FORM:
                cout <<"you already get the form"<<endl;
                break;
            case STATE_RENT_APARTMENT:
                cout <<"please wait, you are renting the room"<<endl;
                break;
            case STATE_FULL_RENTED:
                cout <<"Sorry, all room fulled" <<endl;
                break;
            }
        }
};

int main()
{
    cout << "hello there"<<endl;
    return 0;
}