// an array of characters is given. find the next element of given target which is available in the array .
// In case the element is not available then return 0


char Find_next_char(char ar[],int size,char ch)
{
    int low=0,high=size-1;
    int index=-1;
    while(low<=high)
    {
        int mid=low + (high-low)/2;
        if(ar[mid]<=ch)
            low = mid+1;
        else if(ar[mid]>ch)
        {
            index=mid;
            high = mid-1;
        }
    }
    return (index=='0'?index:ar[index]);
}

int main()
{
   char ch;
   cin>>ch;
   char ar[]{'A','C','D','F','H','I','J','M','P'};
   int size = len(ar);
   cout<<Find_next_char(ar,size,ch);
   return 0;
}
