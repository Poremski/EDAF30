#include <iostream>
#include <fstream>
#include <iomanip>
#include "coding.h"
#include <string>

void encode_file(std::string filename) {
  std::ifstream in("./" + filename + ".enc");

  int c;
  std::ofstream out("./" + filename + ".dec");
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

  encode_file(name);

  return 0;
}
