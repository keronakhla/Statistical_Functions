#include <iostream>
#include <vector>

#include "stats.h"

using namespace std;

int main() {
    int windowLength = 3;
    double f = 0.2;
    vector<double> v;
    vector<double> modeOfV;
    vector<double> movingAverages;
    
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(11);
    v.push_back(13);
    v.push_back(5);
    v.push_back(1);
    v.push_back(0);
    
    modeOfV = mode(v);
    movingAverages = move_avg(v, windowLength);
    
    cout << "Vector v:";
    for (int i = 0; i < (int) v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl << "Mean: " << mean(v) << endl;
    cout << "Median: " << median(v) << endl;
    cout << "Variance: " << variance(v) << endl;
    cout << "Mode:";
    for (int i = 0; i < (int) modeOfV.size(); i++) {
        cout << " " << modeOfV[i];
    }
    cout << endl << "Moving averages with a window of length " << windowLength << ":";
    for (int i = 0; i < (int) movingAverages.size(); i++) {
        cout << " " << movingAverages[i];
    }
    cout << endl << "Trim mean with f = " << f << ": " << trim_mean(v, f) << endl;/**/
    
    return 0;
}
