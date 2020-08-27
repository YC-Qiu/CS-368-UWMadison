// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file tests functions in mathlib.h

#include <iostream>
#include "MathLib.cpp"
#include <cstdio>
int main(){
    using namespace std;
    cout <<"Test absval():  "<< absVal(-2) << endl;
    cout <<"Test absval():  "<< absVal(long(3)) << endl;
    cout <<"Test absval():  "<< absVal(-2.1) << endl;
    cout<<"Test ceiling():  "<< ceiling(1.4)<<endl;
    cout<<"Test floor():  "<<floor(-1.4)<<endl;
    cout<<"Test round():  "<<round(9.08,ROUND_AWAY_ZERO)<<endl;
    cout<<"Test pow():  "<<pow(87,3)<<endl;
    cout<<"Test gcd():  "<<gcd(-5,-15)<<endl;
    cout<<"Test toString():  "<<toString(15,16,false)<<endl;
    getchar();
    return 0;
}