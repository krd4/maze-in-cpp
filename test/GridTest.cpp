#include <gmock/gmock.h>
#include <vector>
#include "../src/Grid.cpp"

TEST(Grid, GridInstantiation) {
    int row=8;
    int col=8;
    Grid grid(row, col);

    EXPECT_TRUE(grid.row == row);
    EXPECT_TRUE(grid.col == col);
}