#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define requiredargcount 3
void howtouse(){
printf("use it like this\n");
printf("1.compile the program\n");
printf("2.enter ./a.out sourcefilename destfilename in the terminal");
}
int main(int argc,char* argv[]){
FILE *fp;
FILE *fp2;
char ch;
char overwrite;
fp=fopen(argv[1],"r");
fp2=fopen(argv[2],"r");
if(fp2){
printf("%s already exists,want to overwrite it?(y/n)",argv[2]);

scanf("%c",&overwrite);
if(!(overwrite == 'y' || overwrite == 'Y')){
printf("aborting\n");
exit(0);
}
}
fp2=fopen(argv[2],"w");
if(argc!=requiredargcount){
howtouse();
exit(1);

}
if(fp == NULL) {
		printf("Unable to open file, %s \n", argv[1]);
	} else {	
		
		ch = fgetc(fp);
		while(!feof(fp)) {
			fprintf(fp2, "%c", ch); 
			ch = fgetc(fp);
		}
		printf("copied %s to %s \n", argv[1], argv[2]);
		fclose(fp);
		fclose(fp2);
		}
}

