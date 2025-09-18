#include<iostream>
#include<stdlib.h>
using namespace std;
#define Maxsize 100
typedef int ElemType;
typedef struct S{
	ElemType data[Maxsize];
	int length;
}SqList;
void CreateList(SqList * &L,ElemType a[],int n){
	int i=0,k=0;
	L=(SqList*)malloc(sizeof(SqList));
	while(i<n){
		L->data[i]=a[i];
		k++,i++;
	}
	L->length=k;
}
void IniList(SqList * &L){
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList*&L){
	free(L);
}
bool ListEmpty(SqList*&L){
	return (L->length==0);
}
int ListLength(SqList*&L){
	return (L->length);
}
void DispList(SqList*L){
	for(int i=0;i<L->length;++i){
		printf("%d",L->data[i]);
		printf("\n");
	}
}
bool GetElem(SqList*&L,int i,int &e){
	if(i<1||i>L->length){
		return false;
	}
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList*L,int e){
	for(int i=0;i<L->length;++i){
		if(L->data[i]==e){
			return (i+1);
		}
	}
	return 0;
}
bool ListInsert(SqList*&L,int i,int e){
	if(i<1||i>L->length+1||L->length==Maxsize){
		return false;
	}
	i--;
	for(int j=L->length;j>i;--j){
		L->data[j]=L->data[j-1];
	}
		L->data[i]=e;
	L->length++;
	return true;
}
bool ListDelete(SqList*&L,int i,int& e){
	if(i<1||i>L->length){
		return false;
	}
	i--;
	e=L->data[i];
	for(int j=i;j<L->length;++j){
		L->data[j]=L->data[j+1];
	}
	L->length--;
	return true;
}
int main(){
	SqList*L=NULL;
	cout<<"InitList:"<<endl;
	IniList(L);
	cout<<L->length<<endl;
	cout<<"Empty:"<<endl;
	if(ListEmpty(L)){
		cout<<"空"<<endl;
	} else{
		cout<<"不为空"<<endl;
	}
	cout<<"ListInsert:"<<endl;
	for(int i=1;i<=5;++i){
		if(ListInsert(L,i,i*10)){
			cout<<"在位置"<<i<<"插入"<<i*10<<endl;
		}else{
			cout<<"在位置"<<i<<"插入"<<i*10<<"失败"<<endl;
		}
	}
	cout<<"DispList:"<<endl;
	DispList(L);
	cout<<"ListLength:"<<endl;
	cout<<ListLength(L)<<endl;
	cout<<"GetElem:"<<endl;
	int getelem;
	if(GetElem(L,3,getelem)){
		cout<<"位置3的元素："<<getelem<<endl;
	}else{
		cout<<"位置3的元素获取失败"<<endl;
	}
	cout<<"LocateElem:"<<endl;
	int l=LocateElem(L,20);
	if(l!=0){
		cout<<"元素20的位置:"<<l<<endl;
	}else{
		cout<<"未找到元素20"<<endl;
	}
	cout<<"ListDelete:"<<endl;
	int d;
	if(ListDelete(L,3,d)){
		cout<<"删除位置3的元素成功"<<endl;
	}else{
		cout<<"删除位置3的元素不成功"<<endl;
	}
	cout<<"DispList:"<<endl;
	DispList(L);
	cout<<"CreateList:"<<endl;
	int b[]={100,200,300,400,500};
	int n=sizeof(b)/sizeof(b[0]);
	SqList*L2=NULL;
	CreateList(L2,b,n);
	DispList(L2);
	cout<<"DestroyList:"<<endl;
	DestroyList(L2);
	DestroyList(L);
	
	
}
