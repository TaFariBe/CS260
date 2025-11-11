#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;
namespace dshw {

    const string Hex = "0123456789ABCDEF";

    int getValue(char r) {
        r = toupper(static_cast<unsigned char>(r));
        for (int i = 0; i < 16; ++i) {
            if (Hex[i] == r) return i;
        }
        return -1;
    }

    bool validate(const string& num, int base) {
        if (base != 2 && base != 8 && base != 16)
            throw invalid_argument("Base must be 2, 8, or 16.");

        for (char c : num) {
            int val = getValue(c);
            if (val == -1 || val >= base)
                return false;
        }
        return true;
    }

    string pad(const string& num, int length, int base) {
        if (!validate(num, base))
            throw invalid_argument("Invalid number for given base.");

        if (length < (int)num.size())
            throw invalid_argument("Length must be >= current length.");

        int firstVal = getValue(num[0]);
        char signDigit = (firstVal >= base / 2) ? Hex[base - 1] : '0';

        if ((int)num.size() == length)
            return num;

        string padded(length - num.size(), signDigit);
        padded += num;
        return padded;
    }

    string trim(const string& num, int base) {
        if (!validate(num, base))
            throw invalid_argument("Invalid number.");

        if (num.empty())
            return num;

        int firstVal = getValue(num[0]);
        char signDigit = (firstVal >= base / 2) ? Hex[base - 1] : '0';

        size_t i = 0;
        while (i < num.size() - 1 && num[i] == signDigit && num[i + 1] == signDigit)
            i++;

        return num.substr(i);
    }

}

#endif
/*  JS
Task 1: 0.5/0.5
Task 2: 1.0/1.0
Task 3: function does not ensure the base is 2, 8, or 16.
        1.3/1.5
Task 4: Function does not properly pad the string.
        1.5/3.0
Task 5: Function does not properly trim the string.
        3.0/4.0
Total: 7.3/10.0

*/