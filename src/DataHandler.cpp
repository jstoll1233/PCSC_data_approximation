//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#include "DataHandler.h"
#include <sstream>
DataHandler::DataHandler(std::string file_name)
: dim(0), num_dp(0)
{
    file.open(file_name);
    if (not file) {
        throw std::runtime_error("file not found ");
    }
    else{
        read_data();
    }
}

void DataHandler::read_data() {
    std::string line;
    std::getline(file, line, ',');
    if (line == "\uFEFFdimension"){
        std::getline(file, line);
        dim = std::stoi(line);
        var = new std::string [dim];
    }

    std::getline(file, line, ',');
    if (line == "number_of_points"){
        std::getline(file, line);
        num_dp = std::stoi(line);
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
    int c;
    while(std::getline(file, line)){
        c = 0;
        std::stringstream ss(line);
        while(getline(ss, line, ',')){
            data[l][c] = std::stod(line);
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