#ifndef rational
#define rational

class Rational
{
    private:
        //some fields
        int num;
        int denom;

        //some functs
        int gcm(int a, int b) const;
        int lcm(int a, int b) const;
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
};


#endif // rational
