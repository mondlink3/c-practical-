#include <iostream>
//#include <Cloud3D.h>
#include "Cloud3D.h"
#include "Cloud3D.imp"
using namespace std;

int main()
{
     cout << "Testing parametired Constructor "<<endl;
     PointCloud3D objCloud(3,4,5);
     cout << "Testing accessors and operator()" << endl;
     for(int l = 0 ; l < objCloud._length ; l++)
     {
         for(int b = 0 ; b < objCloud._breadth ; b++)
         {
             for(int d = 0 ; d < objCloud._depth ; d++)
             {
                 if(l == b )
                 {
                     if(b == d)
                     {
                         objCloud(l,b,d) = true  ;
                     }
                 }
             }
         }
     }
     cout << "Testing copy constructor" << endl;
     PointCloud3D objCopy(objCloud);
     cout << "Testing stream extraction operator" << endl;
     cout << objCopy << endl;
     cout << "Testing no-args constructor" << endl;
     PointCloud3D objAssigedTo;
     cout << "Testing assignment operator" << endl;
     objAssigedTo = objCloud;
     cout << objAssigedTo << endl
     cout << "Testing access via operator()" << endl;
     if(objCloud(0,0,0))
     cout << "The first point is occupied" << endl;
     else
     cout << "The first point is unoccupied" << endl;
    return SUCCESS;
}
