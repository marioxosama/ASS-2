#include <iostream>
#include<cmath>
#include<string>


using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex()
    {
        real=0;
        imaginary=0;
    }
    Complex(double real_part)
    {
        real = real_part;
        imaginary=0;
    }

    Complex(double r , double i)
    {
        real=r;
        imaginary=i;
    }

    void setReal(double r)
    {
        real=r;
    }
    void setImag(double i)
    {
        imaginary=i;
    }
    double getReal()
    {
        return real;
    }
    double getImag()
    {
        return imaginary;
    }

    bool operator== (Complex cx)
    {
        double real1;
        double imaginary1;
        real1 = cx.getReal();
        imaginary1 = cx.getImag();
        if(real1 == real && imaginary1==imaginary){
            return true;
        }
        return false;

    }
    Complex operator + (Complex cx)
    {
        Complex res;
        res.setReal(cx.getReal() + this-> real);
        res.setImag(cx.getImag() + this-> imaginary);
        return res;
    }

        Complex operator - (Complex cx)
    {
        Complex res;
        res.setReal(this->real - cx.getReal());
        res.setImag(this->imaginary - cx.getImag());
        return res;
    }
    Complex operator * (Complex cx)
    {
        Complex res;
        res.setReal(real * cx.getReal() - (imaginary*cx.getImag()));
        res.setImag(real * cx.getImag()  + imaginary * cx.getReal() );
        return res;
    }

    friend istream& operator>> (istream&  in , Complex& cx);
    friend ostream& operator<< (ostream&  out , Complex cx);



};
const Complex i (0,1);

int main()
{
    Complex x1 (1,1);
    Complex x2 (3 ,12);
    Complex x3;
    cin>>x3;
    cout<<x3<<endl;

}

istream& operator>> (istream& in, Complex& cx)
{
        double r,i;
        in>>r;
        in>>i;
        cx.real = r;
        cx.imaginary = i;
        return in;
}

ostream& operator<< (ostream& out, Complex cx)
{
       out<<cx.real;
       if(cx.imaginary<0){
        out<<" "<<cx.imaginary<<"i"<<endl;
       }
       else{out<<" +"<<cx.imaginary<<"i"<<endl;}
       return out;
}
