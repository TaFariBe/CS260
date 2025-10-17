#ifndef LOGIC_PAIR_H
#define LOGIC_PAIR_H

#include "Inputs.h"


namespace dshw
{
    class LogicPair : public Object
    {
        private:
            std::string name;
            bool value;
        public:
            LogicPair(const std::string &name, bool value) : name(name), value(value) {}
            LogicPair(const LogicPair &obj) : name(obj.name), value(obj.value) {}
            LogicPair& operator=(const LogicPair &obj)
            {
                if (this != &obj)
                {
                    name = obj.name;
                    value = obj.value;
                }
                return *this;
            }

            LogicPair(LogicPair&& obj) noexcept : name(std::move(obj.name)), value(obj.value) {}
            LogicPair& operator=(LogicPair&& obj) noexcept
            {
                if (this != &obj)
                {
                    name = std::move(obj.name);
                    value = obj.value;
                }
                return *this;
            }
            ~LogicPair() override {}

            std::string getName() const
            {
                return name;
            }

            bool getValue() const
            {
                return value;
            }

            std::string toString() const override
            {
                return "(" + name + ", " + (value ? "true" : "false") + ")";
            }

            
    };
}

#endif