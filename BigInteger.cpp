#include <stdio.h>
#include <math.h>

int splitNumRight(int num, int length){
	return num % (int)pow(10, length);
}

int splitNumLeft(int num, int length){
	int numLength = length;		
	while((int)(num / pow(10, numLength)) > 0)
		numLength++;
		
	return (int)(num / pow(10, numLength - length)); 
}



int numberSign(int num){
	if(num == 0) return 0;
	else if(num > 1) return 1;
	else return -1;
}

int mult(int num1, int num2, int length){
	
}


int main(){
	printf("%d", splitNumLeft(12569, 5));
	return 0;
}
