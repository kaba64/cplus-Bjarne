#include <iostream>
#include <std_lib_facilities.h>

enum class Month{
		 jan=1,feb,mar,apr,jun,jul,aug,sep,oct,nov,dec
};

Month int_to_month(int x)
{
  if(x<int(Month::jan) || int(Month::dec)<x) error("bad month!");
  return Month(x);
}

auto main() -> int
{
  Month mm = int_to_month(8);
}
