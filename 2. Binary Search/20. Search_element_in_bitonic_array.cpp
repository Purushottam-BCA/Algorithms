// Search an elemnet in bitonic array and if element is present then return its index else return -1.

// STEP-1 : Find the index of Peak element.
// STEP-2 : IF A[index] = ITEM then return index
// STEP-3 : Search ITEM via normal binary search on A[0] to A[index-1] ; If found then return index
// STEP-4 : Search ITEM via Decsending Binary search from A[index] to A[n-1] ; if found then return index else return -1

int search_element_in_bitonic_array(const vector<int> &a,int &item)
{
    int low=0, high=a.size()-1;
    int index;
    
    // ++ Finding index of Peak element ++
    while(low<=high)
    {
        int mid=low  + (high-low)/2;
        if((mid==0 && a[mid]>a[mid+1]) ||(mid==a.size()-1 && a[mid]>a[mid-1]) || (a[mid]>a[mid-1] && a[mid]>a[mid+1]))
            {
                index=mid;
                break;
            }
        else if(a[mid]<a[mid-1])
            high=mid-1;
        else if(a[mid]<a[mid+1])
            low=mid+1;
    }
  
    if(a[index]==item) return index;  //  If Item == A[index] Then return from here. 
  
    // Search in Increasing order (1st Half)
    low=0, high=index-1;
    while(low<=high)
      {
        int mid=low +(high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            high = mid-1;
        else
            low =  mid+1;
       }
    
    // If item is Not avialble in 1st half then Search in descreasing order (2nd Half)
    low=index, high=a.size()-1;
    while(low<=high)
       {
        int mid=low +(high-low)/2;
        if(a[mid]==item)
            return mid;
        else if(a[mid]>item)
            low =  mid+1;
        else
            high =mid-1;
       }
    return -1;  // Incase element is not present in the array then return -1
}


int main()
{
  int item;
  cin>>item;
  vector<int>num={2,6,9,15,42,35,28,19,1};
  cout<<search_element_in_bitonic_array(num,item);
  return 0;
}
