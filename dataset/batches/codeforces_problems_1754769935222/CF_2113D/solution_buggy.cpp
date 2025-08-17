#include<iostream>
#include<algorithm>
using namespace std;
int score(int a[],int b[],int n){
	int pa=0,pb=0,sca=0;
	for(int turn=0;turn<n;turn++){
	    if(a[pa]>b[pb]){
	    	sca++;
	    	pa++;
		}
		else pb++;
	}
	return sca;
}
int main(){
	int t,n,a[200001],b[200001],sca,tt[50001],f=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		for(int q=0;q<n;q++){
			cin>>b[q];
		}
		sca=score(a,b,n);
		for(int s=0;s<n-1;s++){
			for(int d=s+1;d<n;d++){
				swap(a[s],a[d]);
				sca=max(sca,score(a,b,n));
				swap(a[s],a[d]);
			}
		}
		tt[f]=sca;
		f++;
	}
	for(int r=0;r<t;r++){
		cout<<tt[r]<<endl;
	}
	return 0;
}