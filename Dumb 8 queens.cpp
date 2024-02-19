// Quazi Uzma Nadeem


#include <iostream>    
#include<cstdlib>    
#include <cmath>    
using namespace std;    
#include <cmath>
#include <iostream>
using namespace std;
	
	


	bool ok(int q[]){
	  for(int c = 1; c<8 ; c++){
// doing all three tests in one line
        for(int i = 0; i < c; i++){
            if ( q[c]==q[i] || (c-i) == abs(q[c]-q[i]) ) 
           // if we fail any of the tests
           return false;
        } 

    } 
    // passing all the tests and exiting the for loop
        return true;
} 

	void print(int q[], int count){
	    // printing the solution count
	 
    cout << "Solution number: " << count++ << endl;
    for (int r=0; r<8; r++)
    {   for (int c=0; c<8; c++)
        {   if (r==q[c]) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }

    
} 

int main (){
    int q[8]= {0};
       
	  int count=0;

   // series of nested loops and we need to traverse each column
    
    for(int c0 = 0; c0 < 8; c0++) {
       for(int c1=0; c1 < 8; c1++) {
          for(int c2 = 0; c2 < 8; c2++){
            for(int c3 = 0; c3 < 8; c3++){
              for(int c4 = 0; c4 < 8; c4++){
                for(int c5 = 0; c5 < 8; c5++){
                  for(int c6 = 0; c6 < 8; c6++){
                    for(int c7 = 0; c7 < 8; c7++){
                
                           
                          q[0]= c0;
                          q[1]= c1;
                          q[2]= c2;
                          q[3]= c3;         
                          q[4]= c4; 
                          q[5]= c5;
                          q[6]= c6;
                          q[7]= c7;
                           
            if (ok(q)) {
                print (q, ++count);
            }               
                         }
                     }
                 }
             }
         }
     }
  }
}
return 0;
}


    
    