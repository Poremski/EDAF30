#ifndef __TAGREMOVER_H
#define __TAGREMOVER_H

#include <string>
#include <unordered_map>

const static std::unordered_map<std::string,int> str_to_case{
 {"lt",1},
 {"gt",2},
 {"nbsp",3},
 {"amp",4}
};

class TagRemover
{
  public:
  	TagRemover(std::string);
  	void print(std::string);
  private:
  	std::string output;
};

#endif
