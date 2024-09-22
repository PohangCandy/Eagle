// 배열을 이용해서 구현했는데 이 경우 메모리가 삭제되는게 아니므로 낭비가 발생할 수 있다.
 
#include <iostream>
using namespace std;

#define MAX_SIZE (10000)

template <typename T>
class queue {
private:
	T data[MAX_SIZE];
	int _front;
	int _back;

public:
	queue() {
		_front = 0;
		_back = 0;
	}
	~queue() {}

	void push(T inputdata)
	{
		data[_back] = inputdata;
		_back ++;
	}

	T pop()
	{
		T res = data[_front];
		_front++;
		return res;
	}

	int size()
	{
		return _back - _front;
	}

	bool empty()
	{
		return _back == _front;
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
	queue<int> que;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}
		else if (input == "pop")
		{
			if (que.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (input == "size")
		{
			cout << que.size() << "\n";
		}
		else if (input == "empty")
		{
			bool e = que.empty();
			cout << e << "\n";
		}
		else if (input == "front")
		{
			if (que.empty()) cout << -1 << "\n";
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (input == "back")
		{
			if (que.empty()) cout << -1 << "\n";
			else
			{
				cout << que.back() << "\n";
			}
		}
	}


	return 0;
}