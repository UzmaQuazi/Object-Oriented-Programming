
// Quazi Uzma Nadeem

#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
    // doing row and diagonal tests
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
            // passing all the tests and exiting the for loop
   return true;
}


void print(int q[]) {
     // printing the solution count
   static int Solutions = 0;
   Solutions++;
   cout << "Solution number " << Solutions << " : " << endl;
   for (int r = 0; r < 8; r++)
   {   for (int c=0;c<8;c++)
        {   if (r==q[c]) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
}

int main() {
   int q[8] = {};   
   int c = 0;      
   while (c >= 0) {
      // When we reach the last column we have found a solution and we print it 
      if (c == 7) {
         print(q);
         --c;
      }
      else                  
         q[++c] = -1;
      while (c >= 0) {
           // If we have moved passed the last column we backtrack
         ++q[c];           
         if (q[c] == 8)    
            --c;
         else if (ok(q, c)) 
          //  if the position of the queen is valid, we return to the beginning of the outer loop
            break;
      }
   }
   return 0;
}
