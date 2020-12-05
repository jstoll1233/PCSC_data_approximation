//
// Created by jstoll@INTRANET.EPFL.CH on 03.12.20.
//

#include <gtest/gtest.h>
#include "../src/DataHandler.h"


int main(int argc, char **argv) {

    try{
        ::testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
    }
    catch(std::runtime_error &e) {
        std::cerr << e.what();
    }
}

// Tests for Data Handler
std::string file_path = "../data/template_file.txt";
DataHandler DataHandler_t(file_path);
int dimension = DataHandler_t.get_dimension();
int n_points = DataHandler_t.get_number_data_points();
double** data =DataHandler_t.get_data();

TEST(datahandler, header_reading){
    EXPECT_EQ(dimension, 3);
    EXPECT_EQ(n_points, 5);

}

TEST(datahandler, data_reading){
    EXPECT_EQ(data[0][0], 1.2);
    EXPECT_EQ(data[0][dimension-1], 2.8);
    EXPECT_EQ(data[2][1], 3.1);
    EXPECT_EQ(data[n_points-1][0], 6.7);
    EXPECT_EQ(data[n_points-1][dimension-1], 8.8);

}

std::string file_path_wh = "../test/wrong_header.txt";

TEST(datahandler, header_exception){
    try {
        DataHandler DataHandler_t_wh(file_path_wh);
        FAIL() << "Expected std::runtime_error";
    }
    catch (std::runtime_error &e) {
        EXPECT_EQ(e.what(), std::string("second line should contain the number of data points. Check template file if not clear "));

    }
    catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

std::string file_path_wd = "../test/wrong_dimension.txt";

TEST(datahandler, read_dim_exception){
    try {
        DataHandler DataHandler_t_wh(file_path_wd);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument &e) {
        EXPECT_EQ(e.what(), std::string("Problem reading dimension. Check input file"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}


std::string file_path_wv = "../test/wrong_variables.txt";

TEST(datahandler, read_var_exception){
    try {
        DataHandler DataHandler_t_wh(file_path_wv);
        FAIL() << "Expected std::range_error";
    }
    catch (std::range_error &e) {
        EXPECT_EQ(e.what(), std::string("Tried to store more variables than dimension"));
    }
    catch (...) {
        FAIL() << "Expected std::range_error";
    }
}

std::string file_path_wdata = "../test/wrong_data.txt";

TEST(datahandler, read_data_exception){
    try {
        DataHandler DataHandler_t_wh(file_path_wdata);
        FAIL() << "Expected std::runtime_error";
    }
    catch (std::runtime_error &e) {
        EXPECT_EQ(e.what(), std::string("Missing data somewhere"));

    }
    catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}


