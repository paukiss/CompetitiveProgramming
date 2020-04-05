#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;  cin >> t;
    for (int k = 1; k <= t; k++)
    {
        string cad; cin >> cad;
        vector <string> v;

        for (int i = 0, k = 0; i < cad.size(); i++)
        {   
            string res = "";
            for (int j = i; j < cad.size(); j++, k++)
            {
                if (cad[i] != cad[j])
                    break;                
                res += cad[i];
            }
            v.push_back(res);
            i += k - 1 ; k = 0;
        }
        stack <char> s;
        for (int i = 0; i < v.size(); i++)
        {
            int mul = int(v[i][0]-'0');
            string open(mul, '('), close(mul, ')');
            v[i] = open + v[i] + close ;
        } 
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < v[i].size(); j++)
                s.push(v[i][j]);
        
        stack <char> aux;   aux.push(s.top());
        s.pop();
        while(!s.empty())
        {   
            if (aux.top() == s.top())
                aux.push(s.top()), s.pop();  
            else
            {
                if (!isdigit(aux.top()) && !isdigit(s.top()))
                    aux.pop(), s.pop();
                else
                    aux.push(s.top()), s.pop();
            }
        }
        cout << "Case #" << k << ": ";
        while (!aux.empty())
        {
            cout << aux.top(), aux.pop();
        }
        
        puts("");
    }
}