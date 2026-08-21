#include<stdio.h>
int main() {
	int data[100], div[20], temp[100];
	int datalen = 0, divlen = 0;
	char ch;
	printf("Enter the data (binary): ");
	while((ch=getchar()) != '\n'){
		data[datalen++] = ch - '0';
	}
	printf("Enter the divisor (generator polynomial): ");
	while((ch=getchar()) != '\n') {
			div[divlen++] = ch - '0';
	}
	for(int i=0; i<datalen; i++){
		temp[i] = data[i];
	}
	for(int i=0; i<divlen-1; i++){
		temp[datalen+i] = 0;
	}
	int totalLen = datalen + divlen - 1;
	for(int i=0; i<=totalLen - divlen; i++){
		if(temp[i] == 1){
			for(int j=0; j<divlen; j++) {
				temp[i+j] = temp[i+j] ^ div[j];
			}
		}
	}
	for(int i=0; i<datalen; i++){
		printf("%d", data[i]);
	}
	printf(" (Data) + ");
	for(int i=datalen; i<totalLen; i++) {
		printf("%d", temp[i]);
		data[i] = temp[i];
	}
	printf(" (CRC)\n");
	printf("Transmitted Data (Data + CRC): ");
	for(int i=0; i<totalLen; i++) {
		printf("%d", data[i]);
	}
	printf("\n");
	return 0;
}
