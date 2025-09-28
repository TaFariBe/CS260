#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using namespace std;

string pad(const string& binary, int length){
    if ((int)binary.size() >= length){
        return binary;
    }
    char sign = binary[0];
    string padded(length - binary.size(), sign);
    return padded + binary;
}

string trim(const string& binary){
    if (binary.empty()) 
    return binary;

    char sign = binary[0];
    int i = 0;
    while(i < (int)binary.size() - 1 && binary[i] == sign && binary[i+1] == sign){
        i++;
    }
    return binary.substr(i);
}

int binaryToDecimal(const string& binary){
    if (binary.empty()) {cout << "Empty binary string." << endl;}
    int length = binary.size();
    int deci_num = 0;

    for (int i = 0; i < length; i++){
        int bit = binary[i] - '0';
        int power = length - i - 1;

        if (i ==0 && bit == 1){
            deci_num -= (1 << power);
        } else {
            deci_num += bit * (1 << power);
        }
        }
        return deci_num;
    }

string hexToBinary(const string& hex) {
    static const string lookup[16] = 
    {
        "0000", "0001", "0010", "0011",
        "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };

    string result;
    for (char c : hex) {
        int value;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'A' && c <= 'F')
            value = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f')
            value = 10 + (c - 'a');
        else
            cout <<"Invalid hex character." << endl;

        result += lookup[value];
    }
    return result;
}

string subtract(const string& bin1, const string& bin2) {

    int dec1 = binaryToDecimal(bin1);
    int dec2 = binaryToDecimal(bin2);

    int result = dec1 - dec2;

    int length = max((int)bin1.size(), (int)bin2.size());

    bool negative = result < 0;
    int absVal = abs(result);
    string binary;

    while (absVal > 0) {
        binary = (char)('0' + (absVal % 2)) + binary;
        absVal /= 2;
    }
    if (binary.empty()) binary = "0";

    binary = pad(binary, length);

    if (negative) binary[0] = '1';
    else binary[0] = '0';

    return binary;
}

int main()
{
    cout << binaryToDecimal("1011") << endl; 
    cout << subtract("0110", "0011") << endl; // Expect 0011
    return 0;
}

/*  JS
    Task 1: 2/2
    Task 2: 2/2
    Task 3: Empty string still returns 0.
            1.8/2
    Task 4: Your function does not handle non-hex characters correctly.
            If the value variable is not assigned, it will contain an indeterminate value.
            Thus, accessing lookup[value] leads to undefined behavior.
            1.5/2
    Task 5: Your function does not properly handle padding and adding the sign bit.
            Based off your approach, the padding should happen last, after determining the sign bit.
            The sign bit should be added the front of the string instead of replacing the first character.
            1.0/2
    Total:  8.3/10
*/





