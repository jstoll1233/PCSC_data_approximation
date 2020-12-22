//
// Created by jstoll@INTRANET.EPFL.CH on 03.12.20.
//

#include <gtest/gtest.h>
#include <Eigen/Dense>
#include "../src/DataHandler.h"
#include "../src/Lagrange.h"
#include "../src/Barycentric.h"
#include "../src/LeastSquares.h"

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
//std::string file_path = "../data/template_file.txt";
std::string file_path = "../data/template_file.txt";
DataHandler DataHandler_t(file_path);
int dimension = DataHandler_t.get_dimension();
int n_points = DataHandler_t.get_number_data_points();
double** data =DataHandler_t.get_data();

TEST(datahandler, header_reading){
    EXPECT_EQ(dimension, 2);
    EXPECT_EQ(n_points, 4);

}

TEST(datahandler, data_reading){
    EXPECT_EQ(data[0][0], 1.0);
    EXPECT_EQ(data[0][dimension-1], 3);
    EXPECT_EQ(data[2][1], 67);
    EXPECT_EQ(data[n_points-1][0], 4);
    EXPECT_EQ(data[n_points-1][dimension-1], 165);

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


//DataHandler DataHandler_t_(file_path);
//int dimension_ =  DataHandler_t_.get_dimension();
//int n_points_ =  DataHandler_t_.get_number_data_points();
//double** data_ = DataHandler_t_.get_data();

Lagrange lagrange(DataHandler_t);
double nan_ = std::numeric_limits<double>::quiet_NaN();

TEST(lagrange, point_nan){
    nan_ = lagrange.Calculate_value_of_interpolant(0.5);
    EXPECT_EQ(std::isnan(nan_),1);
}


TEST(lagrange, lagrange_calculation) {
    EXPECT_NEAR(lagrange.Calculate_value_of_interpolant(3), 67, 0.001);
    EXPECT_NEAR(lagrange.Calculate_value_of_interpolant(2.5), 37.875, 0.001);
    EXPECT_NEAR(lagrange.Calculate_value_of_interpolant(3.5), 108.625, 0.001);
}


Barycentric barycentric(DataHandler_t);

TEST(barycentric, point_nan){
    nan_ = barycentric.Calculate_value_of_interpolant(5);
    EXPECT_EQ(std::isnan(nan_),1);
}


TEST(barycentric, barycentric_calculation) {
    EXPECT_NEAR(barycentric.Calculate_value_of_interpolant(4), 165, 0.001);
    EXPECT_NEAR(barycentric.Calculate_value_of_interpolant(2.5), 37.875, 0.001);
    EXPECT_NEAR(barycentric.Calculate_value_of_interpolant(3.5), 108.625, 0.001);

}

//Eigen::VectorXf vect(3);
//vect(0) = -0.0144, vect(1) = 0.192, vect(2) = 3.697;
LeastSquares leastsquares(DataHandler_t, 3);

TEST(least_squares, least_squares_calculation) {
    EXPECT_NEAR(leastsquares.Calculate_value_at_point(2), 19, 0.001);
    EXPECT_NEAR(leastsquares.Calculate_value_at_point(2.5), 37.875, 0.001);
    EXPECT_NEAR(leastsquares.Calculate_value_at_point(3.5), 108.625, 0.001);
}

/*
TEST(least_squares, point_nan){
nan_ = leastsquares.Calculate_value_at_point(0.5);
EXPECT_EQ(std::isnan(nan_),1);
}
*/

