#include <iostream>
#include <vector>
#include <map>

using namespace std;

int cubic_mss(const vector<int> &list) {
    int maxSum = 0;
    for (int i = 0; i < list.size(); ++i) {
        for (int j = i; j < list.size(); ++j) {
            int thissum = 0;
            for (int k = i; k <= j; ++k) {
                thissum = thissum + list[k];
            }
            if (thissum > maxSum) {
                maxSum = thissum;
            }
        }
    }
    return maxSum;
}


int quadratic_mss(const vector<int> &list) {
    int maxSum = 0;
    for (int i = 0; i < list.size(); i++) {
        int thisSum = 0;
        for (int j = i; j < list.size(); j++) {
            thisSum = thisSum + list[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/**

maxSum = 0
thisSum = 0
for i=1 to n do
    thisSum = thisSum + ai
    if thisSum > maxSum then
        maxSum = thisSum
    else if thisSum < 0 then
        thisSum = 0
return maxSum

 */

int linear_mss(const vector<int> &list) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 0; i < list.size(); i++) {
        thisSum = thisSum + list[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

map<vector<int>, int> createTestdata() {
    static const map<vector<int>, int> testDataMap{
            {{1,  2,   -30, 4, 5}, 9},
            {{5,  9,   -12, 1, 6}, 14},
            {{8,  2,   100, 7, 2}, 119},
            {{99, -12, -30, 0, 6}, 99},
            {{0,  0,   0,   0, 0}, 0}
    };
    return testDataMap;
}

int main() {
    static const map<vector<int>, int> testData = createTestdata();
    for (const pair<vector<int>, int> testSet : testData) {
        int mss1 = cubic_mss(testSet.first);
        int mss2 = quadratic_mss(testSet.first);
        int mss3 = linear_mss(testSet.first);
        cout << "Test result cubic: " << mss1 << endl;
        cout << "Test result quadratic: " << mss2 << endl;
        cout << "Test result linear: " << mss3 << endl;
        assert(mss1 == testSet.second);
        assert(mss2 == testSet.second);
        assert(mss3 == testSet.second);
    }
    return 0;
}


