#include <iostream>
using namespace std;

#define MAX_SIZE (10000)

template<typename T>
class deque {
private:
	T data[MAX_SIZE];
	int _front;
	int _back;
public:
	deque(){
		_front = 0;
		_back = 0;
	}
	~deque() {
	}

	void push_front(int inputdata)
	{
		for (int i = _back; i > _front; i--)
		{
			data[i] = data[i - 1];
		}
		data[_front] = inputdata;
		_back++;
	}

	void push_back(int inputdata)
	{
		data[_back] = inputdata;
		_back++;
	}

	void pop_front()
	{
		for (int i = 0; i < _back; i++)
		{
			data[i] = data[i + 1];
		}
		_back--;
	}

	void pop_back()
	{
		_back--;
	}

	int size()
	{
		return _back - _front;
	}

	bool empty()
	{
		return (_back == _front);
	}

	T front()
	{
		T res = data[_front];
		return res;
	}

	T back()
	{
		T res = data[_back - 1];
		return res;
	}

};


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	deque<int> deq;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		int X;
		if (input == "push_front")
		{
			cin >> X;
			deq.push_front(X);
		}
		else if (input == "push_back")
		{
			cin >> X;
			deq.push_back(X);
		}
		else if (input == "pop_front")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.front() << "\n";
				deq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.back() << "\n";
				deq.pop_back();
			}
		}
		else if (input == "size")
		{
			cout << deq.size() << "\n";
		}
		else if (input == "empty")
		{
			cout << deq.empty() << "\n";
		}
		else if (input == "front")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.front() << "\n";
			}
		}
		else if (input == "back")
		{
			if (deq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << deq.back() << "\n";
			}
		}
	}

	return 0;
}