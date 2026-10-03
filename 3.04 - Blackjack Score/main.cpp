/*
 Project description:
 Write a program that scores a blackjack hand.
 In blackjack, a player receives from two to five cards. The cards 2 through 10 are scored as 2 through 10 points each. The face cards—jack, queen, and king—are scored as 10 points. The goal is to come as close to a score of 21 as possible without going over 21. Hence, any score over 21 is called “busted.” The ace can count as either 1 or 11, whichever is better for the user. For example, an ace and a 10 can be scored as either 11 or 21. Since 21 is a better score, this hand is scored as 21. An ace and two 8s can be scored as either 17 or 27. Since 27 is a “busted” score, this hand is scored as 17.
 The user is asked how many cards she or he has, and the user responds with one of the integers 2, 3, 4, or 5. The user is then asked for the card values. Card values are 2 through 10, jack, queen, king, and ace. A good way to handle input is to use the type char so that the card input 2, for example, is read as the character '2', rather than as the number 2. Input the values 2 through 9 as the characters '2' through '9'. Input the values 10, jack, queen, king, and ace as the characters 't', 'j', 'q', 'k', and 'a'. (Of course, the user does not type in the single quotes.) Be sure to allow upper- as well as lowercase letters as input.
 After reading in the values, the program should convert them from character values to numeric card scores, taking special care for aces. The output is either a number between 2 and 21 (inclusive) or the word Busted. You are likely to have one or more long multiway branches that use a switch statement or nested if-else statement.
 Your program should include a loop that lets the user repeat this calculation until the user says she or he is done.
 */

#include <iostream>
using namespace std;



//Repeatedly asks for the number of cards until the user puts in 2, 3, 4, or 5
int askNumCards()
{
    while (true)
    {
        try
        {
            string response;
            cout << "Enter the number of cards you recieved: ";
            cin >> response;
            
            //Clears the backlog of characters to be read by cin
            cin.ignore(10000, '\n');
            
            //Tries to convert the response to a number and return it
            double num = stod(response);
            
            //Checks if it's an int
            if (num == static_cast<int>(num))
            {
                if (num >= 2 && num <= 5)
                {
                    return num;
                }
                cout << "\nThat number of cards isn't possible (please enter 2, 3, 4, or 5)\n";
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



//Repeatedly asks for the value of a card until the user puts in 2-10, j(ack), q(ueen), k(ing), or a(ce)
int askCardValue(int idx)
{
    while (true)
    {
        string response;
        cout << "Enter card #"<< idx <<": ";
        cin >> response;
        
        //Clears any backlog of characters to be read by cin
        cin.ignore(10000, '\n');
        
        if (response.length() >= 1 && response.find('.') > response.length())
        {
            //Checks if it's a face card
            switch (toupper(response.at(0)))
            {
                case 'J':
                case 'Q':
                case 'K':
                    return 10;
                case 'A':
                    return 11;
                    
                default:
                    break;
            }
            
            try //If it's not a face card
            {
                int num = stoi(response);
                if (num >= 2 && num <= 10) { return num; }
            } catch (invalid_argument) { }
        }
        
        //If the response isn't a valid card
        cout << "\nSorry, I didn't understand that\n";
    }
}



int main()
{
    while (true)
    {
        //Asks for the number of cards
        int numCards = askNumCards();
        
        //Adds up the cards
        int total = 0;
        int numAces = 0;
        for (int i = 0; i < numCards; i++)
        {
            int card = askCardValue(i+1);
            if (card == 11) { numAces++; }
            total += card;
        }
        
        //Converts the required number of aces from 11s to 1s
        while (total >= 21 && numAces > 0)
        {
            total -= 10;
            numAces--;
        }
        
        //Determines if the hand was a bust
        if (total > 21)
        {
            cout << "Score: Busted ("<< total <<")\n";
        }
        else if (total == 21)
        {
            cout << "Score: Blackjack! ("<< total <<")\n";
        }
        else
        {
            cout << "Score: "<< total <<endl;
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
