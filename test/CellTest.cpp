#include <gmock/gmock.h>
#include <vector>
#include "../src/Cell.cpp"

TEST(Cell, CellInstantiation) {
    Cell cell(4, 4, 8, 8);
    EXPECT_TRUE(cell.row == 4);
    EXPECT_TRUE(cell.col == 4);
    EXPECT_TRUE(cell.mrow == 8);
    EXPECT_TRUE(cell.mcol == 8);
    EXPECT_TRUE(cell.id == 4*8 + 4);
    EXPECT_TRUE(cell.links.size() == 0);
}

TEST(Cell, CellLinking) {
    Cell cell1(4, 4, 8, 8);
    Cell cell2(4, 3, 8, 8);
    Cell cell3(3, 4, 8, 8);

    cell1.link(cell2, false);
    cell1.link(cell3, true);
    
    EXPECT_TRUE(cell1.links[cell2.id]);
    EXPECT_FALSE(cell2.links[cell2.id]);
    EXPECT_TRUE(cell1.links[cell3.id]);
    EXPECT_TRUE(cell3.links[cell1.id]);

    cell1.unlink(cell2, false);
    cell1.unlink(cell3, true);

    EXPECT_FALSE(cell1.links[cell2.id]);
    EXPECT_FALSE(cell1.links[cell3.id]);
    EXPECT_FALSE(cell3.links[cell1.id]);
}

TEST(Cell, RetrievingKeys) {
    Cell cell1(4, 4, 8, 8);
    Cell cell2(4, 3, 8, 8);
    Cell cell3(3, 4, 8, 8);

    cell1.link(cell2, false);
    cell1.link(cell3, true);

    std::vector<int> links = {cell2.id, cell3.id};

    EXPECT_TRUE(cell1.getLinks() == links);
}

TEST(Cell, CheckIfLinked) {
    Cell cell1(4, 4, 8, 8);
    Cell cell2(4, 3, 8, 8);
    Cell cell3(3, 4, 8, 8);

    cell1.link(cell2, false);
    cell1.link(cell3, true);

    EXPECT_TRUE(cell1.linked(cell2));
    EXPECT_FALSE(cell2.linked(cell1));
    EXPECT_TRUE(cell1.linked(cell3));
}

TEST(Cell, Neighborhoods) {
    Cell cell(4, 4, 8, 8);
    Cell north(1,1,1,1);
    Cell south(2,2,2,2);
    Cell east(3,3,3,3);
    Cell west(4,4,4,4);
    cell.set_neighbors(north, south, east, west);

    EXPECT_EQ(cell.north, &north);
    EXPECT_EQ(cell.south, &south);
    EXPECT_EQ(cell.east, &east);
    EXPECT_EQ(cell.west, &west);
}
