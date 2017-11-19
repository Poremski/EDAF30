#include <iostream>
#include <string>
#include <sstream>
#include "luhn.h"

Luhn::Luhn(std::string sequence)
{
    Luhn::setSequence(sequence);
}

void Luhn::setSequence(std::string sequence)
{
    Luhn::_sequence = sequence;
}
int Luhn::getChecksum()
{
    return Luhn::calc();
}
int Luhn::getNextDigit()
{
    int c = 10 - calc(true);
    if (c > 9)
    {
        return 0;
    }
    else
    {
        return c;
    }
}
int Luhn::calc(bool reverse)
{
    int sum = 0;
    int nDigits = Luhn::_sequence.length();
    int parity = nDigits % 2;
    for (int i = 0; i < nDigits; i++)
    {
        int digit = Luhn::_sequence[i] - '0';
        bool multi = (i % 2 == parity);
        if (reverse) multi = (i % 2 != parity);
        if (multi)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
    }
    return sum % 10;
}

int main(int argc, const char * argv[])
{
    std::string sequence;
    if (argc == 2)
    {
        sequence = argv[1];
    }
    else
    {
        std::cout << "Digit sequence: ";
        std::getline(std::cin, sequence);
    }

    Luhn::Luhn lc(sequence);

    std::cout << "Luhn checksum mod 10: " << lc.getChecksum() << std::endl;
    std::cout << "Next check digit: " << lc.getNextDigit() << std::endl;
    return 0;
}
