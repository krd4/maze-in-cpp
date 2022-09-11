#include <vector>
#include <gmock/gmock.h>
#include "../src/Cell.cpp"

TEST(Cell, CellInstantiation) {
    Cell cell(4, 4, 8, 8);
    ASSERT_TRUE(cell.row == 4);
    ASSERT_TRUE(cell.col == 4);
    ASSERT_TRUE(cell.mrow == 8);
    ASSERT_TRUE(cell.mcol == 8);
    ASSERT_TRUE(cell.id == 4*8 + 4);
    ASSERT_TRUE(cell.links.size() == 0);
}

TEST(Cell, CellLinking) {
    Cell cell1(4, 4, 8, 8);
    Cell cell2(4, 3, 8, 8);
    Cell cell3(3, 4, 8, 8);

    cell1.link(cell2, false);
    cell1.link(cell3, true);
    
    ASSERT_TRUE(cell1.links[cell2.id]);
    ASSERT_FALSE(cell2.links[cell2.id]);
    ASSERT_TRUE(cell1.links[cell3.id]);
    ASSERT_TRUE(cell3.links[cell1.id]);

    cell1.unlink(cell2, false);
    cell1.unlink(cell3, true);

    ASSERT_FALSE(cell1.links[cell2.id]);
    ASSERT_FALSE(cell1.links[cell3.id]);
    ASSERT_FALSE(cell3.links[cell1.id]);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}