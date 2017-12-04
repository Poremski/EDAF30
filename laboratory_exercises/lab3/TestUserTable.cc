#include <fstream>
#include <iostream>
#include <string>
#include "UserTable.h"
#include "User.h"

void print(std::string s, User u);

int main()
{
  std::string inName{"users.txt"};
  UserTable userTable(inName);

  User u1 = userTable.find(21330);
  print("21330", u1);

  User u2 = userTable.find(21331);
  print("21331", u2);

  User u3 = userTable.find("Jens Holmgren");
  print("Jens Holmgren", u3);

  User u4(1234, "Javier Poremski");
  std::cout << "Antalet användare förre ny användare: " << userTable.getNbrUsers() << std::endl;
  userTable.addUser(u4);
  std::cout << "Antalet användare efter ny användare: " << userTable.getNbrUsers() << std::endl;

  std::string outName{"TestFile.txt"};
  std::ofstream os(outName);
  userTable.print(os);

  int nbr = userTable.testFindNumber();
  std::cout << "testFindNumber() returnerade " << nbr << "." << std::endl;

  User u5 = userTable.find(21331);
  print("21331", u5);
}

void print(std::string s, User u)
{
  std::cout << s << ": " << u.getName() << ", " << u.getCardNbr() << std::endl;
}
