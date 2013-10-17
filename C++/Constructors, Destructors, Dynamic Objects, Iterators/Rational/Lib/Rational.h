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
        Rational add(const Rational& number) const;
        Rational subtract(const Rational& number) const;
        Rational multiply(const Rational& number) const;
        Rational divide(const Rational& number) const;
        Rational opposite() const;
        bool isPos() const;
        double toDouble() const;
        void print() const;

        //operators
        Rational operator +(const Rational& number) const;
        Rational operator +(int num) const;
        Rational operator -(const Rational& number) const;
        Rational operator -() const;
        Rational operator -(int num) const;
        Rational operator *(const Rational& number) const;
        Rational operator *(int num) const;
        Rational operator /(const Rational& number) const;
        Rational operator /(int num) const;
        Rational operator +=(int num);
        Rational operator +=(const Rational& number);
        Rational operator -=(int num);
        Rational operator -=(const Rational& number);
        Rational operator *=(int num);
        Rational operator *=(const Rational& number);
        Rational operator /=(int num);
        Rational operator /=(const Rational& number);

        bool operator < (const Rational& rat) const;
        bool operator > (const Rational& rat) const;
        bool operator > (int num) const;
        bool operator < (int num) const;
        bool operator <= (const Rational& rat) const;
        bool operator <= (int num) const;
        bool operator >= (const Rational& rat) const;
        bool operator >= (int num) const;
        bool operator == (const Rational& rat) const;
        bool operator == (int num) const;
        bool operator != (const Rational& rat) const;
        bool operator != (int num) const;

        operator int();
        operator float();
        operator double();
        operator bool();

        Rational operator ^(int power);
        Rational operator ~() const;
};

#endif // rational
