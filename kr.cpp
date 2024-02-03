#include <iostream>



void demonstrate(int* arr, int length) 
{
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int* filling(int* arr, int length) {
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 50;
	}
	return arr;
}

void find(int* arr, int length, int number)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i] + arr[j] == number)
			{
				std::cout << arr[i] << " " << arr[j] << std::endl;
			}
		}
	}
}

int main()
{
	srand(time(nullptr));
	int length, number;
	std::cout << "Enter length of array" << std::endl;
	std::cin >> length;
	std::cout << "Enter number" << std::endl;
	std::cin >> number;
	int* arr = new int[length];
	arr = filling(arr, length);
	demonstrate(arr, length);
	find(arr, length, number);
	delete[] arr;
	return 0;
}