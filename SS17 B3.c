#include <stdio.h>
#include <string.h>
#include <ctype.h>

void menu();
void reverseStr(char *str,int size);
void  strAndStr2(char *str,char *str2,int *size,int choice);
void strPer(char *str,int size);
int main(){
	char str[100];
	char str2[100];
	int choice, size,comparison;
	do{
	menu();
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice){
		case 1:
			strAndStr2(str,str2,&size,choice);
			break;
		case 2:
		if(size<1){
			break;
		}else{
			printf("chuoi sau khi dao ");
			reverseStr(str,size);
			break;
		} 
		case 3:
		if(size<1){
			break;
		}else{
			printf("so luong phan tu la %d",size); 
			break;
		}
		case 4:
		if(size<1){
			break;
		}else{
			strAndStr2(str,str2,&size,choice);
			comparison=strcmp(str, str2);
			if(comparison==0){
				printf("2 chuoi bang nhau "); 
			}else if(comparison<0){
				printf("choi thu 2 lon hon chuoi thu nhat "); 
			} else {
				printf("chuoi thu nhat lon hon chuoi thu 2"); 
			}
			break;
		}
		case 5:
			if(size<1){
			break;
		}else{ 
			strPer(str,size);
			for(int i=0;i<size;i++){
				printf("%c",str[i]); 
			}
			break;
		}
		case 6:
		if(size<1){
			break;
		}else{
			if(strlen(str2)>1){
				strAndStr2(str,str2,&size,choice);
				printf("chuoi sau khi noi : %s",strcat(str, str2));
			} else{
				printf("chuoi sau khi noi : %s",strcat(str, str2));
			} 
			break;
		}
		case 7:
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
	printf("\n2. In ra chuoi dao nguoc\n");
	printf("\n3. Dem so luong tu trong chuoi\n");
	printf("\n4. Nhap vao chuoi khac, so sanh chuoi do voi chuoi ban dau\n");
	printf("\n5. In hoa tat ca chu cai trong chuoi\n");
	printf("\n6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
	printf("\n7.Thoat\n");
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
void reverseStr(char *str,int size){
	for(int i=size-1;i>=0;i--){
		printf("%c", str[i]);
	} 
} 
void  strAndStr2(char *str,char *str2,int *size,int choice){
	printf("moi ban nhap chuoi :");
	if(choice==1){
		fgets(str,100,stdin);
		*size=strlen(str);
	}else if(choice==4||choice==6){
		fgets(str2,100,stdin);
	}
}
void strPer(char *str,int size){
	for(int i=0;i<size;i++){
		if(isalpha(str[i]) && str[i-1]==' '||i==0){
			str[i]=toupper(str[i]);
		} 
	}
}
