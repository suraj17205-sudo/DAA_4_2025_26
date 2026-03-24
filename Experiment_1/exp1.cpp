#include <bits/stdc++.h>
#include <thread>
using namespace std;
using namespace std::chrono;

long long operations = 0;
long long recursiveCalls = 0;

void complexRec(int n, int depth, int &maxDepth) {
    recursiveCalls++;
    maxDepth = max(maxDepth, depth);

    operations++; 
    if (n <= 2) return;

    int p = n;
    operations++;

    while (p > 0) {
        operations++; 

        vector<int> temp(n);
        operations += n; 

        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations += 2; 
        }

        p >>= 1;
        operations++; 
    }

    vector<int> small(n);
    operations += n;

    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations += 2; 
    }

    reverse(small.begin(), small.end());
    operations += n; 

    complexRec(n / 2, depth + 1, maxDepth);
    complexRec(n / 2, depth + 1, maxDepth);
    complexRec(n / 2, depth + 1, maxDepth);
}

int main() {
    int maxDepth = 0;

    auto start = steady_clock::now();
    complexRec(8, 1, maxDepth);
    auto end = steady_clock::now();

    auto timeTaken = duration_cast<microseconds>(end - start).count();

    cout << maxDepth << endl;
    cout << operations << endl;
    cout << timeTaken << endl;
}

// 24BCS11025
// Recurrance relation = 3T(n/2) + nlog(n) + 3
// Time complexity = O(nlog3)  (base 2)
