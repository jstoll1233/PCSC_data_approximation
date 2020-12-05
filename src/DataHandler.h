//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#ifndef PCSC_DATA_APPROXIMATION_DATAHANDLER_H
#define PCSC_DATA_APPROXIMATION_DATAHANDLER_H

#include <string>
#include <fstream>
/**
 * Class DataHandler. Data for the approximation problem is manged via this class.
 */
class DataHandler {

    public:
    /**
     * Overloaded constructor for class DataHandler.
     * @param file_name containing the data
     */
    DataHandler(std::string file_name);
    /**
     * Overloaded destructor where de allocation of memory is handled
     */
    ~DataHandler();
    /**
     * @return matrix of pointers. The data matrix
     */
    double** get_data() const;
    int get_number_data_points() const;
    int get_dimension() const;
    std::string* get_variables() const;


    private:
    /**
     * reads the already opened data file and stores its content in the data matrix
     * @param file stream to read from data file
     */
    void read_data();
    std::ifstream file;
    /**
     * dimension of the problem
     */
    int dim;
    int num_dp;
    std::string* var;
    double** data;
};


#endif //PCSC_DATA_APPROXIMATION_DATAHANDLER_H
