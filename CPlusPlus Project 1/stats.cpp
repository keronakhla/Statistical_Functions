#include <algorithm>
#include <cmath>

#include "stats.h"

using namespace std;

/* Function returns the average of the numbers in v */
double mean(vector<double> v) {
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    double sum = 0; /* The sum of all numbers in v */
    double meanValue; /* The average of the numbers in v */
    
    /* Calculate the sum of all numbers */
    for (int i = 0; i < numOfNumbers; i++) {
        sum += v[i];
    }
    
    meanValue = sum / numOfNumbers; /* Calculate the average */
    
    return meanValue;
}

/* Function returns the median of the numbers in v */
double median(vector<double> v) {
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    double medianValue; /* The median of the numbers in v */
    
    sort(v.begin(), v.end()); /* Sort the numbers in v in the ascending order */
    if (numOfNumbers % 2) { /* If the number of numbers in v is odd */
        medianValue = v[numOfNumbers / 2];
    } else { /* If the number of numbers in v is even */
        medianValue = (v[numOfNumbers / 2 - 1] + v[numOfNumbers / 2]) / 2;
    }
    
    return medianValue;
}

/* Function returns the variance of the numbers in v */
double variance(vector<double> v) {
    double meanValue = mean(v); /* Calculate the mean of v */
    double sum = 0;
    double varianceValue; /* The variance of the numbers in v */
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    
    for (int i = 0; i < numOfNumbers; i++) {
        sum += (v[i] - meanValue) * (v[i] - meanValue);
    }
    varianceValue = sum;
    if (numOfNumbers > 1) {
        varianceValue = sum / (numOfNumbers - 1);
    }
    
    return varianceValue;
}

bool cmp(double v1, double v2) {
    return v1 > v2;
}

/* Function returns the mode of the numbers in v */
vector<double> mode(vector<double> v) {
    vector<double> modeVector; /* The mode of the numbers in v */
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    
    sort(v.begin(), v.end(), cmp); /* Sort the numbers in v in the descending order */
    modeVector.push_back(v[0]);
    for (int i = 1; i < numOfNumbers && v[i] == v[i - 1]; i++) {
        modeVector.push_back(v[i]);
    }
    
    return modeVector;
}

/* Function returns a vector of moving averages with a window of length n */
vector<double> move_avg(vector<double> v, int n) {
    vector<double> moveAvgVector; /* Vector of moving averages */
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    
    for (int i = 0; i < numOfNumbers - n + 1; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += v[i + j];
        }
        moveAvgVector.push_back(sum / n);
    }
    
    return moveAvgVector;
}

/* Function returns the average of the numbers remaining after the smallest f * N
 * numbers and the largest f * N numbers are discarded */
double trim_mean(vector<double> v, double f) {
    int numOfNumbers = (int) v.size(); /* Number of numbers in v */
    int numOfDiscarded;
    double sum = 0;
    double trimMeanValue;
    
    sort(v.begin(), v.end()); /* Sort the numbers in v in the ascending order */
    numOfDiscarded = (int) floor(f * numOfNumbers + 0.000001);
    
    for (int i = numOfDiscarded; i < numOfNumbers - numOfDiscarded; i++) {
        sum += v[i];
    }
    trimMeanValue = sum / (numOfNumbers - numOfDiscarded * 2);
    
    return trimMeanValue;
}
