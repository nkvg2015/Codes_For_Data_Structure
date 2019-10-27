#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
	int lar=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && a[l]>a[lar])
		lar=l;
	if(r<n && a[r]>a[lar])
		lar=r;
	if(lar!=i){
		swap(a[i],a[lar]);
		heapify(a,n,lar);
	}
}

void heapSort(int a[],int n){
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
	for(int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}

int main(){
	int a[]={2,4,1,4,5,2,9,5},n=8;
	heapSort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
