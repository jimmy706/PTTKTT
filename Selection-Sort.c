#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int arr[], int n){
	int i, j;
	for(i = 0; i < n - 1; i++){
		int min_index = i;
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}


int main (){
	int n, i;
	freopen("dt.txt", "r", stdin);
	scanf("%d", &n);
	int arr[n];
	
	for(i = 0; i < n; i++){
		int num;
		scanf("%d", &num);
		arr[i] = num;
	}
	
	
	selection_sort(arr, n);
	
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
