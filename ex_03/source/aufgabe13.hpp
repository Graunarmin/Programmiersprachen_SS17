# ifndef AUFABGE13_HPP
# define AUFABGE13_HPP

# include <cmath>
# include <algorithm>
# include <iostream>
# include <vector>
# include "circle.hpp"


struct compare
{
  bool operator()(const Circle &a, const Circle &b) const
  {
    return a < b;
  }
};

# endif // AUFGABE13_HPP
