// HW01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int getTotal(const int* arNumber, int numberLength)
{
	int total{};

	for (int i = 0; i < numberLength; i++)
	{
		total += arNumber[i];
	}

	return total;
}

double getAverage(const int* arNumber, int numberLength)
{
	double average{};
	average = (double)getTotal(arNumber, numberLength) / (double)numberLength;

	return average;
}

void swapData(int& dst, int& src)
{
	int temp = dst;
	dst = src;
	src = temp;
}

void ascendingSelectionSort(int* arNumber, int numberLength)
{
	int remainLength = numberLength;

	while (remainLength > 1)
	{
		int minIndex = 0;

		for (int i = 1; i < remainLength; i++)
		{
			if (arNumber[minIndex] > arNumber[i])
			{
				minIndex = i;
			}
		}
		swapData(arNumber[minIndex], arNumber[0]);
		arNumber++;
		remainLength--;
	}
}

void descendingingSelectionSort(int* arNumber, int numberLength)
{
	int remainLength = numberLength;

	while (remainLength > 1)
	{
		int maxIndex = 0;

		for (int i = 1; i < remainLength; i++)
		{
			if (arNumber[maxIndex] < arNumber[i])
			{
				maxIndex = i;
			}
		}
		swapData(arNumber[maxIndex], arNumber[0]);
		arNumber++;
		remainLength--;
	}
}

int main()
{
	int arNumber[5]{};
	int total{};
	double average{};

	for (int i = 0; i < 5; i++)
	{
		cin >> arNumber[i];
		total += arNumber[i];
	}
	average = (double)total / 5.0;
	cout << "합계 : " << total << endl;
	cout << "평균 : " << average << endl;


	int numberLength = 5;

	cout << "합계 : " << getTotal(arNumber, numberLength) << endl;
	cout << "평균 : " << getAverage(arNumber, numberLength) << endl;

	//////////////////////////////////////////////////////////////////////////

	int* pNumber = arNumber;

	ascendingSelectionSort(pNumber, numberLength);
	cout << "현재 배열 : ";
	for (int i = 0; i < 5; i++)
	{
		cout << arNumber[i] << " ";
	}
	cout << endl;

	descendingingSelectionSort(pNumber, numberLength);
	cout << "현재 배열 : ";
	for (int i = 0; i < 5; i++)
	{
		cout << arNumber[i] << " ";
	}
	cout << endl;
}

