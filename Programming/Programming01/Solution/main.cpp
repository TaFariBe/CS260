#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int toDecimal(const string& num, int base)
{
    int exponent = 0;
    int result = 0;
    // "00001010"
    if (base == 2 || base == 8 || base == 16)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            int value;
            if (num[i] >= '0' && num[i] <= '9')
            {
                value = (num[i] - '0');
            }
            else if (toupper(num[i]) >= 'A' && toupper(num[i]) <= 'F')
            {
                value = (toupper(num[i]) - 'A' + 10);
            }
            else
            {
                return -1;
            }
            if (value >= base)
            {
                return -1;
            }
            result += value * pow(base, exponent);
            exponent++;
        }
        return result;
    }
    else
    {
        return -1;
    }
}

string toBase(int quotient, int base)
{
    if (!quotient)
    {
        return "0";
    }
    string lookup_table = "0123456789ABCDEF";
    string result = "";
    if (base == 2 || base == 8 || base == 16)
    {
        int remainder;
        while (quotient > 0)
        {
            remainder = quotient % base;
            result = lookup_table[remainder] + result;
            quotient /= base;
        }
    }
    return result;
}