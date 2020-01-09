#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val, ind;
};

int main()
{
    //freopen("deque.txt","w",stdout);
    int n, arr[100005];
    int k;

    deque<node>deq;
    int temp;

    int test;

    cin>>test;
    while(test--)
    {
        while(!deq.empty()) deq.pop_back();

        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&temp);

            if(deq.empty())
            {
               deq.push_back({temp,i});
            }

            else if(deq.back().val>temp)
            {
                deq.push_back({temp,i});
            }

            else
            {
                while(deq.back().val<temp)
                {
                    deq.pop_back();
                    if(deq.empty()) break;
                }

                deq.push_back({temp,i});
            }

            if(i - deq.front().ind >= k) deq.pop_front();

            if(i>=k) cout<<deq.front().val<<" ";

        }

        cout<<endl;
    }
}
