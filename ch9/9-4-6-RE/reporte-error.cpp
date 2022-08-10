#include <iostream>

class Date{
public:
  class Invalid {};
  Date(int yi,int mi,int di);
  void add_day(int n);
  int year(){return y;}
  int month(){return m;}
  int day(){return d;}
private:
  int y,m,d;
  bool is_valid();
};

Date::Date(int yi,int mi,int di)
    :y{yi},m{mi},d{di}
  {
  }

void Date::add_day(int n){d = d+n;}

auto main() -> int
{
  Date today{2022,8,2};
  std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
  today.add_day(5);
  std::cout<<today.year()<<"/"<<today.month()<<"/"<<today.day()<<"\n";
}
