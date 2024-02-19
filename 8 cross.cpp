// Quazi Uzma Nadeem

#include <iostream>
#include <cmath>
using namespace std;


bool okay(int q[], int c) {
    
      // neighbour list for squares 0 to 7
    static int helperArray[8][5] = {
               {-1}, 
               {0, -1}, 
               {0, -1}, 
               {0, 1, 2, -1}, 
               {0, 1, 3, -1}, 
               {1, 4, -1}, 
               {2, 3, 4, -1}, 
               {3, 4, 5, 6, -1}};
              
    // checking to make sure that a number has already been placed 
    for (int i = 0; i < c; ++i) 
      if (q[c] == q[i])
         return false;
         // checking to make sure that an adjacent square doesnot have a consecutive number
    for (int i = 0; helperArray[c][i] != -1; i++) 
      if (abs(q[c] - q[helperArray[c][i]]) == 1) 
         return false;
   return true;
         
 }

void printCross(int q[]) {
    // printing our cross
   static int solution = 0;
   cout << "Solution number: " << ++solution << endl;
   cout << " "  << q[0] << q[1] << endl;
   cout << q[2] << q[3] << q[4] << q[5] << endl;
   cout << " "  << q[6] << q[7] << endl;
   cout<< endl;
}

void nsquare(int q[], int c) {
    // if we are in column 8 we found a solution and we print it then backtrack and go to the previous square
  // if we run out of numbers to try, we reset the square back to 1
  //backtrack
   if (c == 8)
      printCross(q);
   else for (q[c] = 1; q[c] <= 8; ++q[c])
   //if we have a valid number in the square we move to the next square
      if (okay(q, c))
         nsquare(q, c+1);
}

int main() {
   int q[8];
   nsquare(q, 0);
   return 0;
}

