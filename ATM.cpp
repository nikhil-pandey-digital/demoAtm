#include <conio.h>
#include <iostream>
using namespace std;
/*
 ATM:
 1) Check Balance
 2) Cash Withdraw
 3) User Details
 4) Update Mobile No.

*/

class atm
{
private:
    long int account_No;
    string name;
    int pin;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int pin_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        pin = pin_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    long int getAccountNo()
    {
        return account_No;
    }
    string getName()
    {
        return name;
    }
    int getPin()
    {
        return pin;
    }
    double getBalance()
    {
        return balance;
    }
    string getMobileNo()
    {
        return mobile_No;
    }

    void setMobileNo(string prevmob, string newmob)
    {

        if (prevmob == mobile_No)
        {
            mobile_No = newmob;
            cout << "Mobile No. Updated Successfully" << endl;
            cout << "Your new Mobile No. is " << mobile_No << endl;
            _getch();
        }
        else
        {
            cout << "Incorrect Old Mobile No." << endl;
              _getch();
        }
    }

    void cashWithdraw(int amount)
    {
        if (amount > 0 && amount < balance)
        {
            balance = balance - amount;
            cout << "Please collect your cash" << endl;
            cout << "Available Balance: " << balance << endl;
           _getch();
        }
        else
        {
            cout << "Invalid Input or Insufficient Balance" << endl;
           _getch();
        }
    }
};

int main(){

      int choice = 0, enteredPin;  
      long int enteredAccountNo;

   
     atm user1;
     user1.setData(1234567, "John", 1111, 50000, "1234567890");
    
    do{
        system("cls");

        cout<<"****Welcome to ATM*****"<<endl;
        cout<<"Enter Your Account No ";
        cin>>enteredAccountNo;
        cout<<"Enter Pin ";
        cin>>enteredPin;

        if((enteredAccountNo == user1.getAccountNo()) && (enteredPin == user1.getPin()))
        {
            do
            {
                int amount;
                string oldMobileNo, newMobileNo;
                system("cls");
                cout << "****Welcome to ATM*****" << endl;
                cout << "Select Options " << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Cash Withdraw" << endl;
                cout << "3. Show User Details" << endl;
                cout << "4. Update Mobile No." << endl;
                cout << "5. Exit" << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Your Bank Balance is : " << user1.getBalance() << endl;
                     _getch();
                    break;

                case 2:
                    cout << "Enter the amount : ";
                    cin >> amount;
                    user1.cashWithdraw(amount);
                    break;

                case 3:
                    cout << "***User Details are :- " << endl;
                    cout << "Account No. : " << user1.getAccountNo() << endl;
                    cout << "Name : " << user1.getName() << endl;
                    cout << "Balance : " << user1.getBalance() << endl;
                    cout << "Mobile No. : " << user1.getMobileNo() << endl;
                     _getch();
                    break;

                case 4:
                    cout << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;

                    cout << "Enter New Mobile No. ";
                    cin >> newMobileNo;

                    user1.setMobileNo(oldMobileNo, newMobileNo);
                     _getch();
                    break;

                case 5:
                    exit(0);
                    break;

                default:
                    cout << "Enter Valid Data " << endl;
                }
            } while (1);
        }
        else
        {
            cout << "User details are invalid " << endl;
            _getch();
        }
    }while(1);
      
}