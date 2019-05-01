#include <stdio.h>
#include <malloc.h>
typedef int bang[50][100];
typedef struct {
	char tenDV[20];
	int TL, GT, DG;
	int PA;
}DoVat;

DoVat * ReadFile(float *W, int *n){
	FILE * f = fopen("QuiHoachDong-bai1.txt", "r");
	DoVat * dsdv = (DoVat*)malloc(sizeof(DoVat));
	fscanf(f, "%f", W);
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%d %d %[^\n]s", &dsdv[i].TL, &dsdv[i].GT, dsdv[i].tenDV);
		dsdv[i].DG = dsdv[i].GT / dsdv[i].TL;
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat) * (i + 1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}

void inDSDV(DoVat *dsdv, int W, int n){
	int TTL = 0, TGT = 0;
	printf("%-20s %-9s %-8s %s\n", "Ten", "TL", "GT", "PA");
	for(int i = 0; i < n; i++){
		printf("%-22s",dsdv[i].tenDV);
		printf("%-9d",dsdv[i].TL);
		printf("%-9d",dsdv[i].GT);
		printf("%-9d\n",dsdv[i].PA);
		TTL += dsdv[i].PA * dsdv[i].TL;
		TGT += dsdv[i].PA * dsdv[i].GT;
	}
	printf("\nTrong luong balo: %d", W);
	printf("\nTTL: %d, TGT: %d", TTL, TGT);
}

int Chon(float TL, float W){
	return (int)W / TL;
}

void TaoBang(DoVat * dsdv, int W, int n, bang F, bang X){
	int xk, yk, k;
	int V, FMax, XMax;
	for(V = 0; V <= W; V++){
		X[0][V] = Chon(dsdv[0].TL, V);
		F[0][V] = X[0][V] * dsdv[0].GT;
	}
	
	for(k = 1; k < n; k++){
		for(V = 0; V <= W; V++){
			FMax = F[k-1][V];
			XMax = 0;
			yk = Chon(dsdv[k].TL, V);
			for(xk = 1; xk <= yk; xk++){
				if(F[k-1][V - xk * dsdv[k].TL] + xk*dsdv[k].GT > FMax){
					FMax = F[k-1][V - xk * dsdv[k].TL] + xk*dsdv[k].GT;
					XMax = xk;
				}
			}
			F[k][V] = FMax;
			X[k][V] = XMax;
		}
	}
}

void InBang(int W, int n, bang F, bang X){
	for(int k = 0; k < n; k++){
		for(int V = 0; V <= W; V++){
			printf("%4d %d", F[k][V], X[k][V]);
		}
		printf("\n");
	}
}

void TraBang(DoVat *dsdv, int W, int n, bang X){
	int k, V = W;
	for(k = n - 1; k >= 0; k--){
		dsdv[k].PA = X[k][V];
		V -= dsdv[k].PA * dsdv[k].TL;
	}
}

int main(){
	float W;
	int n;
	bang F,X;
	DoVat * dsdv = ReadFile(&W, &n);	
	TaoBang(dsdv, W, n, F, X);
	InBang(W, n, F, X);
	TraBang(dsdv, W, n, X);
	inDSDV(dsdv, W, n);
	free(dsdv);
	return 0;
}
