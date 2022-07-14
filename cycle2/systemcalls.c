//https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
#include<stdio.h>
#include<dirent.h>
int main(){
struct dirent *de;
char name[100];
printf("enter the directory name");
scanf("%s",name);
DIR *dr=opendir(name);
if(dr==NULL){
printf("could not open current directory");
return 0;
}
while((de=readdir(dr))!=NULL){
printf("%s\n",de->d_name);
}
closedir(dr);
return 0;
}
