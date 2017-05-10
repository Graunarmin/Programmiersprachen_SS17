# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate

int main ()
{

	std::list <unsigned int> l1(100);
	for (auto& l : l1){ 
		l = std::rand() % 101;
	}
	std::copy(std::begin(l1), std::end(l1),
		std::ostream_iterator<int>(std::cout, "\n"));

	std::vector<unsigned int> v1(l1.size());
	std::copy(std::begin(l1), std::end(l1), std::begin(v1));
	std::copy(std::begin(v1), std::end(v1),
		std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}