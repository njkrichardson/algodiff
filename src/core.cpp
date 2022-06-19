/*
 * =====================================================================================
 *
 *       Filename:  core.cpp
 *
 *    Description:  Core data structures and utilities required for the forward 
 *    and adjoint mode automatic differentiation. 
 *
 *        Version:  1.0
 *        Created:  05/25/2022 21:50:40
 *       Revision:  none
 *       Compiler:  clang 13.0.1
 *
 *         Author:  NJKR
 *   Organization:  LIPS Internal 
 *
 * =====================================================================================
 */
#include <math.h> 
#include <iostream> 

#include "core.h"
#include "primitives.h"

// --- active numeric types 
float active_float::get_primal()
{
    return primal; 
}
        
float active_float::get_tangent()
{
    return tangent; 
}

void active_float::set_primal(float value)
{
    primal = value; 
}

void active_float::set_tangent(float value)
{
    tangent = value; 
}

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
