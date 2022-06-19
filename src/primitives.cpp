/*
 * =====================================================================================
 *
 *       Filename:  primitives.cpp
 *
 *    Description:  Primitive operations and their derivatives. 
 *
 *        Version:  1.0
 *        Created:  06/19/2022 15:54:49
 *       Revision:  none
 *       Compiler:  clang 
 *
 *         Author:  NJKR
 *   Organization:  
 *
 * =====================================================================================
 */

#include <math.h> 
#include "core.h" 

active_float reciprocal(const active_float x)
{
    active_float result{}; 
    result.primal = 1 / x.primal; 
    result.tangent = -result.primal * (result.primal * x.tangent); 
    return result; 
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
