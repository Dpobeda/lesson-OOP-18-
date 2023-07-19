#include <iostream>
#include <random>

// Колекция для демонстрации работы алгоритма.
#include <vector>
#include <list>

// Библиотеки облегчающие обработку коллекций в впринцепе работу с данными.
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

	std::random_device rd; // Генератор случаных чисел (Генератор эндропии).
	std::mt19937 generator(rd()); // Генератор псевдослучайных чисел.
	std::uniform_int_distribution <int> provider(10, 90);

	for (size_t i = 0; i < 20; i++)
	{
		coll1.push_back(provider(generator));
		coll2.push_back(provider(generator));
	}

	int count{};
	// Первый способ.
	/*for (const auto &node : coll1){
		for (const auto &el : coll2) {
			if (el == node) {
				count++;
				break;
			}
		}
	}*/

	// Второй способ.
	for (const auto& node : coll1)
	{
		count += std::count(coll2.begin(), coll2.end(), node);
	}

	std::cout << count << " cовпадения\n";

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

	// min, max, min_max, Модифицируют коллекцию: sort, shuffle, split

	//Сортировка по возрастанию для типов, которые имеют реализованный оператор.
	//std::sort(coll2.begin(), coll2.end(), lamb);

	// Лямба. Пример передачи сохранёного lambda выражения
	/*auto lamb = [](int a, int b)->bool // ->bool, будет гарантировать преобразование в типе данных bool .
	{
		return a > b;
	};*/

	//std::cout << std::endl;

	// Можно и так.
	std::sort(coll2.begin(), coll2.end()),
		[](int a, int b)->bool
	{
		return a > b;
	};
	for (const auto& el : coll2) {
		std::cout << el << " ";
	}
	std::cout << "\n";


	// Так и так 30 пришло по заказу №9087655
	auto search = std::find_if(coll2.begin(), coll2.end(),
		[](int a)->bool {return a > 30; });

	// find - ищет полное соотвествие.
	// find_if - ищет по любому нужному нам условию.

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

	std::cout << count << " cовпадения\n";
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