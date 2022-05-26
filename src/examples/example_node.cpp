/**\file
 * \brief
 * Example node using the std vector complement API
 * @version 26.05.2022
 * @author João Pedro Carvalho de Souza
 */

#include "std_vector_operations.h"


int main(){


    std::vector<double> arr{0,1,1,2,3,3}, arr_copy, result;
    arr_copy = arr;

    std::cout << "Input Vector: " << StdVectorOperation::transformToString(arr) <<std::endl;

    StdVectorOperation::normalizeVector(arr);
    std::cout << "Normalized Vector: " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;

    StdVectorOperation::scalarMultiplicationToVector(arr, 2);
    std::cout << "Vector Elements x2: " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;


    StdVectorOperation::sumEachElementOfVector(arr,arr,result);
    std::cout << "Vector + Vector: " << StdVectorOperation::transformToString(result)<<std::endl;

    
    StdVectorOperation::vectorDivisionToScalar(arr, 2);
    std::cout << "Vector Elements /2: " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;
    
    StdVectorOperation::addScalarToVector(arr, 1);
    std::cout << "Vector Elements +1: " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;

/* Deprecated
    StdVectorOperation::scalarDivisionToVector(arr,9);
    std::cout << "9 / Vector Elements: " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;
*/
    StdVectorOperation::invertEachElement(arr);
    std::cout << "Each Element Inverted " << StdVectorOperation::transformToString(arr)<<std::endl;
    arr = arr_copy;

    std::cout << "Vector Max Value: " << StdVectorOperation::getMaximumValue(arr)<<std::endl;

    std::cout << "Vector Min Value: " << StdVectorOperation::getMinimumValue(arr)<<std::endl;

    std::cout << "Vector Avg Value: " << StdVectorOperation::getAverageValue(arr)<<std::endl;

    std::cout << "Vector Std Dev Value: " << StdVectorOperation::getStdDeviationValue(arr)<<std::endl;

    std::cout << "Vector accumulation: " << StdVectorOperation::sumAllElements(arr)<<std::endl;




    return 0;

}
