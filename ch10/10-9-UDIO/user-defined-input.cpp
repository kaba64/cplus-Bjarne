#include <iostream>
#include <fstream>
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
  if (x<min || max<x){
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

Month operator++(Month& m){
  m = (m == Month::dec) ? Month::jan : Month(static_cast<int>(m)+1);
  return m;
}

class Date{
public:
  Date(const Year yi,const Month mi,const int di)
    :y{yi},m{mi},d{di}{
      if(!is_valid()) throw std::runtime_error("Invalid Date");
  }
  Date():y{defaultDate().y},m{defaultDate().m},d{defaultDate().d}{}
  Date& operator++();
  void add_day(int n);
  int year()const{return y.getYear();}
  int month()const{return static_cast<int>(m);}
  int day()const{return d;}
private:
  Year y;
  Month m;
  int d;
  bool is_valid();
  const Date& defaultDate();
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

Date& Date::operator++(){
  if(static_cast<int>(m)==12 && d==31){
    ++y;
    ++m;
    d = 1;
  }else if(static_cast<int>(m)==2 && d==28){
    ++m;
    d = 1;
  }else if((static_cast<int>(m)==4 || static_cast<int>(m)==6 ||
	    static_cast<int>(m)==9 || static_cast<int>(m)==11) &&
	   d==30){
    ++m;
    d = 1;
  }else if(d==31){
    ++m;
    d = 1;
  }else{
    d+=1;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os,const Date& d){
  return std::cout<<"("<<d.year()<<","<<d.month()<<","<<d.day()<<")\n";
}

const Date& Date::defaultDate(){
  static Date dd(Year(2001),Month::jan,1);
  return dd;
}

void Date::add_day(const int n){
  for(int i =0;i<n;++i)
    ++(*this);
}

std::istream& operator>>(std::istream& is,Date& dd){
  int y,m,d;
  char ch1,ch2,ch3,ch4;
  is>>ch1>>y>>ch2>>m>>ch3>>d>>ch4;
  if(!is.good()){
    throw std::runtime_error("Invalid input");
    return is;
  }else if(ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')'){
    is.clear(std::ios_base::failbit);
    std::string errorType{std::string(1, ch1)+"..."+std::string(1, ch2)+"..."+std::string(1, ch3)+"..."+std::string(1, ch4)};
    throw std::runtime_error("Invalid formate : "+errorType+" The expected is (...,...,...)");
    return is;
  }
  dd = Date{Year(y),int_to_month(m),d};
  return is;
}

int main(int argc,char *argv[]){
  try{
    Date oneDefaultDay;
    std::cin>>oneDefaultDay;
    std::cout<<oneDefaultDay;
  }catch(const std::runtime_error& exp){
    std::cerr<<exp.what()<<"\n";
  }
  return 0;
}
