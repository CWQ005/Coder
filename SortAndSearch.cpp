#include <ctime>
#include <cstdlib>
#include <iostream>
#define N 100
#define M 3           //��ʾ�ж��������򷽷���
using namespace std;

void swap(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}

void swap1(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void Random(int a[N]);
void bubbleSort(int a[N]);
void merge(int a[N],int left,int mid,int right);
void mergeSort(int a[N],int left,int right);
int partition(int a[N],int left,int right);
void qSort(int a[N],int left,int right);
void Sort(int a[N],int left,int right);
int binarySearch(int a[N],int element,int left,int right);

int main()
{
    int a[N];
	Random(a);
	
	for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"��������"<<endl;
    qSort(a,0,N);
	
	for(int i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<binarySearch(a,1000,0,N-1)<<endl;
	return 0;
}

/**
*ѡ��һ������
*/
void Sort(int a[N],int left,int right){
	switch(rand()%M + 1){
		case 1:
		    cout<<"ð������"<<endl;
		    bubbleSort(a);
			break;
		case 2:
		    cout<<"�鲢����"<<endl;
			mergeSort(a,left,right);
			break;
		case 3:
		    cout<<"��������"<<endl;
			qSort(a,left,right);
			break;
		default:
			break;
	}
}

/**
*����100��1000���ڵ������
*/
void Random(int a[N]){
    srand((int)time(NULL));
	for(int i=0;i<N;i++){
		a[i]=rand()%1000;
	}
}

/**
*ð������
*/
void bubbleSort(int a[N]){
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(a[j]<a[i])swap(a[i],a[j]);
		}
	}
}

/**
*�鲢����
*/
void merge(int a[N],int left,int mid,int right){
	int *A = a+left;
	int lb = mid-left;
	int *B = new int[lb];
	for(int i=0;i<lb;B[i]=A[i++]);
	int lc = right-mid;
	int *C = a+mid;
	for(int i=0,j=0,k=0;((j<lb)||(k<lc));){
		if((j<lb)&&(!(k<lc)||(B[j]<=C[k])))A[i++]=B[j++];
		if((k<lc)&&(!(j<lb)||(C[k]< B[j])))A[i++]=C[k++];
	}
    delete [] B;	
}
void mergeSort(int a[N],int left,int right){
	if(right-left<2)return;
	int mid=(right+left)>>1;
	mergeSort(a,left,mid);
	mergeSort(a,mid,right);
	merge(a,left,mid,right);
}

/**
*��������(�����⣬�����......)
*/
void qSort(int a[N],int left,int right){
	if(right-left<2)return;
	int mid = partition(a,left,right-1);
	qSort(a,left,mid);
	qSort(a,mid+1,right);
}
int partition(int a[N],int left,int right){
	//swap(a[left],a[left+(rand()%(right-left)+1)]);//Ϊ�θĳ�a[left+rand%(right-left+1)]ȴ���У�
	swap1(a[left],a[left+rand()%(right-left+1)]);    
	                                               /**
												   *�ѽ������ swap �����йأ����� swap1 �������ˣ�
												   *��Ϊ�� rand()%(right-left+1)=0 ʱ
												   *ִ��swap(a[left],a[left])��ʹ������ 0 ��
                                                   *���Ե�������Ԫ��Ҫִ�н�������ʱ�����swap1(&a,&b);												   
												   */
	int pivot=a[left];
	while(left<right){
	    while((left<right) && (pivot<=a[right]))right--;
	    a[left]=a[right];
	    while((left<right) && (a[left]<=pivot))left++;
        a[right]=a[left]; 
	} 
	a[left]=pivot;
	return left;
}
/**
*���ֲ��ң�
*/
int binarySearch(int a[N],int element,int left,int right){//0 <= left <= right < N;
	while(1<right-left){
		int mid=(right+left)>>1;
		(element<a[mid])?right=mid:left=mid;
	}
	return (element==a[left])?left:-1;
}










