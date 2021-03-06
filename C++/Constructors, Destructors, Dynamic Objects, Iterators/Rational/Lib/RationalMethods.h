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

    Rational Rational::add(const Rational& number) const
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num + newDenom / number.getDenom() * number.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::subtract(const Rational& number) const
    {
        int newDenom = lcm(denom, number.getDenom());
        int newNum = newDenom / denom * num - newDenom / number.getDenom() * number.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::multiply(const Rational& number) const
    {
        Rational result(num * (number.getNum()), denom * (number.getDenom()));
        return result;
    }

    Rational Rational::divide(const Rational& number) const
    {
        Rational result(num * (number.getDenom()), denom * (number.getNum()));
        return result;
    }

    Rational Rational::operator+(const Rational& number) const
    {
        return add(number);
    }

    Rational Rational::operator +(int number) const
    {
        return add(Rational(number));
    }

    Rational operator+(int number, const Rational& rat)
    {
        return (rat + number);
    }

    Rational Rational::operator-() const
    {
        return opposite();
    }

    Rational Rational::operator-(int number) const
    {
        return subtract(Rational(number));
    }

    Rational Rational::operator-(const Rational& number) const
    {
        return subtract(number);
    }

    Rational operator-(int number, const Rational& rat)
    {
        int newDenom = rat.getDenom();
        int newNum = rat.getDenom() * number + -1 * rat.getNum();

        Rational result(newNum, newDenom);
        return result;
    }

    Rational Rational::operator*(const Rational& number) const
    {
        return multiply(number);
    }

    Rational Rational::operator*(int number) const
    {
        return Rational(num * number, denom);
    }

    Rational operator*(int number, const Rational& rat)
    {
        return (rat * number);
    }

    Rational Rational::operator/(const Rational& number) const
    {
        return divide(number);
    }

    Rational Rational::operator/(int number) const
    {
        return Rational(num, denom * number);
    }

    Rational operator/(int number, const Rational& rat)
    {
        return Rational(number * rat.getDenom(), rat.getNum());
    }

    Rational Rational::operator+=(const Rational& number)
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

    Rational Rational::operator-=(const Rational& number)
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

    Rational Rational::operator*=(const Rational& number)
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

    Rational Rational::operator/=(const Rational& number)
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

    bool Rational::operator < (const Rational& rat) const
    {
        if(num * rat.getDenom() >= denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator < (int number) const
    {
        if(num >= denom * number) return false;

        return true;
    }

    bool Rational::operator > (const Rational& rat) const
    {
        if(num * rat.getDenom() <= denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator > (int number) const
    {
        if(num <= denom * number) return false;

        return true;
    }

    bool Rational::operator <= (const Rational& rat) const
    {
        if(num * rat.getDenom() > denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator <= (int number) const
    {
        if(num > denom * number) return false;

        return true;
    }

    bool Rational::operator >= (const Rational& rat) const
    {
        if(num * rat.getDenom() < denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator >= (int number) const
    {
        if(num < denom * number) return false;

        return true;
    }

    bool Rational::operator == (const Rational& rat) const
    {
        if(num * rat.getDenom() != denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator == (int number) const
    {
        if(num != denom * number) return false;

        return true;
    }

    bool Rational::operator != (const Rational& rat) const
    {
        if(num * rat.getDenom() == denom * rat.getNum()) return false;

        return true;
    }

    bool Rational::operator != (int number) const
    {
        if(num == denom * number) return false;

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

    Rational Rational::operator ~() const
    {
        return Rational(denom, num);
    }

    ostream& operator << (ostream &out, const Rational& rat)
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
