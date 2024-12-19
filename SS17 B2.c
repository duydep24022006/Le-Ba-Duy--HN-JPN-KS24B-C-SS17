#include <stdio.h>
#include <string.h>
#include <ctype.h>
void menu();
void character(char *str,int choice,int *letter,int *numerals,int *specialCharcter);
int main(){
	char str[100];
	int choice, size;
	int letter, numerals, specialCharcter ;
	do{
	menu();
	scanf("%d",&choice);
	fflush(stdin);
	letter=0, numerals=0, specialCharcter=0 ;
	switch(choice){
		case 1:
			printf("moi ban nhap chuoi :");
			fgets(str,100,stdin);
			break;
		case 2:
			printf("ki tu ban vua nhap :%s,%d",str,strlen(str)); 
			break;
		case 3:
            character(str,choice,&letter,&numerals,&specialCharcter);
            printf("\nSo luong chu cai: %d\n", letter);
			break;
		case 4:
			character(str,choice,&letter,&numerals,&specialCharcter);
			printf("\nSo luong chu so: %d\n",numerals );
			break;
		case 5:
			character(str,choice,&letter,&numerals,&specialCharcter);
			printf("\nSo luong dac biet: %d\n", specialCharcter);
			break;
		case 6:
			printf("can on ban da su dung tien ich cua  minh");
			return 0;
		default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
	}
	}while(1);

	
}
void menu(){
	printf("\n------------MENU-------------\n");
	printf("\n1. Nhap vao chuoi\n");
	printf("\n2. In ra chuoi\n");
	printf("\n3. Dem so luong chu cai trong chuoi va in ra\n");
	printf("\n4. Dem so luong chu so trong chuoi va in ra\n");
	printf("\n5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
	printf("\n6.Thoat\n");
	printf("\nLua chon cua ban:\n");
}
void character(char *str,int choice,int *letter,int *numerals,int *specialCharcter){
    int count = 0;
    printf("Cac chu cai trong chuoi la: ");
    for (int i = 0; str[i] != '\0'; i++){
        if (choice==3 && isalpha(str[i])){
            (*letter)++;
            printf("%c ", str[i]);
        }else if (choice == 4 && isdigit(str[i])){
            (*numerals)++;
            printf("%c ", str[i]);
        }else if (choice == 5 && !isalnum(str[i]) && !isspace(str[i])){
            (*specialCharcter)++;
            printf("%c ", str[i]);
        }
    }
}

