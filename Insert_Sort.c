#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(int arr[], int n){
	int i,j;
	for(i = 1; i < n; i ++){
		j = i;
		while(j >= 0 && arr[j] < arr[j-1]){
			swap(&arr[j], &arr[j-1]);
			j--;
		}
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
	
	insertion_sort(arr, n);
	
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
