// testaRac.cpp
// Implemeta uma classe para número racionais

#include <iostream>
using namespace std;

//===============================================
// Declaração da classe Racional
//===============================================

class Racional
{
    private:

        short num; //numerador
        short den; //denominador

    public:

        Racional(); //default
        ~Racional();                  //destrutor

        void print();                 //imprime 
        void scan();                  //lê dados

        Racional(int num, int den); //parametro
        Racional(const Racional &B); //construtor de cópia
        
        
        int MDC(int n, int d);        //cálculo do mdc
        void simplifica();            // simplificação do número

        Racional add(const Racional &B); 
        Racional sub(const Racional &B);
        Racional div(const Racional &B);
        Racional mult(const Racional &B);

        // FUNÇÕES DE SOBRECARGA

        Racional operator -(int R);
        Racional operator +(int R);
        Racional operator *(int R);
        Racional operator /(int R);
       
        
        Racional operator -(const Racional &B);
        Racional operator +(const Racional &B);
        Racional operator *(const Racional &B);
        Racional operator /(const Racional &B);

        friend Racional operator -(int L , const Racional &C);
        friend Racional operator +(int L , const Racional &C);
        friend Racional operator *(int L , const Racional &C);
        friend Racional operator /(int L , const Racional &C);

        friend Racional operator -(const Racional &C, int L);
        friend Racional operator +(const Racional &C, int L);
        friend Racional operator *(const Racional &C, int L);
        friend Racional operator /(const Racional &C, int L);

        friend istream &operator >> (istream &input, Racionais &R);
        friend ostream &operator << (ostream &output, const Racionais &R);
        
};

//===============================================
// Implementação dos métodos da classe racional
//===============================================


Racional::Racional(const Racional &B)
{
    cout << "Contruindo Racional (Cópia)\n";
    this->num = B.num;
    this->den = B.den;
}

Racional::~Racional()
{
    cout << "Destruindo Racional \n";
}

void Racional::print()
{
    cout << this-> num << "/" << this->den;
}

void Racional::scan()
{
   cin >> this->num;
   cin.ignore();
   cin >> this->den;
   simplifica();
}

int Racional::MDC(int n, int d)
{
    int r;
    while (d)
    {
        r = n%d;
        n = d;
        d = r;
    }

    return n;
}

void Racional::simplifica()
{
    int mdc = MDC(this->num, this->den);
    this->num /= mdc;
    this->den /= mdc;

    if(this->den < 0)
    {
        this->num *= -1;
        this->den *= -1;
    }
}

Racional Racional::add(const Racional &B)
{
    Racional S;
    S.den = this->den * B.den;
    S.num = this->num * B.den + B.num * this->den;
    S.simplifica();
    return S;
}

Racional Racional::operator +(const Racional &B)
{
    Racional S;
    S.den = this->den * B.den;
    S.num = this->num * B.den + B.num * this->den;
    S.simplifica();
    return S;
}

Racional Racional::operator +(int R)
{
    Racional S;
    S.den = this->den;
    S.num = this->num + R*this->den;
    S.simplifica();
    return S;
}

Racional operator +(int L , const Racional &C)
{
    Racional S;
    S.den = C.den;
    S.num = C.num + L*C.den;
    S.simplifica();
    return S;
}

Racional Racional::sub(const Racional &B)
{
    Racional S;
     S.num = (this->num*B.den) - (this->den*B.num);
     S.den = this->den*B.den;
     S.simplifica();
     return S;
} 


Racional Racional::operator - (const Racional &B)
{
    Racional S;
     S.num = (this->num*B.den) - (this->den*B.num);
     S.den = this->den*B.den;
     S.simplifica();
     return S;
} 

Racional Racional::operator - (int R)
{
    Racional S;
    S.den = this->den;
    S.num = this->num - R*this->den;
    S.simplifica();
    return S;
} 

Racional operator -(int L , const Racional &C)
{
    Racional S;
    S.den = C.den;
    S.num = L*C.den - C.num;
    S.simplifica();
    return S;
}

Racional Racional::mult(const Racional &B)
{
    Racional S;
     S.num = this->num*B.num;
     S.den = this->den*B.den;
     S.simplifica();
     return S;
} 

Racional Racional::operator *(const Racional &B)
{
    Racional S;
     S.num = (this->num*B.num);
     S.den = this->den*B.den;
     S.simplifica();
     return S;
} 

Racional Racional::operator *(int R)
{
    Racional S;
    S.den = this->den;
    S.num = this->num * R;
    S.simplifica();
    return S;
} 

Racional operator *(int L , const Racional &C)
{
    Racional S;
    S.den = C.den;
    S.num = C.num * L;
    S.simplifica();
    return S;
}

Racional Racional::div(const Racional &B)
{
    Racional S;
     S.num = this->num*B.den;
     S.den = this->den*B.num;
     S.simplifica();
     return S;
} 

Racional Racional::operator /(const Racional &B)
{
    Racional S;
     S.num = this->num*B.den;
     S.den = this->den*B.num;
     S.simplifica();
     return S;
} 

Racional Racional::operator /(int R)
{
    Racional S;
    S.den = this->den* R;
    S.num = this->num;
    S.simplifica();
    return S;
} 

Racional operator /(int L , const Racional &C)
{
    Racional S;
    S.den = C.num;
    S.num = L * C.den;
    S.simplifica();
    return S;
}


//===============================================
// Função principal
//===============================================

int main()
{
    system("clear");
    cout << "<<<< Classe Racional >>>> \n";
    cout << endl << endl;

    cout << "Declarando variáveis Racionais: \n\n";
    Racional A(3,2), B(4,2), C = B;
    cout << endl;
    
    // Impressão dos valores inciados
    cout << "Valores iniciais das variáveis: \n";
    cout << endl;
    cout << "A = ";
    A.print();
    cout << endl;
    cout << "B = ";
    B.print();
    cout << endl;
    cout << "C = ";
    C.print();
    cout << endl;
    cout << endl;

    C = 5 / B;
    cout << "div de 5 com B resulta em = "; C.print();
    cout << endl;

    C = B / 2;
    cout << "div de B com 2 resulta em = "; C.print();
    cout << endl;
    cout << endl;

    return 0;
}