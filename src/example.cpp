/*
 * =====================================================================================
 *
 *       Filename:  example.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2022 21:57:34
 *       Revision:  none
 *       Compiler:  clang 
 *
 *         Author:  NJKR
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <math.h> 

class active_float
{
    public: 
        float primal; 
        float tangent; 

        // --- constructors 
        active_float(float primal=0, float tangent=0): primal{primal}, tangent{tangent}{}
        active_float(const active_float& copy): primal{copy.primal}, tangent{copy.tangent}{} 


        // --- operator overloads 
        friend std::ostream& operator<<(std::ostream& buffer, const active_float& x); 
        friend active_float operator+(const active_float x, const active_float y); 
        friend active_float operator-(const active_float x, const active_float y); 
        friend active_float operator*(const active_float x, const active_float y); 
        friend active_float operator/(const active_float x, const active_float y); 
        active_float& operator=(const active_float& x); 
        active_float& operator=(const float& x); 

        // --- accessors & mutators 
        float get_primal()
        {
            return primal; 
        }
        
        float get_tangent()
        {
            return tangent; 
        }

        void set_primal(float value)
        {
            primal = value; 
        }

        void set_tangent(float value)
        {
            tangent = value; 
        }
};

std::ostream& operator<< (std::ostream& buffer, const active_float& x)
{
    buffer << "ActiveFloat(" << x.primal << ", " << x.tangent << ")"; 
    return buffer; 
}

active_float& active_float::operator= (const active_float& x) 
{
    primal = x.primal; 
    tangent = x.tangent; 
    return *this; 
}

active_float& active_float::operator= (const float& x) 
{
    primal = x; 
    tangent = 0; 
    return *this; 
}

active_float reciprocal(const active_float x)
{
    active_float result{}; 
    result.primal = 1 / x.primal; 
    result.tangent = -result.primal * (result.primal * x.tangent); 
    return result; 
}

active_float operator+(const active_float x, const active_float y)
{
    active_float result{}; 
    result.primal = x.primal + y.primal; 
    result.tangent = x.tangent + y.tangent; 
    return result; 
}

active_float operator-(const active_float x, const active_float y)
{
    active_float result{}; 
    result.primal = x.primal - y.primal; 
    result.tangent = x.tangent - y.tangent; 
    return result; 
}

active_float operator*(const active_float x, const active_float y)
{
    active_float result{}; 
    result.primal = x.primal * y.primal; 
    result.tangent = x.primal * y.tangent + y.primal * x.tangent; 
    return result; 
}

active_float operator/(const active_float x, const active_float y)
{
    return reciprocal(y) * x; 
}

active_float root(const active_float x)
{
    active_float result{}; 
    result.primal = sqrt(x.primal); 
    result.tangent = 0.5 * (x.tangent / result.primal); 
    return result; 
}

active_float power(const active_float x, const float exponent) 
{
    active_float result{}; 
    result.tangent = x.tangent / x.primal; 
    result.primal = pow(x.primal, exponent); 
    result.tangent = exponent * (result.primal * result.tangent); 
    return result; 
}

active_float exp(const active_float x)
{
    active_float result{}; 
    result.primal = exp(x.primal); 
    result.tangent = result.primal * x.tangent; 
    return result; 
}

active_float log(const active_float x) 
{
    active_float result{}; 
    result.primal = log(x.primal); 
    result.tangent = x.tangent / x.primal; 
    return result; 
}

active_float sin(active_float x)
{
    active_float result{}; 
    result.primal = sin(x.primal); 
    result.tangent = cos(x.primal) * x.tangent; 
    return result; 
}

active_float cos(active_float x)
{
    active_float result{}; 
    result.primal = cos(x.primal); 
    result.tangent = -sin(x.primal) * x.tangent; 
    return result; 
}

int main()
{
    // --- initialize independent variables 
    active_float x{4}; 
    active_float y{2}; 
    
    // --- initialize dependent variables 
    active_float z{}; 

    // --- compute directional derivative
    float direction[]{1., 0.}; 
    x.set_tangent(direction[0]); 
    y.set_tangent(direction[1]); 

    // --- initial values 
    std::cout << "x: " << x << "\n"; 
    std::cout << "y: " << y << "\n"; 
    std::cout << "z: " << z << "\n"; 

    // --- execute (some) function 
    std::cout << "\n"; 
    std::cout << "Executing: z = x * y" << "\n"; 
    std::cout << "\n"; 
    z = x * y;

    // --- display output 
    std::cout << "x: " << x << "\n"; 
    std::cout << "y: " << y << "\n"; 
    std::cout << "z: " << z << "\n"; 

    // --- print the derivative(s) 
    std::cout << "derivative in the direction: (" << direction[0] << ", " << direction[1] << "): " << z.get_tangent() << "\n"; 

    return 0; 
}

