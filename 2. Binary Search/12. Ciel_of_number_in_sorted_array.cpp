// Find the Ciel of an integer Target in sorted array.
// Ciel means if the number is available then return the number itself 
// But in case number is not available then return the smallest number bigger than Target

// Ex:-  [ 1, 4 , 5, 9 ,14 , 17, 24, 39,91,104]
// Target = 14    Answer = 14
// Target = 26    Answer = 39

int CielOfElement(int a[], int size,int item)
{
    int low=0, high =size-1;
    int index = -1;
    while(low<=high)
    {
        int mid = low +(high-low)/2;
        if(a[mid]==item)
            return a[mid];
        else if(a[mid]<item)
            low = mid+1;
        else if(a[mid]>item)
        {
            index = mid;
            high = mid-1;
        }
    }
    return a[index];
}
