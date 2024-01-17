#include <iostream>
#include <exception>

enum class Month{
		 jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

void printMonth(const Month& m ){
  switch(static_cast<int>(m)){
  case 1:
    std::cout<<"January\n";
    break;
  case 2:
    std::cout<<"February\n";
    break;
  case 3:
    std::cout<<"March\n";
    break;
  case 4:
    std::cout<<"April\n";
    break;
  case 5:
    std::cout<<"May\n";
    break;
  case 6:
    std::cout<<"June\n";
    break;
  case 7:
    std::cout<<"July\n";
    break;
  case 8:
    std::cout<<"August\n";
    break;
  case 9:
    std::cout<<"Sepember\n";
    break;
  case 10:
    std::cout<<"October\n";
    break;
  case 11:
    std::cout<<"November\n";
    break;
  case 12:
    std::cout<<"December\n";
    break;
  }
}

Month int_to_month(const int x){
  if(x<static_cast<int>(Month::jan) || static_cast<int>(Month::dec)<x) throw std::runtime_error("Bad month!");
  return Month(x);
}

int main(int argc,char *argv[]){
  try{
    Month mm = int_to_month(8);
    printMonth(mm);
  }catch(const std::runtime_error& exp){
    std::cerr<<exp.what()<<"\n";
  }
  return 0;
}
