#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <assert.h>
using namespace std;

void showMenu()
{
    cout << "*****MENU*****" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. transfer money to another acount" << endl;
    cout << "5. Exit" << endl;
}

double transferMoney(double accountBalance)
{
    double transferAmount;
    cout << "How much do you want to transfer? : ";
    cin >> transferAmount;

    if (transferAmount <= accountBalance) accountBalance -= transferAmount;
    else cout << "Not enough money to transfer";

    return accountBalance;
}

int main()
{
    int option;
    double balance = 0;
    double depositAmount;
    double withdrawAmount;

    do
    {
        showMenu();
        cout << "Option : ";
        cin >> option;

    switch(option)
    {
        case 1: cout << "Balance is : " << balance << endl;break;

        case 2: cout << "Enter the deposit amount : ";
        cin >> depositAmount;
        balance += depositAmount;
        break;

        case 3: cout << "Enter the withdraw amount : ";
        cin >> withdrawAmount;
        if (withdrawAmount <= balance) balance -= withdrawAmount;
        else cout << "Not enough money !!"<< endl;
        break;

        case 4: balance = transferMoney(balance); break;

        case 5: break;

        default:
            cout << "Invalid option! Please choose a valid menu option (1-5)." << endl; break;
    }

    } while(option != 5);

    return 0;
}