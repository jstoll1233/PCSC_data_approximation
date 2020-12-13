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
     * Getter method for the data.
     * @return matrix of pointers. The data matrix
     */
    double** get_data() const;
    /**
     * Getter method for the number of data points.
     * @return the number of data points contained in the data.
     */
    int get_number_data_points() const;
    /**
     * Getter method for the dimension of the problem
     * @return dimension of the problem (number of variables)
     */
    int get_dimension() const;
    //std::string* get_variables() const;


    private:
    /**
     * reads the already opened data file and stores its content in the data matrix
     * @param file stream to read from data file
     */
    void read_data();
    /**
     * Input file stream. Allows to read the data from the input file.
     */
    std::ifstream file;
    /**
     * dimension of the problem
     */
    int dim;
    /**
     * Number of data points
     */
    int num_dp;
    /**
     * Name of the variables of the problem.
     */
    std::string* var;
    /**
     * Matrix of data
     */
    double** data;
};


#endif //PCSC_DATA_APPROXIMATION_DATAHANDLER_H
