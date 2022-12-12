//Contiguous
#include <stdio.h> #include <stdlib.h>
void recurse(int files[])
{
int flag = 0, startBlock, len, j, k, ch;
printf("Enter the starting block and the length of the files: "); scanf("%d%d", &startBlock, &len);
for (j = startBlock; j < (startBlock + len); j++)
{
if (files[j] == 0) flag++;
}
if (len == flag)
{
for (int k = startBlock; k < (startBlock + len); k++)
{
if (files[k] == 0)
{
files[k] = 1; printf("%d\t%d\n", k, files[k]);
}
}
if (k != (startBlock + len - 1))
printf("The file is allocated to the disk\n");
}
else
printf("The file is not allocated to the disk\n"); printf("Do you want to enter more files?\n"); printf("Press 1 for YES, 0 for NO: "); scanf("%d", &ch);
if (ch == 1) recurse(files);
else
exit(0); return;
}
int main()
{
int files[50];
for (int i = 0; i < 50; i++) files[i] = 0;
printf("Files Allocated are :\n"); recurse(files);
return 0;
}
//Linked
#include <stdio.h>
#include <stdlib.h>
int files[50], indexBlock[50], indBlock, n;
void recurse1();
void recurse2();
void recurse1(){
    printf("Enter the index block: ");
    scanf("%d", &indBlock);
    if (files[indBlock] != 1){
        printf("Enter the number of blocks and the number of files needed for the index %d on the disk: ", indBlock);
        scanf("%d", &n);
    }
    else{
        printf("%d is already allocated\n", indBlock);
        recurse1();
    }
    recurse2();
}
void recurse2(){
    int ch;
    int flag = 0;
    for (int i=0; i<n; i++){
        scanf("%d", &indexBlock[i]);
        if (files[indexBlock[i]] == 0)
            flag++;
    }
    if (flag == n){
        for (int j=0; j<n; j++){
            files[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k=0; k<n; k++){
            printf("%d ------> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
        }
    }
    else{
        printf("File in the index is already allocated\n");
        printf("Enter another indexed file\n");
        recurse2();
    }
    printf("Do you want to enter more files?\n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse1();
    else
        exit(0);
    return;
}
int main()
{
    for(int i=0;i<50;i++)
        files[i]=0;
    recurse1();
    return 0;
}
//Indexed
#include <stdio.h>
#include <stdlib.h>
int main(){
    int f[50], p, i, st, len, j, c, k, a;
    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("Enter how many blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter blocks already allocated: ");
    for (i = 0; i < p; i++) {
        scanf("%d", &a);
        f[a] = 1;
    }
x:
    printf("Enter index starting block and length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if (f[st] == 0)
    {
        for (j = st; j < (st + k); j++){
            if (f[j] == 0){
                f[j] = 1;
                printf("%d-------->%d\n", j, f[j]);
            }
            else{
                printf("%d Block is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("%d starting block is already allocated \n", st);
    printf("Do you want to enter more file(Yes - 1/No - 0)");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    else
        exit(0);
    return 0;
}



