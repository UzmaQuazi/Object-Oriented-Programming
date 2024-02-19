
// QUAZI UZMA NADEEM

#include<iostream>
#include <cstdlib>
#include<vector>

using namespace std;

int main() { 
  //three towers A,B,C represented as an array of 3 vectors
  vector<int> tower[3]; 
   //Initializing the variables
  int disks, to, from=0, moves=0, candidate=1;
  //asking the user for odd or even number of disks
  cout << "Enter the number of disks:"; 
  cin >> disks;
  cout << endl;
   
     //Initializing the 3 towers where t[0], t[1] and t[3] are tower A, B and C respectively
  for (int i=disks+1; i>=1; i--){tower[0].push_back(i);} //starts with a 4
     tower[1].push_back(disks+1); //this places the 4's on tower 1 
     tower[2].push_back(disks+1); //this places the 4's on tower 2 
  

   //using a bool function to check if the number of disks enetred by the user is odd or even
  bool even = false;
  if(disks%2==0) {
  even = true;
  }
   // for even number of disks we initialise to to 2 and for odd we initialise to to 1
  if(even) to = 2; 
  else to = 1; 
  
   //we keep looping as long as if transfer all the rings to tower B and after that we are done and we get out of the while loop.
    while(tower[1].size()<disks+1){ 
    cout << "Move number" << ++moves << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower "<< char(to + 65) << endl;
     
     //transferring the disks from 'from' tower to 'to' tower 
     // this places the disk onto 'to' tower
    tower[to].push_back(tower[from].back()); 
    //this removes the disk from the 'from' tower
    tower[from].pop_back(); 
    
    // getting to the next 'from' tower
   //candidate which is the smallest available disk cannot be the most recent 'to' tower
   // comparing which tower has the smallest ring
    if (tower[(to+1)%3].back() < tower[(to+2)%3].back()){
     from=(to+1)%3;    
    } 
    else{
       from=(to+2)%3;  
    } 
    
    // getting the next candidate
    // the top disk that is being transferred from the from tower.
    candidate=tower[from].back(); 
    
    //getting the next 'to' tower by deciding if the number of disks are even or odd
    //for odd number of disk we move clockwise that is to the right and for even number we move anticlockwise that is to the left
   even =(disks%2==1); 
    if (even) {
        //taking the candidate and comparing it to the back to check if its even
      if (candidate < tower[(from+1)%3].back()) 
      // the tower is moving to the right
      to=(from+1)%3; 
      //+2 for even
      else to=(from+2)%3; 
    }
    else { 
    //   //taking the candidate and comparing it to the back to check if its odd
      if(candidate < tower[(from+2)%3].back()) 
       //the tower is moving to the left
      to=(from+2)%3;
      //+1 for odd
      else to=(from+1)%3; 
    }
  } return 0;
}
