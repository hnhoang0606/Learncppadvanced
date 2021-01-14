#include <iostream>
using namespace std;

class RentalRobot
{
    private:
        enum eSTATE
        {
            STATE_WAITING = 0;
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
            case :
                /* code */
                break;
            
            default:
                break;
            }
        }
};