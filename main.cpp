#include <bits/stdc++.h>

using namespace std;
bool notExit=true;
const double g=9.81;

void clear_console() { // thanks to that guy on stackoverflow
    cout << "\033[2J\033[1;1H";
}

double velocity_Velocity(double d, double t) {
    return d/t;
}

double velocity_Distance(double v, double t) {
    return v*t;
}

double velocity_Time(double d, double v) {
    return d/v;
}

double density_Density(double v, double m) {
    return m/v;
}

double density_Volume(double d, double m) {
    return m/d;
}

double density_Mass(double v, double d) {
    return v*d;
}

double kinetic_Energy(double m, double v) {
    return (m*v*v)/2;
}

double kinetic_Velocity(double e, double m) {
    return sqrt((2*e)/m);
}

double kinetic_Mass(double v, double e) {
    return (2*e)/(v*v);
}

double potential_Energy(double m, double h) {
    return m*g*h;
}

double potential_Height(double e, double m) {
    return e/(m*g);
}

double potential_Mass(double e, double h) {
    return e/(h*g);
}

void velocity_calc() {
    int option;
    cout << endl << "VELOCITY" << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] How fast does something travel (v)" << endl;
    cout << "[2] How long does it take to travel a distance (t)" << endl;
    cout << "[3] How far can something travel in an amount of time (d)" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to main menu" << endl;

    cout << "Enter your selection: ";
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
    else if(option==0) {
        clear_console();
        return;
    }
    else {
        cout << "No such option exists.";
    }

    cout << endl << "Press enter to return";
    cin.ignore();
    cin.get();
    clear_console();
    velocity_calc();
}

void density_calc() {
    int option;
    cout << endl << "DENSITY" << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] The density of something" << endl;
    cout << "[2] The volume of something" << endl;
    cout << "[3] The mass of something" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to main menu" << endl;

    cout << "Enter your selection: ";
    cin >> option;
    if(option == 1) {
        double v, m;
        cout << "Enter the volume (m^3): ";
        cin >> v;
        while(v<=0) {
            cout << "An object cannot have negative or no volume. Please, enter a poitive value: ";
            cin >> v;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a density of " << density_Density(v, m) << " m^3/kg";
    }
    else if(option == 2) {
        double v, m;
        cout << "Enter the density (m^3/kg): ";
        cin >> v;
        while(v<=0) {
            cout << "An object cannot have negative or no density. Please, enter a poitive value: ";
            cin >> v;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a volume of " << density_Volume(v, m) << " m^3";
    }
    else if(option == 3) {
        double d, v;
        cout << "Enter the volume (m^3): ";
        cin >> v;
        while(v<=0) {
            cout << "An object cannot have negative or no volume. Please, enter a poitive value: ";
            cin >> v;
        }
        cout << "Enter the density (m^3/kg): ";
        cin >> d;
        while(d<=0) {
            cout << "An object cannot have negative or no density. Please, enter a positive value: ";
            cin >> d;
        }
        cout << "Your object has a mass of " << density_Mass(v, d) << " kg";
    }
    else if(option == 0) {
        clear_console();
        return;
    }
    else{
        cout << "No such option exists.";
    }
    cout << endl << "Press enter to return";
    cin.ignore();
    cin.get();
    clear_console();
    density_calc();
}

void energy_kinetic();
void energy_potential();

void energy_calc_menu() {
    int option;
    cout << endl << "ENERGY" << endl;
    cout << "What type of energy would you like to work with?" << endl;
    cout << "[1] Kinetic energy" << endl;
    cout << "[2] Potential energy" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to main menu" << endl;

    cout << "Enter your selection: ";
    cin >> option;

    if(option == 1) energy_kinetic();
    else if(option == 2) energy_potential();
    else if(option == 0) {
        clear_console();
        return;
    }
    else {
        cout << endl << "No such option exists.";
    }
    clear_console();
    energy_calc_menu();
}

void energy_kinetic() {
    int option;
    cout << endl << "KINETIC ENERGY" << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] The kinetic energy of something" << endl;
    cout << "[2] The velocity of something" << endl;
    cout << "[3] The mass of something" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to energy calculations" << endl;
    
    cout << "Enter your selection: ";
    cin >> option;

    if(option == 1) {
        double v, m;
        cout << "Enter the velocity (m/s): ";
        cin >> v;
        while(v<0) {
            cout << "An object cannot have a negative velocity. Please, enter a poitive value: ";
            cin >> v;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a kinetic energy of " <<  kinetic_Energy(m, v) << " J";
    }
    else if(option == 2) {
        double e, m;
        cout << "Enter the kinetic energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative kinetic energy. Please, enter a poitive value: ";
            cin >> e;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a velocity of " <<  kinetic_Velocity(e, m)<< " m/s";
    }
    else if(option == 3) {
        double e, v;
        cout << "Enter the kinetic energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative kinetic energy. Please, enter a poitive value: ";
            cin >> e;
        }
        cout << "Enter the velocity (m/s): ";
        cin >> v;
        while(v<0) {
            cout << "An object cannot have a negative velocity. Please, enter a poitive value: ";
            cin >> v;
        }
        cout << "Your object has a mass of " <<  kinetic_Mass(v, e) << " kg";
    }
    else if(option==0) {
        clear_console();
        return;
    }
    else {
        cout << "No such option exists.";
    }

    cout << endl << "Press enter to return";
    cin.ignore();
    cin.get();
    clear_console();
    energy_kinetic();
}

void energy_potential() {
    int option;
    cout << endl << "POTENTIAL ENERGY" << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] The potential energy of something" << endl;
    cout << "[2] The height of something" << endl;
    cout << "[3] The mass of something" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to energy calculations" << endl;
    
    cout << "Enter your selection: ";
    cin >> option;

    if(option == 1) {
        double h, m;
        cout << "Enter the height (m): ";
        cin >> h;
        while(h<0) {
            cout << "An object cannot have a negative height. Please, enter a poitive value: ";
            cin >> h;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a kinetic energy of " <<  potential_Energy(m, h) << " J";
    }
    else if(option == 2) {
        double e, m;
        cout << "Enter the potential energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative kinetic energy. Please, enter a poitive value: ";
            cin >> e;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your is " <<  potential_Height(e, m) << " m above the ground";
    }
    else if(option == 3) {
        double e, h;
        cout << "Enter the potential energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative kinetic energy. Please, enter a poitive value: ";
            cin >> e;
        }
        cout << "Enter the height (m): ";
        cin >> h;
        while(h<0) {
            cout << "An object cannot have a negative height. Please, enter a poitive value: ";
            cin >> h;
        }
        cout << "Your object has a mass of " <<  potential_Mass(e, h) << " kg";
    }
    else if(option==0) {
        clear_console();
        return;
    }
    else {
        cout << "No such option exists.";
    }

    cout << endl << "Press enter to return";
    cin.ignore();
    cin.get();
    clear_console();
    energy_potential();
}

void main_menu() {
    int option;
    cout << endl << "===MAIN=MENU==================" << endl;
    cout << "Select a menu item below:" << endl << endl;
    cout << "[1] Velocity calculations" << endl;
    cout << "[2] Density calculations" << endl;
    cout << "[3] Energy calculations" << endl;
    cout << "==============================" << endl;
    cout << "[0] Exit" << endl;

    cout << "Enter your selection: ";
    cin >> option;
    clear_console();
    if(option == 1) velocity_calc();
    else if(option == 2) density_calc();
    else if(option == 3) energy_calc_menu();
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
    clear_console();
    cout << "====  PHYSICS CALCULATOR  ====" << endl;
    cout << "------  MADE FOR TERRA  ------" << endl;
    cout << "-------  by Timoti902  -------" << endl << endl;
    cout << "Note: the app displays SI units by default, but most calculations\nwork with any unit, just be careful with mixing them." << endl << endl;
    do {
        main_menu();
    } while(notExit);
    return 0;
}