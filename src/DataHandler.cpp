//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#include "DataHandler.h"
#include <sstream>
#include <iostream>
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
    if ((line == "\uFEFFdimension") or (line == "dimension")){
        std::getline(file, line);
        try{dim = std::stoi(line);}
        catch (std::invalid_argument &e) {
            throw std::invalid_argument("Problem reading dimension. Check input file");
        }
        var = new std::string [dim];
    }
    else{
        throw std::runtime_error("first line should contain the dimension. Check template file if not clear ");
    }

    std::getline(file, line, ',');
    if (line == "number_of_points"){
        std::getline(file, line);
        try{num_dp = std::stoi(line);}
        catch (std::invalid_argument &e) {
            throw std::invalid_argument("Problem reading number of points. Check input file");
        }
    }
    else{
        throw std::runtime_error("second line should contain the number of data points. Check template file if not clear ");
    }

    std::getline(file, line, ',');
    if (line == "variables"){
        std::getline(file, line);
        std::stringstream  ss(line);

        int counter =0;
        while (std::getline(ss, line, ',')){
            if (counter >= dim){
                throw std::range_error("Tried to store more variables than dimension");
            }
            var[counter] = line;
            ++counter;
        }
        if (counter != dim){
            throw std::runtime_error("less variables than dimensions");
        }
    }
    else{
        throw std::runtime_error("third line should contain the variables. Check template file if not clear ");
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
            if ((l>=num_dp) or (c>=dim)){
                throw std::range_error("Tried to store more data than dimension x number of data points");
            }
            data[l][c] = std::stod(line);
            ++c;
        }
        if (c != dim){
            throw std::runtime_error("Missing data somewhere");
        }
        ++l;
    }
    if (l != num_dp){
        throw std::runtime_error("missing data somewhere ");
    }
}


double** DataHandler::get_data() const {
    return data;
}

DataHandler::~DataHandler() {
    std::cout << "(Memory successfully freed)"<< std::endl;
    for (int i = 0; i < num_dp; ++i){
        delete [] data[i];
    }
    delete [] data;

    delete [] var;
}

int DataHandler::get_number_data_points() const {
    return num_dp;
}

int DataHandler::get_dimension() const {
    return dim;
}