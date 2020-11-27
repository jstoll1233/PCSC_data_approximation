//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#include "DataHandler.h"
#include <sstream>
DataHandler::DataHandler(std::string file_name, int dimension, int number_data_points)
: dim(dimension), num_dp(number_data_points)
{
    std::ifstream file(file_name);
    if (not file.is_open())
        throw std::runtime_error("file not found ");
    else
        // Allocation of the memory for the data matrix
        data = new double* [num_dp];
        for (int i = 0; i < num_dp; ++ i){
            data[i] = new double [dim];
        }


        read_data(std::ifstream file);
}

void DataHandler::read_data(std::ifstream file) {
    std::string line;
    std::getline(file, line);
    //here we should check that dimension and line.size() are the same.
    int l = 0;
    int c = 0;
    while (std::getline(file, line)){
        c = 0;
        std::stringstream ss(line);
        while (std::getline(ss, line, ',')){
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

}