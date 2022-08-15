//
// Created by syedh on 10/09/2019.
//

#include "C.h"
#include "B.cpp"
#include "A.cpp"
#include <iostream>
using namespace std;
class C: public B, public A {
public:
    C(){
        cout << "C+" ;
    }
    ~C(){
        cout << "C-" ;
    }
};