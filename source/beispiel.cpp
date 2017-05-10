# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate

int main ()
{
	std::vector <int> v0 {10};
	for (auto& v : v0) {
		v = std::rand();
	}
	std::copy(std::begin(v0), std::end(v0), 
		std::ostream_iterator <int>(std::cout, "\n"));

	std::list <int> l0{(int)v0. size()};
	std::copy(std::begin(v0), std::end(v0), std::begin(l0 ));

	std::list <int> l1{std::begin(l0), std::end(l0)};
	std::reverse(std::begin(l1), std::end(l1));
	std::copy(std::begin(l1), std::end(l1), 
		std::ostream_iterator <int>(std::cout, "\n"));

	l1.sort ();
	std::copy(l1.begin(), l1.end(), 
		std::ostream_iterator <int>(std::cout, "\n"));

	std::generate(std::begin(v0), std::end(v0), std::rand );
	std::copy(v0.rbegin(), v0.rend (), 
		std::ostream_iterator <int>(std::cout, "\n"));

	return 0;
}