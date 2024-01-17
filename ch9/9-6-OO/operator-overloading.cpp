#include <iostream>
#include <vector>
#include <exception>

enum class Month{
		 jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

std::string MonthConverString(const Month& m ){
  std::string outPut;
  switch(static_cast<int>(m)){
  case 1:
    outPut = "January";
    break;
  case 2:
    outPut = "February";
    break;
  case 3:
    outPut = "March";
    break;
  case 4:
    outPut = "April";
    break;
  case 5:
    outPut = "May";
    break;
  case 6:
    outPut = "June";
    break;
  case 7:
    outPut = "July";
    break;
  case 8:
    outPut = "August";
    break;
  case 9:
    outPut = "Sepember";
    break;
  case 10:
    outPut = "October";
    break;
  case 11:
    outPut = "November";
    break;
  case 12:
    outPut = "December";
    break;
  }
  return outPut;
}

Month int_to_month(const int x){
  if(x<static_cast<int>(Month::jan) || static_cast<int>(Month::dec)<x) throw std::runtime_error("Bad month!");
  return Month(x);
}

Month operator++(Month& m){
  m = (m == Month::dec) ? Month::jan : Month(static_cast<int>(m)+1);
  return m;
}

std::ostream& operator<<(std::ostream& os,Month m){
  
  return os<<MonthConverString(m);
}

int main(int argc,char *argv[]){
  try{
    Month mm = Month::dec;
    std::cout<<mm<<"\n";
    ++mm;
    std::cout<<mm<<"\n";
  }catch(const std::exception& exp){
    std::cerr<<exp.what()<<"\n";
  }
  return 0;
}
