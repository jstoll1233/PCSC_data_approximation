//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#include "DataHandler.h"
#include <sstream>
DataHandler::DataHandler(std::string file_name)
{
    std::ifstream file(file_name);
    if (not file.is_open()) {
        throw std::runtime_error("file not found ");
    }
    else{
        read_data(std::ifstream file);
    }
}

void DataHandler::read_data(std::ifstream file) {

    std::getline(file, line, ',');
    if (line == "\uFEFFdimension"){
        std::getline(file, line);
        dim = std::stod(line);
        var = new std::string [dim];
    }

    std::getline(file, line, ',');
    if (line == "number_of_points"){
        std::getline(file, line);
        num_dp = std::stod(line);
    }

    std::getline(file, line, ',');
    if (line == "variables"){
        std::getline(file, line);
        std::stringstream  ss(line);

        int counter =0;
        while (std::getline(ss, line, ',')){
            var[counter] = line;
            ++counter;
        }
    }
    //Allocation
    data = new double* [num_dp];
    for (int i = 0; i < num_dp; ++ i){
        data[i] = new double [dim];
    }

    int l = 0;
    int c = 0;
    while(std::getline(file, line)){
        c = 0;
        std::stringstream ss(line);
        while(getline(ss, line, ',')){
            A[l][c] = std::stod(line);
            ++c;
        }
        ++l;
    }
}


double ** DataHandler::get_data() {
    return data;
}

DataHandler::~DataHandler() {
    for (int i = 0; i < num_dp; ++i){
        delete [] data[i];
    }
    delete [] data;

    delete [] var;
}