#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <stdexcept>

namespace dsl
{
    std::string pad(const std::string& str, int length)
    {
        if (length <= str.length()) 
        {
            return str;
        }
        char sign = str[0];
        std::string result = str;
        while (result.length() < length) 
        {
            result = sign + result;
        }
        return result;
    }

    std::string trim(const std::string& binary) 
    {
        int index = 0;
        while (index < binary.length() - 1 && binary[index] == binary[index + 1]) 
        {
            index++;
        }
        return binary.substr(index);
    }

    std::string onesComplement(const std::string& binary) 
    {
        std::string result = "";

        for (int i = binary.length() - 1; i >= 0; i--) 
        {
            if (binary[i] != '0' && binary[i] != '1') 
            {
                throw std::invalid_argument("Invalid binary number");
            }
            result = (binary[i] - '0' ? '0' : '1') + result;
        }
        return result;
    }
}

#endif