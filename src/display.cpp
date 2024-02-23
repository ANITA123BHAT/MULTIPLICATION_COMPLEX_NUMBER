#include <iostream>
#include "../include/complex.h"
using namespace std;

/*constructor definition*/
Complex::Complex(float real, float imaginary){
    this->real=real;
    this->imginary=imaginary;
}

/*member function of class Complex to display the result of multiplication opeartion */
void 
Complex::display_result() {
    if (imginary > 0) {
        cout <<"("<< real<<" + i*" << imginary <<")"<< endl;
    } else if (imginary < 0) {
        cout <<"("<<real<< " - i*" << -imginary << ")"<<endl;
    } else {
        cout <<real<< endl;
    }
    cout<<"\n";
}