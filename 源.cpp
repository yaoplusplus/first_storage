#include<iostream>
using namespace std;
//节点
template <class T>
class chainNode {

public:
	T element;
	chainNode<T>* next;
	chainNode()
	{
		next = 0;
	}
	chainNode(const T&element)
	{
		this->element = element;
		next = 0;
	}
	chainNode(const T& element,chainNode<T>*next)
	{
		this->element = element;
		this->next = next;
	}
};

//链表
template <class T>
class chain {
public:
	int chainsize;
	chainNode<T>* firstnode;
	chainNode<T>* lastnode;

	chain() {
		firstnode = lastnode = 0;
		chainsize = 0;
	}
	void insert(int index, const T& element)
	{
		if (index == 0 || index > chainsize + 1)
		{
			cout << "ileagle address" << endl;

			return;
		}

		if (firstnode == 0)
		{
			firstnode = new chainNode<T>(element);
			lastnode = firstnode;      //the same node

			chainsize++;
			return;
		}
		chainNode<T>* newnode = new chainNode<T>(element);
		if (index == 1) //头部
		{
			newnode->next = firstnode;
			firstnode = newnode;
			chainsize++;
			return;
		}
		if (index == chainsize + 1)// 尾部
		{
			lastnode->next = newnode;
			lastnode = newnode;
			chainsize++;
			return;
		}
		if (index > 1 && index <= chainsize) //内部
		{
			chainNode<T>* current = firstnode;

			int indexcount = 2;
			while (current != 0 && indexcount < index)
			{
				indexcount++;
				current = current->next;
			}
			
			newnode->next = current->next;
			current->next = newnode;
			chainsize++;
			return;
		}
		/*cout <<"times:"<<count << "chainsize:" << chainsize << endl;*/
		return;
	}

	void push_back(const T& element)
	{
		chainNode<T>* newnode = new chainNode<T>(element);
		if (firstnode == 0)
		{
			firstnode = lastnode = newnode;
		}
		else 
		{
			lastnode->next = newnode;
			lastnode = newnode;
		}
		chainsize++;
	}
	//void output(ostream &out) const
	//{
	//	for (chainNode <T>* current = firstnode; current != 0; current = current->next)
	//	{
	//		out << current->element << " ";
	//	}
	//	ostream& operator <<(ostream & out, const chain<T> & x)
	//	{
	//		x.output(out); return out;
	//	}
	//}
	void display()
	{
		chainNode <T>* current = firstnode;
		while (current!= 0)
		{
			cout << current->element << " ";
			current = current->next;
		}
	}
};
template <class T>
void meld(chain<T>& a, chain<T>& b) {
	chain<T> c;
	chainNode<T>* cNode = a.chain<T>::firstnode;
	chainNode<T>* aNode = a.chain<T>::firstnode;
	chainNode<T>* bNode = b.chain<T>::firstnode;
	if (a.chain<T>::chainsize >= b.chain<T>::chainsize) { //a长于等于b
		for (int j = 0; j != b.chain<T>::chainsize; j++) {
			c.push_back(aNode->element);
			aNode = aNode->next;
			c.push_back(bNode->element);
			bNode = bNode->next;
		}//四步：两个赋值，两个函数调用。
		int i = a.chain<T>::chainsize - b.chain<T>::chainsize;
		for (int j = 0; j != i; j++) {
			c.push_back(aNode->element);
			aNode = aNode->next;
		}//两步：一赋值，一调用。 
		//时间复杂度为：4*b+2*(a-b)=2*a+b） (假设a>b)
		//显然具有线性复杂度。
	}
	else {
		for (int j = 0; j != a.chain<T>::chainsize; j++) {
			c.push_back(aNode->element);
			aNode = aNode->next;
			c.push_back(bNode->element);
			bNode = bNode->next;
		}
		int i = b.chain<T>::chainsize - a.chain<T>::chainsize;
		for (int j = 0; j != i; j++) {
			c.push_back(bNode->element);
			bNode = bNode->next;
		}
	}
	c.display();
	cout << "end" << endl;
}

int main() 
{
	chain<int>a;
	chain<int>b;
	a.insert(1,1);
	/*b.insert(1,3); *///  插入出问题了
	a.insert(1,2);
	a.insert(2, 3);
	
	/*cout << "-----------" << endl;
	a.display(); cout << "end" << endl;
	b.display(); cout << "end" << endl;*/
	/*for (int i = 1; i < 21;i++)
	{
		a.insert(i,i);
	}
	for (int j = 21; j < 41; j++)
	{
		a.insert(j, j);
	}*/
	meld(a, b);
	a.display(); cout << endl;
	b.display();
}








