#include <iostream>

auto main() -> int
{
  std::cout<<"PLease enter your first name and age\n";
  std::string first_name;
  int age;
  std::cin>>first_name;
  std::cin>>age;
  std::cout<<"Hello, "<<first_name<<"(age"<<age<<")\n";
}
