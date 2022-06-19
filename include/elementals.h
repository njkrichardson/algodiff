/*
 * =====================================================================================
 *
 *       Filename:  elementals.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/25/2022 21:58:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <math.h> 
#include "core.h"

// --- unary functions 
active_float sin(active_float x); 
active_float cos(active_float x); 

// --- operators 
active_float operator* (active_float x, active_float y); 
active_float operator+ (active_float x, active_float y); 
