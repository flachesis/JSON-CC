#include "json.hpp"
#include "util.hpp"
#include <string>
#include <iostream>

/**
 * Read JSON from standard input, parse it and print with
 * json::print visitor.
 */
int main(int argc, char** argv)
{
  using namespace std;
  using namespace yangacer;
  
  json::istream_iterator beg(cin), end;
  json::var_t v;
  // or use json::parse(beg, end, grammar, o) to parse line-by-line
  if(!json::phrase_parse(beg, end, v)){ 
    cerr << "Parsing failed\n";
  }else{
    cout << "Parsing successed\n";
    json::pretty_print(cout, v);
  }
  return 0;
}