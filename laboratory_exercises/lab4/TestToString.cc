#include <iostream>
#include <string>
#include "date.h"
#include "templates.h"

using Templates::toString;
using std::endl;
using std::cout;

bool test_int()
{
  int a = 1;
  int b = 2;
  std::string res = toString(a) + " " + toString(b);

  if (res != "1 2")
  {
    cout << "TestToString (test_int): strings not equal (" + res + " != 1 2)" << endl;
    return false;
  }
  cout << "TestToString (test_int): PASSED" << endl;
  return true;
}

bool test_bool()
{
  bool a{true};
  bool b{false};
  std::string res = toString(a) + " " + toString(b);

  if (res != "1 0")
  {
    cout << "TestToString (test_bool): strings not equal (" + res + " != 1 0)" << endl;
    return false;
  }
  cout << "TestToString (test_bool): PASSED" << endl;
  return true;
}

bool test_double()
{
  double a = 1.11;
  double b = 2.22;
  std::string res = toString(a) + " " + toString(b);

  if (res != "1.11 2.22")
  {
    cout << "TestToString (test_double): strings not equal (" + res + " != 1.11 2.22)" << endl;
    return false;
  }
  cout << "TestToString (test_double): PASSED" << endl;
  return true;
}

bool test_date()
{
  Date a{2017,12,11};
  Date b{2017,12,12};
  std::string res = toString(a) + " " + toString(b);

  if (res != "2017-12-11 2017-12-12")
  {
    cout << "TestToString (test_date): strings not equal (" + res + " != 2017-12-11 2017-12-12)" << endl;
    return false;
  }
  cout << "TestToString (test_date): PASSED" << endl;
  return true;
}

bool test_string()
{
  std::string a{"qwerty"};
  std::string b{"asdfgh"};
  std::string res = toString(a) + " " + toString(b);

  if (res != "qwerty asdfgh")
  {
    cout << "TestToString (test_string): strings not equal (" + res + " != qwerty asdfgh)" << endl;
    return false;
  }
  cout << "TestToString (test_string): PASSED" << endl;
  return true;
}

bool test_long()
{
  long a = 1234;
  long b = 5678;
  std::string res = toString(a) + " " + toString(b);

  if (res != "1234 5678")
  {
    cout << "TestToString (test_long): strings not equal (" + res + " != 1234 5678)" << endl;
    return false;
  }
  cout << "TestToString (test_long): PASSED" << endl;
  return true;
}

bool test_all()
{
  int a = 1;
  bool b = true;
  double c = 1.1;
  Date d{2017,12,11};
  std::string e{"qwerty"};
  long f = 1;

  std::string res = toString(a) + toString(b) + toString(c) +
                    toString(d) + toString(e) + toString(f);

  if (res != "111.12017-12-11qwerty1")
  {
    cout << "TestToString (test_all): strings not equal (" + res + " != 111.12017-12-11qwerty1)" << endl;
    return false;
  }
  cout << "TestToString (test_all): PASSED" << endl;
  return true;
}

int main()
{
  std::cout << "== TestToString started ==" << std::endl;
  bool a = test_int();
  bool b = test_bool();
  bool c = test_double();
  bool d = test_date();
  bool e = test_string();
  bool f = test_long();
  bool g = test_all();

  if (a && b && c && d && e && f && g)
  {
    std::cout << "== All tests passed ==" << std::endl;
  }

  std::cout << "== TestToString passed ==" << std::endl;
}
