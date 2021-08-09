#include<stdio.h>
#include<conio.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[],int l,int m,int r);

int main()
{
    int arr[] = {10, 30, 40, 50, 17, 19, 23, 10};
    int len, i;
    len = sizeof(arr)/sizeof(int);
    printf("length = %d\n", len);
    
    for(i = 0 ; i < len ; i++)
    	printf("%d ", arr[i]);
    printf("\n");
    
    mergeSort(arr, 0, len - 1);
    
    for(i = 0 ; i < len ; i++)
    	printf("%d ", arr[i]);
    printf("\n");
	    
    getch();
    return 0;
}

void mergeSort(int arr[], int l, int r)
{
	if(r - l > 1)
	{
		int m = (l + r)/2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		
		merge(arr, l, m, r);
	}
} 
void merge(int arr[],int l,int m,int r)
{
	// creating two arrays, one for left elements
	// one for right elements.
	
	int ln, rn, i , j, k;
	ln = m - l;
	rn = r - m;
	
	int L[ln], R[rn];
	
	//copying left and right part into corr arrays.
	for(i = 0 ; i < ln ; i++)
		L[i] = arr[i];
	for(i = 0 ; i < rn ; i++)
		R[i] = arr[m + i];
		
	i = j = 0; // index for left and right sub arrays
	k = l;	   // index for main array
	
	while(i < ln && j < rn)
	{
		if(L[i] > R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}
	while(i < ln)
	{
		arr[k] = L[i++];
		k++;
	}
	while(j < rn)
	{
		arr[k] = R[j++];
		k++;
	}
}







