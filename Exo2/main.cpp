#include <iostream>

using namespace std;

class Point{
protected:
    double x,y;

public:
    Point(double=0, double=0);
    virtual void afficher() const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    void sannoncer(string) const;
};

Point::Point(double a, double b):x(a),y(b){}

void Point::setX(double x)
{
    x = x;
}

void Point::setY(double y)
{
    y = y;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::afficher() const{
    cout << "( " << x << "," << y << " )" ;
}

void Point::sannoncer(string mot) const{
    cout << "Je suis un " << mot << " et me voici " << endl;
    this->afficher();
}

class Cercle: public Point{
private:
    double r;
public:
    Cercle(double =0, double=0, double=0);
    void afficher() const;
    double getR() const;
    void setR( double );
};

Cercle::Cercle(double x, double y, double c):Point(x,y){
    r = c;
}

void Cercle::setR(double r)
{
    this->r = r;
}

double Cercle::getR() const
{
    return r;
}

void Cercle::afficher() const{
    //cout << "(( " << this->x << "," << this->y << " ) " << this->r << ")" << endl;
    cout << "(";
    Point::afficher();
    cout << "," << r << ")" << endl;

}

int main()
{
    Cercle A(2,3,4);
    //A.afficher();
    A.sannoncer("Cercle");
    return 0;
}
