#ifndef rational
#define rational

class Rational
{
    private:
        int num;
        int denom;

        int gcm(int a, int b) const;
        int lcm(int a, int b) const;
        void truncate(int * n, int * d);
        void asignValue(int * n, int * d);
    public:
        //constructors
        Rational();
        Rational(int num, int denom);
        Rational(int number);

        //methods
        int getNum() const;
        int getDenom() const;
        Rational add(Rational * number) const;
        Rational subtract(Rational * number) const;
        Rational multiply(Rational * number) const;
        Rational divide(Rational * number) const;
        Rational opposite() const;
        bool isPos() const;
        double toDouble() const;
        void print() const;

        //operators
        Rational operator +(Rational& number);
        Rational operator +(int num);
        Rational operator -(Rational& number);
        Rational operator -();
        Rational operator -(int num);
        Rational operator *(Rational& number);
        Rational operator *(int num);
        Rational operator /(Rational& number);
        Rational operator /(int num);
        Rational operator +=(int num);
        Rational operator +=(Rational& number);
        Rational operator -=(int num);
        Rational operator -=(Rational& number);
        Rational operator *=(int num);
        Rational operator *=(Rational& number);
        Rational operator /=(int num);
        Rational operator /=(Rational& number);

        bool operator < (Rational& rat);
        bool operator > (Rational& rat);
        bool operator > (int num);
        bool operator < (int num);
        bool operator <= (Rational& rat);
        bool operator <= (int num);
        bool operator >= (Rational& rat);
        bool operator >= (int num);
        bool operator == (Rational& rat);
        bool operator == (int num);
        bool operator != (Rational& rat);
        bool operator != (int num);

        operator int();
        operator float();
        operator double();
        operator bool();

        Rational operator ^(int power);
        Rational operator ~();
};

#endif // rational
