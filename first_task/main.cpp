#include <fstream>
#include <iostream>
#include <ostream>
#include "reader.h"

int main(){
    std::string filename = "../Example.txt";

    ReaderTXT< int, float, std::string, int > reader;
    auto data = reader.readTXT(filename);


    for (auto& e: data) {
        std::cout << std::get<0>(e) << " " << std::get<1>(e) << " " <<
                  std::get<2>(e) << " " << std::get<3>(e) << std::endl;

    }
    return 0;
}
