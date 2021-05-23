// A row-wise & column-wise sorted matrix is given.  
// Search an element and return their index if element exist else return {-1,-1}

// TIME COMPLEXITY - O(m+n) :: m-no of rows | n-number of columns

/* Row-Wise Sorted
  --------------> ^              
  10  20  30  40  |
  15  25  35  45  |
  27  29  37  48  | Column wise sorted
  32  33  39  50  | 
                  
*/

// Start from A[0][n-1] ; (Last element of 1st row)
// REPEAT TILL ( i>=0 and i<m ) && (j>=0 && j<n)
// If(A[i][j] == Item ) return i,j
// If(A[i][j] > Item ) j--  :: Remaining elements of column will also be greater so no need to check there , decrease Column
// If(A[i][j] < Item ) i++  :: Remaining elements of row will also be smaller so no need to check there ,Increase row by 1
// If element not found then return -1,-1


vector <int> Search_element_in_sorted_matrix(int a[][4],int m,int n,int item)
{
    int row=0, col=n-1;
    while((row>=0 && row<m) && (col>=0 && col<n))
    {
        if(a[row][col]==item)
            return (vector <int>{row,col});
        else if(item>a[row][col])
            row++;
        else
            col--;
    }
    return (vector<int>{-1,-1});
}


int main()
{
  int item;
  cin>>item;
  int a[4][4]={{10,20,30,40},
               {15,25,35,45},
               {27,29,37,48},
               {32,33,39,50}};
  vector <int>v=Search_element_in_sorted_matrix(a,4,4,item);
  cout<<v[0]<<" "<<v[1];
  return 0;
}
