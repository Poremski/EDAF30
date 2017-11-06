#include <iostream>
#include <fstream>
#include <iomanip>
#include "coding.h"
#include <string>

void decode_file(std::string filename) {
  std::ifstream in("./" + filename + ".dec");

  int c;
  std::ofstream out("./" + filename + ".enc");
  while ((c = in.get()) != EOF) {
    out.put(encode(char(c)));
  }
}

int main(int argc, const char** argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " filename" << std::endl;
    return 1;
  }

  std::string name{argv[1]};

  decode_file(name);

  return 0;
}
