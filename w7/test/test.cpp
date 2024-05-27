#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> strings;
  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");

  // use &s to avoid copying the string
  for (const string &s : strings)
  {
    // cannot compile because s is const
    // s = 'abc';
    cout << s << endl;
  }
};