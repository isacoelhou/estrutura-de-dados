#include <iostream>
#include "racionais.h"

using namespace std;

Racional::Racional()
{
    //cout << "Contruindo Racional (Default)\n";
    this->num = 0;
    this->den = 1;
}

Racional::Racional(int num, int den)
{
    //cout << "Contruindo Racional (Parametrizado)\n";
    this->num = num;
    if (den == 0)
        den = 1;
    if (den < 0){
        den = -den;
        num = -num;
    }
    
    this->den = den;
    simplifica();
}