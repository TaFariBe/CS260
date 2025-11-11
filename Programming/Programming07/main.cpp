#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "../Programming06/util.h"

using namespace std;
using namespace dshw;


int toDecimal(const string& num, int base) {
    if (!validate(num, base)) {
        throw invalid_argument("Wrong string for base");
    }

    int total = 0;
    int len = num.length();

    for (int i = 0; i < len; i++) {
        int val = getValue(num[i]);
        total += val * pow(base, len - i - 1);
    }

    int firstVal = getValue(num[0]);
    if (firstVal >= base / 2) {
        total -= pow(base, len);
    }

    return total;
}

int add(const string& a, const string& b, int base) {
    if (!validate(a, base) || !validate(b, base)) {
        throw invalid_argument("Wrong string for base");
    }

    int decA = toDecimal(a, base);
    int decB = toDecimal(b, base);
    int result = decA + decB;

    return result; 
}

string onesComplement(const string& num, int base) {
    if (!validate(num, base)) {
        throw invalid_argument("Invalid number.");
    }
    if (base != 2 && base != 8 && base != 16) {
        throw invalid_argument("Base must be 2, 8, or 16.");
    }

    string out = "";
    for (char c : num) {
        int val = getValue(c);
        int newVal = (base - 1) - val;
        out += Hex[newVal];
    }

    return out;
}

string twosComplement(const string& num, int base) {
    if (!validate(num, base)) {
        throw invalid_argument("Invalid number.");
    }

    string oneComp = onesComplement(num, base);

    string one(num.size() - 1, '0');
    one += '1';

    return oneComp;
}

int subtract(const string& a, const string& b, int base) {
    if (!validate(a, base) || !validate(b, base)) {
        throw invalid_argument("Invalid strings.");
    }

    int decA = toDecimal(a, base);
    int decB = toDecimal(b, base);
    int diff = decA - decB;

    return diff;
}

string toBase(int dec, int base) {
    if (base != 2 && base != 8 && base != 16) {
        throw invalid_argument("Base has to be 2, 8 or 16");
    }

    bool neg = (dec < 0);
    int num = abs(dec);
    string result = "";

    if (num == 0) return "0";

    while (num > 0) {
        int rem = num % base;
        result = Hex[rem] + result;
        num /= base;
    }

    if (neg) {
        result = pad(result, result.size(), base);
        result = twosComplement(result, base);
    }

    return result;
}
