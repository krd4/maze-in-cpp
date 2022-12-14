#pragma once
#include "util.cpp"
#include <unordered_map>
#include <vector>


class Cell {
public:
    Cell *north, *south, *east, *west; 
    int row, col, mrow, mcol, id;
    std::unordered_map<int, int> links;
    Cell() {}
    Cell(int row, int col, int mrow, int mcol) {
        this->row = row;
        this->col = col;
        this->mrow = mrow;
        this->mcol = mcol;
        this->id = row * mrow + col;
    };

    void link(Cell& cell, bool bidi = false) {
        links[cell.id] = true;
        if(bidi) cell.link(*this, false);
    }

    void unlink(Cell& cell, bool bidi=false) {
        links.erase(cell.id);
        if(bidi) cell.unlink(*this, false);
    }

    std::vector<int> getLinks() {
        return keys(links);
    }

    bool linked(Cell cell) {
        return links.find(cell.id) != links.end();
    }

    void set_neighbors(Cell& north, Cell& south, Cell& east, Cell& west) {
        this->north = &north;
        this->south = &south;
        this->east = &east;
        this->west = &west;
    }

    void set_neighbors(Cell* north, Cell* south, Cell* east, Cell* west) {
        this->north = north;
        this->south = south;
        this->east = east;
        this->west = west;
    }
};
