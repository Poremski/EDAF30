#include <iostream>
#include <string>
#include <sstream>

class LuhnClass {
  public:
    LuhnClass(std::string sequence) {
      setSequence(sequence);
    }
    void setSequence(std::string sequence) {
      _sequence = sequence;
    }
    int getChecksum() {
      return calc();
    }
    int getNextDigit() {
        int c = 10 - calc(true);
        if (c > 9) return 0;
        else return c;
    }
  private:
      std::string _sequence;
      int calc(bool reverse = false) {
          int sum = 0;
          int nDigits = _sequence.length();
          int parity = nDigits % 2;
          for (int i = 0; i < nDigits; ++i) {
              int digit = _sequence[i] - '0';
              bool multi = (i % 2 == parity);
              if (reverse) multi = (i % 2 != parity);
              if (multi) {
                  digit = digit * 2;
                  if (digit > 9) digit -= 9;
              }
              sum += digit;
          }
          return sum % 10;
      }
};

int main() {
  std::string sequence;
  std::cout << "Digit sequence: ";
  std::getline(std::cin, sequence);

  LuhnClass lc(sequence);

  std::cout << "Luhn checksum mod 10: " << lc.getChecksum() << std::endl;
  std::cout << "Next check digit: " << lc.getNextDigit() << std::endl;
  return 0;
}
