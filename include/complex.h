#ifndef COMPLEX_H
#define COMPLEX_H
#define SIZE 4
#include <bits/stdc++.h>
#include <fstream>
#include<sstream>
#include<string>
#include<vector>
#include<cmath>
#include <cctype>
class Complex {
     public:
    float real, imginary;
    //Complex();//defult construtor.
    Complex(float real = 0, float imginary = 0);//parametrized constructor
    void display_result();
};
/*macros*/
#define multiply_complex(num1, num2) \
    Complex((num1.real * num2.real) - (num1.imginary * num2.imginary), \
            (num1.imginary * num2.real) + (num1.real * num2.imginary))

#endif // COMPLEX_H