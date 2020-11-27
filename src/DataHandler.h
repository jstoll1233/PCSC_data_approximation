//
// Created by jstoll@INTRANET.EPFL.CH on 24.11.20.
//

#ifndef PCSC_DATA_APPROXIMATION_DATAHANDLER_H
#define PCSC_DATA_APPROXIMATION_DATAHANDLER_H

#include <string>
#include <fstream>
class DataHandler {

    public:
    /**
     * Overloaded constructore for class DataHandler.
     * @param file_name containing the data
     * @param dimension of the model to fit
     * @param number_data_points
     */
    DataHandler(std::string file_name, int dimension, int number_data_points);
    ~DataHandler();
    /**
     * @return matrix of pointers. The data matrix
     */
    double** get_data();


    private:
    /**
     * reads the already opened data file and stores its content in the data matrix
     * @param file stream to read from data file
     */
    void read_data(std::ifstream file);
    /**
     * dimension and number of data points
     */
    int dim;
    int num_dp;
    double** data;
};


#endif //PCSC_DATA_APPROXIMATION_DATAHANDLER_H
