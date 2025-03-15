# Bank Account Management System

## Overview
The Bank Account Management System is a simple console-based C++ application that allows users to create accounts, deposit and withdraw money, view account details, and check transaction history. The system uses file handling to store and retrieve account information and transactions.

## Features
- Create a new bank account
- Deposit money into an account
- Withdraw money from an account
- View account details
- View transaction history
- Data persistence using text files

## File Structure
- `main.cpp`: The source code for the application
- `accounts.txt`: Stores account details in the format `AccountNumber|HolderName|Balance`
- `transactions.txt`: Stores transaction history in the format `AccountNumber TransactionType Amount`

## How to Use
1. **Compile the Code**
   
   g++ -o Bank_Acc_System  Bank_Acc_System.cpp

   
2. **Run the Program**
   
   ./Bank_Acc_System


3. **Follow the Menu Options**
   - Choose `1` to create an account.
   - Choose `2` to deposit money.
   - Choose `3` to withdraw money.
   - Choose `4` to view account details.
   - Choose `5` to view transaction history.
   - Choose `6` to exit the program.

## Example Usage
### Creating an Account
```
Enter Account Number: 123456789
Enter Account Holder Name: Somnath
Enter Initial Balance: 500
Account Created Successfully!
```

### Depositing Money
```
Enter Account Number: 123456789
Enter Amount to Deposit: 700
Deposit Successful! New Balance: 1200
```

### Withdrawing Money
```
Enter Account Number: 123456789
Enter Amount to Withdraw: 200
Withdrawal Successful! New Balance: 1200
```

### Viewing Account Details
```
Enter Account Number: 123456789

Account Number: 123456789
Account Holder: Somnath
Balance: 1000
```

### Viewing Transaction History
```
Transaction History for Account: 123456789
-----------------------------------
Deposit - Amount: 700
Withdrawal - Amount: 200
```

## Requirements
- C++ Compiler (g++ recommended)
- Basic knowledge of C++

## Notes
- Ensure `accounts.txt` and `transactions.txt` exist before running the program, or the program will create them.
- Account holder names can contain spaces.
- Data is stored persistently using text files.

## Author
Somnath Shinde

