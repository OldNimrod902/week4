#include <bits/stdc++.h>

using namespace std;
bool notExit=true;

double velocity_Velocity(double d, double t) {
    return d/t;
}

double velocity_Distance(double v, double t) {
    return v*t;
}

double velocity_Time(double d, double v) {
    return d/v;
}

void velocity_calc() {
    int option;
    cout << endl << "VELOCITY" << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] How fast does something travel (v)" << endl;
    cout << "[2] How long does it take to travel a distance (t)" << endl;
    cout << "[3] How far can something travel in an amount of time (d)" << endl;

    cout << "Enter your choice: ";
    cin >> option;
    if(option == 1) {
        double d, t;
        cout << "Enter the distance traveled (m): ";
        cin >> d;
        cout << "Enter the time it took to travel that distance (s): ";
        cin >> t;
        cout << "Your object has a velocity of " << velocity_Velocity(d, t) << " m/s";
    }
}

void main_menu() {
    int option;
    cout << endl << "===MAIN=MENU==================" << endl;
    cout << "Select a menu item below:" << endl << endl;
    cout << "[1] Velocity calculations" << endl;
    cout << "[0] Exit" << endl;

    cout << "Enter your selection: ";
    cin >> option;
    if(option == 1) velocity_calc();
    else if(option == 0) {
        notExit=false;
    }
    else {
        cout << "No such option exists";
        main_menu();
    }

}

int main()
{
    cout << "====  PHYSICS CALCULATOR  ====" << endl;
    cout << "------  MADE FOR TERRA  ------" << endl;
    cout << "-------  by Timoti902  -------" << endl << endl;
    do {
        main_menu();
    } while(notExit);
    return 0;
}