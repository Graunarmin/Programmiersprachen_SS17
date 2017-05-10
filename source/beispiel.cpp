# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate

int main ()
{
	std::vector <int> v0(10); //Erstellt Vector v0 mit 
	for (auto& v : v0){ //Für jedes Element im Vector
		v = std::rand(); //jedem Element wird eine Zufallszahl zugewiesen
	}

	std::copy(std::begin(v0), std::end(v0), //Kopiert alle Element vom 1. bis zum letzten
		std::ostream_iterator<int>(std::cout, "\n")); //und gibt sie nacheinander aus

	std::list <int> l0(v0.size()); //erstellt int-Liste der Groeße des Vektors
	std::copy(std::begin(v0), std::end(v0), std::begin(l0)); //kopiert alle Werte aus dem Vektor in dieser Reihenfolge in die Liste

	std::list <int> l1(std::begin(l0), std::end(l0)); //erstellt eine neue Liste l1 aus allen Werten von l0
	std::reverse(std::begin(l1), std::end(l1)); //Dreht l1 komplett um
	std::copy(std::begin(l1), std::end(l1), //Gibt l1 auf der Konsole aus
		std::ostream_iterator <int>(std::cout, "\n"));

	l1.sort (); //sortiert l1 der Größe nach
	std::copy(l1.begin(), l1.end(), //gibt l1 nochmal (jetzt sortiert) aus
		std::ostream_iterator <int>(std::cout, "\n"));

	std::generate(std::begin(v0), std::end(v0), std::rand); //Jedes Element von v0 bekommt eine neue Zufallszahl zugewiesen
	std::copy(v0.rbegin(), v0.rend (), //gibt alle Werte des generierten Vektors auf der Konsole aus
		std::ostream_iterator <int>(std::cout, "\n"));

	//Datentyp von v0: Vector
	//Datentyp von v: int
	//Datentyp l0 und l1: Liste

	return 0;
}