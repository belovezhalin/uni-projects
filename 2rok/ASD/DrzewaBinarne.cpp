#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int i, L;
    cin >> i >> L;
    
    vector<pair<int, int>> intervals;
    int start = pow(2, L - 1);
    int end = pow(2, L) - 1;
    
    int currentStart = -1;
    
    for(int N = start; N <= end; N++) {
        int p = 0, q = N - 1, mid;
        int steps = 0;
        
        while(p <= q) {
            mid = (p + q) / 2;
            steps++;
            
            if(mid == i) break;
            
            if(i < mid) q = mid - 1;
            else p = mid + 1;
        }
        
        if(steps == L) {
            if(currentStart == -1) currentStart = N;
        } 
        else {
            if(currentStart != -1) {
                intervals.push_back({currentStart, N - 1});
                currentStart = -1;
            }
        }
    }
    
    if(currentStart != -1) {
        intervals.push_back({currentStart, end});
    }
    
    if(intervals.empty()) {
        cout << 0 << endl;
    } 
    else {
        cout << intervals.size() << endl;
        for(auto &interval : intervals) {
            cout << interval.first << " " << interval.second << endl;
        }
    }
    
    return 0;
}
