#include <stdio.h>

void fullMenu(){
printf("\n-----------MENU------------\n");
printf("\n1. Nhap vao so phan tu va tung phan tu\n");
printf("\n2. Hien thi cac phan tu trong mang\n");
printf("\n3. Tinh do dai mang\n");
printf("\n4. Tinh tong cac phan tu trong mang\n");
printf("\n5. Hien thi phan tu lon nhat\n");
printf("\n6. Thoat\n");
printf("\nLua chon cua ban:\n");
}
void currentArray(int arr[],int limit){
	for(int i=0;i<limit;i++){
		printf("[%d]=%d\n",i,arr[i]);
	}
}
int sumArr(int arr[],int limit){
	int sum=0;
	for(int i=0;i<limit;i++){
		sum+=arr[i];
	}
	return sum;
}
int bigArr(int arr[],int limit){
	int big=arr[0];
	for(int i=0;i<limit;i++){
		if(big<arr[i]){
			big=arr[i];
		}
	}
	return big;
}
int main(){
	int arr[100];
	int choice,limit,length,sum,bigArray;
	void (*ptrCurrentArray)(int[], int) = currentArray;
	int (*ptrSumArr)(int [],int)=sumArr;
	int (*ptrBigArr)(int [],int)=bigArr;
	do{
		fullMenu();
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("moi ban nhap so phan tu trong mang ");
				scanf("%d",&limit);
				for(int i=0;i<limit;i++){
					printf("moi ban nhap gia tri o vi tri [%d] ",i);
					scanf("%d",&arr[i]);
				}
				break;
			case 2:
				ptrCurrentArray(arr,limit);
				break;
			case 3:
				printf("do dai cua mang la %d",limit);
				break;
			case 4:
				sum=ptrSumArr(arr,limit);
				printf("tong cua cac phan tu trong mang la %d",sum);	
				break;
			case 5:
				bigArray=ptrBigArr(arr,limit);
				printf("gia tri lon nhat trong mang la %d",bigArray);
				break;
			case 6:
				printf("cam on ban da dung ung dung cua minh");
				return 0;		
		}
	}while(1);
}
