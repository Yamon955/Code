#include <iostream>
using namespace std;
class HeapNode
{
public:
	operator double() const{return data;}
	int operator <= (HeapNode hn) const{return data<=hn.data;	}
	int operator <	(HeapNode hn) const{return data<hn.data;	}
	int operator >= (HeapNode hn) const{return data>=hn.data;	}
	int operator >	(HeapNode hn) const{return data>hn.data;	}
	int operator == (HeapNode hn) const{return data==hn.data;	}
    HeapNode(){}
    HeapNode(int id,double d)
    {
        ID=id;
        data=d;
    }
    int ID;
    double data;
};

class MaxHeap
{
public:
	MaxHeap(int n);     //构造函数，n表示堆中能够存储的最大元素个数
	void Insert(HeapNode heapNode);  //向堆中插入一个节点
	void DeleteMax(HeapNode &heapNode);  //删除堆中最大节点
private:
	int size;            //堆中实际元素的个数
	HeapNode *MH;        //存储堆中的节点
	
	void Delete(HeapNode &heapNode,int index);  //删除堆中标号为index的元素，index从1开始，即1表示最大元素
	void SiftUp(int index);          //将堆中标号为index的元素，向上调整，保证堆结构
	void SiftDown(int index);      //将堆中标号为index的元素，向下调整，保证堆结构
};

MaxHeap::MaxHeap(int n)
{
	size=0;
	MH=new HeapNode[n];
}

void MaxHeap::SiftUp(int index)
{
	if(index<=1)
		return;
	bool done=false;
	do
	{
		if(MH[index]>MH[index/2])
		{
			HeapNode tmp=MH[index];
			MH[index]=MH[index/2];
			MH[index/2]=tmp;
		}
		else
			done=true;
		index=index/2;
	}while(index>1&&!done);
}

void MaxHeap::SiftDown(int index)
{
	if(2*index>size)
		return;
	bool done=false;
	do
	{
		index=2*index;
		if(index+1<=size&&MH[index+1]>MH[index])
			index=index+1;
		if(MH[index/2]<MH[index])
		{
			HeapNode tmp=MH[index];
			MH[index]=MH[index/2];
			MH[index/2]=tmp;
		}
		else
			done=true;
	}while(2*index<=size&&!done);
}

void MaxHeap::Insert(HeapNode heapNode)
{
	size+=1;
	MH[size]=heapNode;
	SiftUp(size);
}

void MaxHeap::Delete(HeapNode &heapNode,int index)
{
	if(index<1||index>size)
	{
		return;
	}
	HeapNode x=MH[index],y=MH[size];
	heapNode=MH[index];
	size-=1;
	if(index==size+1)
		return;
	MH[index]=y;
	if(y>=x)
		SiftUp(index);
	else
		SiftDown(index);
}

void MaxHeap::DeleteMax(HeapNode &heapNode)
{
	Delete(heapNode,1);
}
int main()
{
    double data[]={13,3,4,2,6,15,67,21,88};

    MaxHeap *Maxhp=new MaxHeap(100);
    for(int i=0;i<9;i++)
    {
        HeapNode hp(i+1,data[i]);
        Maxhp->Insert(hp);
    }
    for(int i=1;i<=9;i++)
    {  HeapNode hp2;
       Maxhp->DeleteMax(hp2);
        cout<<hp2.data<<'\t';
    }
    
    return 0;
}