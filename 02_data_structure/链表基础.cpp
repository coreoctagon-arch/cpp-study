#include<bits/stdc++.h>
using namespace std;

struct LNode {
    int data;
    LNode* next;
};

typedef LNode* LinkList;

LNode* getNewNode(int val)
{
	LNode* p=new LNode;
	p->data=val;
	p->next=nullptr;
	return p;
}

int length(LinkList L)
{
	LinkList p=L->next;
	int cnt=0;
	while(p!=nullptr)
	{
		p=p->next;
		cnt++;
	}
	return cnt;
}

LNode* locateElem(LinkList L,int x)
{
	LinkList p=L->next;
	while(p!=nullptr)
	{
		if(p->data==x) return p;
		p=p->next;
	}
	return nullptr;
}

bool insertElem(LinkList L,int i,int x)
{
	if(i<0 || i>length(L)) return false;
	LinkList p=L;
	LNode* tmp=getNewNode(x);
	for(int k=0;k<i;k++)
	{
		p=p->next;
	}
	tmp->next=p->next;
	p->next=tmp;
	return true;
}

bool deleteElem(LinkList L,int i,int &x)
{
	if(i<0 || i>=length(L)) return false;
	LinkList p=L;
	for(int k=0;k<i;k++)
	{
		p=p->next;
	}
	LinkList tmp=p->next;
	p->next=p->next->next;
	delete tmp;
	return true;
}

LinkList createByTail(int a[],int n)
{
	LinkList head=getNewNode(0);
	LinkList p=head;
	for(int i=0;i<n;i++)
	{
		LinkList tmp=getNewNode(a[i]);
		p->next=tmp;
		p=tmp;
	}
	return head;
}

void deleteAllx(LinkList L,int x)
{
	LNode* pre=L;
	LNode* cur=L->next;
	while(cur!=nullptr)
	{
		if(cur->data==x)
		{
			pre->next=cur->next;
			LNode* tmp=cur;
			cur=cur->next;
			delete tmp;
			continue;
		}
		pre=cur;
		cur=cur->next;
	}
}

bool deleteMin(LinkList L,int &x)
{
	LinkList pre=L;
	LinkList p=L->next;
	if(p==nullptr) return false;
	
	LinkList minpre=L;
	LinkList minnode=L->next;
	
	while(p!=nullptr)
	{
		if(p->data < minnode->data)
		{
			minnode=p;
			minpre=pre;
		}
		pre=p;
		p=p->next;
	}
	
	minpre->next=minnode->next;
	delete minnode;
	return true;
}

void deleteDuplicateSorted(LinkList L)
{
	LinkList p=L->next;
	while(p!=nullptr && p->next!=nullptr)
	{
		LNode* q=p->next;
		if(p->data == q->data)
		{
			p->next=q->next;
			delete q;
		}
		else
		{
			p=p->next;
		}
	}
}

void reverseList1(LinkList L)//method 1
{
	//我没明白啥是头插法逆置
	LNode* ppre=nullptr;
	LNode* pcur=L->next;
	if(pcur==nullptr) return;
	LNode* pnext=pcur->next;
	while(pnext!=nullptr)
	{
		pcur->next=ppre;
		ppre=pcur;
		pcur=pnext;
		pnext=pnext->next;
	}
	pcur->next=ppre;
	L->next=pcur;
}

void reverseList2(LinkList L)
{
	LNode* p=L->next;
	L->next=nullptr;
	while(p!=nullptr)
	{
		LNode* next=p->next;
		p->next=L->next;
		L->next=p;
		p=next;
	}
}

void oddBeforeEven(LinkList L)//!!!!!
{
	LNode* pa=L;
	LNode* preb=L;
	LNode* pb=L->next;
	if(pb==nullptr) return;
	while(pb!=nullptr)
	{
		if(pb->data % 2 == 1)
		{
			LNode* tmp=pb;
			pb=pb->next;
			preb->next=tmp->next;
			tmp->next=pa->next;
			pa->next=tmp;
			pa=pa->next;
			continue;
		}
		preb=pb;
		pb=pb->next;
	}
	//preb->next=nullptr;
}

void deleteLessThanX(LinkList L,int x)
{
	LNode* pre=L;
	LNode* cur=L->next;
	
	while(cur!=nullptr)
	{
		if(cur->data < x)
		{
			LNode* tmp=cur;
			pre->next=cur->next;
			cur=cur->next;
			delete tmp;
			continue;
		}
		pre=cur;
		cur=cur->next;
	}
}

bool deleteRangeValue(LinkList L,int s,int t)
{
	if(s>t) return false;
	LNode* pre=L;
	LNode* cur=L->next;
	
	while(cur!=nullptr)
	{
		if(cur->data >= s && cur->data <= t)
		{
			pre->next=cur->next;
			delete cur;
			cur=pre->next;
		}
		else
		{
			pre=cur;
			cur=cur->next;
		}
	}
	return true;
}

void splitOddEvenPosition(LinkList L,LinkList &A,LinkList &B)
{
	LinkList Atail=A;
	LinkList Btail=B;
	
	int flag=0;
	LNode* p=L;
	while(p!=nullptr)
	{
		p=p->next;
		flag++;
		if(flag%2 != 0)
		{
			Atail->next=p;
			Atail=p;
		}
		else
		{
			Btail->next=p;
			Btail=p;
		}
	}
	Atail->next=nullptr;
	Btail->next=nullptr;
}

void swapHalf(LinkList L)
{
	LNode* fast=L;
	LNode* slow=L;
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	LinkList fronthead=L->next;
	LinkList backhead=slow->next;
	
	if(backhead==nullptr) return;
	
	slow->next=nullptr;
	L->next=backhead;
	LNode* p=backhead;
	while(p->next!=nullptr)
	{
		p=p->next;
	}
	p->next=fronthead;
}

LinkList mergeSorted(LinkList A,LinkList B)
{
	LinkList Bhead=B->next;
	B->next=nullptr;
	delete B;
	LNode* prev=A,*cura=A->next,*curb=Bhead;
	while(cura!=nullptr && curb!=nullptr)
	{
		if(cura->data < curb->data)
		{
			prev=cura;
			cura=cura->next;
		}
		else
		{
			LNode* next=curb->next;
			curb->next=nullptr;
			prev->next=curb;
			curb->next=cura;
			prev=prev->next;
			curb=next;
		}
	}
	prev->next=curb;
//	if(cura==nullptr) 
//	{
//		while(curb!=nullptr)
//		{
//			LNode* next=curb->next;
//			curb->next=nullptr;
//			prev->next=curb;
//			prev=curb;
//			curb=next;
//		}
//	}
	return A;
}

LinkList intersectionSorted(LinkList A,LinkList B)
{
	LinkList newhead=new LNode;
	newhead->next=nullptr;
	LNode* newtail=newhead;
	LNode* cura=A->next,*curb=B->next;
	while(cura!=nullptr && curb!=nullptr)
	{
		if(cura->data < curb->data)
		{
			cura=cura->next;
		}
		else if(cura->data > curb->data)
		{
			curb=curb->next;
		}
		else
		{
			LNode* tmp=new LNode;
			tmp->data=cura->data;
			tmp->next=nullptr;
			newtail->next=tmp;
			newtail=tmp;
			cura=cura->next;
			curb=curb->next;
		}
	}
	return newhead;
}

LNode* findMiddle(LinkList L)
{
	LNode* fast=L->next;
	LNode* slow=L->next;
	
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	return slow;
}

bool hasCycle(LNode* head)
{
	LNode* fast=head;
	LNode* slow=head;
	
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(fast==slow)
		{
			return true;
		}
	}
	
	return false;
}

LNode* detectCycle(LNode* head)
{
	LNode* fast=head;
	LNode* slow=head;
	
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
		
		if(fast==slow)
		{
			LNode* p=head;
			while(p!=slow)
			{
				p=p->next;
				slow=slow->next;
			}
			return p;
		}
	}
	
	return nullptr;
}

void deleteEven(LinkList L)
{
	LNode* prev=L;
	LNode* cur=L->next;
	
	while(cur!=nullptr)
	{
		if(cur->data % 2 == 0)
		{
			LNode* next=cur->next;
			prev->next=next;
			delete cur;
			cur=next;
		}
		else
		{
			prev=cur;
			cur=cur->next;
		}
	}
}

void deleteGreaterThanPrev(LinkList L)
{
	LNode* prev=L->next;
	if(prev->next==nullptr) return;
	LNode* cur=prev->next;
	
	while(cur!=nullptr)
	{
		if(prev->data < cur->data)
		{
			prev->next=cur->next;
			delete cur;
			cur=prev->next;
		}
		else
		{
			prev=cur;
			cur=cur->next;
		}
	}
}

void splitPositiveNonpositive(LinkList L, LinkList &A, LinkList &B)
{
	A=new LNode;A->next=nullptr;
	LNode* Atail=A;
	B=new LNode;B->next=nullptr;
	LNode* Btail=B;
	
	LNode* p=L->next;
	while(p!=nullptr)
	{
		if(p->data > 0)
		{
			LNode* next=p->next;
			p->next=nullptr;
			Atail->next=p;
			Atail=p;
			p=next;
		}
		else
		{
			LNode* next=p->next;
			p->next=nullptr;
			Btail->next=p;
			Btail=p;
			p=next;
		}
	}
	L->next=nullptr;
}

void splitHalf(LinkList L, LinkList &A, LinkList &B)
{
	LNode* fast=L;
	LNode* slow=L;
	
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	A=new LNode;
	B=new LNode;
	A->next=L->next;
	B->next=slow->next;
	slow->next=nullptr;
	
	L->next=nullptr;
}

void deleteDuplicateUnsorted(LinkList L)
{
	LNode* p=L->next;
	while(p!=nullptr)
	{
		LNode* cur=p->next;
		LNode* prev=p;
		while(cur!=nullptr)
		{
			if(cur->data==p->data)
			{
				prev->next=cur->next;
				delete cur;
				cur=prev->next;
			}
			else
			{
				prev=cur;
				cur=cur->next;
			}
		}
		p=p->next;
	}
}

void reverseEceryK(LinkList L,int k)
{
	
}

void reoroderFirstLast(LinkList L)
{
	LNode* fast=L;
	LNode* slow=L;
	while(fast!=nullptr && fast->next!=nullptr)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	
	LNode* second=slow->next;
	slow->next=nullptr;
	
	LNode* pre=nullptr;
	LNode* cur=second;
	while(cur!=nullptr)
	{
		LNode* next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	second=pre;
	LNode* first=L->next;
	
	LNode* newtail=L;
	LNode* cura=first,*curb=second;
	while(cura!=nullptr && curb!=nullptr)
	{
		LNode* next1=cura->next;
		cura->next=nullptr;
		newtail->next=cura;
		newtail=cura;
		cura=next1;
		
		LNode* next2=curb->next;
		curb->next=nullptr;
		newtail->next=curb;
		newtail=curb;
		curb=next2;
	}
	if(cura!=nullptr) newtail->next=cura;
	if(curb!=nullptr) newtail->next=curb;
}

bool deleteKthFromEnd(LinkList L,int k,int& x)
{
	if(k<=0) return false;
	LNode* fast=L->next;
	LNode* slowprev=L;
	for(int i=0;i<k;i++)
	{
		if(fast==nullptr) return false;
		fast=fast->next;
	}
	while(fast!=nullptr)
	{
		fast=fast->next;
		slowprev=slowprev->next;
	}
	LNode* cur=slowprev->next;
	slowprev->next=cur->next;
	x=cur->data;
	
	delete cur;
	return true;
}

struct DNode {
    int data;
    DNode* prior;
    DNode* next;
};

typedef DNode* DLinkList;

bool insertNextDNode(DNode* p,DNode* s)
{
	if(p==nullptr || s==nullptr) return false;
	
	if(p->next==nullptr) 
	{
		p->next=s;
		s->prior=p;
		s->next=nullptr;
		return true;
	}
	
	DNode* next=p->next;
	p->next=s;
	s->prior=p;
	s->next=next;
	next->prior=s;
	return true;
}

bool deleteNextDNode(DNode* p,int &x)
{
	if(p==nullptr || p->next==nullptr) return false;
	
	DNode* del=p->next;
	DNode* next=del->next;
	x=del->data;
	delete del;
	
	p->next=next;
	if(next==nullptr) return true;
	next->prior=p;
	return true;
}

bool isEmptyCircular(LinkList L)//???
{
	if(L->next==L) return true;
	return false;
}

int main()
{
	
	return 0;
}