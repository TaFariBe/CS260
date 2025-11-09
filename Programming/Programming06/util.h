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
        for (char c : num) {
            int val = getValue(c);
            if (val == -1 || val >= base) {
                return false;
            }
        }
        return true;
    }

    string pad(const string& num, int Length, int base) {
        if (!validate(num, base)) {
            throw invalid_argument("Invalid number for given base.");
        }

        if (Length < static_cast<int>(num.length())) {
            throw invalid_argument("must be >= current length.");
        }

          char signDigit = num.front();

        if (static_cast<int>(num.length()) == Length)
            return num;


        string padded(Length - num.length(), signDigit);
            padded += num;

        return padded;
    }

    string trim(const string& num, int base) {
        if (!validate(num, base)) {
            throw invalid_argument("Invalid number.");
        }

        if (num.empty()) return num;

        char signedDigit = num[0];
        size_t firstDiff = 0;

        while (firstDiff < num.size() - 1 && num[firstDiff] == signedDigit) {
            int val = getValue(num[firstDiff + 1]);
            int signVal = getValue(signedDigit);
            if (val >= base || signVal >= base) break; 
            if (num[firstDiff + 1] != signedDigit) break;
            firstDiff++;
        }

        string trimmed = num.substr(firstDiff);
        return trimmed;
    }

}

#endif
