//
// Created by jstoll@INTRANET.EPFL.CH on 03.12.20.
//

#include <gtest/gtest.h>

int main(int argc, char **argv) {

    try{
        ::testing::InitGoogleTest(&argc,argv);
        return RUN_ALL_TESTS();
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }


}