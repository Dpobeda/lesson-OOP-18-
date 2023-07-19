#include <iostream>
#include <random>

// �������� ��� ������������ ������ ���������.
#include <vector>
#include <list>

// ���������� ����������� ��������� ��������� � ��������� ������ � �������.
#include <algorithm>
#include <functional>

bool IsMore(int a, int b) 
{
	return a > b;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	std::list<int> coll1;
	std::vector<int> coll2;

	std::random_device rd; // ��������� �������� ����� (��������� ��������).
	std::mt19937 generator(rd()); // ��������� ��������������� �����.
	std::uniform_int_distribution <int> provider(10, 90);

	for (size_t i = 0; i < 20; i++)
	{
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}

	int count{};
	// ������ ������.
	/*for (const auto &node : coll1){
		for (const auto &el : coll2) {
			if (el == node) {
				count++;
				break;
			}
		}
	}*/

	// ������ ������.
	for (const auto& node : coll1)
	{
		count += std::count(coll2.begin(), coll2.end(), node);
	}

	std::cout << count << " c���������\n";

	for (const auto& node : coll1) {
		std::cout << node << " ";
	}
	std::cout << "\n";

	for (const auto& el : coll2) {
		std::cout << el << " ";
	}
	std::cout << "\n";

	std::cout << "\n";

	////|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	if (count > 0) {
		for (const auto& node : coll1) {
			auto it = std::find(coll2.begin(), coll2.end(), node);
			if (it != coll2.end()) {
				coll2.erase(it);
			}
		}
		for (const auto& node : coll1) {
			std::cout << node << " ";
		}
		std::cout << "\n";

		for (const auto& el : coll2) {
			std::cout << el << " ";
		}
		std::cout << "\n";
	}

	//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	// min, max, min_max, ������������ ���������: sort, shuffle, split

	//���������� �� ����������� ��� �����, ������� ����� ������������� ��������.
	//std::sort(coll2.begin(), coll2.end(), lamb);

	// �����. ������ �������� ���������� lambda ���������
	/*auto lamb = [](int a, int b)->bool // ->bool, ����� ������������� �������������� � ���� ������ bool .
	{
		return a > b;
	};*/

	//std::cout << std::endl;

	// ����� � ���.
	std::sort(coll2.begin(), coll2.end()),
		[](int a, int b)->bool
	{
		return a > b;
	};
	for (const auto& el : coll2) {
		std::cout << el << " ";
	}
	std::cout << "\n";


	// ��� � ��� 30 ������ �� ������ �9087655
	auto search = std::find_if(coll2.begin(), coll2.end(),
		[](int a)->bool {return a > 30; });

	// find - ���� ������ �����������.
	// find_if - ���� �� ������ ������� ��� �������.

	if (search != coll2.end())
	{
		std::cout << *search << "\n";
	}


	/*std::list<int> coll1;
	std::vector<int> coll2;
	std::vector<int> coll3;

	std::random_device rd;
	std::mt19937 generator(rd()); 
	std::uniform_int_distribution <int> provider(10, 90);

	for (size_t i = 0; i < 10; i++)
	{
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}

	int count{};
	for (const auto& node : coll1) {
		for (const auto& el : coll2) {
			if (el == node) {
				count++; break;
			}
		}
	}

	std::cout << count << " c���������\n";
	if (count > 0) {
		for (const auto& node : coll2) {
			auto it = std::find(coll1.begin(), coll1.end(), node);
			if (it != coll1.end()) {
				coll1.erase(it);
			}
		}
		for (const auto& node : coll1) {
			std::cout << node << " ";
		}
		std::cout << "\n";

		for (const auto& el : coll2) {
			std::cout << el << " ";
		}
		std::cout << "\n";
	}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (const auto& node : coll1) {
		auto it = std::find(coll1.begin(), coll1.end(), node);
		if (it != coll1.end()) {
			coll1.begin();
		}
	}

	std::cout << "\n";

	for (const auto& node : coll1) {
		 std::cout << node << " ";
	}
	std::cout << "\n";*/

	return {};
	
}