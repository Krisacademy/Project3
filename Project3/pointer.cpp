#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic <int> counter { 0 }; // атомарна€ переменна€

// ‘ункци€, которую выполн€ют потоки
void increment()
{
    for (int i = 0; i < 1000; i++) {
        //counter.fetch_add(1); // атомарное увеличение
        counter++;        
    }

}

int main()
{
    setlocale(0, "ru");
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "–езультат: " << counter.load() << endl;
    return 0;
}