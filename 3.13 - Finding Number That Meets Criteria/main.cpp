/*
 Project description:
 Holy digits Batman! The Riddler is planning his next caper somewhere on Pennsylvania Avenue. In his usual sporting fashion, he has left the address in the form of a puzzle. The address on Pennsylvania is a four-digit number where:
 • All four digits are different
 • The digit in the thousands place is three times the digit in the tens place
 • The number is odd
 • The sum of the digits is 27
 Write a program that uses a loop (or loops) to find the address where the Riddler plans to strike.
 */

#include <iostream>
using namespace std;



int main()
{
    while (true)
    {
        //Checks all possibilities
        for (int attempt = 123; attempt <= 9876; attempt += 2)
        {
            //Splits the number into an array of ints
            int nums[4];
            for (int idx = 0; idx < 4; idx++)
            {
                nums[idx] = static_cast<int>(attempt / pow(10.0,3-idx)) % 10;
            }
            
            
            
            //Checks if all of the digits are different
            bool different = true;
            for (int i = 0; i < 3; i++)
            {
                for (int j = i+1; j < 4; j++)
                {
                    if (nums[i] == nums[j]) { different = false; }
                }
            }
            
            
            
            //Checks if the 1000s place is 3 times the 10s place
            if (different && (nums[0] == 3 * nums[2]))
            {
                //Checks if the total is 27
                int total = 0;
                for (int num : nums) { total += num; }
                
                if (total == 27)
                {
                    cout << attempt;
                    break;
                }
            }
        }
        
        
        
        //Asks if the user wants to repeat the calculation
        while (true)
        {
            char response;
            cout << "\nWould you like to run the calculation again? (It'll still be the same as last time) ";
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
