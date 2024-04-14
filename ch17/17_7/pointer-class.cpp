#include <iostream>
#include <vector>

class vector{
public:
  vector(size_t s):sz{s},elem{new double[s]}{
    std::cout<<"Constructor vector\n";
    for(size_t i=0;i<s;++i)
      elem[i]=1.1*i;
  }
  ~vector(){std::cout<<"Destructor vector\n";delete[] elem;}
  int size() const{return sz;}
  double get(size_t i) const{return elem[i];}
  void set(size_t n,double v){elem[n]=v;}
private:
  size_t sz;
  double* elem;
};

vector* f(size_t s){
  std::cout<<"In f()\n";
  vector* p = new vector(s);
  return p;
}

void ff(){
  std::cout<<"In ff() before calling f()\n";
  vector* q = f(4);
  std::cout<<"In ff() before calling delete\n";
  delete q;
  std::cout<<"In ff() after calling delete\n";
}

int main(int argc,char** argv){
  ff();
  std::cout<<"\nAllocate vector in free store in the main function\n\n";
  vector* p = new vector(4);
  int x = p->size();
  double d = p->get(3);
  std::cout<<"size : "<<x<<"\t , p[3] = "<<d<<std::endl;
  delete p;
  std::cout<<"\nUse STL std::vector\n\n";
  std::vector<std::vector<double>>* stdP = new std::vector<std::vector<double>>(10);
  std::cout<<"The size of stdP "<<stdP->size()<<"\n";
  
  for (size_t i = 0; i <stdP->size(); ++i) {
    (*stdP)[i].resize(5); // Resize each inner vector to size 5
  }
  delete stdP;
  return 0;
}
