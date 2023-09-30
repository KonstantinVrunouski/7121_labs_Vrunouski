#include <iostream>

int countDistinct(int arr[], int n)
{
    int res = 1;
 
    for (int i = 1; i < n; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
 
        if (i == j)
            res++;
    }
    return res;
}

int main()
{
	int cnt = 0, res = 1, n, max_dig = 0, max_dig_index, temp;
	std::cout << "Input number of the elements of the array:\n";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Input elements of the array:\n";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > max_dig)
		{
			max_dig = arr[i];
			max_dig_index = i;
		}
	}

	if (max_dig_index != n - 1)
	{
		for (int i = max_dig_index + 1; i < n; ++i)
		{
			res *= arr[i];
		}
	}
	else
	{
		res = 0;
	}

	for (int i = 0; i < n - 1; ++i) 
	{
        for (int j = 0; j < n - 1; ++j) 
		{
            if (arr[j] > arr[j + 1]) 
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
            }
        }
	}

	std::cout << "Number of the unique elements and result of multiplication of the elements after maximum:\n" << countDistinct(arr, n) << '\t' << res << '\n' << "Sorted array:\n";
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
	delete[] arr;

	return 0;
}

