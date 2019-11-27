#include<stdio.h>
int LA[4]={3,5,8,11};
int LB[7]={2,6,8,9,11,15,20};
int LC[11];
int ai=0,bj=0;
int GetElem(int *Lb,int i,int bj){
	 return (bj=Lb[i]);
}
void ListInsert(int *LC,int k,int ai){
	LC[k]=ai;
}
int main(void){
	int i=1;
	int j=1;
	int k=0;
	int la_len=sizeof(LA)/sizeof(LA[0]);
	int lb_len=sizeof(LB)/sizeof(LB[0]);
	while((i<=la_len)&&(j<=lb_len)){
		ai=GetElem(LA,i-1,ai);
		bj=GetElem(LB,j-1,bj);
		if(ai<=bj){
			ListInsert(LC,k,ai);
			++k;
			++i;
		}
		else{
			ListInsert(LC,k,bj);
			++k;
			++j;
		}
	}
	while(i<=la_len){
		ai=GetElem(LA,i-1,ai);++i; ListInsert(LC,k,ai);++k;
	}
	while(j<=lb_len){
		bj=GetElem(LB,j-1,bj);++j; ListInsert(LC,k,bj);++k;
	}
	for(i=0;i<11;i++)
		printf("%d ",LC[i]);
}
