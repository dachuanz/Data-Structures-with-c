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


int main() {

	int e []  = {9,2,3,4,5,88,};
	choice(e,6);
	int i;
	for( i=0; i<6; i++)

	{
		printf("a[%d]=%d\n",i,e[i]);
	}
	return 0;
}
