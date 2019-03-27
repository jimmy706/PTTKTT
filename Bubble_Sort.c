#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n){
	int i,j;
	for(i = 0; i < n - 1; i ++){
		for(j = i + 1; j < n; j++){
			if(arr[j] < arr[i])
				swap(&arr[i], &arr[j]);
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
	
	bubble_sort(arr, n);
	
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
