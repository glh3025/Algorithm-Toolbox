#include <iostream>
#include <vector>
#include <algorithm>


int_least64_t MaxPairwiseProduct(std::vector<int>& numbers) {

	int n = numbers.size();
	int temp = 0;
	int index = 0;
	for (int i = 1; i < n; ++i) {
		if (numbers[i] > numbers[index]) index = i;
	}
	//std::swap(numbers[index], numbers[n - 1]);
	temp = numbers[index];
	numbers[index] = numbers[n - 1];
	numbers[n - 1] = temp;

	index = 1;
	for (int i = 1; i < n - 1; ++i) {
		if (numbers[i] > numbers[index]) index = i;
	}
	//std::swap(numbers[index], numbers[n - 2]);

	temp = numbers[index];
	numbers[index] = numbers[n - 2];
	numbers[n - 2] = temp;

	return int_least64_t(numbers[n - 1]) * int_least64_t(numbers[n - 2]);
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> numbers[i];
	}

	int_least64_t result = MaxPairwiseProduct(numbers);
	std::cout << result << "\n";
	//while (1);
	return 0;
}
