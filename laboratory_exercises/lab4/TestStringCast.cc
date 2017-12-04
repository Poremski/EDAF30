#include <iostream>
#include <string>
#include "date.h"
#include "templates.h"

using Templates::toString;
using Templates::string_cast;
using std::endl;
using std::cout;

bool test_int()
{
  int a = string_cast<int>("1");
  int b = 1;

  if (a != b)
  {
    cout << "TestStringCast (test_int): not equal (" + toString(a) + " != " + toString(b) + ")" << endl;
    return false;
  }
  cout << "TestStringCast (test_int): PASSED" << endl;
  return true;
}

bool test_bool()
{
  bool a = string_cast<bool>("1");
  bool b{true};

  if (a != b)
  {
    cout << "TestStringCast (test_bool): strings not equal (" + toString(a) + " != " + toString(b) + ")" << endl;
    return false;
  }
  cout << "TestStringCast (test_bool): PASSED" << endl;
  return true;
}

bool test_double()
{
  double a = string_cast<double>("1.11");
  double b = 1.11;

  if (a != b)
  {
    cout << "TestStringCast (test_double): strings not equal (" + toString(a) + " != " + toString(b) + ")" << endl;
    return false;
  }
  cout << "TestStringCast (test_double): PASSED" << endl;
  return true;
}

bool test_date()
{
  Date a = string_cast<Date>("2017-12-11");
  Date b{2017,12,11};

  if (a != b)
  {
    cout << "TestStringCast (test_date): strings not equal (" + toString(a) + " != " + toString(b) + ")" << endl;
    return false;
  }
  cout << "TestStringCast (test_date): PASSED" << endl;
  return true;
}

bool test_long()
{
  long a = string_cast<long>("1234");
  long b = 1234;

  if (a != b)
  {
    cout << "TestStringCast (test_long): strings not equal (" + toString(a) + " != " + toString(b) + ")" << endl;
    return false;
  }
  cout << "TestStringCast (test_long): PASSED" << endl;
  return true;
}

int main()
{
  std::cout << "== TestStringCast started ==" << std::endl;
  bool a = test_int();
  bool b = test_bool();
  bool c = test_double();
  bool d = test_date();
  bool e = test_long();

  if (a && b && c && d && e)
  {
    std::cout << "== All tests passed ==" << std::endl;
  }

  std::cout << "== TestStringCast passed ==" << std::endl;
}
