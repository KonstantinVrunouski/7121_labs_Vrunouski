#include <iostream>
#include <cstdlib>
#include <time.h>
#include <exception>

int getting_size()
{
	int size = 0;
	try
	{
		std::cout << "Elements quantity:\n";
		std::cin >> size;
		if (size <= 0)
			throw std::exception("Invalid quantity.");
	}
	catch(std::exception e)
	{
		std::cerr << "Exception occurred: " << e.what();
		exit(0);
	}
	return size;
}

bool get_user_input_type()
{
	bool ans;
	std::cout << "Input manually or randomly?\n0) Manual; 1) Random\n";
	std::cin >> ans;
	return ans;
}

int* input_array_manual(int size)
{
	int* arr = new int[size];
	std::cout << "Input elements:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	return arr;
}

int* input_array_random(int size)
{
	int* arr = new int[size];
	int l_bord, r_bord;
	std::cout << "Input range of random numbers:\n";
	std::cin >> l_bord >> r_bord;
	if (l_bord > r_bord)
	{
		l_bord = l_bord ^ r_bord;
		r_bord = l_bord ^ r_bord;
		l_bord = l_bord ^ r_bord;
	}
	for (int i = 0; i < size; ++i)
	{
		arr[i] = l_bord + rand() % (r_bord - l_bord + 1);
	}
	return arr;
}


int finding_max_index(int* arr, int size)
{
	int max_num = arr[0], max_num_index = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] > max_num)
		{
			max_num = arr[i];
			max_num_index = i;
		}
	}
	return max_num_index;
}

int calc_multiplication_result(int* arr, int size, int max_num_index)
{
	double multiplication_result = 1;
	if (max_num_index == size - 1)
	{
		return 0;
	}
	else
	{
		for (int i = max_num_index + 1; i < size; ++i)
		{
			multiplication_result *= arr[i];
		}
		return multiplication_result;
	}
}

int countDistinct(int* arr, int n)
{
	int res = 1;

	for (int i = 1; i < n; ++i) {
		int j = 0;
		for (j = 0; j < i; ++j)
			if (arr[i] == arr[j])
				break;

		if (i == j)
			res++;
	}
	return res;
}
void StartingArray(int* arr, int size)
{
	std::cout << "Starting array:\n";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	return;
}

int* bubble_sort(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return arr;
}

void Output(int* arr, int size, int max_num_index, int multiplication_result)
{
	std::cout << "\nNumber of the unique elements and result of multiplication of the elements after maximum:\n" << countDistinct(arr, size) << '\t' << multiplication_result << '\n' << "Sorted array:\n";

	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	return;
}

int main()
{
	srand(time(NULL));

	int size = getting_size();
	int* arr = new int[size];
	if (get_user_input_type() == 0)
	{
		arr = input_array_manual(size);
	}
	else
	{
		arr = input_array_random(size);
	}

	StartingArray(arr, size);

	int max_num_index = finding_max_index(arr, size);

	int multiplication_result = calc_multiplication_result(arr, size, max_num_index);

	arr = bubble_sort(arr, size);

	Output(arr, size, max_num_index, multiplication_result);

	delete[] arr;

	return 0;
}

