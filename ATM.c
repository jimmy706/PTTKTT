#include <stdio.h>
#include <string.h>


void ATM_Machine(int money){
	int a[9], b[9];;
	a[0] = 500000;
	a[1] = 200000;
	a[2] = 100000;
	a[3] = 50000;
	a[4] = 20000;
	a[5] = 10000;
	a[6] = 5000;
	a[7] = 2000;
	a[8] = 1000;	
	
	int i;
	for(i = 0; i < 9; i++) b[i] = 0;
	
	for(i = 0; i < 9; i++){
		b[i] = (int)money / a[i];
		money -= a[i] * b[i];
	}
	
	if(money == 0){
		for(i = 0; i < 9; i++)
			if(b[i] > 0) printf("Rut %d to tien %d\n", b[i], a[i]);
	}
	else printf("Giao dich that bai!!");
}


int main(){
	int money;
	printf("Nhap so tien can rut: ");
	scanf("%d", &money);
	ATM_Machine(money);
	return 0;
}
