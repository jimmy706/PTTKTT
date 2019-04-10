#include <stdio.h>
typedef struct {
	char ten[30];
	float trongLuong, giaTri, donGia;
	int phuongAn, soLuong;
} DoVat;

int Chon(float trongLuong, int soLuong, float weight){
	if(weight > trongLuong)
		if ((int) weight / trongLuong <= soLuong) 
			return (int) weight / trongLuong <= soLuong;
		else
			return soLuong;
	else
		return 0;
}

void Greedy (DoVat dsdv[], int soLuongDoVat, float weight) {
	// Sap xep theo thu tu giam dan don gia
	int i, j;
	for(i = 0; i < soLuongDoVat - 1; i++){
		for(j = i + 1; j < soLuongDoVat; j++){
			if(dsdv[j].donGia > dsdv[i].donGia){
				DoVat temp = dsdv[i];
				dsdv[i] = dsdv[j];
				dsdv[j] = temp;
			}
		}
	}	
	
	for(i = 0; i < soLuongDoVat; i++){
		dsdv[i].phuongAn = Chon(dsdv[i].trongLuong,dsdv[i].soLuong , weight);
		weight -= dsdv[i].phuongAn * dsdv[i].trongLuong;
	}	 
}


int main(){
	float weight;
	int numbers;
	freopen("cai-balo-bai2.txt", "r", stdin);
	scanf("%f %d", &weight, &numbers);
	int i;
	DoVat dsdv[numbers];
	for(i = 0; i < numbers; i++){
		DoVat dv;
		scanf("%f %f %d %[^\n]s", 
		&dv.trongLuong, &dv.giaTri, &dv.soLuong, dv.ten);
		
		dv.donGia = (float)dv.giaTri / dv.trongLuong;
		dsdv[i] = dv;
	}
	
//	for(i = 0; i < numbers; i++)
//		printf("%.f %.f %s\n", dsdv[i].trongLuong, dsdv[i].giaTri, dsdv[i].ten);

	Greedy(dsdv, numbers, weight);
	
	float tongTrongLuong = 0, tongGiaTri = 0;
	for(i = 0; i < numbers; i++){
		printf("%s: %d\n",dsdv[i].ten, dsdv[i].phuongAn);
		
	}
	
	printf("TTL: %.f, TGT %.f", tongTrongLuong, tongGiaTri);
		
	return 0;
}
