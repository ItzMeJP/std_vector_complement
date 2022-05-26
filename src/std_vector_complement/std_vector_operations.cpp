/**\file
 * \brief
 * Array operations class definition
 * @version 26.05.2022
 * @author João Pedro Carvalho de Souza
 */

#include "std_vector_operations.h"

//namespace std_vector_operations {

    // Description: get the the normalized vector. The normalization is between the specified minimum and maximum values and the score range is [0,1].
    bool StdVectorOperation::normalizeVector(std::vector<double> &_arr, double min, double max){
        if(max == min)
            return false;

        std::vector<double> norm_arr;

        for (size_t i = 0; i <_arr.size(); ++i) {
            norm_arr.push_back((_arr[i] - min) / (max - min));
        }

        _arr.clear();
        _arr.swap(norm_arr);

        return true;

    }

    // Description: get the normalized vector. The normalization is between minimum and maximum value in the array and the score range is [0,1].
    bool StdVectorOperation::normalizeVector(std::vector<double> &_arr){

        double min = (double)*std::min_element(_arr.begin(), _arr.end());
        double max = (double)*std::max_element(_arr.begin(), _arr.end());

        return normalizeVector(_arr, min, max);
    }

    // Description: multiply each element of a vector by a scalar
    void StdVectorOperation::scalarMultiplicationToVector(std::vector<double> &_arr, double multiplier){
        std::transform(_arr.begin(), _arr.end(),
                       _arr.begin(),  std::bind(std::multiplies<double>(), std::placeholders::_1, multiplier));
    }

    // Description: divides each element of a vector by a scalar
    void StdVectorOperation::vectorDivisionToScalar(std::vector<double> &_arr, double multiplier){
        std::transform(_arr.begin(), _arr.end(),
                       _arr.begin(), std::bind(std::divides<double>(), std::placeholders::_1, multiplier));
    }

    // Description: sums two vectors point a point
    bool StdVectorOperation::sumEachElementOfVector(std::vector<double> _arr1, std::vector<double> _arr2, std::vector<double> &_result){

        if(_arr1.size() != _arr2.size())
            return false;

        _result = _arr1;
        std::transform (_result.begin(), _result.end(), _arr2.begin(), _result.begin(), std::plus<double>());
        return true;

    }

    // Description: sums two vectors point a point
    bool StdVectorOperation::sumEachElementOfVector(std::vector<bool> _arr1, std::vector<bool> _arr2, std::vector<bool> &_result){

        if(_arr1.size() != _arr2.size())
            return false;

        _result = _arr1;
        std::transform (_result.begin(), _result.end(), _arr2.begin(), _result.begin(), std::plus<bool>());
        return true;

    }

    // Description: add a scalar to each element of a vector
    bool StdVectorOperation::addScalarToVector(std::vector<double> &_arr, double scalar){
        std::transform(_arr.begin(), _arr.end(), _arr.begin(), std::bind(std::plus<double>(), std::placeholders::_1, scalar));
        return true;
    }

    /*deprecated
    bool StdVectorOperation::scalarDivisionToVector(std::vector<double> &_arr, double scalar) {
        //transform (_arr.begin(), _arr.end(),_arr.begin(), std::bind(std::divides<double>(), std::placeholders::_1, scalar));
        return true;
    }
     */

    bool StdVectorOperation::invertEachElement (std::vector<double> &_arr) {

        for (size_t i = 0; i < _arr.size(); ++i) {
            _arr.at(i) == 0? _arr.at(i) = NAN : _arr.at(i) = 1/_arr.at(i);
        }
        return true;
    }

    double StdVectorOperation::getMaximumValue(std::vector<double> _arr){
        return (double)*std::max_element(_arr.begin(), _arr.end());
    }

    double StdVectorOperation::getMinimumValue(std::vector<double> _arr){
        return (double)*std::min_element(_arr.begin(), _arr.end());
    }

    double StdVectorOperation::getAverageValue(std::vector<double> _arr){
        double sum = sumAllElements(_arr);
        return sum/_arr.size();
    }

    double StdVectorOperation::getStdDeviationValue(std::vector<double> _arr){

        double mean = getAverageValue(_arr);

        std::vector<double> diff(_arr.size());
        std::transform(_arr.begin(), _arr.end(), diff.begin(), [mean](double x) { return x - mean; });

        double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);

        return std::sqrt(sq_sum / (_arr.size()-1));
    }

    double StdVectorOperation::sumAllElements(std::vector<double> _arr){
        return std::accumulate(_arr.begin(), _arr.end(), 0.0);
    }

    std::string StdVectorOperation::transformToString(std::vector<double> _arr){

        std::stringstream ss;

        if(_arr.empty())
            return "Empty Vector";

        ss << "[";
        for (size_t i = 0; i < _arr.size()-1; ++i) {
            ss << _arr.at(i) << ", ";
        }
        ss << _arr.back() << "]";

        return ss.str();


    }




//} /* namespace std_vector_operations */