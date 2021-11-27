#include <vector>
#include <iostream>
#include <memory>

std::vector<int> suspicious()
{
	std::vector<int> p;

	for(int i; std::cin >> i; )
	{
		if(i) p.push_back(i);
		else throw std::exception();
	}

	return p; //Move
}

int main()
try {

	auto p = suspicious();

	for(int i = 0; i < p.size(); ++i)
		std::cout << p.at(i) << ' ';
	std::cout << '\n';

	return 0;

} catch (std::exception& e){
	std::cerr << "Error!\n";
	return 1;
}
