#include <fstream>
#include <iostream>
#include <string>
#include "TagRemover.h"

bool test(std::string fname);

int main()
{
  std::cout << "== TestTagRemover started ==" << std::endl;
  bool a = test("TestTagRemover");
  bool b = test("TestSpecCharReplacer");
  bool c = test("TestDoubleTagRemover");
  bool d = test("TestMultilineTagRemover");
  bool e = test("Test");

  if (a && b && c && d && e)
  {
    std::cout << "== All tests passed ==" << std::endl;
  }

  std::cout << "== TestTagRemover passed ==" << std::endl;
}

bool test(std::string fname)
{
  TagRemover tr("html/test/" + fname + ".html");
  tr.print("html/result/" + fname + ".txt");

  std::ifstream f1{"html/correct/" + fname + ".txt"};
  std::ifstream f2{"html/result/" + fname + ".txt"};

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
