/*
 Project description:
 The keypad on your oven is used to enter the desired baking temperature and is arranged like the digits on a phone:
 1 2 3
 4 5 6
 7 8 9
   0
 Unfortunately the circuitry is damaged and the digits in the leftmost column no longer function. In other words, the digits 1, 4, and 7 do not work. If a recipe calls for a temperature that can’t be entered, then you would like to substitute a temperature that can be entered.
 Write a program that inputs a desired temperature. The temperature must be between 0 and 999 degrees. If the desired temperature does not contain 1, 4, or 7, then output the desired temperature. Otherwise, compute the next largest and the next smallest temperature that does not contain 1, 4, or 7 and output both.
 For example, if the desired temperature is 450, then the program should output 399 and 500. Similarly, if the desired temperature is 375, then the program should output 380 and 369.
 */

#include <iostream>
using namespace std;

//The digits to exclude
const int EXCLUDE[] = {1, 4, 7};



//Repeatedly asks the given question until the user puts in a number
int askTemp()
{
    string response;
    while (true)
    {
        try
        {
            //Asks the given question and records the response
            cout << "Enter the desired temperature: ";
            cin >> response;
            
            //Clears the backlog of characters to be read by cin
            cin.ignore(10000, '\n');
            
            //Tries to convert the response to a number
            double num = stod(response);
            
            //Checks if it's an int
            if (num == static_cast<int>(num))
            {
                if (num >= 0 && num <= 999)
                {
                    return num;
                }
                cout << "\nPlease enter a number from 0 to 999\n";
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



//Returns whether the given digit is allowed
bool isAllowed(int digit)
{
    for (int excluded : EXCLUDE)
    {
        if (digit == excluded) { return false; }
    }
    return true;
}



int main()
{
    //Finds the smallest and largest digits that are allowed
    int MIN = 9;
    int MAX = 0;
    for (int n = 0; n <= 9; n++)
    {
        if (isAllowed(n))
        {
            if (n < MIN) { MIN = n; }
            if (n > MIN) { MAX = n; }
        }
    }
    
    
    
    while (true)
    {
        //Asks for the number
        int num = askTemp();
        
        //Splits num into an array of ints
        int len = 3;
        int nums[len];
        for (int idx = 0; idx < len; idx++)
        {
            nums[idx] = static_cast<int>(num / pow(10.0,len-idx-1)) % 10;
        }
        
        
        
        //Finds the first invalid digit (if any)
        int problem = -1;
        for (int idx = 0; idx < len; idx++)
        {
            if (!isAllowed(nums[idx]))
            {
                problem = idx;
                break;
            }
        }
                
        
        
        if (problem == -1)
        {
            cout << num <<" is valid" <<endl;
        }
        else
        {
            //Finds the next valid number that's greater than num
            
            int larger[len];
            for (int idx = 0; idx < len; idx++) { larger[idx] = nums[idx]; } //Copies over the array of nums
            
            //Updates the digits
            larger[problem]++;
            for (int idx = problem + 1; idx < len; idx++)
            {
                larger[idx] = MIN;
            }
            
            //Prints out the number
            cout <<"Larger: ";
            for (int i : larger) { cout << i; }
            
            
            
            //Finds the next valid number that's smaller than num
            
            int smaller[len];
            for (int idx = 0; idx < len; idx++) { smaller[idx] = nums[idx]; } //Copies over the array of nums
            
            //Updates the digits
            smaller[problem]--;
            for (int idx = problem + 1; idx < len; idx++)
            {
                smaller[idx] = MAX;
            }
            
            //Prints out the number
            cout <<"\nSmaller: ";
            for (int i : smaller) { cout << i; }
            cout<<endl;
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
