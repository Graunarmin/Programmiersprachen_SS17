# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate
# include <set>
# include <map>

int main ()
{

	std::list <unsigned int> l1(100);
	//Liste mit random-Zahlen füllen
	for (auto& l : l1){
		l = std::rand() % 101;
	}
	// std::copy(std::begin(l1), std::end(l1),
	// 	std::ostream_iterator<int>(std::cout, "\n"));

	std::vector<unsigned int> v1(l1.size());
	//Inhalt der Liste in Vektor kopieren
	std::copy(std::begin(l1), std::end(l1), std::begin(v1));
	std::copy(std::begin(v1), std::end(v1),
		std::ostream_iterator<int>(std::cout, "\n"));

	std::set<int> s1;
	//Inhalt des Vektors in set sortieren (doppelte werden nur 1x einsortiert)
	for(auto& i : v1){
		s1.insert(i);
	}
	std::copy(std::begin(s1), std::end(s1),
	//set ausgeben
		std::ostream_iterator<int>(std::cout, "\n"));

	std::cout << "In der Liste stehen " << s1.size() << " verschiedene Zahlen. \n";

	std::cout << "Diese Zahlen zwischen 0 und 100 fehlen: \n";

	for (int j = 0; j <= 100; ++j){
		//alle Zahlen zw 1 u 100 finden, die nicht im set stehen.
		if(s1.find(j) == s1.end()){
			std::cout << j << "\n";
		}
	}

	std::map<int, int> map1;
	/* mit map, weil man bei map der jeweiligen Zahl (key) einen Wert (value)
	*zuweisen und diesen entsprechend erhöhen kann, wenn die Zahl erneut
	*gefunden wird. Map ist ein assoziativer Container. */
	int i{0};
	int c;
	while(i<v1.size()){
		c = v1[i];
		++map1[c];
		/*Jede Zahl, die in v1 gefunden wird, wird mit Schlüssel 0 hinzugefügt
		*und dann durch ++ um 1 erhöht. Wird sie nochmal gefunden, wird der
		*Schlüssel nochmal um 1 erhöht */
		++i;
	}

	typedef std::map<int,int>::const_iterator Iter;
	//Ausgabe der map als key : value
	for(Iter p = map1.begin(); p!= map1.end(); ++p){
		std::cout << p -> first << " : " << p -> second << '\n';
	}

	return 0;
}
