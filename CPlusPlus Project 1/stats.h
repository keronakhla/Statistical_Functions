#include <vector>

using namespace std;

/* Function returns the average of the numbers in v */
double mean(vector<double>);

/* Function returns the median of the numbers in v */
double median(vector<double>);

/* Function returns the variance of the numbers in v */
double variance(vector<double>);

/* Function returns the mode of the numbers in v */
vector<double> mode(vector<double>);

/* Function returns a vector of moving averages with a window of length n */
vector<double> move_avg(vector<double>, int);

/* Function returns the average of the numbers remaining after the smallest f * N
 * numbers and the largest f * N numbers are discarded */
double trim_mean(vector<double>, double);
