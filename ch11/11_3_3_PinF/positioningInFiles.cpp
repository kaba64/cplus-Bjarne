#include <iostream>
#include <fstream>
#include <span>
#include <string>
#include <exception>

constexpr int NUMBER = 15;

template<typename T> void writeToFile(const std::string oname){

  std::ofstream ofs(oname, std::ios_base::binary);
  if (ofs.is_open()) {
    for (int i = 0; i < NUMBER; ++i) {
      T writeIn = 2*i;
      auto byte_span = std::as_bytes(std::span{&writeIn, 1});
      ofs.write(reinterpret_cast<const char*>(byte_span.data()), sizeof(T));
      if(i<NUMBER-1){
	char c = '\t';
	auto byte_span = std::as_bytes(std::span{&c, 1});
	ofs.write(reinterpret_cast<const char*>(byte_span.data()), sizeof(char));
      }
    }
  }else {
    throw std::runtime_error("Error: Cannot open the output file "+oname);
  }
  ofs.close();
}

template<typename T> T readingInPositionFile(const std::string iname,const int position){

  std::ifstream ifs{iname, std::ios_base::binary};
  ifs.exceptions(ifs.exceptions() | std::ios_base::badbit);

  T singlenput;
  if(ifs.is_open()){
    std::streampos offset = (position - 1) * (sizeof(T)+1);
    ifs.seekg(offset, std::ios_base::beg);
    /* Read the value */
    ifs.read(reinterpret_cast<char*>(&singlenput), sizeof(T));
  }else{
    throw std::runtime_error("Error: Cannot open the input file "+iname);
  }

  ifs.close();
  return singlenput;
}

template<typename T> void writingToPositionFile(const std::string oname,const int position,const T input){

  std::ofstream ofs(oname, std::ios_base::binary);
  if (ofs.is_open()) {
    std::streampos offset = (position - 1) * (sizeof(T)+1);
    ofs.seekp(offset, std::ios_base::beg);
    auto byte_span = std::as_bytes(std::span{&input, 1});
    ofs.write(reinterpret_cast<const char*>(byte_span.data()), sizeof(T));
  }else{
    throw std::runtime_error("Error: Cannot open the input file "+oname);
  }

  ofs.close();
}

int main(int argc, char **argv) {
  
  std::string oname{"file.txt"};
  
  try{
    writeToFile<int>(oname);
  }catch(const std::exception& e){
    std::cerr<<e.what()<<"\n";
  }

  int position{7};
  std::cout<<"data["<<position-1<<"] = "<<readingInPositionFile<int>(oname,position)<<"\n";

  try{
    int value{7};
    writingToPositionFile<int>(oname,position,value);
    std::cout<<"data["<<position-1<<"] = "<<readingInPositionFile<int>(oname,position)<<"\n";
  }catch(const std::exception& e){
    std::cerr<<e.what()<<"\n";
  }
  
  return 0;
}
