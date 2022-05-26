/**\file
 * \brief
 * Array operations class declaration
 * @version 26.05.2022
 * @author João Pedro Carvalho de Souza
 */

#ifndef STD_VECTOR_COMPLEMENT_ARR_OPERATION_H
#define STD_VECTOR_COMPLEMENT_ARR_OPERATION_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <numeric>
#include <sstream>

#define MSG_PREFIX "<StdVectorComplement> "

#ifndef NDEBUG
#define DEBUG_MSG(str) do { std::cout << "\033[;33m" << MSG_PREFIX << str << "\033[0m"<< std::endl; } while( false )
#else
#define DEBUG_MSG(str) do { } while ( false )
#endif

//namespace std_vector_operations {
    class StdVectorOperation {
    public:
        StdVectorOperation();

        ~StdVectorOperation();

        static bool normalizeVector(std::vector<double> &_arr, double min, double max);

        static bool normalizeVector(std::vector<double> &_arr);

        static void scalarMultiplicationToVector(std::vector<double> &_arr, double multiplier);

        static bool
        sumEachElementOfVector(std::vector<double> _arr1, std::vector<double> _arr2, std::vector<double> &_result);

        static bool
        sumEachElementOfVector(std::vector<bool> _arr1, std::vector<bool> _arr2, std::vector<bool> &_result);

        static void vectorDivisionToScalar(std::vector<double> &_arr, double multiplier);

        static bool addScalarToVector(std::vector<double> &_arr, double scalar);

       // static bool scalarDivisionToVector(std::vector<double> &_arr, double scalar);

        static bool invertEachElement(std::vector<double> &_arr);

        static double getMaximumValue(std::vector<double> _arr);

        static double getMinimumValue(std::vector<double> _arr);

        static double getAverageValue(std::vector<double> _arr);

        static double getStdDeviationValue(std::vector<double> _arr);

        static double sumAllElements(std::vector<double> _arr);

        static std::string transformToString(std::vector<double> _arr);


    };
//}

#endif //STD_VECTOR_COMPLEMENT_ARR_OPERATION_H
