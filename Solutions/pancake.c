#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){	
	int T,Case=0;
    scanf("%d",&T);
    while(T--){
    	Case++;
    	char* ptr= (char*)malloc(1000*sizeof(char));
    	int K;
    	scanf("%s%d",ptr,&K);
    	int i=0,flag = 0,count=0,len=strlen(ptr);
    	while(i<len){
    		if(len - i < K && ptr[i] == '-') {printf("Case #%d: IMPOSSIBLE\n",Case); flag=1; break; }
    		if(ptr[i] == '-') {
    			count ++;
    			for(int j=1;j<K;j++){
    				if(ptr[i+j] == '-') ptr[i+j] = '+';
    				else ptr[i+j] = '-';
    			}
    		}
    		i++;
    	}
        if(!flag) printf("Case #%d: %d\n",Case,count); 
    }
	return 0;
}