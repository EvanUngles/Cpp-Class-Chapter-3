/*
 Project description:
 Write a C++ program that solves a quadratic equation to find its roots. The roots of a quadratic equation x^2 + bx + c = 0 (where a is not zero) are given by the formula (–b ± sqrt(b^2 – 4ac)) / 2a. The value of the discriminant (b^2 – 4ac) determines the nature of roots. If the value of the discriminant is zero, then the equation has a single real root. If the value of the discriminant is positive then the equation has two real roots. If the value of the discriminant is negative, then the equation has two complex roots.
 The program takes values of a, b, and c as input and outputs the roots. Be creative in how you output complex roots. Include a loop that allows the user to repeat this calculation for new input values until the user says she or he wants to end the program.
 */

#include <iostream>
using namespace std;



//Repeatedly asks the given question until the user puts in a number
double askNum(string question)
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
            
            //Tries to convert the response to a number and return it
            return stod(response);
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
        //Asks for the value of a (can't be 0)
        double a;
        while (true)
        {
            a = askNum("Enter the value for a (cannot be 0): ");
            
            if (a != 0.0) { break; }
            cout << "\nThe coefficient of x^2 cannot be 0, please try again\n";
        }
        
        //Asks for the value of b and c
        double b = askNum("Enter the value for b: ");
        double c = askNum("Enter the value for c: ");
        
        
        
        //Calculates the roots
        double discriminant = (b * b) - (4 * a * c);
        if (discriminant > 0) //If there are 2 real solutions
        {
            //Calculates both roots
            double root1 = (-b - sqrt(discriminant)) / (2 * a);
            double root2 = (-b + sqrt(discriminant)) / (2 * a);
            
            cout << "x = "<< root1 <<", "<< root2 <<endl;
        }
        else if (discriminant == 0) //If there is only one real solution
        {
            cout << "x = "<< (-b / (2 * a)) <<" (multiplicity of 2)\n";
        }
        else //If there are 2 complex solutions
        {
            //Calculates the real and imaginary components separately
            double real = -b / (2 * a);
            double imaginary = sqrt(abs(discriminant)) / (2 * a);
            
            cout << "x = "<< real <<" - "<< imaginary <<"i, "<< real <<" + "<< imaginary <<"i\n";
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
