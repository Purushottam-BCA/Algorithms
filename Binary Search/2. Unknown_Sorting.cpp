// Search an element ina sorted array If you don't know whether it is ascending or descending 

int unknown_sorting_order(int a[],int size,int item)
{
    int low=0, high=size-1;
    if(size==1)     // If only one item then check and return 
    {
      if(a[0]==item)
         return 0;
      else
         return -1;
    }
    else     // In case it has at least two elements
    {
      if(a[0] > a[size-1])     // If First Element > Last element then Descending 
         return bin_search_desc(a,size,item); 
      else if(a[0]<a[size_-1]) // If first element < Last Element Ascending
         return bin_search(a,size,item);
    }
   return -1;   // If item not found then return -1
}
