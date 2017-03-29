#include <stdio.h>
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


int main() {

	int e []  = {9,2,3,4,5};
	bubble(e,5);
	int i;
	for( i=0; i<5; i++)

	{
		printf("a[%d]=%d\n",i,e[i]);
	}
	return 0;
}
