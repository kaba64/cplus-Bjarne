/*Sample example of the book*/
#include <iostream>
#include <vector>
#include <string>

class X{
public:
  int val;
  void out(const std::string& s, int const nv)const{
    std::cout << this << "–>" << s << " : " << val << " (" << nv << ")\n"; }
  X():val(0){out("X()",0);}                          /* default constructor */
  X(int v):val(v){out( "X(int)",v); }
  X(const X& x){ val=x.val; out("X(X&) ",x.val); }   /* copy constructor */
  X& operator=(const X& a){                          /* copy assignment */
    out("X::operator=()",a.val);
    val=a.val;
    return *this;
  }
  ~X(){ out("~X()",0);}
};

X glob(2);      // a global variable
X copy(X a) { return a; }
X copy2(X a) { X aa = a; return aa; }
X& ref_to(X& a) { return a; }
X* make(int i) { X a(i); return new X(a); }
class XX {
public:
  X a; X b;
};

int main(int argc,char** argv){
  X loc {4};          // local variable
  X loc2 {loc};       // copy construction
  loc = X{5};         // copy assignment
  std::cout<<"\nBefore X copy(X a) function\n\n";
  loc2 = copy(loc);   // call by value and return
  std::cout<<"\nAfter X copy(X a) function\n\n";
  std::cout<<"\nBefore X copy2(X a) function\n\n";
  loc2 = copy2(loc);
  std::cout<<"\nAfter X copy2(X a) function\n\n";
  X loc3 {6};
  std::cout<<"\nBefore X& ref_to(X& a) function\n\n";
  X& r = ref_to(loc);   // call by reference and return
  std::cout<<"\nAfter X& ref_to(X& a) function\n\n";
  std::cout<<"\nBefore X* make(int i) function\n\n";
  delete make(7);
  std::cout<<"\nAfter X* make(int i) function\n\n";
  std::cout<<"\nBefore std::vector<X> v(4)\n\n";
  std::vector<X> v(4);   // default values
  std::cout<<"\nAfter std::vector<X> v(4)\n\n";
  std::cout<<"\nBefore class XX\n\n";
  XX loc4;
  std::cout<<"\nAfter class XX\n\n";
  std::cout<<"\nBefore new X{9}\n\n";
  X* p = new X{9};
  std::cout<<"\nAfter new X{9}\n\n";
  delete p;
  std::cout<<"\nAfter delete p\n\n";
  return 0;
}
