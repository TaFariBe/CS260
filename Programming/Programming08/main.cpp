#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "util.h"
using namespace std;
using namespace dshw;

string arithmeticShiftRight(const string &s, int n, int base) {
    validate(s, base);
    string x = s;
    char sign = s[0];

    for (int i = 0; i < n; i++) {
        x = sign + x.substr(0, x.size() - 1);
    }
    return x;
}

string logicalShiftLeft(const string &s, int n, int base) {
    validate(s, base);
    string x = s;

    for (int i = 0; i < n; i++) {
        x = x.substr(1) + "0";
    }
    return x;
}

string toBinary(const string &s, int base) {
    validate(s, base);
    if (base == 2) return trim(s, 2);

    string out = "";
    for (char c : s) {
        int v = getValue(c);
        if (base == 8)
            out += OCTALS[v];
        else
            out += HEXADECIMALS[v];
    }
    return trim(out, 2);
}

string fromBinary(const string &b, int base) {
    validate(b, 2);

    int group = (base == 8 ? 3 : 4);
    string s = b;
    int r = s.size() % group;
    if (r != 0) s = pad(s, s.size() + (group - r), 2);

    string out = "";
    for (int i = 0; i < (int)s.size(); i += group) {
        int val = 0;
        for (int j = 0; j < group; j++)
            val = val * 2 + (s[i+j] - '0');
        out += DIGITS[val];
    }
    return trim(out, base);
}

string multiply(const string &a, const string &b, int base) {
    validate(a, base);
    validate(b, base);
    string A = toBinary(a, base);
    string B = toBinary(b, base);

    long long x = stoll(A, nullptr, 2);
    long long y = stoll(B, nullptr, 2);
    long long p = x * y;

    string bin = "";
    if (p == 0) return "0";
    while (p > 0) {
        bin = char('0' + (p % 2)) + bin;
        p /= 2;
    }

    return fromBinary(bin, base);
}

string divide(const string &a, const string &b, int base) {
    validate(a, base);
    validate(b, base);

    string A = toBinary(a, base);
    string B = toBinary(b, base);
    long long x = stoll(A, nullptr, 2);
    long long y = stoll(B, nullptr, 2);
    long long Q = x / y;
    long long R = x % y;

    string q = "";
    string r = "";

    if (Q == 0) q = "0";
    else while (Q > 0) { q = char('0' + (Q % 2)) + q; Q /= 2; }
    if (R == 0) r = "0";
    else while (R > 0) { r = char('0' + (R % 2)) + r; R /= 2; }

    return fromBinary(r, base) + " " + fromBinary(q, base);
}
