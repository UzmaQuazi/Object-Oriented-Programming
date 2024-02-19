
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int q[8], c=0, solution=0;
    q[0]=0;

NextColumn:
    c++;
    // if we are in column 8 we have found a solution and we print it
    if (c==8) goto print;
    q[c]= -1;

NextRow:
    q[c]++;
    // if we are in row 8 we have to backtrack as no valid loaction for queen is found
    if (q[c]==8) goto backtrack;

    // Row test and diagonal test
    for (int i=0;i<c;i++)
        if ( q[c]==q[i] || (c-i) == abs(q[c]-q[i]) ) 
       
        // if we fail any of the test
        goto NextRow;

    goto NextColumn;

backtrack:
    c--;
    if (c==-1) return 0;

    goto NextRow;

print:
solution++;
    cout << endl << "Solution number: " << solution << endl;
    for (int i=0;i<8;i++)
    {   for (int j=0;j<8;j++)
        {   if (j==q[i]) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
  

    goto backtrack;
}
