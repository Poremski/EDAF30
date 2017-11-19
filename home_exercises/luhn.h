#ifndef LUHN_H
#define LUHN_H

#include <string>

class Luhn
{
    public:
        Luhn(std::string sequence);
        void setSequence(std::string sequence);
        int getChecksum();
        int getNextDigit();
    private:
        std::string _sequence;
        int calc(bool reverse = false);
};

#endif // LUHN_H