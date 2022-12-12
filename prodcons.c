#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/sem.h>
#include<sys/shm.h>
#include<sys/ipc.h>
void signal(int);
void wait(int);
int main()
{
    int mutex,empty,full,n,shmid;
    pid_t ret;
    int in=-1,out=-1;
    char *buffer;
    char c[2];
    printf("Enter size of the buffer:");
    scanf("%d",&n);
    if((mutex=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1)
    {
        perror("\nFailed to create semaphore");
        exit(0);
    }
    if(semctl(mutex,0,SETVAL,1)==-1)
    {
        perror("Unable to set value to semaphore");
        exit(0);
    }
    if((empty=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1)
    {
         perror("\nFailed to create semaphore");
        exit(0);
    }
    if(semctl(empty,0,SETVAL,n)==-1)
    {
        perror("Unable to set value to semaphore");
        exit(0);
    }
    if((full=semget(IPC_PRIVATE,1,0666|IPC_CREAT))==-1)
    {
         perror("\nFailed to create semaphore");
        exit(0);
    }
    if(semctl(full,0,SETVAL,0)==-1)
    {
        perror("Unable to set value to semaphore");
        exit(0);
    }
    if((shmid=shmget(IPC_PRIVATE,n*sizeof(char),0666|IPC_CREAT))==-1)
    {
        perror("failed to allocate shared memory");
        exit(0);
    }
    buffer=(char *)shmat(shmid,(const void*)0,0) 
    ret=fork();
    while(1){
    if(ret==0)
    {
        wait(empty);
        printf("Item Produced:");
        scanf("%s",c);
        wait(mutex);
        in=(in+1)%n;
        buffer[in]=c[0];
        signal(mutex);
        signal(full);
        
    }
    else if(ret>0)
    {
        sleep(6);
        wait(full);
        wait(mutex);
        out=(out+1)%n;
        c[0]=buffer[out];
        printf("\nItem Consumed:%c",c[0]);
        signal(mutex);
        signal(empty);
        
    }
    }
}
void wait(int semid)
{
    struct sembuf sb;
    sb.sem_num =0;
    sb.sem_op=-1;
    sb.sem_flg=0;
    semop(semid,&sb,1)
}
void signal(int semid)
{

    struct sembuf sb;
    sb.sem_num =0;
    sb.sem_op=1;
    sb.sem_flg=0;
    semop(semid,&sb,1); 
}
    
