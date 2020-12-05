//
// Created by jstoll@INTRANET.EPFL.CH on 27.11.20.
//
//#include "DataHandler.h"
#include <iostream>
#include <fstream>
#include "DataHandler.h"

int main(int argc, char ** argv){
    std::string file_name;
    std::string path;
    path = "../data/";
    std::cout << "Please enter the file name containing the data: " << std::endl;
    std::cin >> file_name;
    path.append(file_name);

    try {
        DataHandler handler(path);
        int dim = handler.get_dimension();
        std::cout << "Dimension " << dim;

    }

    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }


    return 0;
}