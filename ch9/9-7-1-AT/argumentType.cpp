#include <iostream>
#include <exception>
#include <string>

class Year {
  static constexpr int min{1800};
  static constexpr int max{2200};
public:
  Year(int x);
  int getYear()const{return y;}
  Year operator ++() {//prefix increment
    ++y;
    return *this;
  }
private:
  int y;
};

Year::Year(int x): y{x} {
  if (x<min || max<=x){
    std::string errorOut{"Invalid year. Enter a year in the range ["+std::to_string(min)+
			 ","+std::to_string(max)+"]."};
    throw std::runtime_error(errorOut);
  }
}

enum class Month{
		 jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
};

Month int_to_month(const int x){
  if(x<static_cast<int>(Month::jan) || static_cast<int>(Month::dec)<x)
    throw std::runtime_error("Invlid month. Enter a month in the range [1,12].");
  return Month(x);
}

class Date{
public:
  Date(const Year yi,const Month mi,const int di)
    :y{yi},m{mi},d{di}{
      if(!is_valid()) throw std::runtime_error("Invalid Date");
  }
  void add_day(int n);
  int year()const{return y.getYear();}
  int month()const{return static_cast<int>(m);}
  int day()const{return d;}
private:
  Year y;
  Month m;
  int d;
  bool is_valid();
};

bool Date::is_valid(){
  
  if((static_cast<int>(m)==1 || static_cast<int>(m)==3 || static_cast<int>(m) ==5 ||
      static_cast<int>(m)==7 || static_cast<int>(m)==8 || static_cast<int>(m)==10 ||
      static_cast<int>(m)==12) && (d>0 && d<32))
    return true;
  else if((static_cast<int>(m)==4 || static_cast<int>(m)==6 || static_cast<int>(m)==9 ||
	   static_cast<int>(m)==11) && (d>0 && d<31))
    return true;
  else if(static_cast<int>(m)==2  && (d>0 && d<30))
    return true;
  return false;
}

void Date::add_day(const int n){
  if(static_cast<int>(m)==12 && (d+n-1)==31){
    ++y;
    m = Month::jan;
    d = 1;
  }else if(static_cast<int>(m)==2 && (d+n-1)==28){

  }else if((static_cast<int>(m)==4 || static_cast<int>(m)==6 ||
	   static_cast<int>(m)==9 || static_cast<int>(m)==11) &&
	  (d+n-1)==30){

  }else if((d+n-1)>=31){
    m = int_to_month(static_cast<int>(m)+1);
    d = 1;
  }else{
    d+=n;
  }
}

int main(int argc,char *argv[]){
  try{
    Date today{Year(2022),Month::may,28};
    std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
    today.add_day(5);
    std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
  }catch(const std::runtime_error& exp){
    std::cerr<<exp.what()<<"\n";
  }
  return 0;
}
