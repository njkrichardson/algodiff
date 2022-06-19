/*
 * =====================================================================================
 *
 *       Filename:  core.h
 *
 *    Description:  Header file for core automatic differentiation types and utilities. 
 *
 *        Version:  1.0
 *        Created:  05/25/2022 21:54:50
 *       Revision:  none
 *       Compiler:  clang 13.0.1
 *
 *         Author:  NJKR
 *   Organization:  LIPS Internal 
 *
 * =====================================================================================
 */

class active_float
{
    public: 
        float primal; 
        float tangent; 
}; 

class active_double 
{
    public: 
        double primal; 
        double tangent; 
}; 
