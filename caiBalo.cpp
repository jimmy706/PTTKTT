#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char tenDV[20];
	float trongLuong, giaTri, donGia;
	int phuongAn;
}DoVat;

DoVat * ReadFile(float *W, int *n){
	FILE * f;
	f = fopen("CaiBalo1.txt", "r");
	DoVat * dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	fscanf(f, "%f", W);
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%f %f %[^\n]s", &dsdv[i].trongLuong, &dsdv[i].giaTri, dsdv[i].tenDV);
		dsdv[i].donGia = dsdv[i].giaTri / dsdv[i].trongLuong;
		dsdv[i].phuongAn = 0;
		i++;
		dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}*n = i;
	fclose(f);
	return dsdv;
}


void BubbleSort(DoVat *dsdv, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(dsdv[i].donGia < dsdv[j].donGia){
				DoVat temp = dsdv[i];
				dsdv[i] = dsdv[j];
				dsdv[j] = temp;
			}
		}
	}
}

int Chon(float trongLuong, float W){
	if(W > trongLuong){
		return (int)W / trongLuong;
	}
	else return 0;
}

void Greedy(DoVat *dsdv, int n, float W){
	for(int i = 0; i < n; i++){
		dsdv[i].phuongAn = Chon(dsdv[i].trongLuong, W);
		W -= dsdv[i].phuongAn*dsdv[i].trongLuong;
	}
}

void InDSDV(DoVat *dsdv ,int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat ","T. Luong", "Gia Tri", "Don Gia", "P. An");
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	for(i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-20s",dsdv[i].tenDV);
		printf("|%-9.1f",dsdv[i].trongLuong);
		printf("|%-9.1f",dsdv[i].giaTri);
		printf("|%-9.1f",dsdv[i].donGia);
		printf("|%-9d|\n",dsdv[i].phuongAn);
		TongTL=TongTL+dsdv[i].phuongAn * dsdv[i].trongLuong;
		TongGT=TongGT+dsdv[i].phuongAn * dsdv[i].giaTri;
	}
	printf("|---|--------------------|---------|---------|---------|---------|\n");
	printf("Trong luong cua ba lo= %4.1f\n",W);
	printf("Tong trong luong= %4.1f, Tong gia tri= %4.1f\n", TongTL, TongGT);
}

int main(){
	int n;
	float W;
	DoVat *dsdv;	
	dsdv = ReadFile(&W, &n);
	BubbleSort(dsdv, n);	
	Greedy(dsdv,n,W);
//	for(int i =0; i < n; i++){
//		printf("%s %f %f %f\n", dsdv[i].tenDV, dsdv[i].trongLuong, dsdv[i].giaTri, dsdv[i].donGia);
//	}
	InDSDV(dsdv, n, W);
	return 0;
}
