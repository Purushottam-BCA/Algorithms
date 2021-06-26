#include<bits/stdc++.h>
using namespace std;

#define ar(i,n) for(int i=0;i<n;i++)
#define ard(i,n) for(int i=n-1;i>=0;--i)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define nl cout<<"\n"
#define len(a) sizeof(a)/sizeof(a[0])

int main()
{
   int a[]={7,10,4,3,20,15,6};
   int k=2;
   int sizeArray = len(a);
   priority_queue<int> maxH; // Build Max Heap
   for(int i=0;i<sizeArray;i++)
   {
      maxH.push(a[i]);
      if(maxH.size()>k) // When Size>k
         maxH.pop();
   }
   cout<<maxH.top();
   return 0;
}

// TIME - O(nlogk)
