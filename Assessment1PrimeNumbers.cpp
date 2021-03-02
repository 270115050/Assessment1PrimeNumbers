//Programmer:	Jay Anino. ID 270115050 
//Yoobee College Bachelor of Software Engineering 
//Date Started:	26/02/2021 
//Due Date:     01/03/2021 
//Reference:	Lab1PrimeNumbers 
//Description:	This program generate prime numbers between any two different numbers 
//Guarantee:	Program works to full specifications 

#include <iostream> 
#include <windows.h> 
#include <conio.h> 
using namespace std;
//------------------------------------------------------------------------------------------------------------------------
bool check_number(int);
void getPrimeNumbers();
int getNum1();
int getNum2();
void setNum1Num2();

int firstNum;
int secondNum;
//------------------------------------------------------------------------------------------------------------------------
int main(){

    char choice = ' ';
    bool isTrue = true;

    do { // loop while user input is y. 
        cout << "|--------------------------------------------------------------------------|" << endl
            << "|This program prints out prime numbers that the user has given.            |" << endl
            << "|Make sure that the first number is greater than the second number.        |" << endl
            << "|--------------------------------------------------------------------------|" << endl;

        system("pause");
        system("cls");

        cout << "|--------------------------------------------------------------------------|" << endl
            << "Press 'y' to start program or press 'n' to exit: ";
        cin >> choice;

        if (tolower(choice) == 'y') { // checks user input if valid or not. 
            isTrue = true;
            system("cls");
            getPrimeNumbers();
        }

        else if (tolower(choice) == 'n')
            isTrue = false;

        else {
            cout << "|------------------------------|" << endl
                << "|Invalid input please try again|" << endl
                << "|------------------------------|" << endl;

            system("pause");
            system("cls");
        }
    } while (isTrue);
    return 0;
}
//------------------------------------------------------------------------------------------------------------------------ 
//This function checks if the number is a prime number and returns a boolean. 
//------------------------------------------------------------------------------------------------------------------------ 
bool check_number(int n1) {

    for (int i = 2; i < n1; i++) {
        if (n1 % i == 0)
            return false;
    }
    return true;
}
//------------------------------------------------------------------------------------------------------------------------ 
//This function ask for 2 inputs from the user and prints out all prime numbers. 
//------------------------------------------------------------------------------------------------------------------------ 
void getPrimeNumbers() {

    int num1, num2, numPrime;

    num1 = 0;
    num2 = 0;
    numPrime = 0;

    setNum1Num2();
    num1 = getNum1();
    num2 = getNum2();

    if (num1 > num2 || num1 == num2) { // checks if starting num is greater or equal to second num. 
        while (num1 > num2 || num1 == num2) {
            cout << "|--------------------------------------------------------------------------|" << endl
                 << "|Invalid input starting number should be greater than final number         |" << endl
                 << "|--------------------------------------------------------------------------|" << endl;

            setNum1Num2();
            num1 = getNum1();
            num2 = getNum2();
            system("cls");
        }
    }
    else {
        num1 = getNum1();
        num2 = getNum2();
    }

    cout << endl << "|------------------------------------------------------------------------------------------------------------------|" << endl
         << "|Prime List between(" << num1 << " and " << num2 << "): ";

    for (int i = num1; i <= num2; i++) {
        if (check_number(i) && i != 0 && i != 1) { //checks if the number is prime. If true it prints it out and keeps count how many prime numbers there are. 
            numPrime++;
            cout << i << " ";
        }
    }

    cout << endl << "|------------------------------------------------------------------------------------------------------------------|" << endl
        << "Total prime numbers between(" << num1 << " and " << num2 << ") : " << numPrime << endl
        << "|------------------------------------------------------------------------------------------------------------------|" << endl;

    system("pause");
    system("cls");
}
//------------------------------------------------------------------------------------------------------------------------ 
// Returns secondNum 
//------------------------------------------------------------------------------------------------------------------------ 
int getNum1() { // Returns firstnum 
    return firstNum;
}
//------------------------------------------------------------------------------------------------------------------------ 
// Returns secondNum 
//------------------------------------------------------------------------------------------------------------------------ 
int getNum2() {
    return secondNum;
}
//------------------------------------------------------------------------------------------------------------------------ 
// This function stores the 2 user inputs from the user and checks if the input is correct. 
//------------------------------------------------------------------------------------------------------------------------ 
void setNum1Num2() {
    cout << "|------------------------------|" << endl
         << "Enter starting number: ";
    cin >> firstNum;
    system("cls");

    while (!cin.good()) {

        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "|-------------------------------|" << endl
            << "|Invalid input, please try again|" << endl
            << "|-------------------------------|" << endl
            << "Enter starting number: ";
        cin >> firstNum;

        system("cls");
    }

    cout << "Starting number is: " << getNum1() << endl
         << "Enter final number: ";
    cin >> secondNum;

    cout << "|------------------------------|" << endl;

    while (!cin.good()) {

        system("cls");
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        cout << "|-------------------------------|" << endl
            << "|Invalid input, please try again|" << endl
            << "|-------------------------------|" << endl
            << "Starting number is: " << getNum1() << endl
            << "|-------------------------------|" << endl
            << "Enter final number: ";
        cin >> secondNum;
    }
}
//------------------------------------------------------------------------------------------------------------------------