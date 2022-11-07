#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class thisPlayer {
public:
    thisPlayer();
    string name;
    int age;
    int balance;
    void toString() {
        cout << "The balance of " << name << " is: " << balance;
    }
};
thisPlayer::thisPlayer() {
    balance = 0;
}
void ageVerification(int age) {
    if (age < 18) {
        cout << "You have to be over 18 to bet!!!";
        //_sleep(5000);
        terminate();
    }
}
thisPlayer addMoney(thisPlayer player) {
    cout << "\nHi " << player.name << "\n Do you want to add money?y/n";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "\nEnter the value what you want to add to your balance: ";
        int value;
        cin >> value;
        player.balance = player.balance + value;
        return player;
    }
    if (choice == 'n' || choice == 'N') {
        return player;
    }
    addMoney(player);
    return player;
}
void betRules() {
    cout << "\n============RULES===========";
    cout << "\nChoose a number between 1 to 10";
    cout << "\nYou win --> you get your bet amount x10";
    cout << "\nWrong bet --> you lose the amount you bet\n";
}
int main()
{
    thisPlayer player;
    char choice;
    cout << "============Welcome to Tonight Casino===========\n";
    cout << "What's your name?";
    cin >> player.name;
    cout << "How old are you?";
    cin >> player.age;
    ageVerification(player.age);
    player = addMoney(player);
    do {
        betRules();
        cout << "Your balance is: " << player.balance;
        int bet = 0;
        do {
            cout << "\nHey " << player.name << "! Enter amount to bet: ";
            cin >> bet;
            if (bet > player.balance) {
                cout << "\nThe betting amount can not be bigger then your balance!!!\n";
                player = addMoney(player);
            }
        } while (bet > player.balance);
        player.balance -= bet;
        int guess;
        do {
            cout << "\nSelect a number between 1 to 10";
            cin >> guess;
            if (guess < 1 && guess > 10)
                betRules();
        } while (guess < 0 && guess > 10);
        int randNum = (rand() % 10) + 1;
        if (guess == randNum) {
            cout << "\nYou won!!! The number was:" << randNum << "\n You've won:" << bet * 10;
            player.balance += bet * 10;
        }
        else {
            cout << "\nYou lost!!! The number was:" << randNum << " \n Better luck next time";
        }

        cout << "\nDo you want to try agaim?y/n";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\nThanks for playing the game. Your balance is: " << player.balance << "\n\n";
    return 0;
}