#include <iostream>

int main(int argc,char **argv){
  
  std::cout<<"The first double deletion will not generate error since ptr is not pointing to a memory address\n";
  double* ptr=nullptr;
  std::cout<<"Before calling delete ptr : "<<std::hex<<ptr<<"\n";
  delete ptr;
  std::cout<<"After calling delete ptr : "<<std::hex<<ptr<<"\n";
  delete ptr; /* This will not generate error since ptr was not pointing to a memory address*/

  std::cout<<"\nThe following will generate error in the second delete\n\n";
  double* ptr2=new double{5.};
  std::cout<<"Before calling delete ptr2 : "<<std::hex<<ptr2<<"\n";
  delete ptr2;
  std::cout<<"After calling delete ptr2 : "<<std::hex<<ptr2<<"\n";
  delete ptr2;
  return 0;
}
