#include<stdio.h>
int main(int argc,char *argv[]){
FILE *fp;
char ch;
int space=0;
fp=fopen(argv[1],"r");
while(1){
ch=fgetc(fp);
if(feof(fp)){
break;
}
if(ch==' '){
space++;
}
}
printf("no of spcaes %d",space);
fclose(fp);
}
