#include <iostream>
#include <vector>

using namespace std;

int lps(string s)
{
    vector<vector<int>> strg(s.size(), vector<int>(s.size(), 0));
    for (int gap = 0; gap < strg[0].size(); gap++)
    {
        for (int i = 0, j = i + gap; j < strg.size(); i++, j++)
        {
            if (gap == 0)
            {
                strg[i][j] = 1;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    strg[i][j] = 2;
                else
                {
                    strg[i][j] = 1;
                }
            }
            else
            {
                if (s[i] == s[j])
                {
                    strg[i][j] = 2 + strg[i + 1][j - 1];
                }
                else
                    strg[i][j] = max(strg[i][j - 1], strg[i + 1][j]);
            }
        }
    }

    return strg[0][strg.size()-1];
}

int main()
{
  string s= "ab";
 int t= lps(s);
 cout<<t;


}
