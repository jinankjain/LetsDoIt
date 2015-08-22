#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

#define sz 1000002

/******   start your code   *******/

class runner
{
public:
    int res;
    bool key;
};
char L1[sz];
char L2[sz];
int main()
{
    int T,i,j,result;
    runner a,b;
    bool flag;
    sf("%d",&T);
    getchar();
    while(T--)
    {
       gets(L1);
       gets(L2);
       a.res=b.res=0;
       flag=true;
       a.key=true;
       b.key=true;
       for(i=0;L1[i];i++)
       {
           if(a.key==true)
           {
               if(L1[i]=='#')
               {
                   if(L2[i]=='#')
                   {
                       flag=false;
                   }
                   else
                   {
                       a.key=false;
                       a.res++;
                   }
               }
           }
           else
           {
               if(L2[i]=='#')
               {
                   if(L1[i]=='#')
                   {
                       flag=false;
                   }
                   else
                   {
                       a.key=true;
                       a.res++;
                   }
               }
           }
           if(b.key==true)
           {
              if(L2[i]=='#')
               {
                   if(L1[i]=='#')
                   {
                       flag=false;
                   }
                   else
                   {
                       b.key=false;
                       b.res++;
                   }
               }
           }
           else
           {
               if(L1[i]=='#')
               {
                   if(L2[i]=='#')
                   {
                       flag=false;
                   }
                   else
                   {
                       b.key=true;
                       b.res++;
                   }
               }
           }
           if(flag==false)break;
       }
       if(flag==true)
       {
           if(a.res<=b.res)result=a.res;
           else
            result=b.res;
           pf("Yes\n%d\n",result);
       }
       else
        pf("No\n");
    }
    return 0;
}
