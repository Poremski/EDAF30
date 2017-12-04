#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Primes.h"

std::string calc(int m, std::ofstream* of);
void find_P(std::string s, int* p);
void get_nbrs(std::vector<int>* v, std::string* primes);

Primes::Primes(int m, std::string fname)
{
  std::ofstream of{fname};
  std::string pr = calc(m, &of);
  std::vector<int> v;
  get_nbrs(&v, &pr);
  of.put('\n');
  std::string tmp;
  for (int n : v) tmp += std::to_string(n) + " ";
  for (char c : tmp) of.put(c);
}

std::string calc(int m, std::ofstream* of)
{
  std::string primes(m + 1, 'P');
  primes[0] = 'C';
  primes[1] = 'C';

  std::string out_primes{primes};
  for (char c : primes) of->put(c);

  int p{2};
  while (p * 2 <= m)
  {
    of->put('\n');
    for (size_t i = p + 1; i != primes.size(); i++)
    {
      if (i % p == 0) primes[i] = 'C';
    }
    for (char c : primes) of->put(c);
    find_P(primes, &p);
  }
  return primes;
}

void find_P(std::string s, int* p)
{
  for (size_t i = *p + 1; i < s.size(); ++i)
  {
    if (s[i] == 'P')
    {
      *p = i;
      return;
    }
  }
}

void get_nbrs(std::vector<int>* v, std::string* primes)
{
  for (size_t i = 0; i != primes->size(); ++i)
  {
    if (primes->at(i) == 'P') v->push_back(i);
  }
}
