#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void printv(const std::vector<T>& x){
  
  for(auto it=x.cbegin();it!=x.cend();++it){
    int index = distance(x.cbegin(),it);
    std::cout<<"x ["<<index<<"] = "<<*it<<"\n";
  }
  std::cout<<"\n";
}

auto main() -> int
{
  std::vector<int> x(5);
  int i{2};
  std::cout<<"Initial vector\n";
  printv(x);
  std::cout<<"\nCaution: Do not use the following statmetns since the"
    " order of their evalution depends on the compilers (optimizatin)\n\n";
  std::cout<<"Modify the vecotor with i = "<<i<<" and the assignment : x[++i]=i\n";
  x[++i]=i;
  printv(x);

  std::cout<<"Modify the vecotor with i = "<<i<<" and the assignment : x[i]=++i\n";
  x[i]=++i;
  printv(x);
  
}
