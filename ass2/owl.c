 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include "Graph.h"

char words[1000][20];
int path[1000]={0};
int owl[1000][1000]={{-1}};
int notebefore[1000]={0};
int solu[1000][1000]={{-1}};
int x[1000]={-1};
int maxpath,pathnum;

int connected(char a[],char b[]){
	int la,lb,k1,k2,i;
	char *c;
	la = strlen(a);
	lb = strlen(b);
	// printf("%d\n",la);
	// printf("%d\n",lb);
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

void readGraph(int v, Graph g){
	int i,j;
	for (i=0;i<v;i++){
		for (j=0;j<v;j++){
			if (i != j && connected(words[i],words[j])){
				insertEdge(newEdge(i,j),g);
			}
		}
	}
}

void findowl(int v, Graph g){
	int i,j,k;

	for (i=0;i<v-1;i++){
		for(j=i+1;j<v;j++){
			if (isEdge(newEdge(i,j),g) == 1){
				if (path[i] + 1 > path[j]){
					for (k=0;k<notebefore[j];k++){
						owl[j][k]=-1;
					}
					notebefore[j]=1;
					owl[j][0]=i;
					path[j]=path[i]+1;
					if (path[j]>maxpath){
						maxpath=path[j];
					}
				}else {
					if (path[i] +1 == path[j]){
						notebefore[j]++;
						owl[j][notebefore[j]-1]=i;
					}
				}
			}
		}
	}
}


void printt(int node,int x[],int s){
	int i,j;
	if (notebefore[node] != 0){
		for (i=0;i<notebefore[node];i++){
			x[s]=node;
			printt(owl[node][i],x,s+1);
			x[s+1]=-1;
			// if (path[node] != maxpath){
			// 	printf(" %s ->",words[node]);
			// 		}else{
			// 	printf(" %s\n",words[node]);
			// }
		}
	}else{
		x[s]=node;
		for (j=0;j<maxpath+1;j++){
			// printf("%d ",x[j]);
			solu[pathnum][maxpath-j]=x[j];
		}
		pathnum++;
		// printf("\n");
	}

}

int change(int a[],int b[]){
	int i;
	for (i=0;i<maxpath+1;i++){
		if (a[i] > b[i]){
			return(1);
		}else{
			if (a[i] < b[i]){
				return(0);
			}
		}
	}
	return(0);
}

int main(int argc, char **argv){
	// char *wordsline=malloc(sizeof(char)*2048);
	
	char word[20];
	int l,i,v,j,k;
	int input;
	int p[1000];
	l=-1;
	v=-1;
	do{
		input = getchar();
		if (input == EOF){
			break;
		}
		if (!islower(input)){
			if (strlen(word) > 0){
				v++;
				for (i=0;i<=l;i++){
					words[v][i]=word[i];
				}
				l=-1;
				memset(word, '\0', 20);
			}
		}else{
			l++;
			word[l]=input;

		}
	}while (1);
	if (strlen(word) > 0){
		v++;
		for (i=0;i<=l;i++){
			words[v][i]=word[i];
		}
	}
	v++;
	printf("Dictionary\n");
	for (i=0;i<v;i++){
		printf("%d: %s\n",i,words[i]);
	}
	Graph g=newGraph(v);
	readGraph(v, g);
	// sort(v);
	maxpath=0;pathnum=0;
	findowl(v,g);
	showGraph(g);
	printf("Longest ladder length: %d\n",maxpath+1);
	printf("Longest ladders:\n");
	for (i=0;i<v;i++){
		if (path[i] == maxpath){
			printt(i,x,0);
		}
	}
	// for (i=0;i<pathnum-1;i++){
	// 	for(j=i+1;j<pathnum;j++){
	// 		if (change(solu[i],solu[j])){
	// 			for (k=0;k<maxpath+1;k++){
	// 				p[k]=solu[i][k];
	// 				solu[i][k]=solu[j][k];
	// 				solu[j][k]=p[k];
	// 			}
	// 		}
	// 	}			
	// }
	for (i=0;i<pathnum;i++){
		printf("%d:",i+1);
		for (j=0;j<maxpath+1;j++){
			if (j != maxpath){
				printf(" %s ->",words[solu[i][j]]);
			}else{
				printf(" %s\n",words[solu[i][j]]);
			}
		}
	}	
}
