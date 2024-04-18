#include "list.h"

int main(int argc,char** argv){
  Link* norse_gods = new Link{"Thor"};
  norse_gods = insert(norse_gods,new Link{"Odin"});
  norse_gods = insert(norse_gods,new Link{"Zeus"});
  norse_gods = insert(norse_gods,new Link{"Freja"});
  
  Link* greek_gods = new Link{"Hera"};
  greek_gods = insert(greek_gods,new Link{"Athena"});
  greek_gods = insert(greek_gods,new Link{"Mars"});
  greek_gods = insert(greek_gods,new Link{"Poseidon"});

  std::cout<<"\nPrint before making changes\n\n";
  print_all(norse_gods);
  print_all(greek_gods);
  
  Link* p = find(greek_gods,"Mars");
  if(p)
    p->namep="Ares";
  
  p = find(norse_gods,"Zeus");
  if(p){
    if(p==norse_gods)
      norse_gods = p->succ;
    Link* temp = erase(p);
    greek_gods = insert(greek_gods,p);
  }

  std::cout<<"\nPrint after making changes\n\n";
  print_all(norse_gods);
  print_all(greek_gods);
  
  delete norse_gods;
  delete greek_gods;
  return 0;
}
