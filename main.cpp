#include <bits/stdc++.h>

using namespace std;
bool notExit=true;
double g=9.81;
double price_electricity = 0;

char fun_facts[15][200] {
    "Isaac Newton published his three laws of motion in Principia in 1687.",
    "One newton is roughly the weight of a small apple.",
    "If you double an object's speed, its kinetic energy becomes four times bigger.",
    "A typical lightning bolt carries around a billion joules of energy.",
    "Golf ball dimples reduce drag, which lets a golf ball fly much farther than a smooth ball would.",
    "A launch at 45 degrees gives the longest range.",
    "A feather falls slowly on Earth only because of air resistance. In a vacuum, it falls as fast as a Framework 12.",
    "During the Apollo 15 mission in 1971, astronaut David Scott dropped a hammer and a feather on the Moon, and they hit the ground at the same time.",
    "The Sun's surface gravity is about 274 m/s^2, roughly 28 times Earth's.",
    "Static friction is usually stronger than kinetic friction, which is why it's harder to start pushing a heavy object than to keep it sliding.",
    "At the top of Mount Everest, gravity is about 0.3% weaker than at sea level.",
    "Sunlight takes about 8 minutes and 20 seconds to reach Earth.",
    "If an atom were the size of a football stadium, its nucleus would be about the size of a marble.",
    "Voyager 1 is the most distant human-made object ever, currently more than 28 billion km from us.",
    "Water is the densest at 4 degrees Celsius, so it takes up the least amount of space on that temperature."
};

struct questions{
    double answer;
    char text[400];
};

questions quiz_questions[5] = {
    {4.27, "Ratticus is chasing you, because you did not pay your rent in time. He started 10 meters behind you and after 30 seconds,\nhe is only 2 meters behind you. You are running with 4 m/s. How fast is Ratticus, in m/s? v="},
    {5.48, "You just got a shiny iPad Air 11\' M4 from Terra, but you're irresponsible and dropped it.\nIt fell from your hands, 1.5 meters high. How fast did it hit the ground, in m/s? Let g=10 m/s^2 v="},
    {58.86, "Poobert pushes up 3kg of letters up a 2 meter high ramp. How much potential energy do the letters gain in joules? Let g=9.81 m/s^2. E="},
    {0.61, "You just spent your coins on a Blahaj at the shop, but you accidentally left it there. But no worries, Heide threw it after you at 30 degrees with 7 m/s speed. What was the maximum height Blahaj reached in meters? Let g=10 m/s^2 h="},
    {3.16, "You asked Blargh to take you to your island. You were really excited but you fell out of\nhis hot air balloon that was 100 meters in the sky.\nHow much time did elapse, until you were at an equal distance from the ground and the hot air balloon, in seconds? Let g=10 m/s^2 t="}
};

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
    cout << endl << "===VELOCITY=CALCULATIONS======" << endl;
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
            cout << "An object cannot travel negative distance. Please, enter a positive value: ";
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
        while(v<=0) {
            cout << "The velocity of an object cannot be negative. Please, enter a positive value: ";
            cin >> v;
        }
        cout << "Enter the distance traveled (m): ";
        cin >> d;
        while(d<0) {
            cout << "An object cannot travel negative distance. Please, enter a positive value: ";
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
    cout << endl << "===DENSITY=CALCULATIONS=======" << endl;
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
            cout << "An object cannot have negative or no volume. Please, enter a positive value: ";
            cin >> v;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a density of " << density_Density(v, m) << " kg/m^3";
    }
    else if(option == 2) {
        double v, m;
        cout << "Enter the density (kg/m^3): ";
        cin >> v;
        while(v<=0) {
            cout << "An object cannot have negative or no density. Please, enter a positive value: ";
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
            cout << "An object cannot have negative or no volume. Please, enter a positive value: ";
            cin >> v;
        }
        cout << "Enter the density (kg/m^3): ";
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
    cout << endl << "===ENERGY=RELATED=CALC.=======" << endl;
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
    cout << endl << "===KINETIKC=ENERGY============" << endl;
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
            cout << "An object cannot have a negative velocity. Please, enter a positive value: ";
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
            cout << "An object cannot have negative kinetic energy. Please, enter a positive value: ";
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
            cout << "An object cannot have negative kinetic energy. Please, enter a positive value: ";
            cin >> e;
        }
        cout << "Enter the velocity (m/s): ";
        cin >> v;
        while(v<=0) {
            cout << "An object cannot have a negative velocity. Please, enter a positive value: ";
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
    cout << endl << "===POTENTIAL=ENERGY===========" << endl;
    cout << "Currently, the gravitational acceleration is set to " << g << " m/s^2" << endl;
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
            cout << "An object cannot have a negative height. Please, enter a positive value: ";
            cin >> h;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object has a potential energy of " <<  potential_Energy(m, h) << " J";
    }
    else if(option == 2) {
        double e, m;
        cout << "Enter the potential energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative potential energy. Please, enter a positive value: ";
            cin >> e;
        }
        cout << "Enter the mass (kg): ";
        cin >> m;
        while(m<=0) {
            cout << "An object cannot have negative or no mass. Please, enter a positive value: ";
            cin >> m;
        }
        cout << "Your object is " <<  potential_Height(e, m) << " m above the ground";
    }
    else if(option == 3) {
        double e, h;
        cout << "Enter the potential energy (J): ";
        cin >> e;
        while(e<0) {
            cout << "An object cannot have negative kinetic energy. Please, enter a positive value: ";
            cin >> e;
        }
        cout << "Enter the height (m): ";
        cin >> h;
        while(h<=0) {
            cout << "An object cannot have a negative height. Please, enter a positive value: ";
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

void electricity_bill() {
    int option;
    double power, time;
    cout << endl << "===ELECTRICITY=BILL=CALC.=====" << endl;
    if(price_electricity==0) cout << "NOTE: The price of electricity is currently not set. Please, enter a value by selecting [9]." << endl;
    else cout << "The price of 1 kWh is set to " << price_electricity << endl;
    cout << "What would you like to know?" << endl;
    cout << "[1] How much does a specific device cost to maintain?" << endl;
    cout << "[2] How much is the bill for the whole month?" << endl;
    cout << "==============================" << endl;
    cout << "[9] Change electricity price" << endl;
    cout << "[0] Return to main menu" << endl;
    cout << "Enter your selection: ";
    cin >> option;

    if(option == 0) {
        clear_console();
        return;
    }
    else if(price_electricity==0) {
        cout << "First, please enter the price 1 kWh of electricity (don't put currency signs next to it): ";
        cin >> price_electricity;
        while(price_electricity<=0) {
            cout << "Sadly, electricity is not free. Enter a non-zero positive value: ";
            cin >> price_electricity;
        }
    }
    else if(option == 1) {
        cout << "Enter how much is the hourly consumption of the device in watts: ";
        cin >> power;
        while(power<0) {
            cout << "Your device can\'t have negative consumption. Enter a positive value: ";
            cin >> power;
        }
        cout << "Enter for how long did you use the device (hours): ";
        cin >> time;
        while(time<0) {
            cout << "Your device can\'t be used for a negative amount of time. Enter a positive value: ";
            cin >> time;
        }
        cout << "Your device consumed " << power*time/1000 << " kWhs and, it cost you " << power*time*price_electricity/1000; 
    }
    else if(option == 2) {
        cout << "Enter how much do you consume monthly, in kWh: ";
        cin >> power;
        cout << "Your bill for this month should be " << price_electricity*power;
    }
    else if(option == 9) {
        cout << "CHANGE PRICE" << endl;
        cout << "Enter the price 1 kWh of electricity (don't put currency signs next to it): ";
        cin >> price_electricity;
        while(price_electricity<=0) {
            cout << "Sadly, electricity is not free. Enter a non-zero positive value: ";
            cin >> price_electricity;
        }
    }
    else {
        cout << "No such option exists.";
    }
    cout << endl << "Press enter to return";
    cin.ignore();
    cin.get();
    clear_console();
    electricity_bill();
}

void fall_calc() {
    int option;
    cout << endl << "===FREE-FALL=CALCULATIONS=====" << endl;
    cout << "Currently, the gravitational acceleration is set to " << g << " m/s^2" << endl;
    cout << "NOTE: These calculations don't concern themselfs with air resistence" << endl;
    cout << "What would you like to calculate?" << endl;
    cout << "[1] How fast does an object fall" << endl;
    cout << "[2] Projectile motion (with an angle)" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to main menu" << endl;
    cout << "Enter your selection: ";
    cin >> option;
    if(option == 1) {
        double h;
        cout << "Enter the height from which the object falls (m): ";
        cin >> h;
        while(h<0) {
            cout << "The height cannot be a negative value. Please enter a non-negative value: ";
            cin >> h;
        }
        cout << "Your objects reaches the ground in " << sqrt(2*h/g) << " seconds, and at moment of collission it has a velocity of " << sqrt(2*g*h) << " m/s";
    }
    else if(option == 2) {
        double angle, v;
        
        cout << "Enter the velocity at which the object gets launched (m/s): ";
        cin >> v;
        while(v<0) {
            cout << "The velocity cannot be a negative value. Please enter a non-negative value: ";
            cin >> v;
        }
        cout << "Enter the angle at which the object gets launched (degrees): ";
        cin >> angle;
        while(angle<0) {
            cout << "The angle cannot be a negative value. Please enter a non-negative value: ";
            cin >> angle;
        }
        angle=angle*M_PI/180;
        cout << "Your object reaches the ground in " << 2*v*sin(angle)/g << " seconds,\nit reaches a maximum height of " << v*v*sin(angle)*sin(angle)/(2*g) << " metres,\nand travels " << v*v*sin(2*angle)/g << " metres horizontally.";
    }
    else if(option == 0) {
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
    fall_calc();

}

void gravitation_menu() {
    int option;
    cout << endl << "===SELECT=PLANET==============" << endl;
    cout << "Selecting a planet changes the gravitational acceleration. Currently g=" << g << " m/s^2" << endl << endl;
    cout << "Chose a planet/moon below:" << endl;
    cout << "[1] Earth (9.81)" << endl;
    cout << "[2] Earth\'s moon (1.62)" << endl;
    cout << "[3] Mars (3.72)" << endl;
    cout << "[4] Venus (8.87)" << endl;
    cout << "[5] Custom" << endl;

    cout << "Enter your selection: ";
    cin >> option;
    if(option == 1) g=9.81;
    else if(option == 2) g=1.62;
    else if(option == 3) g=3.72;
    else if(option == 4) g=8.87;
    else if(option == 5) {
        cout << "Enter your custom gravitational acceleration: ";
        cin >> g;
        while(g==0) {
            cout << "The gravitational acceleration cannot be 0. Enter a non-zero value: ";
            cin >> g;
        }
        while(g<0) {
            char answer;
            cout << "Are you sure that on your planet things fall upwards? Enter [Y/N]: ";
            cin >> answer;
            if(toupper(answer) == 'N') {
                cout << "Then enter a positive value: ";
                cin >> g;
                if(g==0) g=9.81; // I dont know how to check if the user enters 0, then a negative number, then N, then 0 again, so if that happens, the g just will be 9.81. Sorry xD
            }
            else if(toupper(answer) == 'Y') break;
        }
        
    }
    else {
        cout << "No such option exists.";
    }
    cout << endl << "Press enter to return to main menu";
    cin.ignore();
    cin.get();
    clear_console();
}

void fun_fact_finder() {
    cout << endl << "FUN FACTS" << endl << endl;
    int fact = rand()%15;
    cout << "FUN FACT #" << fact+1 << ": " << fun_facts[fact] << endl;
    cout << "Press enter to return to main menu";
    cin.ignore();
    cin.get();
    clear_console();
}

void answer_correctness(double input, double result) {
    if(fabs(input-result)<0.01) cout << "Amazing! You're right!" << endl;
    else cout << "You're wrong. The correct answer was " << result << endl;
}

void quiz_menu() {
    int option;
    cout << endl << "===QUIZZES====================" << endl;
    cout << "Select a type of quiz from below. You have an error margin of 0.01." << endl;
    cout << "[1] Velocity related questions" << endl;
    cout << "[2] Energy related questions" << endl;
    cout << "[3] Electricity related questions" << endl;
    cout << "[4] Hand-made, harder questions {**TERRA THEMED**}" << endl;
    cout << "==============================" << endl;
    cout << "[0] Return to main menu" << endl;
    cout << "Enter your selection: ";
    cin >> option;
    if(option == 1) {
        double time, velocity, distance;
        int type = rand()%3+1;
        if(type==1) {
            time=(rand()%10+1)/2.0;
            distance=rand()%186+15;
            cout << "A car travels " << distance << " kms in " << time << " hours. What's the average speed of the car in km/h? v=";
            cin >> velocity;
            answer_correctness(velocity, distance/time);
        }
        else if(type==2) {
            distance=rand()%186+15;
            velocity=rand()%101+15;
            cout << "A bus's average speed is " << velocity << " km/h. It goes on a trip between two cities, that are " << distance << " kms apart. How long will it take for the bus to travel across the cities in hours? t=";
            cin >> time;
            answer_correctness(time, distance/velocity);
        }
        else if(type==3) {
            time=(rand()%10+1)/2.0;
            velocity=rand()%31+15;
            cout << "A motorboat has an average speed of " << velocity << " km/h and yesterday it went out on the lake for " << time <<" hours. How far away did it go in kilometers? d=";
            cin >> distance;
            answer_correctness(distance, velocity*time);
        }
    }
    else if(option == 2) {
        double energy, velocity, height, mass;
        int type = rand()%3+1;
        if(type==1) {
            height=rand()%201+1;
            mass=(rand()%41+1)/2.0;
            cout << "An object with a mass of " << mass << " kg is " << height << " metres above the ground. What's its potential energy in joules? E=";
            cin >> energy;
            answer_correctness(energy, mass*height*g);
        }
        else if(type==2) {
            energy=rand()%1001+1;
            mass=(rand()%41+1)/2.0;
            cout << "An object with " << energy << " joules of potential energy has a mass of " << mass << " kg. How far away it is from the ground in metres? d=";
            cin >> height;
            answer_correctness(height, energy/(mass*g));
        }
        else if(type==3) {
            velocity=rand()%31+1;
            mass=(rand()%41+1)/2.0;
            cout << "An object has a velocity of " << velocity << " m/s and it weighs " << mass << " kg. How much kinetic energy does it have in joules? E=";
            cin >> energy;
            answer_correctness(energy, (mass*velocity*velocity)/2);
        }
    }
    else if(option == 3) {
        double power, time, price, priceOfOne, consume, input;
        int type = rand()%3+1;
        if(type==1) {
            power=rand()%781+20;
            time=rand()%20+1;
            priceOfOne=rand()%20+15;
            cout << "The price of electricity is " << priceOfOne << " cents/kWh. A device in your house was working for " << time << " hours, and it consumes " << power << " watts. How much did it cost you in cents? price=";
            cin >> price;
            answer_correctness(price, time*power*priceOfOne/1000.0);
        }
        else if(type==2) {
            power=rand()%200+150;
            price=(rand()%20+15)*power/100.00;
            cout << "You consumed " << power << " kWh of electricity this month, and your bill was " << price << " dollars. How much does a kWh of electricity cost you, in dollars? price=";
            cin >> priceOfOne;
            answer_correctness(priceOfOne, price/power);
        }
        else if(type==3) {
            power=rand()%200+400;
            time=rand()%16+5;
            consume=power*time;
            cout << "A device in your kitchen runs on " << power << " watts of electricity and it consumed " << consume/1000 << " kWh of electricity. For how long was that device plugged in, in hours? t=";
            cin >> input;
            answer_correctness(input, time);
        }
    }
    else if(option == 4) {
        double answer;
        int question_number = rand()%5;
        cout << "Answer the question below: ";
        cout << "QUESTION No." << question_number+1 << endl;
        cout << quiz_questions[question_number].text;
        cin >> answer;
        answer_correctness(answer, quiz_questions[question_number].answer);
    }
    else if(option == 0) {
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
    quiz_menu();
}

void main_menu() {
    int option;
    cout << endl << "===MAIN=MENU==================" << endl;
    cout << "Select a menu item below:" << endl << endl;
    cout << "[1] Velocity calculations" << endl;
    cout << "[2] Density calculations" << endl;
    cout << "[3] Energy calculations" << endl;
    cout << "[4] Free-fall calculations" << endl;
    cout << "[5] Electricity bill calculator" << endl;
    cout << "===FUN=EXTRAS=================" << endl;
    cout << "[7] Quiz" << endl;
    cout << "[8] Very fun facts" << endl;
    cout << "[9] Select planet" << endl;
    cout << "==============================" << endl;
    cout << "[0] Exit" << endl;

    cout << "Enter your selection: ";
    cin >> option;
    clear_console();
    if(option == 1) velocity_calc();
    else if(option == 2) density_calc();
    else if(option == 3) energy_calc_menu();
    else if(option == 4) fall_calc();
    else if(option == 5) electricity_bill();
    else if(option == 7) quiz_menu();
    else if(option == 8) fun_fact_finder();
    else if(option == 9) gravitation_menu();
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
    srand(time(0));
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