// splicing lists
#include <iostream>
#include <list>

int main ()
{
  std::list<int> mylist1;
  std::list<int>::iterator it;

  for (int i = 0; i < 4; i++)
    mylist1.push_back(i + 1);

  it = mylist1.begin();
  std::advance(it, 1);
  mylist1.splice(--mylist1.end(), mylist1, it);

  // it--;

  std::cout << "mylist1 contains:";
  for (auto ity=mylist1.begin(); ity!=mylist1.end(); ++ity)
    std::cout << ' ' << *ity;
  std::cout << '\n';

  return 0;
}