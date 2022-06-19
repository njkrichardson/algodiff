/*
 * =====================================================================================
 *
 *       Filename:  utils.cpp
 *
 *    Description:  Utilies module including profilers/timers, file handling, and 
 *    logging. 
 *
 *        Version:  1.0
 *        Created:  06/03/2022 14:18:51
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  NJKR
 *   Organization:  
 *
 * =====================================================================================
 */
#include <chrono> 
#include <iostream> 

class Timer
{
    private: 
        using clock_t = std::chrono::steady_clock; 
        using second_t = std::chrono::duration<double, std::ratio<1>>; 
        std::chrono::time_point<clock_t> m_start {clock_t::now()}; 
    public: 
        void reset()
        {
            m_start = clock_t::now(); 
        }

        double elapsed_time() const 
        {
            return std::chrono::duration_cast<second_t>(clock_t::now() - m_start).count(); 
        }
}; 

int main()
{
    int a{5}; 
    int b{5}; 
    int sum{}; 
    int num_elements{1000000}; 

    Timer t; 
    for (int i{0}; i < num_elements; ++i)
    {
        sum = a + b; 
        a = sum; 
    }
    std::cout << "Time elapsed: " << t.elapsed_time() << " seconds\n"; 
    return 0; 
}
