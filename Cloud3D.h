#ifndef CLOUD3D_H
#define CLOUD3D_H

#include <iostream>
using namespace std ;
enum StatusCode
{
    SUCCESS,
    ERROR_RANGE_HIGH,
    ERROR_RANGE_LOW
};
template <typename T>
class Cloud3D
{
 public :
     Cloud3D();
     Cloud3D(int intLength, int intBreadth, int intDepth);
     Cloud3D(const Cloud3D<T> &objOriginal);

     Cloud3D<T>& operator=(const Cloud3D<T>& objRHS);

     bool& operator()(int x,int y ,int z);

     template <typename T1>
     friend ostream& operator << (ostream& sLHS,const Cloud3D<T1>& objRHS);

     template <typename T1>
     friend istream& operator >> (istream& sLHS,const Cloud3D<T1>& objRHS) ;

     int getLength() const;
     int getBreadth() const ;
     int getDepth() const;

     static const int  MIN_SIZE = 1;
     static const int MAX_SIZE = 100000000;
     static const int DEFAULT_SIZE = 10 ;

     ~Cloud3D();

 private:
     void enforceRange(int intValue, int intMIn,int intMax) const ;
     void allocateCloud(int intLength,int intBreadth, int intDepth);
     void freeCloud();
     void copyCloud(const Cloud3D& objOriginal);
     bool*** _points;
     int _length;
     int _breadth;
     int _depth;

};

#include "Cloud3D.imp"
#endif // CLOUD3D_H
