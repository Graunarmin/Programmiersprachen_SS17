# ifndef BUW_LIST_HPP
# define BUW_LIST_HPP
# include <cstddef>
# include <utility>

// List.hpp

template <typename T>
struct List;

template <typename T>
struct ListNode
{
  //Default Constructor
  ListNode():
    m_value(),
    m_prev(nullptr), //prev pointer auf nullptr
    m_next(nullptr) {} //next pointer auf nullptr

  //Constructor
  ListNode (T const& v, ListNode* prev , ListNode* next):
    m_value(v),
    m_prev(prev),
    m_next(next) {}

  //Membervariablen
  T m_value;
  ListNode* m_prev; //Zeiger auf prev
  ListNode* m_next; //Zeiger auf next
};

template <typename T>
struct ListIterator
{
  typedef ListIterator<T> Self;
  typedef T value_type;
  typedef T* pointer;
  typedef T& reference;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  friend class List<T>; //heißt: ListIterator kann alle Funktionen der Klasse List benutzen

  //Aufgabe 4.5
  //Constructors
  ListIterator(): // Zeiger, der auf Elemente der Liste zeigt
    m_node{nullptr} {}

  ListIterator(ListNode<T>* n):
    m_node{n} {}

  void position(ListNode<T>){

  }

  reference operator*() const {
    /*Dereferenzierung, Übergang von Zeiger auf Objekt;
    *gib also den Inhalt des Knotens zurück, auf den
    *der Iterator gerade zeigt*/
    return m_node->m_value;
  }
  pointer operator->() const {
    //gibt pointer auf das Objekt zurück
    //WIE TESTEN??
    return &(m_node->m_value);
  }

  Self& operator++() {
      m_node = m_node -> m_next;
      return *this;
  }

  Self operator++(int) {
      /*auto*/ListIterator old(*this); //Konstruktor!
      m_node = m_node -> m_next;
      return old;
  }

  bool operator==(const Self& x) const {
    //vgl Iterator mit anderem Zeiger
    return m_node == x.m_node;
  }

  bool operator!=(const Self& x) const {
    return m_node != x.m_node;
  }

  Self next() const //gibt Iterator auf den nächsten Knoten zurück, falls es einen gibt
  {
    if (m_node)
      return ListIterator (m_node -> m_next);
    else
      return ListIterator (nullptr);
  }


private :
    // The Node the iterator is pointing to
  ListNode <T>* m_node = nullptr;
};

template <typename T>
struct ListConstIterator
{
  friend class List <T>;
public:
// not implemented yet
private:
  ListNode <T>* m_node = nullptr;
};


template <typename T>
class List
{
public:
  typedef T value_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef ListIterator <T> iterator;
  typedef ListConstIterator <T> const_iterator;

  friend class ListIterator <T>;
  friend class ListConstIterator <T>;
  // not implemented yet

  //Aufgabe 4.2
  //Default Constructor
  List():
    m_size{0},
    m_first{nullptr},
    m_last{nullptr} {}

  //Aufgabe 4.8
  //Copy Constructor
  List(List<T> const& list):
    m_size{0},
    m_first{nullptr},
    m_last{nullptr}{
    for(auto e = list.begin(); e != nullptr; ++e)
    {
      push_back(*e);
    }
    }

  //Aufgabe 4.13
  //Move Constructor
  List(List<T>&& list):
    m_size{list.m_size},
    m_first{list.m_first},
    m_last{list.m_last}{
      list.clear();
    }

  //Aufgabe 4.2
  bool empty() const
  {
    return m_size == 0;
  }

  std::size_t size() const
  {
    return m_size;
  }

  //Aufgabe 4.3
  T front()
  {
    if (empty())
    {
      std::cout << "Sorry, but this list is empty";
      return 0;
    }
    return (*m_first).m_value;
  }

  void push_front(T const& v)
  {
    if(empty())
    {
      m_first = new ListNode<T>{v, nullptr, nullptr};
      m_last = m_first;
    }
    else
    {
      m_first = new ListNode<T>{v, nullptr, m_first};
      (*(*m_first).m_next).m_prev = m_first;
    }
    ++m_size;
  }
  void pop_front()
  {
    if(empty())
    {
      std::cout << "Sorry, but this list is already empty.\n";
    }
    if(size() == 1)
    {
      m_first = m_last = nullptr;
      --m_size;
    }
    else
    {
      (*(*m_first).m_next).m_prev = nullptr;
      m_first = (*m_first).m_next;
      --m_size;
    }
  }

  T back()
  {
    if (empty())
    {
      std::cout << "Sorry, but this list is empty";
      return 0;
    }
    return(*m_last).m_value;
  }

  void push_back(T const& v){
    if(empty()){
      m_last = new ListNode<T>{v, nullptr, nullptr};
      m_first = m_last;
    }
    else{
      m_last = new ListNode<T>{v, m_last, nullptr};
      (*(*m_last).m_prev).m_next = m_last;
      //same: m_last->m_prev->m_next = m_last;
    }
    ++m_size;
  }

  void pop_back(){
    if(empty())
    {
      std::cout << "Sorry, but this list is already empty. \n";
    }
    if(size() == 1)
    {
      m_first = m_last = nullptr;
      --m_size;
    }
    else
    {
      (*(*m_last).m_prev).m_next = nullptr;
      m_last = (*m_last).m_prev;
      --m_size;
    }
  }

  T valueAt(iterator const& p)
  {
    if (empty())
    {
      std::cout << "Sorry, but this list is empty";
      return 0;
    }
    return p.m_node -> m_value;
  }


  //Aufgabe 4.4
  void clear()
  {
    while(!empty())
    {
      pop_front();
    }
  }

  //Destructor
  ~List()
  {
    clear();
  }

  //Aufgabe 4.6
  ListIterator<T> begin() const //zeigt auf erstes Element
  {
    if(empty())
    {
      return ListIterator<T> {};
    }
    else
    {
      return ListIterator<T>(m_first);
    }
  }

  ListIterator<T> end() const //zeigt auf nullptr
  {
    return ListIterator<T>{};
  }

  ListIterator<T> last() const //zeigt auf letztes Element
  {
    if(empty())
    {
      return ListIterator<T>{};
    }
    else
    {
      return ListIterator<T>(m_last);
    }
  }

  //Aufgabe 4.10
  void reverse()
  {
    List<T>temp;
    for(auto e = begin(); e != nullptr; ++e)
    {
        temp.push_back(*e);
    }
    clear();
    for (auto e = temp.begin(); e != nullptr; ++e)
    {
      push_front(*e);
    }
  }

  void insert(iterator const& position, T const& value)
  {
    if(empty())
    {
      push_back(value);
    }
    else if(position == begin())
    {
      push_front(value);
    }
    else if(position == end())
    {
      push_back(value);
    }
    else
    {
      auto n = new ListNode<T>{value, position.m_node -> m_prev, position.m_node};
      position.m_node -> m_prev -> m_next = n;
      position.m_node -> m_prev = n;
      ++m_size;
    }
  }

  List& operator=(List<T> list) //ohne Referenz, sonst ist list nacher leer!
  {
    swap(list);
    return *this;
  }

  void swap(List<T>& list)
  {
    std::swap(m_first, list.m_first);
    std::swap(m_last, list.m_last);
    std::swap(m_size, list.m_size);
  }

  friend void swap(List<T>& lhs, List<T>& rhs)
  {
    lhs.swap(rhs);
  }

private:
  std::size_t m_size = 0;
  ListNode<T>* m_first = nullptr;
  ListNode<T>* m_last = nullptr;
};

template<typename T>
bool operator ==(List<T> const& xs, List<T> const& ys)
{
  auto a = xs.begin();
  auto b = ys.begin();

  if(xs.size() == ys.size())
  {
    while(a != nullptr)
    {
    if (*a != *b){
      return false;
    }
    ++a;
    ++b;
  }
  return true;
  }
return false;
}

template<typename T>
bool operator !=(List<T> const& xs, List<T> const& ys)
{
  auto a = xs.begin();
  auto b = ys.begin();

  if(xs.size() == ys.size())
  {
    while(a != nullptr)
    {
    if (*a != *b){
      return true;
    }
    ++a;
    ++b;
    }
    return false;
  }
  return true;
}

template<typename T>
List<T> reverse(List<T> const& list)
{
  List<T>reversedList;
  for(auto e = list.begin(); e != nullptr; ++e)
  {
      reversedList.push_front(*e);
  }
  return reversedList;
}

# endif // # define BUW_LIST_HPP
