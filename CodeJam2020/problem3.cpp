#include <bits/stdc++.h>

using namespace std;

struct hora
{
    int s, e;
    char c;
};

bool ord(hora a, hora b)
{
    if (a.s < b.s)
        return true;
    return false;
}
int main()
{
    int t;  cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;     cin >> n;  
        vector <hora> v(n), aux;
        for (int i = 0; i < n; i++)
            cin >> v[i].s >> v[i].e, v[i].c = '0';

        
        aux = v;
        sort(v.begin(), v.end(), ord);
        
        v[0].c = 'C';
        v[1].c = 'J';
        for (int i = 2; i < n ; i++)
        {
            if (v[i-1].c == 'C')
            {
                int j;
                for (j = i - 1; j >= 0 ; j--)
                    if (v[j].c == 'J')
                        break;    
                if (v[j].e <= v[i].s)
                    v[i].c = 'J';
                else if (v[i-1].e <= v[i].s)
                    v[i].c = 'C';                
            }
            else
            {
                int j;
                for (j = i - 1; j >= 0 ; j--)
                    if (v[j].c == 'C')
                        break;    
                if (v[j].e <= v[i].s)
                    v[i].c = 'C';
                else if (v[i-1].e <= v[i].s)
                    v[i].c = 'J';
            }
        }
        // puts("-555");
        // for (int i = 0; i < n; i++)
        // {
        //     cout << v[i].s << " " << v[i].e << " " << v[i].c << "\n";
        // }
        string res = "";
        int contC = 0, contJ = 0;
        for (int i = 0; i < n; i++)
        {   
            if (v[i].c == 'C')
                contC += 1;
            if (v[i].c == 'J')
                contJ += 1;
        }
  
        cout << "Case #" << k << ": ";
        if (contJ + contC == n)
        {   
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (aux[i].s == v[j].s && aux[i].e == v[j].e)
                    {
                        aux[i].c = v[j].c, v[j].s = -1, v[j].e = -1;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++)
                res += aux[i].c;
            cout << res << "\n";
        }
        else
            cout << "IMPOSSIBLE\n";
            
        
         
    }
    
}

// 5
// 99 150
// 1 100
// 100 301
// 2 5
// 150 250