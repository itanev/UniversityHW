#ifndef rationalMethods
#define rationalMethods

using namespace std;

Rational::Rational()
{
    num = 0;
    denom = 1;
}

Rational::Rational(int num, int denom)
{
    if(denom == 0) throw invalid_denom;

    int lcmNum = gcm(num, denom);

    if(lcmNum <= abs(num) && lcmNum <= abs(denom))
    {
        num /= lcmNum;
        denom /= lcmNum;
    }

    this->num = num;
    this->denom = denom;
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

//add method
Rational Rational::add(Rational * number) const
{
    int newDenom = lcm(denom, number->getDenom());
    int newNum = newDenom / denom * num + newDenom / number->getDenom() * number->getNum();

    Rational result(newNum, newDenom);
    return result;
}

//subtract method
Rational Rational::subtract(Rational * number) const
{
    int newDenom = lcm(denom, number->getDenom());
    int newNum = newDenom / denom * num - newDenom / number->getDenom() * number->getNum();

    Rational result(newNum, newDenom);
    return result;
}

//multiply method
Rational Rational::multiply(Rational * number) const
{
    Rational result(num * (number->getNum()), denom * (number->getDenom()));
    return result;
}

//divide method
Rational Rational::divide(Rational * number) const
{
    Rational result(num * (number->getDenom()), denom * (number->getNum()));
    return result;
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
