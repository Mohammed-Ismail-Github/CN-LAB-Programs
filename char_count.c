#include<stdio.h>
#include<string.h>

int main(){
	char data[20][20], frame[20][25];
	int n, len, ch;
	printf("Enter the number of frames: ");
	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++){
		printf("Enter Frame %d: ", i+1);
		fgets(data[i], sizeof(data[i]), stdin);
		len = strlen(data[i]);
		data[i][len-1] = '\0';
	}
	for(int i=0; i<n; i++){
		len = strlen(data[i]);
		frame[i][0] = len + '0';
		frame[i][1] = '\0';
		strcat(frame[i], data[i]);
	}
	printf("AT THE SENDER\n");
	printf("Frames after adding count:\n");
	for(int i=0; i<n; i++){
		printf("Frame %d : %s\n", i+1, frame[i]);
	}
	printf("Transmitted Data : ");
	for(int i=0; i<n; i++){
		printf("%s", frame[i]);
	}
	printf("\nAT THE RECEIVER\n");
	for(int i=0; i<n; i++){
		ch = frame[i][0] - '0';
		for(int j=0; j<ch; j++){
			data[i][j] = frame[i][j+1];
		}
		data[i][ch] = '\0';
	}
	printf("Data after removing count characters : ");
	for(int i=0; i<n; i++){
		printf("%s", data[i]);
	}
	printf("\nFrames received:\n");
	for(int i=0; i<n; i++){
		printf("Frame %d : %s\n", i+1, data[i]);
	}
	return 0;
}
