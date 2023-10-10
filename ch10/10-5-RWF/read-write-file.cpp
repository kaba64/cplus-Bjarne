#include <iostream>
#include <fstream>
#include <vector>

class Reading{
public:
  Reading(int hin,double tin)
    :hour{hin},temperature{tin}{}
  int hour;
  double temperature;
};

auto main() -> int
{
  std::vector<Reading> temps;
  int hour;
  double temperature;
  std::string iname="temperature";
  std::ifstream ist{iname+".txt"};
  while(ist>>hour>>temperature){
    temps.push_back(Reading{hour,temperature});
  }
  
  for(unsigned int i=0;i<temps.size();++i)
    std::cout<<temps[i].hour<<"\t"<<temps[i].temperature<<"\n";
}
