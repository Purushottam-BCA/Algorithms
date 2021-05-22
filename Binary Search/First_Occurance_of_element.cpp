// In a non decreasing sorted array find the starting index of an element
// If Array = {5,8,10,10,10,10,10,18,24,65,90,100} and Element = 10 then Starting Index = 2

int first_occurance(int a[],int array_size,int item)   
{
    int low=0,high=array_size-1;
    int mid,res=-1;
    while(low<=high)
    {
        mid=low + (high-low)/2;
        if(a[mid]==item)
        {
            res = mid;
            high = mid-1;   // if A[mid] element matches with element then search in left only to check other strating index
        }
        else if(a[mid]>item)
            high = mid-1;
        else
            low =  mid+1;
    }
    return res; 
}
