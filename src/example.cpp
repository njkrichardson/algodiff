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

#include "primitives.h" 
#include "core.h" 

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
