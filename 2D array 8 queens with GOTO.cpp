
#include <iostream>
using namespace std;

int main() {
   int b[8][8] = {0}, row, col = 0;
   int solution = 0;
   
  // Placing the queen in row zero and column zero
   b[0][0] = 1;
  
 // moving to the next column    
nextcolumn:
   col++;
   // if we are in column 8 we have found a solution and we print it
   if (col == 8)
      goto print;
   row = -1;
   
   // increment the row
nextRow:
   row ++;
   // if we are in row 8 we have to backtrack as no valid loaction for queen is found
   if (row == 8)
      goto backtrack;

// if row is not equal to 8 we perform row test
   for (int i = 0; i < col; ++i)                    // row test
      if (b[row][i] == 1)
         goto nextRow;
  
   for (int i = 1; row - i >= 0 && col - i >= 0; ++i) // up-diagonal test
      if (b[row-i][col-i] == 1)
         goto nextRow;
  
   for (int i = 1; row + i < 8 && col - i >= 0; ++i)  // down-diagonal test
      if (b[row+i][col-i] == 1)
         goto nextRow;
  // if all tests are passed we place a queen in a valid space
   b[row][col] = 1;
   goto nextcolumn;

backtrack:
   col--;
   // if we are in column 1 we have found all solutions
   if (col<0)
      return 0;
      // if we are not in column 1, we erase that queen and move to the next row
   for (row = 0; b[row][col] != 1; row++);
   b[row][col] = 0;
   goto nextRow;

print:
  solution ++;
   cout << "solution number " << solution << ":\n";
   for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j)
         cout << b[i][j];
      cout << endl;
   }
   goto backtrack;
}