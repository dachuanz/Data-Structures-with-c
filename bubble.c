#include <stdio.h>


/**
冒泡排序

*/
void bubble(int *a,int n) /*定义两个参数：数组首地址与数组大小*/

{

	int i,j,temp;

	for(i=0; i<n-1; i++)

		for(j=i+1; j<n; j++) /*注意循环的上下限*/

			if(a[i]>a[j]) {

				temp=a[i];

				a[i]=a[j];

				a[j]=temp;

			}

}

/**


选择排序
*/

void choice(int *a,int n)

{

	int i,j,k,temp;

	for(i=0; i<n-1; i++) {

		k=i; /*给记号赋值*/

		for(j=i+1; j<n; j++)

			if(a[k]>a[j]) k=j; /*是k总是指向最小元素*/

		if(i!=k) { /*当k!=i是才交换，否则a[i]即为最小*/

			temp=a[i];

			a[i]=a[k];

			a[k]=temp;

		}

	}

}
/**

快速排序 
*/

void quick(int *a,int i,int j)

{

	int m,n,temp;

	int k;

	m=i;

	n=j;

	k=a[(i+j)/2]; /*选取的参照*/

	do {

		while(a[m]<k&&m<j) {
			m++;   /* 从左到右找比k大的元素*/
		}

		while(a[n]>k&&n>i) {
			n--;   /* 从右到左找比k小的元素*/
		}

		if(m<=n) { /*若找到且满足条件，则交换*/

			temp=a[m];

			a[m]=a[n];

			a[n]=temp;

			m++;

			n--;

		}

	} while(m<=n);

	if(m<j) quick(a,m,j); /*运用递归*/

	if(n>i) quick(a,i,n);

}


int main() {

	int e []  = {9,2,3,4,5,88,};
	quick(e,0,5);
	int i;
	for( i=0; i<6; i++)

	{
		printf("a[%d]=%d\n",i,e[i]);
	}
	return 0;
}
