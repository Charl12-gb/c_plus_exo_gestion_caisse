#include <iostream>

using namespace std;

class NComplexe{
private:
    double a,b;

public:
    NComplexe(double a, double b);
    void setA(double a);
    void setB(double b);
    double getA() const;
    double getB() const;

    void afficher() const;
    NComplexe somme(NComplexe N2);
    NComplexe Produit(NComplexe N2);
    void Increment() const;
    NComplexe& operator+=(const NComplexe & z);
    NComplexe& operator-=(const NComplexe & z);
    NComplexe& operator*=(const NComplexe & z);
};

//NComplexe::NComplexe(double a=0, double b=0){}
NComplexe::NComplexe(double Re, double Im){
    this->a = Re;
    this->b = Im;
}

void NComplexe::setA(double a)
{
    this->a = a;
}

void NComplexe::setB(double b)
{
    this->b = b;
}

double NComplexe::getA() const
{
    return this->a;
}

double NComplexe::getB() const
{
    return this->b;
}

void NComplexe::Increment() const{
    if( this->b >= 0){
        cout << this->a+1 << "+i" << this->b+1 << endl;
    }else{
        cout << this->a+1 << "" << this->b+1 << "i" << endl;
    }
}

void NComplexe::afficher() const{
    if( this->b == 0 ){
        cout << this->a << endl;
    }else if( this->b > 0){
        cout << this->a << "+i" << this->b << endl;
    }else{
     cout << this->a << "" << this->b << "i" << endl;
    }
    //cout<< this << endl;
}

NComplexe NComplexe::Produit(NComplexe N2){
     return NComplexe ( ( (this->a*N2.a)+((this->b*N2.b)*(-1)) ), ( (this->b*N2.a)+((this->a*N2.b)) ) );
}

NComplexe NComplexe::somme(NComplexe N2){
    //NComplexe result;
    //result.a = this->a + N2.a;
    //result.b = this->b + N2.b;
    return NComplexe( (this->a + N2.a),(this->b + N2.b) );
}

NComplexe& NComplexe::operator+=(const NComplexe & z){
    this->a += z.a;
    this->b += z.b;
    return *this;
}

NComplexe& NComplexe::operator-=(const NComplexe & z){
    this->a -= z.a;
    this->b -= z.b;
    return *this;
}

NComplexe& NComplexe::operator*=(const NComplexe & z){
    this->a = ( (this->a*z.a)+((this->b*z.b)*(-1)) );
    this->b = ( (this->b*z.a)+((this->a*z.b)) );
    return *this;
    //return NComplexe ( ( (this->a*z.a)+((this->b*z.b)*(-1)) ), ( (this->b*z.a)+((this->a*z.b)) ) );
}

ostream& operator<<(ostream &sortie, const NComplexe &z){
    if( z.getB() == 0 ){
        cout << z.getA();
    }else if( z.getB() > 0){
        cout << z.getA() << "+i" << z.getB();
    }else{
        cout << z.getA() << "" << z.getB() << "i";
    }
    return sortie;
}

const NComplexe operator+(const NComplexe & z, const NComplexe & z1){
    return NComplexe((z.getA()+z1.getA()), (z.getB()+z1.getB()) );
    //return ((z.a+z1.a), (z.b+z1.b) );
}

const NComplexe operator-(const NComplexe & z, const NComplexe & z1){
    return NComplexe((z.getA()-z1.getA()), (z.getB()-z1.getB()) );
}

const NComplexe operator*(const NComplexe & z, const NComplexe & z1){
    return NComplexe ( ( (z.getA()*z1.getA())+((z.getB()*z1.getB())*(-1)) ), ( (z.getB()*z1.getA())+((z.getA()*z1.getB())) ) );
}
int main()
{
    NComplexe A(2,3);
    A.afficher();
    NComplexe B(1,2);
    NComplexe C(2,3);
    B.afficher();
    A+=B;
    //A.afficher();
    cout<< A <<endl;
    NComplexe D = B+C;
    cout<< D <<endl;
    //NComplexe C = A.Produit(B);
    //C.afficher();

    //cout << "Hello world!" << endl;
    return 0;
}
