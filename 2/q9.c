#include <stdio.h>
#include <stdlib.h>
int max_prof(int a[],int n){
	int sum=0;
	for(int i=0;i<n-1;i++){
		a[i]=a[i+1]-a[i];
		if(a[i]>0){sum+=a[i];}
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){scanf("%d",&a[i]);}
	printf("%d", max_prof(a,n));
	return 0;
}