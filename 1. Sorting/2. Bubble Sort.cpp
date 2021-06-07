// Time Complexity ->  Best Case :: O(n)    Worst case :: O(N^2)

void swap( int &a, int &b)
{
  a=a+b;
  b=a-b;
  a=a-b;
}

void Bubble_sort( int a[], int n )
{
  for( int i=0; i<n-1 ; i++ )
  {
    bool ischanged=false;
    for( int j=1; j<n-i-1; j++)
      if(a[j]>a[j+1])
      {
        swap(a[i],a[j]);
        ischanged=true;
      }
    if(!ischanged)
      return;
  }
}
