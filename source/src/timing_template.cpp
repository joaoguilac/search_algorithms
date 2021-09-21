/*!
 * This is a template code to demonstrate how to measure runtime of part of your code.
 * I'm using the chrono C++ library.
 * @date September 8th, 2020.
 * @author Selan
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>	// std::ifstream

#include "searching.h"

int main( void )
{
    double sum{0};
    double average;
    sa::value_type repetitions{30};
    sa::value_type size_min{10000};
    sa::value_type size_max{10000000};
    std::vector<sa::value_type> times;

    // =====================================Linear search=====================================
    std::ofstream lin( "linear.txt" );
    while (size_min < size_max) {
        sum = 0;
        times.resize(size_min);
        std::fill(times.begin(), times.end(), 2);
        
        for (int i = 0; i < repetitions; i++) {
            // std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";
            auto start = std::chrono::steady_clock::now();
            //================================================================================
            sa::lsearch(&times[0], &times.back(), 0);
            //================================================================================
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            // std::cout << ">>> ENDING computation that needs timing <<<\n";

            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double> diff = end - start;

            sum += std::chrono::duration <double, std::milli> (diff).count();
        }

        average = sum/repetitions;
        // Milliseconds (10^-3)
        lin << size_min << "\t" << average << std::endl;
        size_min += 20000;
        
        // tim << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        //     << " ms" << std::endl;
    }

    // =====================================Binary search (iterative)=====================================
    std::ofstream ite( "bs_iterative.txt" );
    size_min = 10000;
    while (size_min < size_max) {
        sum = 0;
        times.resize(size_min);
        std::fill(times.begin(), times.end(), 2);
        
        for (int i = 0; i < repetitions; i++) {
            // std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";
            auto start = std::chrono::steady_clock::now();
            //================================================================================
            sa::bsearch(&times[0], &times.back(), 0);
            //================================================================================
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            // std::cout << ">>> ENDING computation that needs timing <<<\n";

            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double> diff = end - start;

            sum += std::chrono::duration <double, std::milli> (diff).count();
        }

        average = sum/repetitions;
        // Milliseconds (10^-3)
        ite << size_min << "\t" << average << std::endl;
        size_min += 20000;
        
        // tim << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        //     << " ms" << std::endl;
    }

    // =====================================Binary search (recursive)=====================================
    std::ofstream rec( "bs_recursive.txt" );
    size_min = 10000;
    while (size_min < size_max) {
        sum = 0;
        times.resize(size_min);
        std::fill(times.begin(), times.end(), 2);
        
        for (int i = 0; i < repetitions; i++) {
            // std::cout << ">>> STARTING computation that needs timing, please WAIT.... <<<\n";
            auto start = std::chrono::steady_clock::now();
            //================================================================================
            sa::bsearch_rec_aux(&times[0], &times.back(), 0);
            //================================================================================
            std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
            // std::cout << ">>> ENDING computation that needs timing <<<\n";

            //Store the time difference between start and end
            // auto diff = end - start;
            std::chrono::duration<double> diff = end - start;

            sum += std::chrono::duration <double, std::milli> (diff).count();
        }

        average = sum/repetitions;
        // Milliseconds (10^-3)
        rec << size_min << "\t" << average << std::endl;
        size_min += 20000;
        
        // tim << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count()
        //     << " ms" << std::endl;
    }

    // >>>>>>>>  Put the code that needs timing here  <<<<<<<<<<<< //
    // typedef  int test_t; // The testing type for increment.
    // int a{1};
    // for ( test_t i=std::numeric_limits<test_t>::min() ; i < std::numeric_limits<test_t>::max() ; ++i )
    // for ( unsigned long long j{0} ; j < std::numeric_limits<unsigned long long>::max() ; ++j )
    // for ( unsigned long long j{0} ; j < std::numeric_limits<unsigned long long>::max() ; ++j )
    //     a *= 2;

    // Nanoseconds (10^-9)
    // std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count()
    //     << " ns" << std::endl;

    // Seconds
    // auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    // std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;

    // return EXIT_SUCCESS;
    lin.close();
    ite.close();
    rec.close();
}
