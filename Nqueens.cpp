// Quazi Uzma Nadeem

#include <iostream>
using namespace std;

//using the bool funtion to the check if the queen placed in column c is ok
bool okay(int q[], int c) {
   for (int i = 0; i < c; i++)
   // doing row and diagonal tests
      if (q[i] == q[c] || c - i == abs(q[i] - q[c]) )
         return false;
          // passing all the tests and exiting the for loop
   return true;
}


int nQueens(int n) {
   int* q = new int[n]; // this dynamically allocates array of size n
 int c = 0, solutions = 0;
     q[0] = 0; // starting with placing the queen in the upper left corner

 //as long as we have not moved back coloumn zero we perform the following operations
   while (c >= 0) {
      if (c > n - 1) { //if we have crossed the last coloumn then we have found a solution and we increment the solution count. This keeps track of the number of solutions
         solutions++;
         c--; // we backtrack and go to the previous column
         q[c]++; // and then move to the next row
      }
      // if we exceed the last row , we reset the row to zero and we backtrack
      if(q[c]>n-1){ 
         q[c] = 0;
         c--;
        
       if (c!= -1)  //if we have not moved back column 0, we increment the row
         q[c]++;
      }
         // passing the array q to the bool function, if the  is queen placed in a valid position, we increment and go to the next column
          else if (okay(q, c)){
            c++;
      }
      else {
          q[c]++;  // if not, we move to next row
      }
   }
   delete[] q; // deallocating q by calling delete [ ] q
   return solutions;
}

int main() {
   int num ; //(num x num) represents the size of the chessboard
   cout<< "Enter the value of num:"<<endl; //asking the user for the value of num
   cin>> num; // taking the input
   
   for (int i = 1; i <= num; i++)
      cout << "There are " << nQueens(i) << " solutions to the " << i << " queens problem."<< endl;
   return 0;
}
