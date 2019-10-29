//
// Created by zersa on 10/29/19.
//

#include <iostream>
#include <string>
#include "GetIndexOf.h"


struct SomeType {

    int a;
    std::string b;
    float c;
};

int main() {

    std::cout << GetIndexOf< Tuple< int,Tuple< double, Tuple< float, Tuple < SomeType, NullType > > > >, float > ()() << "\n";
    std::cout << GetIndexOf< Tuple< int,Tuple< SomeType, Tuple< float, NullType > > >, SomeType > ()() << "\n";
}


