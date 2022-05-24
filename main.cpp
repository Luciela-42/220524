#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

template<typename T>
class Stack
{
public:
	Stack() {}
	virtual ~Stack() {};

	T Database[10];

	int Cursor = -1;

	void Push(T A)
	{
		//Cursor++;
		//Database[Cursor] = A;
		Database[++Cursor] = A;
	}

	T Pop()
	{
		Cursor--;
	}

	T Top()
	{
		return Database[Cursor];
	}
};

template<typename T>
class Queue
{
public:		//접근 지정자
	Queue(int NewCapicity = 10)
	{
		Capicity = NewCapicity;
		Database = new int[Capicity];
		Size = 0;
		Front = 0;
		Rear = 0;
	}
	
	virtual ~Queue()
	{
		delete[] Database;
	}

	//Accessor
	int GetSize() { return Size; }
	int GetCapicity() { return Capicity; }

	bool Push(int Data)
	{
		if (Size > Capicity)
		{
			return false;
		}

		Database[Rear++] = Data;
		Rear = Rear % Capicity;
		Size++;

		return true;
	}

	int Pop()
	{
		if (Size <= 0)
		{
			return -1;
		}

		T Number = Database[Front++];
		Front = Front % Capicity;

		Size--;

		return Number;
	}
protected:
	T* Database;
	int Capicity;
	int Size;
	int Front;
	int Rear;
};

template<typename T>
class ChildQueue : public Queue<T>
{
public:
	void Clear()
	{
		Queue::Size = 0;
	}
};

class Parent
{
public:
	Parent() : Money(0) {}
	virtual ~Parent() {}

	void Do()
	{	
		
	}

private: // 접근 불가
	int Money;

public:
	// Accessor, 함수를 이용하여 접근
	int GetMoney() 
	{
		return Money; 
	}

	void SetMoney(int NewMoney)
	{
		if (NewMoney > 0)
		{
			Money = NewMoney;
		}
	}
};

class StaticClass
{
public:
	StaticClass()
	{
		Count++;
	}

	virtual ~StaticClass()
	{
		Count--;
	}

	static int Count;
};

int StaticClass::Count = 0;

class Singleton
{
private:
	Singleton()
	{

	}

public:
	void Do()
	{

	}

	virtual ~Singleton()
	{

	}

	static Singleton* GetInstance() //자신을 return.
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton();
		}
		return Instance;
	}

private:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;

int main()
{
	Singleton::GetInstance()->Do();
	//StaticClass* A = new StaticClass();
	//delete A;
	//StaticClass* B = new StaticClass();
	//StaticClass* C = new StaticClass();
	//StaticClass* D = new StaticClass();

	//cout << StaticClass::Count << endl;
	
	//Parent P;
	//P.Do();
	//cout << P.GetMoney() << endl;
	//P.SetMoney(10);
	//cout << P.GetMoney() << endl;

	//return 0;

	// Queue Class

	//Queue<int> IntQueue(10000);
	//for (int i = 0; i < IntQueue.GetCapicity(); ++i)
	//{
	//	IntQueue.Push(i);
	//}

	//cout << IntQueue.Pop() << endl;
	//cout << IntQueue.Pop() << endl;

	////IntQueue.Clear();

	//IntQueue.Push(10);
	//IntQueue.Push(11);

	//while (IntQueue.GetSize() != 0)
	//{
	//	cout << IntQueue.Pop() << endl;
	//}

	//return 0;

	// Stack Class
	//Stack<float> IntStack;

	//for (int i = 1; i <= 10; ++i)
	//{
	//	IntStack.Push(i * 1.1f);
	//}

	//for (int i = 1; i <= 10; ++i)
	//{
	//	cout << IntStack.Top() << ", ";
	//	IntStack.Pop();
	//}

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
}