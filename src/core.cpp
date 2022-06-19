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

// --- active numeric types 
class active_float
{
    public: 
        float primal; 
        float tangent; 
        active_float(float primal=0, float tangent=0): primal{primal}, tangent{tangent}{}
};

class active_double 
{
    public: 
        double primal; 
        double tangent; 
        active_double(double primal=0, double tangent=0): primal{primal}, tangent{tangent}{}
}; 
