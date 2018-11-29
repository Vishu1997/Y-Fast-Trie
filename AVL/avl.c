#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int * ReadFile(char * filename);

#define FREQ 2.60e9

unsigned long long rdtsc()
{
  unsigned long long int x;
  unsigned a, d;

  __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

  return ((unsigned long long)a) | (((unsigned long long)d) << 32);
}

int main(){
	avl_node * root = NULL;
	int t;
	scanf("%d", &t);
	int n;
	for(int i=0;i<t;i++){
		scanf("%d", &n);
		root = insertNode(root, n);
	}
	unsigned long long start, end;
	int *Search=ReadFile("../Oper_10m32.txt");
	start = rdtsc();
	for(int i=1;i<=Search[0];i++){
		if(searchNode(root, Search[i]) == NULL)
			printf("%d\n", Search[i]);
	}
	avl_node *pred=NULL, *suc=NULL;
	for(int i=1;i<=Search[0];i++){
		findPredSuc(root, &pred, &suc, Search[i]);
		//printf("%d %d\n", pred->value, suc->value);
	}
  for(int i=1;i<=Search[0];i++){
    root = deleteNode(root, Search[i]);
  }
	end = rdtsc();
	printf("%lf\n", (end - start) / FREQ);
}

int * ReadFile(char * filename){
	FILE *f=fopen(filename, "r");
	char buf[16];
	fgets(buf, 16, f);
	//printf("%s", buf);
	int t=atoi(buf);
	int *s=malloc(sizeof(int)*(t+1));
	int i=0;
	s[i++]=atoi(buf);
	while(fgets(buf, 16, f))
		s[i++]=atoi(buf);
	return s;
}
