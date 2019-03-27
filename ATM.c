#include <stdio.h>
#include <string.h>
typedef struct {
	int arr[6];
} Amount;

Amount ATM_Machine(int money){
	/* 
		amount[0]: 500.000
		amount[1]: 200.000
		amount[2]: 100.000
		amount[3]: 50.000
		amount[4]: 20.000
		amount[5]: 10.000
	*/
	Amount amount;
	int i;
	for(i = 0; i <= 5; i++)
		amount.arr[i] = 0;
	
	while(money > 0){
		if(money >= 500000){
			amount.arr[0] = money / 500000;
			money = money - ((int)money / 500000) * 500000;			
		}
		if(money >= 200000){
			amount.arr[1] = money / 200000;
			money = money - ((int)money / 200000) * 200000;
		}
		if(money >= 100000){
			amount.arr[2] = money / 100000;
			money = money - ((int)money / 100000) * 100000;
		}
		if(money >= 50000){
			amount.arr[3] = money / 50000;
			money = money - ((int)money / 50000) * 50000;
		}
		if(money >= 20000){
			amount.arr[4] = money / 20000;
			money = money - ((int)money / 20000) * 20000;
		}
		if(money >= 10000){
			amount.arr[5] = money / 10000;
			money = money - ((int)money / 10000) * 10000;
		}
		if (money < 10000){
			money -= money;
		}
	}
	
	return amount;
}


int main(){
	Amount amount = ATM_Machine(2980000);
	printf("\n500k: %d", amount.arr[0]);
	printf("\n200k: %d", amount.arr[1]);
	printf("\n100k: %d", amount.arr[2]);
	printf("\n50k: %d", amount.arr[3]);
	printf("\n20k: %d", amount.arr[4]);
	printf("\n10k: %d", amount.arr[5]);
//	char str[99];
//	scanf("%[0-9a-zA-Z ]", str);
//
//	printf(str);
	return 0;
}
