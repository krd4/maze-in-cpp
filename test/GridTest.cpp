#pragma once
#include <gmock/gmock.h>
#include <vector>
#include <utility>
#include "../src/Grid.cpp"
#include "../src/util.cpp"

TEST(Grid, GridInstantiation) {
    int row=8;
    int col=8;
    std::pair<int, int> shape(row, col);
    Grid grid(row, col);

    EXPECT_TRUE(grid.row == row);
    EXPECT_TRUE(grid.col == col);
    EXPECT_TRUE(grid.size() == shape);
}