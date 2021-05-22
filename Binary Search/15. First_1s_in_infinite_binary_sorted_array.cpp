// An infinite binary sorted array is given , Find the index of 1st ONE in the array.
// Infinite binary sorted array means "ALL 0s comes before ALL 1s"
// Ex:-  [0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,,1,1,1]

int infinite_binary_sorted(int a[])
{
    int low=0,high=1,index=-1;
    while(!a[high]) // Till it is 0 or False
    {
        low=high;
        high *=2;
    }

    while(low<=high)
    {
        int mid=low +(high-low)/2;
        if(a[mid])  // if it is 1 or True then go left to find more
        {
         index=mid;
         high = mid-1;
        }
        else        // If false then no need to go to 1st half so go directly to 2nd half
         low =  mid+1;
    }
    return index;
}

int main()
{
  int d[]{0,0,1,1,1,1,1,1};
  cout<<infinite_binary_sorted(d);
return 0;
}
