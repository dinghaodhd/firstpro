#include<iostream> 
#include <thread>
#include <atomic> 
#include <time.h>

std::atomic_long total(0);
long cont(0);

void click()
{
	for (int i = 0; i < 1000000;++i)
	{
		// 仅仅是数据类型的不同而以，对其的访问形式与普通数据类型的资源并无区别
		total += 1;
	}
}

void thd1()
{
	for (auto i = 0;i < 5000;i++)
	{
		total += 1;
		cont += 1;
	}
}

void thd2()
{
	for (auto i=0;i<5000;i++)
	{
		total += 1;
		cont += 1;
	}
}

int main()
{
	clock_t start = clock();

	std::thread t1(thd1);
	std::thread t2(thd2);
	t1.join();
	t2.join();

	std::cout << "total:" << total << std::endl;
	std::cout << "cont:" << cont << std::endl;
	system("pause");
	return 0;
}