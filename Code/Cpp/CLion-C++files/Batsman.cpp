//
// Created by syedh on 13/09/2019.
//

#include "Batsman.h"
#include <iostream>
#include <string>
using namespace std;

class Batsman {
private:
    int bcode;
    string bname;
    int innings;
    int notout;
    int runs;
    float batavg;

    float calavg(){
        return (float) runs/(innings-notout);
    }
public:
    void readdata(int bcode, string name, int innings, int notout, int runs){
        this->bcode = bcode;
        this->bname = name;
        this->innings = innings;
        this->notout = notout;
        this->runs = runs;
        this->batavg = calavg();
    }
    void displaydata(){
        cout << "bcode:"<<bcode<<endl;
        cout << "bname:"<<bname<<endl;
        cout << "innings:"<<innings<<endl;
        cout << "notout:"<<notout<<endl;
        cout << "runs:"<<runs<<endl;
        cout << "batavg:"<<batavg<<endl;
    }

};