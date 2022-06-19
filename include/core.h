#pragma once 
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

// --- active numeric types 
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
        float get_primal(); 
        
        float get_tangent(); 

        void set_primal(float value); 

        void set_tangent(float value); 
};

std::ostream& operator<< (std::ostream& buffer, const active_float& x); 
active_float operator+(const active_float x, const active_float y); 
active_float operator-(const active_float x, const active_float y); 
active_float operator*(const active_float x, const active_float y); 
active_float operator/(const active_float x, const active_float y); 
