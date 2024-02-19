//Quazi Uzma Nadeem

#include <iostream>
#include <cmath>
using namespace std;


 //using the bool funtion to the check if the queen placed in column c is ok
bool okay(int q[], int c) {
   for (int i = 0; i < c; i++)
   // doing row and diagonal tests
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
         // passing all the tests and exiting the for loop
   return true;
}

void printfancyqueen(int q[]) {
   static int solution = 1;
   // box is a 2D array of characters of size 5 by 7
   typedef char box[5][7]; 
    // bb= black box and wb= white box (box bb and box wb are 2d arrays of characters of size 5 by 7) 
   // wq respresents a picture of a queen placed in a white square and bq respresents a picture of a queen placed in a black square
   // board is an array of pointers. Can be a pointer to white box or black box.  
   box bb, wb, wq,bq, *board[8][8]; 
  
   // creating the chessboard by filling in black box and wb white box.
   // Also initialising the black queen and white queen
   for (int i=0; i<5; i++){
      for (int j=0; j<7; j++) {
      	 wb[i][j] = ' ';
		 wq[i][j] = ' ';
		 bb[i][j] = char(219);
         bq[i][j] = char(219);
       }  
   }
     

   // 11 assignment statements to initialise the black and white queen.This is done to create the design of the queens in the 2D array
      bq[1][1]=  ' ';
      bq[2][1]=  ' ';
      bq[3][1]=  ' ';
      bq[3][2]=  ' ';
      bq[3][3]=  ' ';
      bq[3][4]=  ' ';
      bq[3][5]=  ' ';
      bq[1][3]=  ' ';
      bq[1][5]=  ' ';
      bq[2][3]=  ' ';
      bq[2][5]=  ' ';
	  
      wq[1][1]= char(219);
      wq[2][1]= char(219);
      wq[3][1]= char(219);
      wq[3][2]= char(219);
      wq[3][3]= char(219);
      wq[3][4]= char(219);
      wq[3][5]= char(219);
      wq[1][3]= char(219);
      wq[1][5]= char(219);
      wq[2][3]= char(219);
      wq[2][5]= char(219);
	  
	  
 
   // Filling the board with pointers to b;ack boxes and white boxes in alternate positions.
   for(int i=0; i<8; i++){
       for(int j=0; j<8; j++){
	      if((i+j)%2 == 0) board[i][j] = &wb;
         else board[i][j] = &bb;
        }
   }
    // this is to change eight entries in the array to show the positions of eight queens on the board
	// we do this by replacing the pointer in board representing either a wq or bq as appropriate for that position, which means putting pointers to wq or bq in appropiate squares.
	// i= column and q[i]= row  
	
   for(int i=0; i<8; i++)
      if((i+q[i])%2 == 0) board[q[i]][i] = &wq;
      else board[q[i]][i] = &bq;

   cout << "Solution number " << solution++ << ":\n "; // printing the solution count
   
   // this prints the upper border
     cout<< " ";
   for (int i=0; i<7*8; i++)
      cout << '_';
      cout << endl;
   
   // now we are printing the chessboard
   // i represents the horizontal band
   // j represengts which box we are talking about
   // k represents which line we are in, in each box
   // l moves through whatever line k is, to fill in the particular character.
   for (int i=0; i<8; i++)  {        
      for (int k=0; k<5; k++) {     
         cout << " "<< char(179); // printing the left border
         for (int j=0; j<8; j++) { 
            for (int l=0; l<7; l++) {
              
			      // board[i][j] is the box pointer in the ith row, jth column of the board , so dereferencing board[i][j] gives us the box being pointed to.
                // k tell which row and l tells which column of the box being pointed to, to look into
               cout << (*board[i][j])[k][l]; //dereferencing and printing the box
           }
       }
         cout << char(179) << endl; // This prints a bar at the end of the line and then moves to the new line
      }
  }

   // Printing lower border before exiting
  cout << " ";
   for (int i=0; i<7*8; i++)
      cout << char(196);
   cout << endl;
}

int main() {
   int q[8]={0}, c=0;
  
   //as long as we have not moved back coloumn zero we perform the following operations
    while (c >=0) 
    {
      if (c==8) // if we have crossed the last coloumn then we have found a solution and we print it 
         { printfancyqueen(q);
      
	   c--; // we backtrack and go to the previous column
        q[c]++;// and then move to the next row
      }
      // if we are in row 8, we reset the row to zero and we backtrack
       if (q[c]==8) { 
       q[c]=0;
       c--;// 
   //if we have moved back row 0, we increment the row
        if (q[c] != -1)
        q[c]++; 
      } 
	  // passing the array q to the bool function, if the  is queen placed in a valid position, we increment and go to the next column
      else if (okay(q,c)) {
          c++;
      }
      else { 
          q[c]++; // if not, we move to next row
    }
  }
  }


