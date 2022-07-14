#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#define SEGSIZE 1024
void main(){
int shmid;
key_t key;
char *segmentpointer;
char buff[100];
printf("enter some data to write to the shared memory");
gets(buff);
key=ftok("/home/mec/KTU-OS-LAB",'z');
shmid=shmget(key,SEGSIZE,IPC_CREAT|IPC_EXCL|0666);
if(shmid==-1){ 
perror("shmget");
exit(1);
}
printf("key of shared memory is %d \n",shmid);
segmentpointer=shmat(shmid,NULL,0);
printf("process is attached at %p\n",segmentpointer);
if(segmentpointer==(char*)-1){
perror("shmat");
}
system("ipcs -m");
strcpy(segmentpointer,buff);
printf("you wrote: %s\n",(char*)segmentpointer);

if(shmctl(shmid,IPC_RMID,0)==-1)
printf("can't remove shared memory segmet \n");
else
printf("removed successfully");
}

