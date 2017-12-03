#include <stdio.h>
#include <stdlib.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
 
// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
 		int mid = (l+r)/2;
 		//printf("(l = %d, mid = %d, r = %d)\n",l,mid,r);
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}
 
int main(int argc, char * argv [])
{

	if (argc <= 1) return 0;

	char *p;
	int num;

	errno = 0;
	long conv = strtol(argv[1], &p, 10); 


	// Check for errors: e.g., the string does not represent an integer
	// or the integer is larger than int
	if (errno != 0 || *p != '\0' || conv > INT_MAX) return 0;
	int n = conv;

   int arr1[n]; 
   int arr2[] = {2, 3, 4, 11, 20,21,30,13};   
   int size1 = sizeof(arr1)/ sizeof(arr1[0]);
   int size2 = sizeof(arr2)/sizeof(arr2[0]); 


   for(int i = 0; i < size1; i++) arr1[i] = 0;
   int index = size1-1, index2 = size2-1;

   while(index >= 0 && index2 >= 0){
   		arr1[index--] = arr2[index2--];
   }


   for(int i = size1-size2; i < size1; i++){
   		printf("%d ",arr1[i]);
   }
   printf("\n");
   

   int x = 10;
   int result = binarySearch(arr1, 0, n-1, x);
   return 0;
}

