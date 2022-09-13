#pragma once
#include <vector>
#include <utility>
#include "Cell.cpp"
#include "util.cpp"

class Grid {
public:
    int row, col;
    std::vector<std::vector<Cell>> grid;
    Grid(int row, int col) {
        this->row = row;
        this->col = col;
        this->grid = prepare_grid();
        configure_cell();
    }

    std::vector<std::vector<Cell>> prepare_grid() {
        std::vector<std::vector<Cell>> vec;
        for(int i=0; i < row; i++) {
            std::vector<Cell> row_vec;
            for(int j=0; j < col; j++) {
                Cell cell(i, j, row, col);
                row_vec.push_back(cell);
            }
            vec.push_back(row_vec);
        }
        return vec;
    }

    void configure_cell() {
        for(int i=0; i < row; i++) {
            for(int j=0; j < col; j++) {
                Cell* cell = &grid[i][j];
                Cell *north, *south, *east, *west;
                if(i==0) north = nullptr;
                else north = &grid[i-1][j];
                if(j==0) west = nullptr;
                else west = &grid[i][j-1];
                if(i==row) south = nullptr;
                else south = &grid[i+1][j];
                if(j==col) east = nullptr;
                else east = &grid[i][j+1];
                cell->set_neighbors(north, south, east, west);
            }
        }
    }

    std::pair<int, int> size() {
        return size_2d_vec(grid);
    }

    Cell* random_cell() {
        int row_i = randint(0, row);
        int col_i = randint(0, col);
        return &grid[row_i][col_i];
    }
};