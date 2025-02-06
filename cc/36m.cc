#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
  std::vector<std::vector<bool>> row(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool>> col(9, std::vector<bool>(9, false));
  std::vector<std::vector<bool>> box(9, std::vector<bool>(9, false));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      char c = board.at(i).at(j);
      if (c == '.') {
        continue;
      }
      int num = c - '0' - 1;
      int box_index = i / 3 * 3 + j / 3;
      if (row.at(i).at(num) || col.at(j).at(num) || box.at(box_index).at(num)) {
        return false;
      }
      row.at(i).at(num) = true;
      col.at(j).at(num) = true;
      box.at(box_index).at(num) = true;
    }
  }
  return true;
}
