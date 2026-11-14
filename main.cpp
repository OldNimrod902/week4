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
        while(d<0) {
            cout << "An object cannot travel negative distance. Please, enter a poitive value: ";
            cin >> d;
        }
        cout << "Enter the time it took to travel that distance (s): ";
        cin >> t;
        while(t<=0) {
            cout << "An object cannot travel for a negative amount of time. Please, enter a positive value: ";
            cin >> t;
        }
        cout << "Your object has a velocity of " << velocity_Velocity(d, t) << " m/s";
    }
    else if(option == 2) {
        double v, d;
        cout << "Enter the velocity of the object (v): ";
        cin >> v;
        while(v<0) {
            cout << "The velocity of an object cannot be negative. Please, enter a positive value: ";
            cin >> v;
        }
        cout << "Enter the distance traveled (m): ";
        cin >> d;
        while(d<0) {
            cout << "An object cannot travel negative distance. Please, enter a poitive value: ";
            cin >> d;
        }
        cout << "It took " << velocity_Time(d, v) << "s to travel that distance";
    }
    else if(option == 3) {
        double t, v;
        cout << "Enter the velocity of the object (v): ";
        cin >> v;
        cout << "Enter for how long did the object move (t): ";
        cin >> t;
        while(t<=0) {
            cout << "An object cannot travel for a negative amount of time. Please, enter a positive value: ";
            cin >> t;
        }
        cout << "The object traveled " << velocity_Distance(v, t) << "m";
    }
}

void main_menu() {
    int option;
    cout << endl << endl << "===MAIN=MENU==================" << endl;
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