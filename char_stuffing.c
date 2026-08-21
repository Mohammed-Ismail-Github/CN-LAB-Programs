#include <stdio.h>
#include <string.h>

int main(){
    char data[100], stuffed[200];
    int j=0;
    printf("Enter the data: ");
    scanf("%s", data);
    stuffed[j++] = '#';
    for(int i = 0; i < strlen(data); i++){
        if(data[i] == '#' || data[i] == '@'){
            stuffed[j++] = '@';
        }
        stuffed[j++] = data[i];
    }
    stuffed[j++] = '#';
    stuffed[j] = '\0';
    printf("\nStuffed Data: %s\n", stuffed);
    return 0;
}
