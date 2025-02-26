//Anhelina Belavezha
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<double>> wstegi;
vector<double> inputvector;
vector<double> VY;
int n, m;
double w;

inline void solve(vector <double>& cur) {
    for (int i = 0; i < n; i ++) {
        double S = 0.0;
        vector <pair <double, double> > temp;
        for (int j = max(0, m - i); j <= m; j ++) {
            if (i - (m - j) >= 0) temp.push_back({wstegi[j][i - (m - j)], i - (m - j)});
        }
        for (int j = m - 1; j >= 0; j --) {
            if (i + (m - j) < n) temp.push_back({wstegi[j][i], i + (m - j)});
        }
        for (auto it : temp) {
            S += it.first * cur[it.second];
        }
        cur[i] = cur[i] + w * (VY[i] - S) / wstegi[m][i];
    }
}

int main() {
    int L;
    double input;
    
    vector<double> VX;
    
    cin >> n >> m;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j < (n - (m - i)); ++j) {
            cin >> input;
            inputvector.push_back(input);
        }

        wstegi.push_back(inputvector);
        inputvector.clear();
    }
    
    for(int i = 0; i < n; ++i) {
        cin >> input;
        VY.emplace_back(input);
    }
    
    for(int i = 0; i < n; ++i) {
        cin >> input;
        VX.emplace_back(input);
    }

    cin >> w >> L;

    while (L --) {
        solve(VX);
    }

    for(int i = 0; i < VX.size(); ++i) {
        cout << fixed << setprecision(16) << VX[i] << '\n';
    }
}