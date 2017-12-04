#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include "TagRemover.h"

std::string format(std::ifstream* in);
void remove_tag(std::ifstream* in, std::string* out);
void spec_char_replacer(std::ifstream* in, std::string* out);

TagRemover::TagRemover(std::string fname)
{
  std::ifstream in{fname};
  output = format(&in);
}

void TagRemover::print(std::string fname)
{
  std::ofstream of{fname};
  of << output;
}

std::string format(std::ifstream* in)
{
  std::string out;
  char c;
  while ((c = in->get()) != EOF)
  {
    switch (c)
    {
      case '<' : remove_tag(in, &out); break;
      case '&' : spec_char_replacer(in, &out); break;
      default : out += c; break;
    }
  }
  return out;
}

void remove_tag(std::ifstream* in, std::string* out)
{
  if (out->back() == ' ') out->pop_back();
  char c;
  while ((c = in->get()) != EOF)
  {
    if (c == '\n') *out += '\n';
    else if (c == '>')
    {
      if (out->back() == '\n' && (c=in->get()) != ' ') *out += c;
      return;
    }
  }
}

void spec_char_replacer(std::ifstream* in, std::string* out)
{
  std::string spec_char;
  char c;
  while((c = in->get()) != ';')
  {
    spec_char += c;
  }

  switch (str_to_case.count(spec_char) ? str_to_case.at(spec_char) : 0) {
    case 1 : *out += '<'; break;
    case 2 : *out += '>'; break;
    case 3 : *out += ' '; break;
    case 4 : *out += '&'; break;
    default : *out += "&" + spec_char + ";";
  }
}
