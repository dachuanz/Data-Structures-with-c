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

�������������������׵�ַ�������С*
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
/**

��������
*/

void quick(int *a,int i,int j)

{

	int m,n,temp;

	int k;

	m=i;

	n=j;

	k=a[(i+j)/2]; /*ѡȡ�Ĳ���*/

	do {

		while(a[m]<k&&m<j) {
			m++;   /* �������ұ�k���Ԫ��*/
		}

		while(a[n]>k&&n>i) {
			n--;   /* ���ҵ����ұ�kС��Ԫ��*/
		}

		if(m<=n) { /*���ҵ��������������򽻻�*/

			temp=a[m];

			a[m]=a[n];

			a[n]=temp;

			m++;

			n--;

		}

	} while(m<=n);

	if(m<j) quick(a,m,j); /*���õݹ�*/

	if(n>i) quick(a,i,n);

}



void insert(int *a,int n)

{

	int i,j,temp;

	for(i=1; i<n; i++) {

		temp=a[i]; /*tempΪҪ�����Ԫ��*/

		j=i-1;

		while(j>=0&&temp<a[j]) { /*��a[i-1]��ʼ�ұ�a[i]С������ͬʱ������Ԫ�������*/

			a[j+1]=a[j];

			j--;

		}

		a[j+1]=temp; /*����*/

	}

}

int main() {

	int e []  = {10,3,2,4,5,88,};
	insert(e,6);
	int i;
	for( i=0; i<6; i++)

	{
		printf("a[%d]=%d\n",i,e[i]);
	}
	return 0;
}
