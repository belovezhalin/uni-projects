#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

struct Edge {
    int u, v, apples;
};

bool compareEdges(const Edge &e1, const Edge &e2) {
    return e1.apples > e2.apples;
}

int find(vector<int> &parent, int i) {
    if(parent[i] == i) return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } 
    else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } 
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<Edge> edges(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].apples;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(N+1), rank(N+1, 0);
    iota(parent.begin(), parent.end(), 0);

    int totalApples = 0;
    int edgesTaken = 0;

    for(const auto &edge : edges) {
        if(edgesTaken >= Q) break;

        int u = edge.u, v = edge.v;
        int setU = find(parent, u);
        int setV = find(parent, v);

        if(setU != setV) {
            unionSets(parent, rank, setU, setV);
            totalApples += edge.apples;
            edgesTaken++;
        }
    }

    cout << totalApples << endl;
    return 0;
}
