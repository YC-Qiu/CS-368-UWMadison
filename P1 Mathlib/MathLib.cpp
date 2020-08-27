// Author:          Yucheng Qiu
// Wisc id:         yqiu56
// Description:     This file tests functions in mathlib.h

#include <iostream>
#include "MathLib.h"
#include <string>
int absVal(int num){

    return num > 0 ? num : -num;

}

long absVal(long num){

    return num > 0 ? num : -num;

}
double absVal(double num){

    return num > 0 ? num : -num;

}

double pow(double num, long power){
    if(power == 0) return 1;
    if(power < 0) return 1.0 / pow(num,-power);
    int product = 1;
    for(int i = power; i > 0;i--){
    
        product *= num;
    
    }

    return product;
}
long ceiling(double num){

    return (num == long(num) || num <= 0)  ? long(num) : long(num) + 1;

}
long floor(double num){

    return num >= 0 || (num == long(num) && num<0)  ? long(num) : long(num) - 1;
}
long round(double num, RoundingRule rule){
    switch (rule){
    case ROUND_UP:
        return (ceiling(num));
    case ROUND_DOWN:
        return (floor(num));
    case ROUND_TO_ZERO:
        return (long(num));
    case ROUND_AWAY_ZERO:
        if(num - long(num) == 0) return long(num);
        else if(num>0) return long(num) + 1;
        else return long(num)-1;
    case ROUND_HALF_UP:
        return ( absVal(double(num - long(num))) > 0.5 && num < 0) || 
            (absVal(double(num - long(num))) < 0.5 && num > 0) ? floor(num) : ceiling(num);
    case ROUND_HALF_DOWN:
        return ( absVal(double(num - long(num))) >= 0.5 && num < 0) || 
            (absVal(double(num - long(num))) <= 0.5 && num > 0) ? floor(num) : ceiling(num);
    case ROUND_HALF_TO_ZERO:
        return ( absVal(double(num - long(num))) > 0.5 && num < 0) || 
            (absVal(double(num - long(num))) <= 0.5 && num > 0) ? floor(num) : ceiling(num);  
    case ROUND_HALF_AWAY_ZERO:
        return ( absVal(double(num - long(num))) >= 0.5 && num < 0) || 
            (absVal(double(num - long(num))) < 0.5 && num > 0) ? floor(num) : ceiling(num);
    case ROUND_HALF_TO_ODD:
        if(absVal(double(num - long(num))) != 0.5) return round(num,ROUND_HALF_UP);
        else if(long(num) % 2 == 0) return round(num,ROUND_HALF_AWAY_ZERO);
        else return round(num,ROUND_HALF_TO_ZERO);
    case ROUND_HALF_TO_EVEN:
        if(absVal(double(num - long(num))) != 0.5) return round(num,ROUND_HALF_UP);
        else if(long(num) % 2 == 0) return round(num,ROUND_HALF_TO_ZERO);
        else return round(num,ROUND_HALF_AWAY_ZERO);
    default:
        break;
    }
    return 0;
}

int gcd(int a, int b){
    if(a<0 || b<0) return gcd(absVal(a),absVal(b));
    if(a < b) return gcd(b,a);
    if(b == 0) return a;
    if(b == 1) return 1;
    return gcd(b, a%b);
}

std::string toString(int num, unsigned int radix = 10, bool IS_LOWER_CASE = true){
    if(radix > 36) return "Radix too large.";
    // Find the max power for num
    int MAX_POW = 0;
    bool POSITIVE; // if number is positive or negative
    
    if(num > 0) POSITIVE = 1;
    else if (num == 0) return "0";
    else {POSITIVE = 0; num = -num;}

    while(pow(radix,MAX_POW) <= num){
        MAX_POW++;
    }

    std::string str = "";
    if(!POSITIVE) str = "-";// Negative number
    int temp_num = num;
    for(int i = MAX_POW - 1; i>=0; i--){
        // find the divisor
        int div= temp_num / long(pow(radix,i));
        temp_num -= div * long(pow(radix,i));
        if(div <= 9 ) {
            str += char(div+48);
        }
        else if(!IS_LOWER_CASE){
            str += char(div+55);
        }
        else{
            str += char(div+87); // Number 10 + 87 = 'a'
        }
    }
    return str;
}
