#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 100

typedef struct {
	char tenDV[20];
	float trongLuong, giaTri, donGia;
	int phuongAn;
}DoVat;	

int n; // luu so luong do vat
int bestSolutions[MAX]; // Luu phuong an tot nhat tam thoi
float W; // Luu trong luong cua Ba lo
float CT; // Luu can tren
float TGT; // Luu Tong gia tri cua cac vat da duoc chon tai moi nut
float GiaLNTT; // Luu Gia lon nhat tam thoi
float TLConLai; // Luu Trong luong con lai cua Ba lo tai moi nut
DoVat *dsdv;

DoVat * ReadFile(float *W, int *n){
	FILE *f = fopen("CaiBalo3.txt", "r");
	DoVat *dsdv;
	int i = 0;
	fscanf(f, "%f", W);
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	while(!feof(f)){
		fscanf(f,"%f %f %[^\n]s", &dsdv[i].trongLuong, &dsdv[i].giaTri, dsdv[i].tenDV);	
		dsdv[i].donGia = dsdv[i].giaTri / dsdv[i].trongLuong;
		dsdv[i].phuongAn = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}*n = i - 1;
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
	return W > trongLuong;
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
	printf("Trong luong cua balo= %4.1f\n",W);
	printf("Tong trong luong= %4.1f, Tong gia tri= %4.1f\n", TongTL, TongGT);
}

void init(){ // Khoi tao goc
	TLConLai = W;
	CT = W * dsdv[0].donGia;
	GiaLNTT = 0.0;
	TGT = 0.0;
}

void GhiNhanKiLuc(){
	if(GiaLNTT < TGT){
		GiaLNTT = TGT;
		for(int i = 0; i < n; i++){
			dsdv[i].phuongAn = bestSolutions[i];
		}
	}	
}

void Try(int i){ // i la thu tu do vat trong dsdv
	int j = Chon(dsdv[i].trongLuong, TLConLai);
	for(j; j >= 0; j--){
		TGT += j * dsdv[i].giaTri;
		TLConLai -= j * dsdv[i].trongLuong;
		CT = TGT + TLConLai * dsdv[i + 1].donGia;
		if(CT > GiaLNTT){
			bestSolutions[i] = j;
			if((i == n - 1) || (TLConLai == 0))
				GhiNhanKiLuc();			
			else 
				Try(i + 1); // Xet nut con
		}
		
		// Quay lui xet
		bestSolutions[i] = 0;
		TGT -= j * dsdv[i].giaTri;
		TLConLai += j * dsdv[i].trongLuong;
	}
	
}


int main(){
	dsdv = ReadFile(&W, &n);
	BubbleSort(dsdv, n);
	init();
	Try(0);
	InDSDV(dsdv, n ,W);
	free(dsdv);
	return 0;
}
