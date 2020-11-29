#include <bits/stdc++.h>
#include "beadslib.h"
using namespace std;
int n,m;
int curpos[300001];
vector<int> swapper[300001];
vector<int> pos[300001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        curpos[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int s;
        cin >> s;
        int fs=curpos[s];
        int se=curpos[s+1];
        swapper[fs].push_back(i+1);
        swapper[se].push_back(i+1);
        pos[fs].push_back(s+1);
        pos[se].push_back(s);
        swap(curpos[s],curpos[s+1]);
    }
    int q = getNumQuestions();
    for(int i=0;i<q;i++)
    {
        int k,j;
        getQuestion(k,j);
        int rez=k;
        int ind=upper_bound(swapper[k].begin(),swapper[k].end(),j)-swapper[k].begin();
        if(ind)
        {
            ind--;
            rez=pos[k][ind];
        }
        answer(rez);
    }
    return 0;
}
