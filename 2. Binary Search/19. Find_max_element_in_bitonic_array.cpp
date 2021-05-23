/* the array with single peek element can be called bitonic array

Given a bitonic array find the maximum value of the array. 
An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 2

Example 3:
Input: arr = [0,10,5,2]
Output: 10

Example 4:
Input: arr = [3,4,5,1]
Output: 5

Example 5:
Input: arr = [24,69,100,99,79,78,67,36,26,19]
Output: 100       */

int max_in_bitonic_array(const vector<int> &a)
{
    int low=0, high=a.size()-1;
    while(low<=high)
    {
        int mid=low  + (high-low)/2;
        if(mid==0 && a[mid]>a[mid+1])
            return a[mid];
        else if(mid==a.size()-1 && a[mid]>a[mid-1])
            return a[mid];
        else if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
            return a[mid];
        else if(a[mid]<a[mid-1])
            high=mid-1;
        else if(a[mid]<a[mid+1])
            low=mid+1;
    }
    return -1;
}


int main()
{
    vector<int>num={1,6,15,28,42,35,28,19,1};
    cout<<max_in_bitonic_array(num);
    return 0;
}
