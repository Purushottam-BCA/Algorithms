// A sorted array is given. You have to return the element with whom Target value will make minimum difference.

// Ex:- 1 11 19 24 36 39 40 51 62     ||  Key=7 ~ Output=11 because [(11-7)<(7-1) AND (11-7)<(19-7)]
// Ex:- 5,8,11,12,15,18,21,40,90,120,124,144,592,635,1024,1365,2000     || Key=1000 ~ Output=1024
// Ex:- 1 11 19 24 36 39 40 51 62     ||  Key=24 ~ Output=24

// Tips :- In binary search , if Given target value  is found then A[Mid] point to the target value.
// but if the target is not found then A[low] Point to the right Neighbour and A[high] will point to the Left Neighbour. [ALWAYS]

//################## Approach-1 ( Direct Differnce) #####################

int min_diff_element_in_sorted_array(int a[],int size,int item)
{
    int low=0, high=size-1;
    int diff;
    while(low<=high)
    {
        int mid=low + (high-low)/2;
        if(abs(a[mid]-item)<=abs(a[mid+1]-item) && abs(a[mid]-item)<=abs(a[mid-1]-item))
            return a[mid];
        else if(abs(a[mid]-item)>abs(a[mid-1]-item))
            high = mid-1;
        else if(abs(a[mid]-item)>abs(a[mid+1]-item))
            low=mid+1;
    }
    if(item<0)
        return a[low];  // Right Neighbour
    else
        return a[high]; // Left neighbour
}

// ####################### Approach-2 'TOO LONG' ##########################

int min_diff_element_in_sorted_array2(int a[],int size,int item)
{
    int low=0, high=size-1;
    while(low<=high)
    {
        int mid=low + (high-low)/2;
        if(a[mid]-item==0)
            return item;
        else if((a[mid]<=item && a[mid+1]>=item && mid<=high-1))
        {
            int diff1=abs(a[mid]-item);
            int diff2=abs(a[mid+1]-item);
            return (diff1<=diff2?a[mid]:a[mid+1]);
        }
        else if (a[mid]>=item && a[mid-1]<=item && mid>=low+1)
        {
            int diff1=abs(a[mid]-item);
            int diff2=abs(a[mid-1]-item);
            return (diff1<=diff2?a[mid]:a[mid-1]);
        }
        else if(item<a[mid])
            high = mid-1;
        else if(item>a[mid])
            low=mid+1;
    }
    if(item<0)
        return a[low];
    else
        return a[high];
}

// ############################# Approach-3 'BEST' ############################

int min_diff_element_in_sorted_array(int a[],int size,int item)
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid=low +(high-low)/2;
        if(a[mid]==item)
            return item;
        else if(a[mid]>item)
            high = mid-1;
        else
            low =  mid+1;
    }
    int diff1=abs(a[low]-item);
    int diff2=abs(a[high]-item);
    return (diff1<=diff2?a[low]:a[high]);
}

// ----------------------- Main Function ----------------------

int main()
{
  int item;
  cin>>item;
  int c[]{5,8,11,12,15,18,21,40,90,120,124,144,592,635,1024,1365,2000};
  int size=sizeof(c)/sizeof(c[0]);
  cout<<min_diff_element_in_sorted_array(c,size,item);
  return 0;
}
