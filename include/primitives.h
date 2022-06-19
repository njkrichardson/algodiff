#pragma once 
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

active_float reciprocal(const active_float x); 
active_float root(const active_float x); 
active_float power(const active_float x, const float exponent); 
active_float exp(const active_float x); 
active_float log(const active_float x);   
active_float sin(active_float x); 
active_float cos(active_float x); 
