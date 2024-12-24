#include<stdio.h>
int main(){
	char string[100]; 
	FILE *fptr;
	fptr = fopen("bt01.txt","a");
	if(fptr == NULL){
		printf("khong the mo file");
		return 1; 
	} 
	printf("Moi ban nhap vao mot chuoi bat ki:"); 
	fgets(string,100,stdin);
	fprintf(fptr,"%s",string); 
	fclose(fptr);
	return 0; 
} 
