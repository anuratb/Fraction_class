//Name :Anurat Bhattacharya(19CS10071)

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdexcept>
using namespace std;
#ifndef FRAC_INCLUDE
#define FRAC_INCLUDE
//===================================================================
/**
 * @brief User Defined Data Type Fraction
 * 
 */
class Fraction
{
    /**
     * @brief Private Members
     * @param nm Numerator 
     * @param dn denominator
     * @param precision_ precision for converting from double to fraction
     */
    int nm;
    unsigned int dn;
    const static int precision_ = 1000;
    // To normalize and change  to standard form
    void normalize();

public:
    /**
     * @brief Static Constants 
     *         sc_fUnity : 1 / 1
     *         sc_fzero : 0 / 1 
     */
    const static Fraction sc_fUnity, sc_fZero;

    /**
     * @brief Construct a new Fraction object using n and d
     * 
     * @param n numerator
     * @param d denominator
     */
    Fraction(int n = 1, int d = 1);

    /**
     * @brief Construct a new Fraction object from a double value
     *        as (d*precision) / precision
     *        Implicit conversion not allowed
     * 
     * @param d Double equivalent of the fraction
     */
    explicit Fraction(double d);

    /**
     * @brief Copy Constructor,modifies current object,parameter not modified
     * 
     * @param other Object to be copied,called by reference(const ref)
     */
    Fraction(const Fraction &other);

    //DEstructors
    ~Fraction();

    /**
     * @brief Copy Assignment operator,for assignment of current object
     *        Modifies current object
     * 
     * @param other call by reference(as const ref)
     * @return Fraction& ,reference to assigned object
     */
    Fraction &operator=(const Fraction &other);

    //Unary Arithmetic operators

    /**
     * @brief Unary Minus,Does not modify object
     * 
     * @return Fraction,negative of current fraction, by value
     */
    Fraction operator-() const; //Unary minus

    /**
     * @brief Unary Plus,Does not modify object
     * 
     * @return Fraction ,same as that of current object, by value
     */
    Fraction operator+() const; //Unary plus

    /**
     * @brief Prefix pre-decrement operator for dividendo
     *        Modifies current object
     *         
     * @return Fraction& returns reference to current object ,(p-q)/q ,if current obj p/q
     */
    Fraction &operator--(); //Pre-decrement

    /**
     * @brief Prefix pre-increment operator for componendo ,
     *        Modifies current object
     * 
     * @return Fraction& ,reference to current object, (p+q)/q if current obj p/q
     */    
    Fraction &operator++(); //Pre-Increment

    /**
     * @brief Postfix post-decrement operator for lazy dividendo ,
     *        Modifies current obj,subtracts 1 from it
     * 
     * @return Fraction ,by value, the original object 
     */
    Fraction operator--(int); //Post-decrement

    /**
     * @brief Postfix post-increment operator for lazy dividendo ,
     *        Modifies current object ,adds 1 to it
     * 
     * @return Fraction ,by value,the original object
     */
    Fraction operator++(int); //Post-increment

    //Binary Arithmetic Operators
    /**
     * @brief Addition operator,adds 2 fractions 
     *        Does not Modify Parameters      
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand
     * @return Fraction by value , A + B
     */
    friend Fraction operator+(const Fraction &A, const Fraction &B); //Addition

    /**
     * @brief Subtraction operator,subtracts 2 fractions 
     *        Does not Modify Parameters      
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand
     * @return Fraction by value , A - B
     */
    friend Fraction operator-(const Fraction &A, const Fraction &B); //Subtraction

    /**
     * @brief Multiplication operator,Multiplies 2 fractions 
     *        Does not Modify Parameters      
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand
     * @return Fraction by value A*B
     */
    friend Fraction operator*(const Fraction &A, const Fraction &B); //Multiplication

    /**
     * @brief Division operator,Divides 2 fractions 
     *        Does not Modify Parameters  
     * @throws runtime_error("Error!Division by zero") , if B is Fraction::sc_fzero     
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand
     * @return Fraction by value A/B
     */
    friend Fraction operator/(const Fraction &A, const Fraction &B); //Division

    /**
     * @brief Modulus operator,Find the remander when A is divided by B
     *        Does not Modify Parameters  
     * @throws runtime_error("Error!Division by zero") , if B is Fraction::sc_fzero     
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand
     * @return Fraction by value A%B
     */
    friend Fraction operator%(const Fraction &A, const Fraction &B); //Modulus

    //Binary Relational Operators
    /**
     * @brief Equality Operator,const member func,does not modify operands
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand 
     * @return true if A and B are equal
     * @return false else
     */
    bool operator==(const Fraction &B) const; //Equality

    /**
     * @brief Not Equals Operator,const member func,does not modify operands
     *  
     * @param B Call by reference(as const ref), right operand 
     * @return true if A and B are not equal
     * @return false else
     */
    bool operator!=(const Fraction &B) const; //Not equal to

    /**
     * @brief Less Than Operator,const member func,does not modify operands
     *  
     * @param B Call by reference(as const ref), right operand 
     * @return true if A is strictly less than B 
     * @return false else
     */  
    bool operator<(const Fraction& B) const;

    /**
     * @brief Less Than or Equals Operator,const member func,does not modify operands
     *  
     * @param B Call by reference(as const ref), right operand 
     * @return true if A is  less than or equal to B 
     * @return false else
     */
    bool operator<=(const Fraction &B) const; //less than equal to

    /**
     * @brief Greater Than Operator,const member func,does not modify operands
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand 
     * @return true if A is strictly greater than B 
     * @return false else
     */
    bool operator>(const Fraction &B) const; //Greater than

    /**
     * @brief Greater Than or Equals Operator,const member func,does not modify operands
     * 
     * @param A Call by reference(as const ref), left operand
     * @param B Call by reference(as const ref), right operand 
     * @return true if A is  greater than or equal to B 
     * @return false else
     */
    bool operator>=(const Fraction &B) const; //Grater than equal to

    //Special operator
    /**
     * @brief To get the Inverse of the current Fraction
     *        Does not Modify current object
     * @throws runtime_exception() if current object is equal to sc_fZero
     * 
     * @return Fraction ,by value, the reciprocal of current object
     */
    Fraction operator!() const; //To invert

    //IO operators

    /**
     * @brief Output Stream Operator
     *        Does not modify the object to be printed, modifies ostream object
     *        Output Format: <numerator> / <denominator>
     * 
     * @param os Call by Reference, the output_stream object
     * @param A Call by reference(as const ref) ,the Fraction to be printed
     * @return ostream& the modified state of the ostream object
     */
    friend ostream &operator<<(ostream &os, const Fraction &A) ; //Output

    /**
     * @brief Input Stream Operator
     *        Both the operand objects modified
     *        Input Format : <numerator> <denominator>
     * 
     * @param in Call by Reference, the input stream(istream) object
     * @param A Call by reference ,the Fraction to be inputted
     * @return istream& the modified state of the istream object
     */
    friend istream &operator>>(istream &in, Fraction &A); //Input

    //Utility functions

    /**
     * @brief To get the Precision value,used here
     * 
     * @return int - The value of the precision
     */
    inline static int precision() { return precision_; }

    /**
     * @brief Utility Function to get gcd of two integers
     *        Operands not modified
     * 
     * @param a -Call by value,Left Operand
     * @param b -Call by value,Right Operand
     * @return int -the gcd of a and b,by value
     */
    static int gcd(int a, int b);

    /**
     * @brief Utility Function to get gcd of two integers
     *        Operands not modified
     * @throws runtime_error() if any of the arguments is 0
     * @param a -Call by value,Left Operand
     * @param b -Call by value,Right Operand
     * @return int -the lcm of a and b,by value 
     */
    static int lcm(int a, int b);
};
//===================================================================
#endif
