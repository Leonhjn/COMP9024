#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int connected(char a[],char b[]){
	int la,lb,k1,k2,i;
	char *c;
	la = strlen(a);
	lb = strlen(b);
	printf("%d\n",la);
	printf("%d\n",lb);
	k1 = 0;
	k2 = 0;
	if (la > lb){
		i=la;la=lb;lb=i;
		c=a;a=b;b=c;
	}
	if ((lb-la) > 1){
		return 0;
	}
	if (la == lb){
		for (i=0;i<la;i++){
			if (a[i] != b[i]){
				k1++;
			}
			if (k1 > 1){
				return 0;
			}
		}
		return 1;
	}
	else{
		i=0;
		while (i < la){
			if (k2 == 0){
				if (a[i] != b[i]){
					if (a[i] != b[i+1])
						return 0;
					k2 = 1;
				}
			}else{
					if (a[i] != b[i+1])
						return 0;
				}
			i++;
		}
		return 1;
	}
}

int main(){
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	printf("%s\n",s1);
	printf("%s\n",s2);
	if (connected(s1,s2)){
		printf("%d\n",1);
	}else{
		printf("%d\n",0);
	}
}