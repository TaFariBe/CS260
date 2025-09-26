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
            static const int MAX_INPUTS;
            std::string word;
            unsigned int length;
            static bool seeded;
            void seed()
            {
                if (!seeded)
                {
                    std::srand(static_cast<unsigned int>(std::time(0)));
                    seeded = true;
                }
            }
            char getRandomBit()
            {
                seed();
                return (std::rand() % 2) ? '1' : '0';
            }
            int getRandomLength()
            {
                seed();
                return (std::rand() % MAX_INPUTS) + 1;
            }

        public:
            Inputs() : Inputs(static_cast<unsigned int>(getRandomLength())) {}

            Inputs(unsigned int numInputs) : word(""), length(numInputs)
            {
                if (numInputs < 1 || numInputs > MAX_INPUTS)
                {
                    throw std::invalid_argument("numInputs must be between 1 and " + std::to_string(MAX_INPUTS));
                }

                for (unsigned int i = 0; i < numInputs; i++)
                {
                    word += getRandomBit();
                }
            }

            Inputs(const std::string &inputStr) : word(inputStr), length(static_cast<unsigned int>(inputStr.length()))
            {
                for (char c : word)
                {
                    if (c != '0' && c != '1')
                    {
                        throw std::invalid_argument("Input string must contain only '0' and '1'");
                    }
                }
            }

            Inputs(const Inputs &other) : word(other.word), length(other.length) {}

            Inputs& operator=(const Inputs &other)
            {
                if (this != &other)
                {
                    word = other.word;
                    length = other.length;
                }
                return *this;
            }

            ~Inputs() override {}

            std::string toString() const override
            {
                return word;
            }

            unsigned int size() const
            {
                return length;
            }

            int sum() const
            {
                int count = 0;
                for (char c : word)
                {
                    if (c == '1')
                    {
                        count++;
                    }
                }
                return count;
            }

            char operator[](unsigned int index)
            {
                if (index >= length)
                {
                    throw std::out_of_range("Index out of range");
                }
                return word[index];
            }

            const char operator[](unsigned int index) const
            {
                if (index >= length)
                {
                    throw std::out_of_range("Index out of range");
                }
                return word[index];
            }

    };
    const int Inputs::MAX_INPUTS = 32;
    bool Inputs::seeded = false;
}
#endif