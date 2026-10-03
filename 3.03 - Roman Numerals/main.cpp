/*
 Project description:
 Write a program that accepts a year written as a four-digit Arabic (ordinary) numeral and outputs the year written in Roman numerals.
 Important Roman numerals are V for 5, X for 10, L for 50, C for 100, D for 500, and M for 1,000. Recall that some numbers are formed by using a kind of subtraction of one Roman “digit”; for example, IV is 4 produced as V minus I, XL is 40, CM is 900, and so on. A few sample years: MCM is 1900, MCML is 1950, MCMLX is 1960, MCMXL is 1940, MCMLXXXIX is 1989.
 Assume the year is between 1000 and 3000. Your program should include a loop that lets the user repeat this calculation until the user says she or he is done.
*/

#include <iostream>
using namespace std;



//Repeatedly asks for the year until the user puts in an integer between 1000 and 3000
int askYear()
{
    while (true)
    {
        try
        {
            string response;
            cout << "Enter a year between 1000 and 3000: ";
            cin >> response;
            
            //Clears the backlog of characters to be read by cin
            cin.ignore(10000, '\n');
            
            //Tries to convert the response to a number
            double num = stod(response);
            
            //Checks if it's an int
            if (num == static_cast<int>(num))
            {
                if (num >= 1000 && num <= 3000)
                {
                    return num;
                }
                cout << "\nPlease enter a number between 1000 and 3000\n";
            }
            else
            {
                cout << "\nPlease enter a whole number\n";
            }
        }
        catch (invalid_argument) //If the user didn't put in a number
        {
            cout << "\nPlease enter a number\n";
        }
    }
}



int main()
{
    const char NUMERALS[] = {'I','V','X','L','C','D','M'};
    const int VALUES[] = {1,5,10,50,100,500,1000};
    
    while (true)
    {
        //Asks for the year to be converted to Roman Numerals
        int year = askYear();
        
        
        
        //Converts to Roman Numerals and prints the result
        int remaining = year;
        for (int idx = 6; idx >= 0; idx--)
        {
            while (remaining >= VALUES[idx])
            {
                remaining -= VALUES[idx];
                cout << NUMERALS[idx];
            }
            
            //Checks if there is still more to be done
            if (remaining == 0) { break; }
            
            //Determines what the allowed numeral for subtraction would be
            int subtractor;
            if (idx <= 2)      { subtractor = 0; }
            else if (idx <= 4) { subtractor = 2; }
            else               { subtractor = 4; }
            
            //Checks if the numeral should be subtracted
            if (VALUES[idx] - VALUES[subtractor] <= remaining)
            {
                remaining -= (VALUES[idx] - VALUES[subtractor]);
                cout << NUMERALS[subtractor] << NUMERALS[idx];
            }
        }
        
        
        
        //Asks if the user wants to repeat the calculation
        while (true)
        {
            char response;
            cout << "\nWould you like to run the calculation again? (y/n) ";
            cin >> response;
            
            //Clears the backlog of characters to be read by cin
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
