#ifndef INPUTS_H
#define INPUTS_H

#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "Object.h"

namespace dshw
{
    class Inputs : public Object
    {
        private:
            std::string bits;
        public:
            Inputs() : Inputs(2) {}
            Inputs(int length)
            {
                if (length <= 1)
                {
                    throw std::invalid_argument("Length must be positive and greater than 1");
                }
                bits = std::string(length, '0');
            }
            Inputs(int length, bool starting_bit)
            {
                if (length <= 1)
                {
                    throw std::invalid_argument("Length must be positive and greater than 1");
                }
                bits = std::string(length, starting_bit ? '1' : '0');
            }
            Inputs(const std::string &bitString) : bits(bitString)
            {
                for (char c : bitString)
                {
                    if (c != '0' && c != '1')
                    {
                        throw std::invalid_argument("Bit string must contain only '0' and '1'");
                    }
                }
                if (bitString.empty())
                {
                    throw std::invalid_argument("Bit string must not be empty");
                }
            }

            Inputs(const Inputs &obj) : bits(obj.bits) {}
            Inputs& operator=(const Inputs &obj)
            {
                if (this != &obj)
                {
                    bits = obj.bits;
                }
                return *this;
            }

            ~Inputs() override {} 

            const char& input(unsigned int position) const
            {
                if (position > bits.size() || position < 1)
                {
                    throw std::out_of_range("Position out of range");
                }
                return bits[position - 1];
            }

            const char& operator[](unsigned int index) const
            {
                if (index >= bits.size())
                {
                    throw std::out_of_range("Index out of range");
                }
                return bits[index];
            }

            Inputs& operator++(int)
            {
                std::string original = bits;
                for (int i = bits.size() - 1; i >= 0; i--)
                {
                    if (bits[i] == '0')
                    {
                        bits[i] = '1';
                        break;
                    }
                    else
                    {
                        bits[i] = '0';
                    }
                }
                if (bits == std::string(bits.size(), '0'))
                {
                    bits = original;
                }
                return *this;
            }

            Inputs& operator++()
            {
                std::string original = bits;
                for (int i = bits.size() - 1; i >= 0; i--)
                {
                    if (bits[i] == '0')
                    {
                        bits[i] = '1';
                        break;
                    }
                    else
                    {
                        bits[i] = '0';
                    }
                }
                if (bits == std::string(bits.size(), '0'))
                {
                    bits = original;
                }
                return *this;
            }

            
            Inputs& operator--(int)
            {
                std::string original = bits;
                for (int i = bits.size() - 1; i >= 0; i--)
                {
                    if (bits[i] == '1')
                    {
                        bits[i] = '0';
                        break;
                    }
                    else
                    {
                        bits[i] = '1';
                    }
                }
                if (bits == std::string(bits.size(), '1'))
                {
                    bits = original;
                }
                return *this;

            }

            Inputs& operator--()
            {
                std::string original = bits;
                for (int i = bits.size() - 1; i >= 0; i--)
                {
                    if (bits[i] == '1')
                    {
                        bits[i] = '0';
                        break;
                    }
                    else
                    {
                        bits[i] = '1';
                    }
                }
                if (bits == std::string(bits.size(), '1'))
                {
                    bits = original;
                }
                return *this;
            }

            unsigned int size() const
            {
                return bits.size();
            }

            unsigned int length() const
            {
                return bits.size();
            }

            unsigned int sum() const
            {
                unsigned int count = 0;
                for (char c : bits)
                {
                    if (c == '1')
                    {
                        count++;
                    }
                }
                return count;
            }

            std::string toString() const override
            {
                return bits;
            }
            



    };
}
#endif