/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
typedef double(*FUNC)(double);

double line(double x){
    return x;
}

double square( double x){
    return x*x;
}

double cube(double x){
    return x*x*x;
}
//we are using a method called reimann sum to calculate the approximately correct area by taking small rectangles and then adding them up.
double integrate(FUNC f, double a, double b){
    double sum =0;
    // changeinx= breadth of the rectangle
    double changeinx = 0.0001;
    
    //changeinx/2= midpoint of each sub interval of each rectangle
    //we take the height by calculating the midpoint of each sub interval of an individual rectangle to increase the accuracy
    double x= a+ changeinx/2;
  
   // setting up a while loop where it loops till the value of x goes from a to b and exits the loop if the condition fails
   while(x < b){
        // calculating the integral by summing up areas of all the individual rectangles
        // we get the area by using the formula, Area of rectangle= length X breadth
        // Length of the rectangle= f(x) 
        sum= sum + changeinx*f(x);
        x= x + changeinx;
    }
    return sum; // gives the total area of all rectangles which is the integral value.
}

int main()
{
    cout<<"The integral of f(x)=x between 1 and 5 is: "<<integrate(line,1,5)<<endl;
    cout<<"The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square,1,5)<<endl;
    cout<<"The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube,1,5)<<endl;

    return 0;
}
