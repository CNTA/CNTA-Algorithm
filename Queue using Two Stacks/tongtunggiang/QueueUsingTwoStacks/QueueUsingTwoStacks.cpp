#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Represents a queue containing integers
 *
 * The queue is implemented using two stacks: inbox and outbox.
 * - The enqueue operation will push a new element onto the inbox stack.
 * - The dequeue operation will pop and return the top element of the outbox stack.
 * - In case that the outbox stack is empty, it will be refilled by popping elements
 *   from the inbox stack and pushing them to the outbox stack.
 *
 * @note For convenience's sake, the std::vector class will be used as the stack data structure:
 * - Stack's push operation: std::vector::push_back
 * - Stack's pop operation: std::vector::pop_back
 * - Stack's top operation: std::vector::back
 *
 * @note I skipped the declaration and definition for Queue class' constructor and destructor, as
 * I won't need them anyway in the scope of this exercise.
 */
class Queue
{

public:

	void Enqueue(int x);
	int Dequeue();
	int GetFront();

private:

	void FillOutbox();

private:

	vector<int> m_Outbox;
	vector<int> m_Inbox;
};

int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int queries;
	cin >> queries;

	Queue queue;
	for (int i = 0; i < queries; i++)
	{
		int query;
		cin >> query;
		
		switch (query)
		{
		case 1:
		{
			int x;
			cin >> x;
			queue.Enqueue(x);
		}
			break;
		case 2:
			queue.Dequeue();
			break;
		case 3:
			cout << queue.GetFront() << endl;
			break;
		default:
			break;
		}
	}

	return 0;
}



void Queue::Enqueue(int x)
{
	m_Inbox.push_back(x);
}


int Queue::Dequeue()
{
	if (m_Outbox.empty())
		FillOutbox();

	int outboxTop = m_Outbox.back();
	m_Outbox.pop_back();
	return outboxTop;
}


int Queue::GetFront()
{
	if (m_Outbox.empty())
		FillOutbox();

	return m_Outbox.back();
}


void Queue::FillOutbox()
{
	while (!m_Inbox.empty())
	{
		int inboxTop = m_Inbox.back();
		m_Outbox.push_back(inboxTop);
		m_Inbox.pop_back();
	}
}