#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,n;
    stack<char>st;


    int test;
    cin>>test;
    getline(cin,n);
    while(test--)
    {
        bool check = true;

        getline(cin,s);

        if(s.size()==0)
        {
            cout<<"YES"<<endl;
            continue;
        }

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')' or s[i]=='}' or s[i]==']')
            {
                if(st.empty())
                {
                    check = false;
                    cout<<"NO"<<endl;
                    break;
                }
            }

            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
            {
                st.push(s[i]);
            }

            if(s[i]=='}' and st.top()!='{')
            {
                //cout<<"{}"<<endl;
                check = false;
                cout<<"NO"<<endl;
                break;
            }

            if(s[i]==')' and st.top()!='(')
            {
                //cout<<"()"<<endl;
                check = false;
                cout<<"NO"<<endl;
                break;
            }

            if(s[i]==']' and st.top()!='[')
            {
                check = false;
                cout<<"NO"<<endl;
                break;
            }

            if((s[i]==')' and st.top()=='(') or (s[i]=='}' and st.top()=='{') or (s[i]==']' and st.top()=='['))
            {
              st.pop();
            }


        }

        if(!st.empty() and check==true) cout<<"NO"<<endl;
        else if(check==true) cout<<"YES"<<endl;
        while(!st.empty())
        {
            st.pop();
        }
    }

}
