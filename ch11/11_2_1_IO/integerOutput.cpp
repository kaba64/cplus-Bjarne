#include <iostream>
#include <bitset> // for bit
#include <chrono>
#include <ctime>

int main(int argc,char **argv){
  
  // Get current time point
  auto now = std::chrono::system_clock::now();

  // Convert current time point to a time_t object
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);

  // Convert time_t object to a tm struct (for local time)
  std::tm* local_time = std::localtime(&now_time);

  int todayYear{local_time->tm_year + 1900};

  std::cout<<"Today is "<<std::bitset<sizeof(int) * 8>(todayYear)<<" in binary\n";
  std::cout<<"Today is "<<todayYear<<" in decimal\t"<<std::hex<<todayYear<<" in hex\t"
	   <<std::oct<<todayYear<<" in oct\n\n";
  std::cout<<std::showbase<<std::dec<<"Today is "<<todayYear<<"\t"<<std::hex<<todayYear<<"\t"
           <<std::oct<<todayYear<<"\n";

  std::cout<<"\n\n";

  std::cout<<std::dec<<1234<<"\t"<<0x4d2<<"\t"<<02322<<"\n\n";
  
  return 0;
}
