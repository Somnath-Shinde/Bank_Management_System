#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class BankAccount {
public:
    string accountNumber;
    string holderName;
    double balance;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Account Holder Name: ";
        getline(cin, holderName);
        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream outFile("accounts.txt", ios::app);
        if (outFile.is_open()) {
            outFile << accountNumber << "|" << holderName << "|" << balance << endl;
            outFile.close();
            cout << "Account Created Successfully!\n";
        } else {
            cout << "Error: Unable to open file!\n";
        }
    }

    void depositMoney() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Amount to Deposit: ";
        cin >> amount;

        vector<BankAccount> accounts;
        ifstream inFile("accounts.txt");
        bool found = false;
        double newBalance = 0;

        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                BankAccount acc;
                getline(ss, acc.accountNumber, '|');
                getline(ss, acc.holderName, '|');
                ss >> acc.balance;

                if (acc.accountNumber == accNum) {
                    acc.balance += amount;
                    newBalance = acc.balance;
                    found = true;
                }
                accounts.push_back(acc);
            }
            inFile.close();
        } else {
            cout << "Error opening accounts.txt!\n";
            return;
        }

        if (found) {
            ofstream outFile("accounts.txt", ios::trunc);
            for (const BankAccount &acc : accounts) {
                outFile << acc.accountNumber << "|" << acc.holderName << "|" << acc.balance << endl;
            }
            outFile.close();
            cout << "Deposit Successful! New Balance: " << newBalance << endl;
            logTransaction(accNum, "Deposit", amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void withdrawMoney() {
        string accNum;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNum;
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;

        vector<BankAccount> accounts;
        ifstream inFile("accounts.txt");
        bool found = false;
        double newBalance = 0;

        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                BankAccount acc;
                getline(ss, acc.accountNumber, '|');
                getline(ss, acc.holderName, '|');
                ss >> acc.balance;

                if (acc.accountNumber == accNum) {
                    if (acc.balance >= amount) {
                        acc.balance -= amount;
                        newBalance = acc.balance;
                        found = true;
                    } else {
                        cout << "Insufficient balance!\n";
                        inFile.close();
                        return;
                    }
                }
                accounts.push_back(acc);
            }
            inFile.close();
        } else {
            cout << "Error opening accounts.txt!\n";
            return;
        }

        if (found) {
            ofstream outFile("accounts.txt", ios::trunc);
            for (const BankAccount &acc : accounts) {
                outFile << acc.accountNumber << "|" << acc.holderName << "|" << acc.balance << endl;
            }
            outFile.close();
            cout << "Withdrawal Successful! New Balance: " << newBalance << endl;
            logTransaction(accNum, "Withdrawal", amount);
        } else {
            cout << "Account not found!\n";
        }
    }

    void viewAccount() {
        string accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        ifstream inFile("accounts.txt");
        bool found = false;

        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                BankAccount acc;
                getline(ss, acc.accountNumber, '|');
                getline(ss, acc.holderName, '|');
                ss >> acc.balance;

                if (acc.accountNumber == accNum) {
                    cout << "\nAccount Number: " << acc.accountNumber << "\n";
                    cout << "Account Holder: " << acc.holderName << "\n";
                    cout << "Balance: " << acc.balance << "\n";
                    found = true;
                    break;
                }
            }
            inFile.close();
        }

        if (!found) {
            cout << "Account not found!\n";
        }
    }

    void viewTransactionHistory() {
        string accNum;
        cout << "Enter Account Number: ";
        cin >> accNum;

        ifstream inFile("transactions.txt");
        bool found = false;

        cout << "\nTransaction History for Account: " << accNum << "\n";
        cout << "-----------------------------------\n";

        if (inFile.is_open()) {
            string transAccNum, type;
            double amount;
            while (inFile >> transAccNum >> type >> amount) {
                if (transAccNum == accNum) {
                    cout << type << " - Amount: " << amount << endl;
                    found = true;
                }
            }
            inFile.close();
        }

        if (!found) {
            cout << "No transactions found for this account.\n";
        }
    }

    void logTransaction(const string &accNum, const string &type, double amount) {
        ofstream outFile("transactions.txt", ios::app);
        if (outFile.is_open()) {
            outFile << accNum << " " << type << " " << amount << endl;
            outFile.close();
        } else {
            cout << "Error logging transaction!\n";
        }
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\nBank Account Management System\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.createAccount();
                break;
            case 2:
                account.depositMoney();
                break;
            case 3:
                account.withdrawMoney();
                break;
            case 4:
                account.viewAccount();
                break;
            case 5:
                account.viewTransactionHistory();
                break;
            case 6:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
