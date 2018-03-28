#pragma once
#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore
{
public:
	~Semaphore() {}

	int count;
	mutex mtx;
	condition_variable cv;

protected:
	Semaphore(int i) : count(i)
	{
		
	}
};

//Wait Function
static void P(Semaphore& sem)
{
	unique_lock<mutex> lock(sem.mtx);

	while (sem.count <= 0)
	{
		sem.cv.wait(lock);
	}
	sem.count--;
}

//Signal Function
static void V(Semaphore& sem)
{
	unique_lock<mutex> lock(sem.mtx);
	sem.count++;
	sem.cv.notify_one();
}
