#include<bits/stdc++.h>
using namespace std;

const int MaxSize=100;

struct SqList{
	int data[MaxSize];
	int length;
};

void print(const SqList& L)
{
	for(int i=0;i<L.length;i++)
	{
		cout<<L.data[i]<<" ";
	}
	cout<<endl;
}

bool insertElem(SqList& L,int i,int x)
{
	if(i<0 || i>L.length) return false;
	
	for(int k=L.length-1;k>=i;k--)
	{
		L.data[k+1]=L.data[k];
	}
	L.data[i]=x;
	L.length++;
	return true;
}

bool deleteElem(SqList& L,int i,int& x)
{
	if(i<0 || i>=L.length) return false;
	x=L.data[i];
	for(int k=i+1;k<L.length;k++)
	{
		L.data[k-1]=L.data[k];
	}
	L.length--;
	return true;
}

int locateElem(SqList L,int x)
{
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]==x) return i;
	}
	return -1;
}

void reverseList(SqList& L)
{
	if(L.length==0) return;
	int l=0,r=L.length-1;
	while(l<r)
	{
		swap(L.data[l],L.data[r]);
		l++;r--;
	}
}

void deleteAllX(SqList& L,int x)//method 2
{
	int k=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]!=x)
		{
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
}

//void deleteAllX(SqList& L,int x)//method 1
//{
//	for(int i=0;i<L.length;i++)
//	{
//		if(L.data[i]==x)
//		{
//			for(int j=i+1;j<L.length;j++)
//			{
//				L.data[j-1]=L.data[j];
//			}
//			L.length--;
//			i--;//important
//		}
//	}
//}

void deleteDuplicateSorted(SqList& L)
{
	int i=0;
	for(int j=1;j<L.length;j++)
	{
		if(L.data[i]!=L.data[j])
		{
			i++;
			L.data[i]=L.data[j];
		}
	}
	L.length=i+1;
}

bool deleteRangeIndex(SqList& L,int s,int t)
{
	if(s<0 || s>L.length || t<0 || t>L.length) return false;
	if(s>t) return false;
	int i=s;
	for(int j=t+1;j<L.length;j++)
	{
		L.data[i]=L.data[j];
		i++;
	}
	L.length=i;
	return true;
}

bool deleteMin(SqList& L,int& x)
{
	if(L.length==0) return false;
	int pos=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[pos]!=min(L.data[pos],L.data[i])) pos=i;
	}
	x=L.data[pos];
	L.data[pos]=L.data[L.length-1];
	L.length--;
	return true;
}

bool deleteValueRange(SqList& L,int s,int t)
{
	if(s>t) return false;
	int k=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]<s || L.data[i]>t)
		{
			L.data[k]=L.data[i];
			k++;
		}
	}
	L.length=k;
	return true;
}

void oddBeforeEven(SqList& L)
{
	int l=0,r=L.length-1;
	while(l<r)
	{
		while(L.data[l]%2==0)
		{
			swap(L.data[l],L.data[r]);
			r--;
		}
		l++;
	}
}

void negetiveBeforeNonnegative(SqList& L)
{
	int l=0,r=L.length-1;
	while(l<r)
	{
		while(l<r && L.data[l]<0)
		{
			l++;
		}
		while(l<r && L.data[r]>=0)
		{
			r--;
		}
		if(l<r)
		{
			swap(L.data[l],L.data[r]);
			l++;
			r--;
		}
	}
}

//bool deleteSortedValueRange(SqList& L,int s,int t)//method 1
//{
//	if(s>t) return false;
//	int k=0;
//	for(int i=0;i<L.length;i++)
//	{
//		if(L.data[i]<s || L.data[i]>t)
//		{
//			L.data[k]=L.data[i];
//			k++;
//		}
//	}
//	L.length=k;
//	return true;
//}

bool deleteSortedValueRange(SqList& L,int s,int t)//method 2
{
	if(s>t) return false;
	int pos1=0,pos2=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]<s) pos1=max(pos1,i+1);
		if(L.data[i]<=t) pos2=max(pos2,i+1);
	}
	int len=pos2-pos1;
	for(int j=pos2;j<L.length;j++)
	{
		L.data[j-len]=L.data[j];
	}
	L.length-=len;
	return true;
}

void leftRotate(SqList& L,int p)
{
	p%=L.length;
	int l=0,r=L.length-1;
	while(l<r)
	{
		swap(L.data[l],L.data[r]);
		l++;
		r--;
	}
	l=0,r=L.length-1-p;
	while(l<r)
	{
		swap(L.data[l],L.data[r]);
		l++;
		r--;
	}
	l=L.length-p,r=L.length-1;
	while(l<r)
	{
		swap(L.data[l],L.data[r]);
		l++;
		r--;
	}
}

void deleteDuplicateUnsorted(SqList& L)
{
	for(int i=0;i<L.length;i++)
	{
		int x=L.data[i];
		for(int j=i+1;j<L.length;j++)
		{
			if(L.data[j]==x)
			{
				for(int k=j+1;k<L.length;k++)
				{
					L.data[k-1]=L.data[k];
				}
				L.length--;
				j--;
			}
		}
	}
}

void stableNegativeBeforeNonnegative(SqList& L)
{
	int k=0;
	for(int i=0;i<L.length;i++)
	{
		if(L.data[i]<0)
		{
			int tmp=L.data[i];
			for(int j=i;j>k;j--)
			{
				L.data[j]=L.data[j-1];
			}
			L.data[k]=tmp;
			k++;
		}
	}
}

int main()
{
	SqList L = {{3, -1, 0, -5, 7, -2, 4}, 7};
	int p=3;
stableNegativeBeforeNonnegative(L);
print(L);
//cout<<x<<endl;
	return 0;
}