// A Boolean array is given. All true appears before false then find the index of first False.
// INPUT :: A = {T, T, T, T, T, T, T, T, T, F, F, F, F, F};   
// OUTPUT :: 9

int True_false(bool a[], int array_size)     
{
    int low =0, high=array_size-1,index;
    while(low<=high)
    {
        int mid=low + (high-low)/2;
        if(a[mid])  // IF A[Mid] = true index will lie in 2nd Half 
            low=mid+1;
        else        // If A[Mid] = false the check in 1st half 
        {
            index=mid;
            high=mid-1;
        }
    }
    return index;
}
