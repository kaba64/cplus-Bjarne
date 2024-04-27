#include <string>
#include <initializer_list>

class vector{
public:
  vector();
  explicit vector(size_t s,double value=0);
  vector(std::initializer_list<double> lst);
  vector(const vector& src);                         /*copy constructor*/
  vector& operator =(const vector& src);             /*copy assignment*/
  vector(vector&& src);                              /*move constructor*/
  vector& operator =(vector&& src);                  /*move assignment*/
  double operator [](size_t i)const;                 /*get rvalu*/
  double& operator [](size_t i);                     /*to get lvalue*/ 
  size_t size()const{return sz;}
  double get(size_t i)const{return elem[i];}
  void set(size_t n,double v){elem[n]=v;}
  void reserve(size_t newalloc);
  size_t capacity()const;
  void resize(size_t newsize);
  void print_vector(const std::string& name)const;
  ~vector();
private:
  size_t sz;
  double* elem;
  size_t space;
};
