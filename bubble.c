#include <stdio.h>


/**
ð������

*/
void bubble(int *a,int n) /*�������������������׵�ַ�������С*/

{

	int i,j,temp;

	for(i=0; i<n-1; i++)

		for(j=i+1; j<n; j++) /*ע��ѭ����������*/

			if(a[i]>a[j]) {

				temp=a[i];

				a[i]=a[j];

				a[j]=temp;

			}

}

/**


ѡ������
*/

void choice(int *a,int n)

{

	int i,j,k,temp;

	for(i=0; i<n-1; i++) {

		k=i; /*���ǺŸ�ֵ*/

		for(j=i+1; j<n; j++)

			if(a[k]>a[j]) k=j; /*��k����ָ����СԪ��*/

		if(i!=k) { /*��k!=i�ǲŽ���������a[i]��Ϊ��С*/

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
