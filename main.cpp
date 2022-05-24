#include <iostream>
#include <string>
#include <stack>


using namespace std;

template<typename T>
class Queue
{
public:
	Queue() {}
	virtual ~Queue() {};

	T Database[10];

	int Cursor = -1;
	int Cursor2 = 0;

	void Push(T A)
	{
		//Cursor++;
		//Database[Cursor] = A;
		Database[++Cursor] = A;
	}

	void Pop()
	{
		Cursor2++;
	}

	T Top()
	{
		return Database[Cursor2];
	}
};


int main()
{
	Queue<int> IntQueue;

	for (int i = 1; i <= 10; ++i)
	{
		IntQueue.Push(i);
	}

	for (int i = 1; i <= 10; ++i)
	{
		cout << IntQueue.Top() << ", ";
		IntQueue.Pop();
	}

	//stack<float> FloatStackSTL;
	//for (int i = 1; i <= 10; ++i)
	//{
	//	FloatStackSTL.push(i * 1.1f);
	//}

	//for (int i = 1; i <= 10; ++i)
	//{
	//	cout << FloatStackSTL.top() << ", ";
	//	FloatStackSTL.pop();
	//}
	return 0;
}