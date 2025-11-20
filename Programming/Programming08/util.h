#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
using namespace std;

namespace dshw {

const string DIGITS = "0123456789ABCDEF";
const string OCTALS[8] = {"000","001","010","011","100","101","110","111"};
const string HEXADECIMALS[16] = {
    "0000","0001","0010","0011","0100","0101","0110","0111",
    "1000","1001","1010","1011","1100","1101","1110","1111"
};

int getValue(char);
void validate(const string&, int);
string pad(const string&, int, int);
string trim(const string&, int);

long long toDecimal(const string&, int);
string add(const string&, const string&, int);
string onesComplement(const string&, int);
string twosComplement(const string&, int);
string subtract(const string&, const string&, int);
string toBase(long long, int);

}

#endif
