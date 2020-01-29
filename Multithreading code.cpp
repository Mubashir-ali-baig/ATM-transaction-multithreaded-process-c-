// Multithreading code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)
#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>

int GetRandom(int max);

using namespace std;

int GetRandom(int max)
{
	srand(time(NULL));
	return rand() % max;
}

string GetTime() {
	auto nowTime = std::chrono::system_clock::now();
	time_t sleepTime = chrono::system_clock::to_time_t(nowTime);

	return ctime(&sleepTime);
}

double acctBalance = 100;

mutex acctLock;

void GetMoney(int id, double withdrawl) {
	lock_guard<mutex> lock(acctLock);
	this_thread::sleep_for(chrono::seconds(3));
	cout << id << " tries to withdraw $ " << withdrawl << " on" << GetTime() << endl;
	if ((acctBalance) >= 0)
	{
		acctBalance -= withdrawl;
		cout << "New Account Balance is $ " << acctBalance << endl;

	}
	else {
		cout << "Not Enough Money in Account" << endl;
		cout << "Current Balance is $ " << acctBalance << endl;
	}
}

int main()
{
	thread threads[10];
	for (int i = 0; i < 10; i++) {
		threads[i]=thread(GetMoney,i,15);
	}
	for (int i = 0; i < 10; i++) {
		threads[i].join();
	}
	return 0;
}

