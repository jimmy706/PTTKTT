#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
/* Find number that is greatest between first 2 difference numbers in array */
/*  start --> Starting index, end --> Ending index */
int find_pivot(int arr[], int start, int end){	
	int k = start + 1; // index next to starting index
	while(k <= end && arr[k] == arr[start]) 
		k++;
		
	if(k > end) return -1; // when all numbers at start --> end is all equals
	else if(arr[k] > arr[start]) return k;
	else return start;
}

int partition (int arr[], int start, int end, int pivotNumber){
	int Left = start, Right = end;
	
	while(Left <= Right){
		while(arr[Left] < pivotNumber) Left++;
		while(arr[Right] >= pivotNumber) Right--;
		if(Left < Right) swap(&arr[Left], &arr[Right]);
	}
	
	return Left;
}

void quick_sort(int arr[], int start, int end){
	int pivotNumber, pivotIndex, partitionIndex;
	pivotIndex = find_pivot(arr, start, end);
	
	if(pivotIndex != -1){
		pivotNumber = arr[pivotIndex];
		partitionIndex = partition(arr, start, end, pivotNumber);
		quick_sort(arr, start, partitionIndex - 1);
		quick_sort(arr, partitionIndex, end);
	}
}


int main(){
	int n, i;
	freopen("dt.txt", "r", stdin);
	scanf("%d", &n);
	int arr[n];
	
	for(i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	
	quick_sort(arr, 0, n - 1);
	
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
