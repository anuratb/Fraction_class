//Name :Anurat Bhattacharya(19CS10071)

#include "Fraction.hxx"
//declaring static constants
const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);
void Fraction::normalize() //to change to standard form
{
    try
    {
        if (this->dn == 0) //error if denominator is 0
            throw runtime_error("Error!Division by zero");
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n'; //Report Error
        exit(1);                  //Abort the program
    }
    if (nm == 0)
    {
        dn = 1;
    }
    else
    {
        //reduce to lowest form
        int g = gcd(nm, dn);
        nm /= g;
        dn /= g;
    }
}
Fraction::Fraction(int n, int d) //CR
{
    try
    {
        if (d == 0)
            throw runtime_error("Error!Division By zero");
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
        exit(1); //terminate if denominator 0
    }

    //make denominator positive
    if (d < 0)
    {
        nm = -n;
        dn = -d;
    }
    else
    {
        nm = n;
        dn = d;
    }
    normalize(); //reduce to standard form
}
Fraction::Fraction(double d) //CR
{
    nm = d * precision_;
    dn = precision_;
    normalize(); //reduce to standard form
}
Fraction::Fraction(const Fraction &other) //CCR
{
    nm = other.nm; //copy numerator
    dn = other.dn; //copy denominaotr
}
Fraction::~Fraction() {}                             //DR
Fraction &Fraction::operator=(const Fraction &other) //CAO
{
    nm = other.nm; //copy numerator
    dn = other.dn; //copy denominator
    return *this;  //return reference to current object to allow chaining of = operator
}
Fraction Fraction::operator-() const //unary minus
{
    return Fraction(-nm, dn);
}
Fraction Fraction::operator+() const //unary plus
{
    return *this; //no change
}
Fraction &Fraction::operator--() //pre decrement
{
    nm -= dn;     //first decrement
    return *this; //then return
}
Fraction &Fraction::operator++() //pre increment
{
    nm += dn;     //first increment
    return *this; //then return
}
Fraction Fraction::operator--(int) //post decrement
{
    Fraction t(*this); //create a copy
    nm -= dn;          //decrement
    return t;          //return the copy
}
Fraction Fraction::operator++(int) //post increment
{
    Fraction t(*this); //create copy
    nm += dn;          //increment
    return t;          //return the copy
}
Fraction operator+(const Fraction &A, const Fraction &B) //Addition
{
    //Optimization to return the other oprand if either one is 0
    if (A == Fraction::sc_fZero)
        return B;
    if (B == Fraction::sc_fZero)
        return A;
    //Standard fraction addition
    int l = Fraction::lcm(A.dn, B.dn);
    int a = l / A.dn;
    int b = l / B.dn;
    return Fraction(A.nm * a + B.nm * b, l); //normalisation done by constructor
}
Fraction operator-(const Fraction &A, const Fraction &B) //Subtraction
{
    //standard fraction subtraction
    int l = Fraction::lcm(A.dn, B.dn);
    int a = l / A.dn;
    int b = l / B.dn;
    return Fraction(A.nm * a - B.nm * b, l); // normalisation done by constructor
}
Fraction operator*(const Fraction &A, const Fraction &B) //Multiplication
{
    //Optimization to return the other oprand if either one is 1
    if (A == Fraction::sc_fUnity)
        return B;
    if (B == Fraction::sc_fUnity)
        return A;
    return Fraction(A.nm * B.nm, A.dn * B.dn); //(a/b) * (p/q) = (a*p)/(b*q)
}
Fraction operator/(const Fraction &A, const Fraction &B) //Division
{
    try
    {
        if (B == Fraction::sc_fZero) //Error if divisor is 0
            throw runtime_error("Error!Division by zero");
        if (B == Fraction::sc_fUnity)
            return A; //Optimization to return dividend if divisor is 1
        return Fraction(A.nm * B.dn, A.dn * B.nm);
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        exit(1); //Abort if division attempted by 0
    }
}
Fraction operator%(const Fraction &A, const Fraction &B) //Modulus
{
    try
    {
        if (B == Fraction::sc_fZero) //Error if divisor is 0
            throw runtime_error("Error!Division by zero");
        //A = B*C where C is a fraction
        // A = B*q + r , where q is an integer
        //so C = q + r/B ==> r = (C-q)*B ==> r = ((C.nm%C.dn)/C.dn) * B
        Fraction C = A / B;
        Fraction r = Fraction(C.nm % C.dn, C.dn) * B;
        return r;
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        exit(1);
    }
}
bool Fraction::operator==(const Fraction &B) const //Equality
{
    return (nm == B.nm) && (dn == B.dn);
}
bool Fraction::operator!=(const Fraction &B) const //Not equal to
{

    return !((nm == B.nm) && (dn == B.dn));
}

bool Fraction::operator<(const Fraction&B) const //less than
{
    //First we make denominator equal
    int l = Fraction::lcm(dn, B.dn);
    int a = l / dn;
    int b = l / B.dn;
    return (a * nm) < (b * B.nm); //Compare *this and B under same denominator
}
bool Fraction::operator<=(const Fraction&B) const //less than equal
{
    //First we make denominator equal
    int l = Fraction::lcm(dn, B.dn);
    int a = l / dn;
    int b = l / B.dn;
    return (a * nm) <= (b * B.nm); //Compare *this and B under same denominator
}

bool Fraction::operator>(const Fraction &B) const //Greater than
{
    //First we make denominator equal
    int l = Fraction::lcm(dn, B.dn);
    int a = l / dn;
    int b = l / B.dn;
    return (a * nm) > (b * B.nm); //Compare *this and B under same denominator
}
bool Fraction::operator>=(const Fraction &B) const //Greater than equal
{
    //First we make denominator equal
    int l = Fraction::lcm(dn, B.dn);
    int a = l / dn;
    int b = l / B.dn;
    return (a * nm) >= (b * B.nm); //Compare *this and B under same denominator
}
Fraction Fraction::operator!() const//To invert
{
    try
    {
        //Cannot invert 0
        if ((*this) == Fraction::sc_fZero) //Error if current object is 0
            throw runtime_error("Error!Division by zero");
        return Fraction(dn, nm);
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
        exit(1);
    }
}
ostream &operator<<(ostream &os, const Fraction &A) //O/P
{
    if (A.dn == 1) //Whole number
    {
        os << A.nm;
    }
    else //Fraaction
    {
        os << A.nm << " / " << A.dn;
    }
    return os;
}
istream &operator>>(istream &in, Fraction &A) //I/P
{
    int n, d;
    in >> n >> d;
    //make denominator positive
    if (d < 0)
    {
        A.nm = -n;
        A.dn = -d;
    }
    else
    {
        A.nm = n;
        A.dn = d;
    }
    A.normalize(); //if d is 0 error reporting will be done thorugh this func
    return in;
}
int Fraction::gcd(int a, int b)
{
    //Make operands positive
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    //base cases
    if (b == 0)
        return a;
    if (a % b == 0)
    {
        return b;
    }
    if (b == 1)
        return 1;
    //reccursive definition
    return gcd(b, a % b);
}
int Fraction::lcm(int a, int b)//lcm
{
    try
    {
        if(a==0||b==0)
        {
            throw runtime_error("Arguments of lcm(int,int) mus be non zero,since 0 cannot divide any integer");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    return (a * b) / gcd(a, b);
}

