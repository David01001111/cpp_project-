#include <iostream>
#include <ctime>
using namespace std;

//This is a class that creates an int array filled with non-repeating random values then sorts it

class RandSort
{
private:
	bool alreadythere;
	int SIZE;
	int* mas;
public:
	RandSort() :alreadythere(false),SIZE(0), mas(NULL)
	{ }
	~RandSort()
	{
		delete []mas;
	}
	void get_size()
	{
		cout << "input size of array: ";
		cin >> SIZE;                       //size of Array
		mas = new int[SIZE];
	}
	void Show_Arr()
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << mas[i] << " ";    //Show Array
		}
		cout << endl;
	}
	void RandArray();//create non-repeating array
	void SortArray();//sorting Array
};

void RandSort::RandArray()
{
	for (int i = 0; i < SIZE;)
	{
		alreadythere = false;
		int NewRandomValue = rand() % 20;

		for (int j = 0; j < i; j++)
		{
			if (mas[j] == NewRandomValue)
			{
				alreadythere = true;
				break;
			}
		}

		if (!alreadythere)
		{
			mas[i] = NewRandomValue;
			i++;
		}
	}
}

void RandSort::SortArray()
{
	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (mas[i] > mas[j])
			{
				int temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	RandSort s1;
	s1.get_size();
	s1.RandArray();
	s1.Show_Arr();
	s1.SortArray();
	s1.Show_Arr();
	
	return 0;
}

