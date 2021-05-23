// In a given sorted infinite array find the element index.
// Infinite array means we don't know the size of array and number of element in the array

int find_element_in_infinite_array(int a[], int item)
{
    int low=0, high=1;
    while(a[high]<item)
    {
        low=high;
        high*=2;
    }
  // Apply Binary Search here
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
    return -1;
}


int main()
{
   int item;
   cin>>item;
   int c[]{1,2,5,8,11,12,15,18,21,40,90,120,124,144,592,635,1024,1365,2000}; // Practically it is not possible to denote infinite array
   cout<<find_element_in_infinite_array(c,item);
}
