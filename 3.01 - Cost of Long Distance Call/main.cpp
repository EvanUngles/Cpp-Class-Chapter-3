/*
 Project description:
 Write a program that computes the cost of a long-distance call. The cost of the call is determined according to the following rate schedule:
        a. Any call started between 8:00 am and 6:00 pm, Monday through Friday, is billed at a rate of $0.40 per minute.
        b. Any call starting before 8:00 am or after 6:00 pm, Monday through Friday, is charged at a rate of $0.25 per minute.
        c. Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
 The input will consist of the day of the week, the time the call started, and the length of the call in minutes. The output will be the cost of the call.
 The time is to be input in 24-hour notation, so the time 1:30 pm is input as 13:30. The day of the week will be read as one of the following pairs of character values, which are stored in two variables of type char: Mo Tu We Th Fr Sa Su. Be sure to allow the user to use either uppercase or lowercase letters or a combination of the two. The number of minutes will be input as a value of type int. (You can assume that the user rounds the input to a whole number of minutes.)
 Your program should include a loop that lets the user repeat this calculation until the user says she or he is done.
*/

#include <iostream>
#include <string>
using namespace std;



//Repeatedly asks what day of the week they started the call until the user puts in a valid day of the week
string askDay()
{
    while (true)
    {
        cout << "Enter the first two letters for the day of the week that you started the call (\"Mo\" for Monday, \"Tu\" for Tuesday, etc.): ";
        //Reads the first two chars and sets their cases
        char char1 = toupper(cin.get());
        char char2 = tolower(cin.get());
        
        //Clears the backlog
        cin.ignore(10000, '\n');
        
        //Checks if it's a real day
        for (string dayName : {"Mo","Tu","We","Th","Fr","Sa","Su"})
        {
            if (char1 == dayName.at(0) && char2 == dayName.at(1))
            {
                return dayName;
            }
        }
        
        //If what the user put in wasn't a real day
        cout << "Sorry, I didn't understand that\n\n";
    }
}



//Repeatedly asks for the time they started the call until the user puts in a time in 24h notation
//Returns the time as the number of hours since midnight (ex: 13:30 would be returned as 13.5)
double askTime()
{
    while (true)
    {
        string response;
        cout << "Enter the time of day when you started the call (in 24-hour notation): ";
        cin >> response;
        
        //Clears the backlog
        cin.ignore(10000, '\n');
        
        //Checks for a colon and stores it's position
        unsigned long position = response.find(':');
        //Checks if the colon is in the right spot (and the length of the response makes sense) and that there aren't any decimals or negative numbers
        if ( ((position == 1 && response.length() == 4) || (position == 2 && response.length() == 5)) && (response.find('.') > response.length() && response.find('-') > response.length()) )
        {
            try
            {
                //Takes the portion of the string that would be the hour and tries to convert that to an int
                int hour = stoi(response.substr(0, position));
                int minute = stoi(response.substr(position + 1));
                
                if ((0 <= hour && hour < 24) && (0 <= minute && minute < 60))
                {
                    return hour + (minute / 60.0);
                }
                else //If the input is formatted correctly but isn't a real time (ex: 24:62)
                {
                    cout << "Sorry, that isn't a valid time\n\n";
                }
            }
            catch (...) //If the input looks like a time but the hours and minutes aren't numbers
            {
                cout << "Sorry, I didn't understand that\n\n";
            }
        }
        else //If the input isn't formatted like a time (x:xx or xx:xx)
        {
            cout << "Please enter the time in 24-hour notation\n\n";
        }
    }
}



//Repeatedly asks how many minutes the call lasted until the user puts in a positive integer
int askLength()
{
    string response;
    while (true)
    {
        try
        {
            cout << "Enter the length of the call in minutes (round to the nearest minute): ";
            cin >> response;
            
            //Tries to convert the response to a number and store it in num
            double num = stod(response);
            
            //Checks if the user put in a whole number
            if (num == static_cast<int>(num))
            {
                //Returns the number if it's positive or 0
                if (num >= 0)
                {
                    return num;
                }
                cout << "Please enter a positive number\n\n";
            }
            else
            {
                cout << "Please round to the nearest minute\n\n";
            }
        }
        catch (invalid_argument) //If the user didn't put in a number
        {
            cout << "Please enter a number\n\n";
        }
    }
}



int main()
{
    //Adjusts the settings for printing decimals so it will always show 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    while (true)
    {
        //Asks for the values
        string day = askDay();
        double time = askTime();
        int length = askLength();
        
        
        
        //Calculates the cost of the call
        double cost;
        if (day == "Sa" || day == "Su")
        {
            cost = 0.15 * length;
        }
        else if (time < 8 || time > 18)
        {
            cost = 0.25 * length;
        }
        else
        {
            cost = 0.40 * length;
        }
        
        cout << "\nThe call will cost $" << cost <<endl;
        
        
        
        //Asks if the user wants to repeat the calculation
        while (true)
        {
            char response;
            cout << "\nWould you like to run the calculation again? (y/n) ";
            cin >> response;
            
            //If the user put in several characters, the remaining characters would stay in the backlog and get read the next time cin is used, so this clears the backlog
            cin.ignore(10000, '\n');
            
            if (tolower(response) == 'y')
            {
                cout << endl;
                break;
            }
            else if (tolower(response) == 'n')
            {
                return 0;
            }
            cout << "Sorry, I didn't understand that, please enter either \"y\" (for yes) or \"n\" (for no)";
        }
    }
}
