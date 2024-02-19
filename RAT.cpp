

 // Quazi Uzma Nadeem
#include <iostream>
using namespace std;

class Rat{
    private:
        int n;
        int d;
    public:
        //constructors

        //default constructors
        Rat(){
            n=0;
            d=1;
        }

        //2 parameter constructor
        Rat(int i, int j){
            n=i;
            d=j;
        }

        //conversion constructor
        Rat(int i) {
            n=i;
            d=1;
        }

        //accessor functions
        int getN() {return n;}
        int getD() {return d;}

        
        void setN(int i) {n=i;}
        void setD(int i) {d=i;}

        //arithmetic operators
  Rat operator+(Rat r){
            Rat t;
            t.n=n*r.d+d*r.n;
            t.d=d*r.d;
            return t.lf();
        }

    Rat operator-(Rat r){
            Rat t;
            t.n=n*r.d-d*r.n;
            t.d=d*r.d;
            return t.lf();
        }

     Rat operator*(Rat r){
            Rat t;
            t.n=n*r.n;
            t.d=d*r.d;
            return t.lf();
        }

     Rat operator/(Rat r){
            Rat t;
            t.n=n*r.d;
            t.d=d*r.n;
            return t.lf();
        }
      // for the greatest common divider
        int gcd(int a, int n)
        { int x;
         while (n != 0 )
            {   x = a;
                a = n;
                n = x % n;
            }  return a;
        }

        //this reduces the fraction to the lowest term 
        //lf=lowest fraction
        Rat lf() {
        int g = gcd(n, d);
            return Rat(n/g, d/g);
        }

        
        friend ostream& operator<< (ostream& os, Rat r);
        friend istream& operator>> (istream& is, Rat& r);
};



  ostream& operator<< (ostream& os, Rat r){
    r = r.lf();
    if (r.n%r.d == 0 || r.d == 1) 
        os << r.n << endl;
        //outputs mixed numbers
    else if (r.n > r.d) 
        os << r.n/r.d << " " << r.n%r.d << "/" << r.d << endl;
    else
        os << r.n << "/" << r.d << endl;
    return os;
}



istream& operator>> (istream& is, Rat& r){
     is >> r.n >> r.d;
   return is;
}

int main() {
     Rat x(1, 2), y(2, 3), z;
    z= x+y;
    cout<< z<< endl;
    
    y.setN(7);
      y.setD(2);
     z= x+y;
    cout<< z<<endl;
    
    z=x-y;
      cout<< z<<endl;
    
    z=x/y;
      cout<< z<<endl;
      
   z= x+5; 
   cout<<z;   
    
    return 0; 
    
}
   
        
       


