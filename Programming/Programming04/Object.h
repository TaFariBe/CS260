#ifndef OJECT_H
#define OJECT_H

#include <iostream>
#include <string>

namespace dshw
{
    class Object
    {
        public:
            virtual ~Object(){};
            virtual std::string toString() const = 0;
            
            friend std::ostream& operator<<(std::ostream& os, const Object& obj)
            {
                os << obj.toString();
                return os;
            }
    };
}
#endif