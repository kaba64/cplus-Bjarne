#include <iostream>
#include <vector>
#include <fstream>
#include <span>

int main(int argc, char **argv) {
  
  std::vector<int> input(10);
  std::string oname{"integerBinary.txt"};

  /* Write [0,10] in binary format */
  {
    std::ofstream ofs(oname, std::ios_base::binary);
    if (ofs.is_open()) {
      for (int i = 0; i < input.size(); ++i) {
	auto byte_span = std::as_bytes(std::span{&i, 1});
	ofs.write(reinterpret_cast<const char*>(byte_span.data()), sizeof(int));
      }
      ofs.close();
    } else {
      std::cerr << "Error: Cannot open the output file " << oname << "\n";
      return 1; // Return an error code
    }
  }

  /* Read the written data in binary format */
  try{
    std::ifstream ifs{oname, std::ios_base::binary};
    ifs.exceptions(ifs.exceptions() | std::ios_base::badbit);

    int i{0};
    for(int x;ifs.read(reinterpret_cast<char*>(&x), sizeof(int));){
      input.at(i) = x;
      ++i;
    }
    for (int num : input) {
      std::cout << num << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1; // Return an error code
  }
  
  return 0;
}
