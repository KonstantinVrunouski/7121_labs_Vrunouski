#include <iostream>
#include <set>

int main()
{
	std::set<int> s;
	std::multiset<int> s_multi;
	int cnt = 0, res = 1, n, max_dig = 0, max_dig_index;
	std::cout << "Input number of the elements of the array:\n";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Input elements of the array:\n";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		s.insert(arr[i]);
		s_multi.insert(arr[i]);
	}

	std::multiset <int>::iterator it = s_multi.begin();

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

	std::cout << "Number of the unique elements and result of multiplication of the elements after maximum:\n" << s.size() << '\t' << res << '\n' << "Sorted array:\n";

	for (int i = 1; it != s_multi.end(); i++, it++)
	{
	       std::cout << *it << " ";
	}
	std::cout << '\n';
	delete[] arr;

	return 0;
}

