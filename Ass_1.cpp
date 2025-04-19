#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Account {
protected:
    string customerName;
    int accountNumber;
    string accountType;
    float balance;

public:
    void initialize() {

        customerName = "rohit";
        accountNumber = 129;
        balance = 1000;
        cout<<"customerName :"<<customerName<<endl;
        cout<<"accountNumber :"<<accountNumber<<endl;
        cout<<"Initial Balance :"<<balance<<endl;
    }
    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful.\nUpdated balance: " << balance << endl;
    }

    void displayBalance() {
        cout << "Account Balance: " << balance << endl;
    }

    void updateBalance(float newBalance) {
        balance = newBalance;
    }
};

class Sav_Acc : public Account {
public:
    void Interest() {
        float rate;
        int time;
        cout << "Enter interest rate (%): ";
        cin >> rate;
        cout << "Enter time (in years): ";
        cin >> time;
        float interest = balance * pow((1 + rate / 100), time) - balance;
        balance += interest;
        cout << "Interest of " << interest << " added. \nUpdated balance: " << balance << endl;
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. \nUpdated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

class Cur_Acc : public Account {
private:
    float minBalance = 500;
    float serviceCharge = 50;

public:
    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount <= balance) {
            balance -= amount;
            checkMinimumBalance();
            cout << "Withdrawal successful.\nUpdated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void checkMinimumBalance() {
        if (balance < minBalance) {
            balance -= serviceCharge;
            cout << "Balance below minimum. Service charge of " << serviceCharge << " imposed." << endl;
        }
    }

    void chequebook() {
        cout << "Cheque book facility is available for current accounts." << endl;
    }
};

int main() {
    int choice;
    cout << "Choose Account Type:\n1. Savings Account\n2. Current Account\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        Sav_Acc b1;
        b1.initialize();
        b1.deposit();
        b1.Interest();
        b1.withdraw();
        b1.displayBalance();
    } else if (choice == 2) {
        Cur_Acc b2;
        b2.initialize();
        b2.deposit();
        b2.chequebook();
        b2.withdraw();
        b2.displayBalance();
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
OUTPUT:
Choose Account Type:
1. Savings Account
2. Current Account
Enter choice: 1
customerName :rohit
accountNumber :129
Initial Balance :1000
Enter amount to deposit: 200
Deposit successful.
Updated balance: 1200
Enter interest rate (%): 5
Enter time (in years): 1
Interest of 59.9999 added. 
Updated balance: 1260
Enter amount to withdraw: 600
Withdrawal successful. 
Updated balance: 660
Account Balance: 660
