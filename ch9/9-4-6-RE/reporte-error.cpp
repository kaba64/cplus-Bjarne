#include <iostream>
#include <exception>

class Date{
public:
  
  Date(int yi,int mi,int di);
  void add_day(int n);
  int year()const{return y;}
  int month()const{return m;}
  int day()const{return d;}
private:
  int y,m,d;
  bool is_valid();
};

Date::Date(int yi,int mi,int di)
  :y{yi},m{mi},d{di}
{
  if(!is_valid()) throw std::runtime_error("Invalid Date");
}

bool Date::is_valid(){
  if(y>0){
    if(m>0 && m<13){
      if((m==1 || m==3 || m ==5 || m==7 || m==8 || m==10 || m==12) && (d>0 && d<32))
	return true;
      else if((m==4 || m==6 || m ==9 || m==11) && (d>0 && d<31))
	return true;
      else if(m==2  && (d>0 && d<30))
	return true;
      else
	return false;
    }else{
      return false;
    }
  }else{
    return false;
  }
}

void Date::add_day(int n){d = d+n;}

int main(int argc,char *argv[]){
  try{
    Date today{2022,8,12};
    std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
    today.add_day(5);
    std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
  }catch(const std::runtime_error& exp){
    std::cerr<<exp.what()<<"\n";
  }
  return 0;
}
