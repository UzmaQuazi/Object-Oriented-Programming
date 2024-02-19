
// Quazi Uzma Nadeem
#include <iostream>

using namespace std;

// setting up a bool function to check the stability of the pairs
 bool ok(int q[], int man) {
     //mp= man's preference //wp= woman's preference
     // mp[i][j] gives man i's ranking of woman j
        int mp[3][3] = { {0,2,1},  //Man 0 likes woman 0 the most and woman 1 the least
                         {0,2,1},  //Man 1 likes woman 0 the most and woman 1 the least
                         {1,2,0}}; //Man 2 likes woman 1 the most and woman 0 the least
     
     // wp[i][j] gives woman i's ranking of man j
        int wp[3][3] = { {2,1,0},  //woman 0 likes man 2 the most and man 0 the least
                         {0,1,2},  //woman 1 likes man 0 the most and man 2 the least
                         {2,0,1}}; //woman 2 likes man 2 the most and man 1 the least
                         
        int cm, cw, nm, nw;  // cm= currently assigned man
                             // cw= currently assigned woman
                             // nm= new man
                             // nw= new woman
        nm = man;
        nw = q[man];
       
        
    for (int cm=0; cm< man; cm++){
     // Checking to see if the woman has been already paired with a man and we return false if she has been paired already   
     if(q[cm] == nw) return false; 
        
        cw=q[cm];
   //checking if the current man likes the new woman more than his current partner and 
   //the new woman likes the current man more than her partner
   // or
   //if the new man likes the current woman more than his partner and 
   //the current woman likes the new man more than her partner, we return false
    if(( mp[cm][nw]< mp[cm][cw] && wp[nw][cm]< wp[nw][nm] )|| (mp[nm][cw]< mp[nm][nw] && wp[cw][nm]< wp[cw][cm] ))
       
      return false;
    }
        return true; // we return true if all tests are passed and the pair does not introduce an instability
        
        
 }
 // printing the solution
void printpair(int q[]){
    static int solution = 1; 
    cout << "Solution number: " << solution++ << endl; // solution count
    for ( int c = 0; c < 3; c++ ){
        cout << "man " << c << " is paired with woman " << q[c] << endl; //printing each pair
    }
    cout <<"\n";
}

int main() {

     int q[3] = {0}; 
     int man = 0; // we begin with man 0
    // as long as we have not moved back man zero we perform the following operations
    while (man != -1){

        // checking to see if all men are paired up with the women 
        if(man> 2){
            printpair(q);// if so, then we have found a solution and we print it 
            // we backtrack and go to the previous man
            man--;
            // and then increment the woman there
            q[man]++;
        }
        // checking if all the present women are paired 
        else if (q[man] > 2){
            q[man] = 0;// if so, we reset woman to zero and backtrack
            man--;
            if (man != -1)
            // moving to the next woman 
            q[man]++;
        }
        //checking to see if the array q is stable by passing it to the bool function
        else if(ok(q, man)){
            man++;// if so, we increment and go to the next man
        }
        else{
            q[man]++;// if q is not stable we match the man with the next woman
        }
    }
    return 0;
}
