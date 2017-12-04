#include <fstream>
#include <iostream>
#include <string>
#include "Primes.h"

bool test(std::string fname);

int main()
{
  std::cout << "== TestPrimes started ==" << std::endl;
  bool a = test("TestPrimes");
  if (a) std::cout << "== All tests passed ==" << std::endl;
  std::cout << "== TestPrimes passed ==" << std::endl;
}

bool test(std::string fname)
{
  Primes pr(35, "prime/result/" + fname + ".txt");
  std::ifstream f1{"prime/correct/" + fname + ".txt"};
  std::ifstream f2{"prime/result/" + fname + ".txt"};

  char c1, c2;

  while((c1 = f1.get()) != EOF && (c2 = f2.get()) != EOF)
  {
    if (c1 != c2)
    {
      std::cout << fname
                << ": files not equal (\'"
                << c1
                << "\' != \'"
                << c2
                << "\' at pos "
                << f1.tellg()
                << ")"
                << std::endl;
      return false;
    }
  }

  if ((c1 = f1.peek()) != EOF || (c2 = f2.peek()) != EOF)
  {
    std::cout << fname
              << ": files not equal (both files not at EOF)"
              << std::endl;
    return false;
  }

  std::cout << fname << ": PASSED" << std::endl;
  return true;
}
