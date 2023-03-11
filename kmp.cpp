#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(char *pat, int M, int *lps);

vector<int32_t> cc;
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);


    int lps[M];


    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cc.push_back(i - j);
            j = lps[j - 1];
        }


        else if (i < N && pat[j] != txt[i])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}


void computeLPSArray(char *pat, int M, int *lps)
{

    int len = 0;

    lps[0] = 0; 


    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
          
            if (len != 0)
            {
                len = lps[len - 1];

                
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int main()
{
    char txt[1000009];
    char pat[1000009];
    cin >> pat >> txt;
    KMPSearch(pat, txt);
    cout << cc.size() << endl;
    for(int32_t x : cc) cout << x + 1 << " ";
    return 0;
}