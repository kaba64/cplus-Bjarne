#include <iostream>

int main(int argc,char **argv){

  int a, b, c, d;
  std::cout<<"Please enter an integer number followed by its hex, oct, and oct equivalent\n";
  if(argc==1 || std::stoi(argv[1])==1){
    std::cin>>a>>std::hex>>b>>std::oct>>c>>d;
    std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
  }else if(std::stoi(argv[1])==2){
    std::cin.unsetf(std::ios::dec);
    std::cin.unsetf(std::ios::oct);
    std::cin.unsetf(std::ios::hex);
    std::cin>>a>>b>>c>>d;
    std::cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n";
  }
  return 0;
}
