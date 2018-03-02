#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int *L,*R,*S;
int main(){
 
    int N,K,T,Case=0;
    scanf("%d",&T);
    while(T--){
    	Case++;
    	scanf("%d%d",&N ,&K);
        L = (int *)malloc(N*sizeof(int));
    	R = (int *)malloc(N*sizeof(int));
    	S = (int *)malloc(N*sizeof(int));
        memset(S,0,N*sizeof(int));
        L[0]=R[N-1]=0;
        for(int i=1; i<N; i++){
        	L[i] = L[i-1]+1;
        	R[N-i-1] = R[N-i] + 1;
        }

        for(int i=0; i<K; i++){
        	int  maxfit=-1,maxfitpos=-1; 
            for(int j=0; j<N; j++){
            	if(S[j] != 1 ){
            		if(maxfit < MIN(L[j],R[j])) { maxfit = MIN(L[j],R[j]); maxfitpos = j;}
            		else if(maxfit == MIN(L[j],R[j])){
            			 if( MAX(L[j],R[j]) > MAX(L[maxfitpos],R[maxfitpos])) maxfitpos = j;	
            		}
            	}
            }

            if( i == K-1 ) {printf("Case #%d: %d %d\n",Case,MAX(L[maxfitpos],R[maxfitpos]),MIN(L[maxfitpos],R[maxfitpos])); break;}
            S[maxfitpos] = 1;   
            for(int j = maxfitpos+1; j<=N-1 && S[j] != 1; j++ ) L[j] -= L[maxfitpos]+1;
            for(int j = maxfitpos-1; j>=0 && S[j] != 1; j-- ) R[j] -= R[maxfitpos]+1;	
        }
        free(L);
        free(R);
        free(S);
    }
  return 0;
}