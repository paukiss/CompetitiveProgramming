#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n, c = 0, r = 0, trace = 0;     cin >> n;
        vector< vector<int> > v(n, vector<int> (n,4));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
                if (i == j) trace += v[i][j];
            }   
        }

        for (int i = 0; i < n; i++)
        {
            set<int> s;
            for (int j = 0; j < n; j++)
                s.insert(v[i][j]);
            if (s.size() != n)
                r += 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            set<int> s;
            for (int j = 0; j < n; j++)
                s.insert(v[j][i]);
            if (s.size() != n)
                c += 1;
        }
        
        cout << "Case #" << k <<": " << trace << " " << r << " " << c << "\n";
    }
}