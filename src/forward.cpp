/*
 * =====================================================================================
 *
 *       Filename:  forward.cpp
 *
 *    Description:  Forward mode automatic differentiation utilities. 
 *
 *        Version:  1.0
 *        Created:  05/15/2022 17:49:02
 *       Revision:  none
 *       Compiler:  clang 13.0.1
 *
 *         Author:  NJKR
 *   Organization:  LIPS Internal 
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
}; 

active_float sin(active_float x)
{
    active_float result{}; 
    result.primal = sin(x.primal); 
    result.tangent = cos(x.primal) * x.tangent; 
    return result; 
}

active_float operator* (active_float x, active_float y)
{
    active_float result{}; 
    result.primal = x.primal * y.primal; 
    result.tangent = y.primal * x.tangent + x.primal * y.tangent; 
    return result; 
}


