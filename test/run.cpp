#include <gmock/gmock.h>
#include "utilTest.cpp"
#include "CellTest.cpp"
#include "GridTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}