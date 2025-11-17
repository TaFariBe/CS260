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

/*  JS
    Task 1: 2/2
    Task 2: Your function should return a string, not an int.
            Additionally, your should not convert the numbers to decimal to perform the addition.
            You should be adding the numbers directly in their given base.
            1/2
    Task 3: 2/2
    Task 4: Your function returns the one's complement.
            The one variable is not being added to the one's complement to produce the two's complement.
            The logic for your one variable is incorrect for base 2 when the input is 1.
            When the input is 1, one should be 01 not just 1.
            Then add one to the one's complement.
            Additionally, your function should also check that negative powers of 2 in base 2 are properly converted.
            Example, the two's complement of 1000 (-8) will produce 1000 (-8) again instead of 01000 (+8).
            You should also check if the result is the same as the original number and pad with a leading zero if so.
            0.5/1
    Task 5: Your function should return a string, not an int.
            Additionally, your function should not convert to decimal to perform the subtraction.
            You should be subtracting the numbers directly in their given base.
            0.5/1
    Task 6: Your function needs to ensure the result of repeated division is positive before proceeding.
            If the most significant digit of the resulting base number is greater than or equal to half the base, pad the number with a leading zero.
            Then, if the original decimal number is negative, you should convert the resulting base number to its two's complement form.
            1.5/2
    Total:  7.5/10.0


*/