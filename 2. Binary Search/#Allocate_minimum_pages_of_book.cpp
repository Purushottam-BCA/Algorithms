/*

If there are n different books having different number of pages and m students. 
The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 

~ One book can be assigned to only one student. Two stdents can't read from same book.
~ Every student will definitely get at least One Book. So we can't give all the books to any one student.
~ Books will be distributed in contineous manner to any student. 
~ EX:- Books [A,B,C,D] and 2 students then :-     Student 1 == Student 2
                                                     A           B,C,D
                                                    A,B           C,D 
                                                   A,B,C           D

Example : 
Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113

Explanation :
There are 2 students. Books can be distributed in following fashion : 
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.   */


bool isvalid(const vector <int> &a,int size,int mid,int k)  // Checking Wheather distribution is possible or not.
{
    int student=1, sum=0;
    for(int i=0;i<size;i++)
    {
        // check if current number of pages are greater than mid that means we will get the result after mid no. of pages
        if(a[i]>mid)
            return false;
        sum += a[i];
        if(sum>mid)
        {
            student++;
            sum = a[i];  // Update Sum with new value as for new student
        }
        if(student>k)    // if more students required then retunr false
            return false;
    }
    return true;
}


int allotment_no_of_pages(const vector<int>&a ,int k)  
{
    if(a.size()<k) return -1;   // return -1 if no. of books is less than no. of students

    int size = a.size();                         // Total Elements in array
    int low= a[size-1];                          // Storing Last value
    int high=accumulate(a.begin(),a.end(),0);    // Storing Sum of elemnts
    int result=-1;
    while(low<=high)
    {
        int mid=low+ (high-low)/2;
        if(isvalid(a,size,mid,k))
            {
                result=mid;   // Find minimum of result and current mid
                high=mid-1;   // as we are finding minimum and books are sorted so reduce high = mid -1
            }
        else                  // if not possible means pages should be increased so low = mid + 1
            low = mid+1;

    }
    return result;            // at-last return minimum no. of  pages
}

// ---------- MAIN DRIVER PROGRAM -----------

int main()  
{ 
  vector <int> pages={12, 34, 67, 90};
  int students;
  cin>>students;
  cout<<allotment_no_of_pages(pages,students);
  return 0;
}
