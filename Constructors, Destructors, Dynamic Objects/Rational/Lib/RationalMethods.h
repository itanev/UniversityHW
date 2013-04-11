#ifndef rationalMethods
#define rationalMethods

using namespace std;

void Rational::truncate(int * n, int * d)
{
    int lcmNum = gcm(*n, *d);

    if(lcmNum <= abs(*n) && lcmNum <= abs(*d))
    {
        *n /= lcmNum;
        *d /= lcmNum;
    }
}

void Rational::asignValue(int * newNum, int * newDenom)
{
    truncate(newNum, newDenom);

    this->denom = *newDenom;
    this->num = *newNum;
}

Rational::Rational()
{
    num = 0;
    denom = 1;
}

Rational::Rational(int num, int denom)
{
    if(denom == 0) throw invalid_denom;

    asignValue(&num, &denom);
}

Rational::Rational(int number)
{
    this->num = number;
    denom = 1;
}

int Rational::getNum() const
{
    return num;
}

int Rational::getDenom() const
{
    return denom;
}

void Rational::print() const
{
    if(denom == 1) cout << num << endl;
    else if(num == 0) cout << 0 << endl;
    else if(abs(num) == abs(denom)) cout << num/denom << endl;
    else cout << num << '/' << denom << endl;
}

//private gratest common multiple
int Rational::gcm(int a, int b) const { return (b == 0) ? a : gcm(b, a%b); }
//private least common multiple
int Rational::lcm(int a, int b) const { return a*b /gcm(a,b); }

    Rational Rational::add(Rational * number) const
    {
        int newDenom = lcm(denom, number->getDenom());
        int newNum = newDenom / denom * num + newDenom / number->getDenom() * number->getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::subtract(Rational * number) const
    {
        int newDenom = lcm(denom, number->getDenom());
        int newNum = newDenom / denom * num - newDenom / number->getDenom() * number->getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::multiply(Rational * number) const
    {
        Rational result(num * (number->getNum()), denom * (number->getDenom()));
        return result;
    }

    Rational Rational::divide(Rational * number) const
    {
        Rational result(num * (number->getDenom()), denom * (number->getNum()));
        return result;
    }

    Rational Rational::operator+(Rational& number)
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num + newDenom / number.getDenom() * number.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::operator +(int number)
    {
        int newNum = number * denom + num;

        Rational result(newNum, denom);
        return result;
    }

    static Rational operator+(int number, Rational& rat)
    {
        return (rat + number);
    }

    Rational Rational::operator-()
    {
        return opposite();
    }

    Rational Rational::operator-(int n)
    {
        int newDenom = denom;
        int newNum = -1 * denom * n + num;

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::operator-(Rational& number)
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num - newDenom / number.getDenom() * number.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    static Rational operator-(int number, Rational& rat)
    {
        int newDenom = rat.getDenom();
        int newNum = rat.getDenom() * number + -1 * rat.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::operator*(Rational& number)
    {
        Rational result(num * (number.getNum()), denom * (number.getDenom()));
        return result;
    }

    Rational Rational::operator*(int number)
    {
        Rational result(num * number, denom);
        return result;
    }

    static Rational operator*(int number, Rational& rat)
    {
        return (rat * number);
    }

    Rational Rational::operator/(Rational& number)
    {
        Rational result(num * (number.getDenom()), denom * (number.getNum()));
        return result;
    }

    Rational Rational::operator/(int number)
    {
        Rational result(num, denom * number);
        return result;
    }

    static Rational operator/(int number, Rational& rat)
    {
        Rational result(number * rat.getDenom(), rat.getNum());
        return result;
    }

    Rational Rational::operator+=(Rational& number)
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num + newDenom / number.getDenom() * number.getNum();

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator+=(int n)
    {
        int newDenom = denom;
        int newNum = denom * n + num;

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator-=(Rational& number)
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num - newDenom / number.getDenom() * number.getNum();

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator-=(int n)
    {
        int newDenom = denom;
        int newNum = denom * n - num;

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator*=(Rational& number)
    {
        int newDenom = denom * (number.getDenom());
        int newNum = num * (number.getNum());

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator*=(int n)
    {
        int newDenom = denom * n;
        int newNum = num * n;

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator/=(Rational& number)
    {
        int newDenom = num * (number.getNum());
        int newNum = denom * (number.getDenom());

        asignValue(&newNum, &newDenom);
    }

    Rational Rational::operator/=(int n)
    {
        int newDenom = num * n;
        int newNum = denom * n;

        asignValue(&newNum, &newDenom);
    }

    bool Rational::operator < (Rational& rat)
    {
        if(num * rat.getDenom() >= denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator < (int number)
    {
        if(num >= denom * number) return false;

        return true;
    }

    static bool operator < (int number, Rational& rat)
    {
        if(rat.getNum() <= rat.getDenom() * number) return false;

        return true;
    }

    bool Rational::operator > (Rational& rat)
    {
        if(num * rat.getDenom() <= denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator > (int number)
    {
        if(num <= denom * number) return false;

        return true;
    }

    static bool operator > (int number, Rational& rat)
    {
        if(rat.getNum() >= rat.getDenom() * number) return false;

        return true;
    }

    bool Rational::operator <= (Rational& rat)
    {
        if(num * rat.getDenom() > denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator <= (int number)
    {
        if(num > denom * number) return false;

        return true;
    }

    static bool operator <= (int number, Rational& rat)
    {
        if(rat.getNum() < rat.getDenom() * number) return false;

        return true;
    }

    bool Rational::operator >= (Rational& rat)
    {
        if(num * rat.getDenom() < denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator >= (int number)
    {
        if(num < denom * number) return false;

        return true;
    }

    static bool operator >= (int number, Rational& rat)
    {
        if(rat.getNum() > rat.getDenom() * number) return false;

        return true;
    }

    bool Rational::operator == (Rational& rat)
    {
        if(num * rat.getDenom() != denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator == (int number)
    {
        if(num != denom * number) return false;

        return true;
    }

    static bool operator == (int number, Rational& rat)
    {
        if(rat.getNum() != rat.getDenom() * number) return false;

        return true;
    }

    bool Rational::operator != (Rational& rat)
    {
        if(num * rat.getDenom() == denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator != (int number)
    {
        if(num == denom * number) return false;

        return true;
    }

    static bool operator != (int number, Rational& rat)
    {
        if(rat.getNum() == rat.getDenom() * number) return false;

        return true;
    }

    Rational::operator int()
    {
        return int(num / denom);
    }

    Rational::operator float()
    {
        return float(num / denom);
    }

    Rational::operator double()
    {
        return double(num / denom);
    }

    Rational::operator bool()
    {
        return (*this == 0) ? false : true;
    }

    Rational Rational::operator ^(int power)
    {
        Rational multiple(this->getNum(), this->getDenom());

        for(int i = 0; i < power; i++)
        {
            (*this) *= multiple;
        }
    }

    Rational Rational::operator ~()
    {
        return Rational(denom, num);
    }

    static ostream& operator << (ostream &out, Rational& rat)
    {
        int num = rat.getNum();
        int denom = rat.getDenom();

        if(num == 0) out << 0;
        else if(denom == 1) out << rat.getNum();
        else
            out << rat.getNum() << '/' << rat.getDenom();

        return out;
    }

//is positive method
bool Rational::isPos() const
{
    if( (num < 0 && denom < 0) ||
        (num > 0 && denom > 0)  ) return true;
    else return false;
}

//to Double method
double Rational::toDouble() const
{
    return (double)num / (double)denom;
}

//opposite method
Rational Rational::opposite() const
{
    int newNum = (this->isPos()) ? (-1 * abs(num)) : abs(num);
    int newDenom = abs(denom);

    if(denom < 0 && num < 0) newNum = -1 * abs(num);

    Rational result(newNum, newDenom);

    return result;
}

#endif // rationalMethods
