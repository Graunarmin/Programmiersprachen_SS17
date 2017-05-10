# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate
# include <set>

int main ()
{

	std::list <unsigned int> l1(100);
	for (auto& l : l1){ 
		l = std::rand() % 101;
	}
	// std::copy(std::begin(l1), std::end(l1),
	// 	std::ostream_iterator<int>(std::cout, "\n"));

	std::vector<unsigned int> v1(l1.size());
	std::copy(std::begin(l1), std::end(l1), std::begin(v1));
	// std::copy(std::begin(v1), std::end(v1),
	// 	std::ostream_iterator<int>(std::cout, "\n"));

	std::set<int> s1;
	for(auto& i : v1){
		s1.insert(i);
	}
	std::copy(std::begin(s1), std::end(s1),
		std::ostream_iterator<int>(std::cout, "\n"));

	std::cout << "In der Liste stehen " << s1.size() << " verschiedene Zahlen. \n";

	std::cout << "Diese Zahlen zwischen 0 und 100 fehlen: \n";

	for (int j = 0; j <= 100; ++j){
		if(s1.find(j) == s1.end()){
			std::cout << j << "\n";
		}
	}

	return 0;
}