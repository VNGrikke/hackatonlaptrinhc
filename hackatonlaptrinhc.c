#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,m,i,j,amount,findNumber;
	printf("Nhap so luong phan tu co trong mang:");
	scanf("%d",&n);
	int numbers[n],newNumbers[n+1];
	int sumOfnumbers;
	float average;
	do{
	sumOfnumbers = 0;
	amount = 0;	
	printf("\n*******************MENU******************\n");
	printf("1. Nhap gia tri %d phan tu cua mang\n",n);
	printf("2. In gia tri cac phan tu trong mang\n");
	printf("3. Tinh trung binh cac phan tu duong co trong mang\n");
	printf("4. In ra vi tri cac phan tu co gia tri bang k\n");
	printf("5. Su dung thuat toan noi bot sap xep mang giam dan\n");
	printf("6. Tinh so luong cac phan tu la so nguyen to co trong mang\n");
	printf("7. Sap xep cac phan tu chan chia het cho 3 o dau mang theo thu tu tang dan\ncac phan tu le chia het cho 3 o cuoi mang theo thu tu giam dan\ncac phan tu con lai o giua mang giam dan\n");
	printf("8. Nhap gia tri m, chen gia tri vao mang (sap xep giam dan) dung vi tri\n");
	printf("9. Thoat\n");
	printf("Lua chon cua ban:");
	int choice;
	scanf("%d",&choice);
	
	switch(choice){
			case 1:
				printf("Nhap gia tri cac phan tu:\n");
				for(i=0;i<n;i++){
					printf("numbers[%d]=",i);
					scanf("%d",&numbers[i]);
				}
			break;
				
			case 2:
				printf("Gia tri cac phan tu co trong mang:");
				for(i=0;i<n;i++){
					printf("%d\t",numbers[i]);
				}
			break;
			
			case 3:
				for(i=0;i<n;i++){
					if(numbers[i]>0){
						sumOfnumbers += numbers[i];
						amount += 1;
					}		
				}
				average = sumOfnumbers/amount;
				printf("Trung binh phan tu duong co trong mang:%.3f",average);
			break;
			
			case 4:
				printf("Nhap vao phan tu can tim:");
				scanf("%d",&findNumber);
				printf("Vi tri cac phan tu can tim:");
				for(i=0;i<n;i++){
					if(numbers[i]==findNumber){
						printf("%d, ",i);
						amount+=1;	
					}
				}
				if(amount==0){
					printf("Khong co phan tu can tim.");
				}
			break;
			
			case 5:
				printf("Sap xep mang theo thu tu giam dan:");
				for(i=0;i<n;i++){
					for(j=0;j<n-i-1;j++){
						if(numbers[j]<numbers[j+1]){
							int temp = numbers[j];
							numbers[j] = numbers[j+1];
							numbers[j+1] = temp;
						}
					}
				}
				for(i=0;i<n;i++){
						printf("%d, ",numbers[i]);	
				}
			break;
			
			case 6:
				for(i=0;i<n;i++){
					if(numbers[i]==2||numbers[i]==3||numbers[i]==5){
						amount +=1;
					}else if(numbers[i]!=1&&numbers[i]%2!=0&&numbers[i]%3!=0&&numbers[i]%5!=0){
						amount +=1;
					}
				}
				printf("So luong phan tu la so nguyen to co trong mang: %d",amount);
				
			break;
			
			case 7:
//				for(i=0;i<n;i++){
//					if(numbers[i]%2==0&&numbers[i]%3==0){
//						numbers[i]=evenNumbers[i];		
//				}
			break;
			
			case 8:
				printf("nhap gia tri phan tu muon chen:");
				scanf("%d",&m);
				for(i=0;i<n;i++){
					for(j=0;j<n-i-1;j++){
						if(numbers[j]<numbers[j+1]){
							int temp = numbers[j];
							numbers[j] = numbers[j+1];
							numbers[j+1] = temp;
						}
					}
				}
				for(i=0;i<n;i++){
					newNumbers[i+1]=numbers[i];
				}
				newNumbers[0]=m;
				for(i=0;i< sizeof(newNumbers)/sizeof(int) ;i++){
					for(j=0;j< sizeof(newNumbers)/sizeof(int)-i-1 ;j++){
						if(newNumbers[j]<newNumbers[j+1]){
							int temp = newNumbers[j];
							newNumbers[j] = newNumbers[j+1];
							newNumbers[j+1] = temp;
						}
					}
				}
				for( i = 0 ; i < sizeof(newNumbers)/sizeof(int) ; i++){
					printf("%d, ",newNumbers[i]);	
				}
			break;
			
			case 9:
				exit(0);
			default:
					printf("Vui long nhap tu 1-9");
		}
	}while(1==1);	
}
