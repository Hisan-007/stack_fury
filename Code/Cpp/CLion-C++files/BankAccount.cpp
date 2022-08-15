//
// Created by syedh on 13/09/2019.
//

#include "BankAccount.h"
#include<iostream>
#include<string>
using namespace std;

class BankAccount {
public :
    string accountName;
    int accountNumber;
    int balance;
    BankAccount(){};
    BankAccount(string accountName, int accountNumber, int balance){
        this->accountName = accountName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    };

    void depositMoney(int money){
        cout<<"cash before:"<<balance<<endl;
        balance+=money;
        cout<<"money deposited:"<<money<<endl;
    }
    void withdrawMoney(int money){
        balance-=money;
        cout<<"money withdrawn:"<<money<<endl;
    }

};
class Saving: public BankAccount {

public:
    Saving(string accountName, int accountNumber, int balance){
        this->accountName = accountName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void displayBalance(){
        cout<<endl;
        cout<<"User name:"<<accountName<<endl;
        balance += balance/100 *2.5;
        cout<<"Balance:"<<balance<<endl;
        cout<<"With 2.5% profit"<<endl;
    }

};
class Current: public BankAccount {
public:
    Current(string accountName, int accountNumber, int balance){
        this->accountName = accountName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void displayBalance(){
        cout<<"User name:"<<accountName<<endl;
        cout<<"Balance:"<<balance<<endl;
        cout<<"Current Account with no interests"<<endl;
    }
};