
#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}

int main()
{
    vector<string>v;
    bool check;
    int n;
    int test;
    cin>>test;
    for(int t=0;t<test;t++)
    {
        v.clear();
        check = true;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            v.push_back(s);
        }

        for(int i=0;i<n;i++)
        {
            sort(v[i].begin(), v[i].end());
        }

        //for(int i=0;i<n;i++) cout<<v[i]<<endl;

        for(int i=1;i<n;i++)
        {

            if(v[i][0]<v[i-1][0])
            {
                check = false;
                break;
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][j]<v[i-1][j])
                {
                    check = false;
                    break;
                }
            }

            if(check==false) break;
        }

       if (check==true) cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
}

