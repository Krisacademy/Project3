#include<iostream>
#include<thread>
using namespace std;

int counter = 0;

void increment()
{
	for (int i = 0; i < 1000; i++)
	{
		counter++;
	}
}
int main()
{
	thread t1(increment);
	thread t2(increment);

	t1.join();
	t2.join();
	cout << "Counter = " << counter << endl;//2000
}