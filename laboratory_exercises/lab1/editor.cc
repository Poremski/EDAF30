#include "editor.h"

#include <string>
#include <iostream>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const {
    char c = text[pos];
    int skip = 0;
    char find = '\0';
    switch(c)
    {
      case ')':
        find = '(';
        break;
      case ']':
        find = '[';
        break;
      case '}':
        find = '{';
        break;
      default:
        break;
    }
    for (int i = pos-1; i>=0; --i)
    {
      if (text[i] == c)
      {
        ++skip;
      }
      else if (text[i] == find && skip != 0)
      {
        --skip;
      }
      else if (text[i] == find)
      {
        return i;
      }
    }
    return string::npos;
}
