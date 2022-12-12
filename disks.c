//SSTF
#include <stdio.h> #include <stdlib.h> int main(){
int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move; printf("Enter the number of Requests\n");
scanf("%d", &n);
printf("Enter the Requests sequence\n"); for (i = 0; i < n; i++)
scanf("%d", &RQ[i]); printf("Enter initial head position\n"); scanf("%d", &initial);
printf("Enter total disk size\n"); 
scanf("%d", &size);
printf("Enter the head movement direction for high 1 and for low 0\n"); scanf("%d", &move);
for (i = 0; i < n; i++){
for (j = 0; j < n - i - 1; j++){
if (RQ[j] > RQ[j + 1]){
int temp; temp = RQ[j];
RQ[j] = RQ[j + 1];
RQ[j + 1] = temp;
}
}
}
int index;
for (i = 0; i < n; i++){ if (initial < RQ[i]){
index = i; break;
}
}
if (move == 1){
for (i = index; i < n; i++){
TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); initial = RQ[i];
}
TotalHeadMoment = TotalHeadMoment + abs(size - RQ[i - 1] - 1); TotalHeadMoment = TotalHeadMoment + abs(size - 1 – 0);
initial = 0;
for (i = 0; i < index; i++){
TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); initial = RQ[i];
}
}
else{
for (i = index - 1; i >= 0; i--){
TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); initial = RQ[i];
}



TotalHeadMoment = TotalHeadMoment + abs(RQ[i + 1] - 0); TotalHeadMoment = TotalHeadMoment + abs(size - 1 - 0); initial = size - 1;
for (i = n - 1; i >= index; i--){
TotalHeadMoment = TotalHeadMoment + abs(RQ[i] - initial); initial = RQ[i];
}
}
printf("Total head movement is %d", TotalHeadMoment); return 0;
}
//Scan Disk 
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,k,req[50],mov=0,cp,index[50],min,a[50],j=0,mini,cp1;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    cp1=cp;
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
for(k=0;k<n;k++)
    {
    for(i=0;i<n;i++)
    {
        index[i]=abs(cp-req[i]); // calculate distance of each request from current position
    }
    // to find the nearest request
    min=index[0];
    mini=0;
    for(i=1;i<n;i++)
    {
        if(min>index[i])
        {
            min=index[i];
            mini=i;
        }
    }
    a[j]=req[mini];
    j++;
    cp=req[mini]; // change the current position value to next request
    req[mini]=999;
    } // the request that is processed its value is changed so that it is not processed again
    printf("Sequence is : ");
    printf("%d",cp1);
    mov=mov+abs(cp1-a[0]);    // head movement
    printf(" -> %d",a[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(a[i]-a[i-1]); ///head movement
        printf(" -> %d",a[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
}

