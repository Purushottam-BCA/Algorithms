// In a non decreasing sorted array find the last index of an element
// If Array = {5,8,10,10,10,10,10,18,24,65,90,100} and Element = 10 then last Index = 5


int last_occurance(int a[], int array_size, int item)   
{
    int low=0,high=array_size-1;
    int mid,res=-1;
    while(low<=high)
    {
        mid=low + (high-low)/2;
        if(a[mid]==item)
        {
            res = mid;
            low = mid+1;   // if A[mid] matches with element then search in right only 
        }
        else if(a[mid]>item)
            high = mid-1;
        else
            low =  mid+1;
    }
    return res;
}
