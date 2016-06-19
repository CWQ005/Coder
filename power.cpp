/**
*¸¿¿¿¿base¿exponent¿¿¿
*/
#include <iostream>
#include <cmath>
double Power(double base, int exponent) ;
double Power1(double base, int exponent) ;
using namespace std;
int main()
{	
    cout<<Power(2,-2)<<" "<<Power1(2,-2)endl;
    return 0;
}
/**
*¿¿¿¿
*/
double Power(double base, int exponent) {
    if(exponent==0)return 1;
    if(exponent==1)return base;
    if(exponent==-1)return 1/base;
    int temp=exponent>>1;
    return Power(base,temp)*Power(base,exponent-temp);
    }
/**
*¿¿¿¿
*/
double Power1(double base, int exponent) {
    int exp=abs(exponent);
    if(exp==0)return 1;
    int x=1;
    double res=base;
    while (exp>=2*x)
    {
        res*=res;
	x=2*x;
    }
    while (x<exp)
    {
        res*=base;
	x++;
    }
    return exponent<0?1/res:res;
}
