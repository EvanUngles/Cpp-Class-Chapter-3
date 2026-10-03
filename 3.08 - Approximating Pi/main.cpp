/*
 Project description:
 An approximate value of pi can be calculated using the series given: pi = 4 [ 1 – 1/3 + 1/5 – 1/7 + 1/9 ... + ((–1)^n)/(2n + 1) ]. Write a C++ program to calculate the approximate value of pi using this series.
 The program takes an input n that determines the number of terms in the approximation of the value of pi and outputs the approximation. Include a loop that allows the user to repeat this calculation for new values n until the user says she or he wants to end the program.
 */

#include <iostream>
using namespace std;



//Repeatedly asks the given question until the user puts in a number
int askInt(string question)
{
    string response;
    while (true)
    {
        try
        {
            //Asks the given question and records the response
            cout << question;
            cin >> response;
            
            //Clears the backlog of characters to be read by cin
            cin.ignore(10000, '\n');
            
            //Tries to convert the response to a number
            double num = stod(response);
            
            //Checks if it's an int
            if (num == static_cast<int>(num))
            {
                if (num >= 0)
                {
                    return num;
                }
                cout << "\nPlease enter a positive number\n";
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
    while (true)
    {
        //Asks for the precision of the approximation
        int precision = askInt("Enter the precision of the approximation (number of terms in the series used for the approximation): ");
        
        
        
        //Approximates pi
        double total = 0.0;
        for (int idx = 0; idx <= precision; idx++)
        {
            total += pow(-1.0, idx) / (2 * idx + 1);
        }
        total *= 4.0;
        
        
        
        //Prints out the results
        cout << "Approximation: " << total <<endl;
        
        double percentError = 100 * abs(total - 3.14159265359) / 3.14159265359;
        percentError = round(percentError * 100.0) / 100.0;
        cout << "Percent difference: "<< percentError <<"%\n";
        
        
        
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
