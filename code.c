#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h>
int main(){
    int input;
    printf("Enter the approach:\n1. Array (Naive method, Time Complexity: O(n^2), Space Complexity: O(1)) \n2. Sieve of Eratosthenes (Time Complexity: O(n log log n), Space Complexity: O(n))\n3. Linear Sieve (Time Complexity: O(n), Space Complexity: O(n))\n");
    scanf("%d",&input);
    
    if(input==1)
    {   
        int n,a;
        printf("Enter the last number you want to check up to:");
        scanf("%d",&n);
        for (int i=2;i<=n;i++){
            a=0;
            for (int j=1;j<=i;j++){
                if(i%j==0){
                    a++;
                }
            }
            if(a==2){
                printf("%d ",i);
            }
        }
        return 0;
    }
    
    if(input==2)
    {
        int m;
        printf("Enter the last number you want to check up to:");
        scanf("%d",&m);
        bool *isPrime=(bool*)calloc(m+1,sizeof(bool));
        for (int i=2;i<=m;i++) {
            isPrime[i]=true;
        }
        for (int p=2;p*p<=m;p++){
            if (isPrime[p]==true){
                for (int i=p*p;i<=m;i+=p){
                    isPrime[i]=false;
                }
            }
        }
        for (int p=2;p<=m;p++){
            if (isPrime[p]){
                printf("%d ",p);
            }
        }
        printf("\n");
        free(isPrime);
        return 0;
    }
    
    if(input==3)
    {
        int n;
        printf("Enter the last number you want to check up to:");
        scanf("%d",&n);
        int *primes=(int*)malloc((n+1)*sizeof(int));
        int cnt=0;
        bool *isPrime=(bool*)calloc(n+1,sizeof(bool));
        for(int i=2;i<=n;i++){
            if(!isPrime[i]){
                primes[cnt++]=i;
            }
            for(int j=0;j<cnt && i*primes[j]<=n;j++){
                isPrime[i*primes[j]]=true;
                if(i%primes[j]==0) break;
            }
        }
        for(int i=0;i<cnt;i++){
            printf("%d ",primes[i]);
        }
        printf("\n");
        free(primes);
        free(isPrime);
        return 0;
    }
    
    else{
        printf("Invalid input");
        return 0;
    }
}
