#include <map>
#include <vector>


class Cell {
public:
    int row, col, mrow, mcol, id;
    std::map<int, int> links;
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
};
