#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include <vector>
#include <array>

class SudokuGame {
public:
    SudokuGame() {
        reset();
    }

    void reset() {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                board_[i][j] = 0;
                isFixed_[i][j] = false;
            }
        }
        // Initialize with a simple puzzle for testing
        board_[0][0] = 5; isFixed_[0][0] = true;
        board_[0][1] = 3; isFixed_[0][1] = true;
        board_[0][4] = 7; isFixed_[0][4] = true;
        board_[1][0] = 6; isFixed_[1][0] = true;
        board_[1][3] = 1; isFixed_[1][3] = true;
        board_[1][4] = 9; isFixed_[1][4] = true;
        board_[1][5] = 5; isFixed_[1][5] = true;
        board_[2][1] = 9; isFixed_[2][1] = true;
        board_[2][2] = 8; isFixed_[2][2] = true;
        board_[2][7] = 6; isFixed_[2][7] = true;
    }

    int getCell(int row, int col) const {
        return board_[row][col];
    }

    bool isFixed(int row, int col) const {
        return isFixed_[row][col];
    }

    void setCell(int row, int col, int value) {
        if (!isFixed_[row][col] && value >= 0 && value <= 9) {
            board_[row][col] = value;
        }
    }

    bool isSelected(int row, int col) const {
        return selectedRow_ == row && selectedCol_ == col;
    }

    void selectCell(int row, int col) {
        selectedRow_ = row;
        selectedCol_ = col;
    }

    void getSelectedCell(int& row, int& col) const {
        row = selectedRow_;
        col = selectedCol_;
    }

private:
    std::array<std::array<int, 9>, 9> board_;
    std::array<std::array<bool, 9>, 9> isFixed_;
    int selectedRow_ = -1;
    int selectedCol_ = -1;
};

#endif // SUDOKU_GAME_H
