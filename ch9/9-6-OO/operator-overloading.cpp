#include <iostream>
#include <vector>
#include <std_lib_facilities.h>
using namespace std;

enum class Month{
		 jan=1,feb,mar,apr,jun,jul,aug,sep,oct,nov,dec
};

Month int_to_month(int x)
{
  if(x<int(Month::jan) || int(Month::dec)<x) error("bad month!");
  return Month(x);
}

Month operator++(Month& m)
{
  m = Month(int(m)+1);
  return m;
}

ostream& operator<<(ostream& os,Month m)
{
  vector<string> month_tbl;
  return os<<month_tbl[int(m)];
}

auto main() -> int
{
  Month mm = Month::jan;
  //++mm;
  cout<<mm;
}
