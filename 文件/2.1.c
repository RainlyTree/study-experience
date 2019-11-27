#include<stdio.h>
#define bool int
#define flase 0
#define ture 1
int LA[4]={3,5,8,11};
int LB[7]={2,6,8,9,11,15,20};
int LC[9];
void GetElem(int *Lb,int i,int *Lc){
	Lc[i]=Lb[i];
}
bool LocateElem(int *La,int e){
	int i;
	bool reray=ture;
	for(i=0;i<4;i++){
		if(e==La[i])
			reray=flase;
	}
	return reray;
}
int main(void){
	int i,j;
	int LaLength=sizeof(LA)/sizeof(LA[0]);
	int LbLength=sizeof(LB)/sizeof(LB[0]);
	for(i=0;i<LaLength;i++)
		GetElem(LA,i,LC);
	for(i=0,j=0;i<LbLength;i++){
		if(LocateElem(LA,LB[i])){
			LC[j+4]=LB[i];
			j++;
		}
	}
	for(i=0;i<9;i++)
		printf("%d ",LC[i]);
	printf("\n");
	return 0;
}