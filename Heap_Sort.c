#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push_down(int arr[], int first, int last){
	int r = first; // inset node index
	
	while(r <= (last - 1)/2 ){ // while r <= arr[(n - 2)/2]
		if(last == 2*r + 1){ // have left node only
			if(arr[r] > arr[last]) {
				swap(&arr[r], &arr[last]);
			}
			r = last;
		}
		else 
		if((arr[r] > arr[2*r + 1]) && 
		(arr[2*r + 1] ) <= arr[2*r + 2]){
			swap(&arr[r], &arr[2*r + 1]);
			r = 2*r + 1;
		}
		else 
		if((arr[r] > arr[r*2 + 2]) &&
		(arr[r*2 + 2] < arr[r*2 + 1])){
			swap(&arr[r], &arr[2*r + 2]);
			r = 2*r + 2;
		}
		else{
			r = last;
		}
	}
}




void heap_sort(int arr[], int n){
	int i;
	for(i = (n - 2)/2; i >= 0; i--){
		push_down(arr, i, n - 1);
	}
	
	for(i = n - 1; i >= 2; i--){
		swap(&arr[0], &arr[i]);
		push_down(arr, 0, i - 1);
	}
	swap(&arr[0], &arr[1]);
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

	heap_sort(arr, n);
	
	for(i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
