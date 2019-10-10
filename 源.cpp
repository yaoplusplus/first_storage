#include<iostream>
using namespace std;
//�ڵ�
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

//����
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
		if (index == 1) //ͷ��
		{
			newnode->next = firstnode;
			firstnode = newnode;
			chainsize++;
			return;
		}
		if (index == chainsize + 1)// β��
		{
			lastnode->next = newnode;
			lastnode = newnode;
			chainsize++;
			return;
		}
		if (index > 1 && index <= chainsize) //�ڲ�
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
	if (a.chain<T>::chainsize >= b.chain<T>::chainsize) { //a���ڵ���b
		for (int j = 0; j != b.chain<T>::chainsize; j++) {
			c.push_back(aNode->element);
			aNode = aNode->next;
			c.push_back(bNode->element);
			bNode = bNode->next;
		}//�Ĳ���������ֵ�������������á�
		int i = a.chain<T>::chainsize - b.chain<T>::chainsize;
		for (int j = 0; j != i; j++) {
			c.push_back(aNode->element);
			aNode = aNode->next;
		}//������һ��ֵ��һ���á� 
		//ʱ�临�Ӷ�Ϊ��4*b+2*(a-b)=2*a+b�� (����a>b)
		//��Ȼ�������Ը��Ӷȡ�
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
	/*b.insert(1,3); *///  �����������
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








