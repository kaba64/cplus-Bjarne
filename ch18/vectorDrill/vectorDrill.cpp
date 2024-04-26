#include <iostream>
#include <vector>

constexpr int size = 10;
std::vector<int> gv{1,2,4,8,16,32,64,128,256,512};

void printVector(const std::vector<int> vIn,const std::string& name){
  int idx{0};
  for(auto it=vIn.cbegin();it!=vIn.cend();++it){
    idx = std::distance(vIn.cbegin(),it);
    std::cout<<name<<"["<<idx<<"] = "<<*it<<"\t";
    if((idx+1)%3==0)
      std::cout<<"\n";
  }
  std::cout<<"\n";
}

void f(std::vector<int> gvIn){

  std::vector<int> lv(gvIn.size());
  lv=gv;
  printVector(lv,"lv");

  std::vector<int> lv2{gvIn};
   printVector(lv2,"lv2");
}

int main(int argc,char** argv){

  std::cout<<"\nf(gv)\n\n";
  f(gv);

  std::vector<int> vv(size);
  for(size_t i=0;i<vv.size();++i){
    if(i==0)
      vv.at(i)=1;
    else
      vv.at(i)=vv.at(i-1)*(i+1);
  }
  
  std::cout<<"\nf(vv)\n\n";
  f(vv);
  
  return 0;
}
