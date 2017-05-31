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

  //Constructors
  ListIterator(): // Zeiger, der auf Elemente der Liste zeigt
    m_node{nullptr} {}

  ListIterator(ListNode<T>* n):
    m_node{n} {}

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
    //Preincrement
    //erhöht um eins und gibt zurück
    // if(m_node->m_next == nullptr)
    // {
    //   std::cout << "This the last node, you can't go any further!";
    //   return 0;
    // }
    // else
    // {
      m_node = m_node -> m_next;
      return *this;
    // }
  }

  Self operator++(int) {
    //Postincrement
    //erhoeht um 1, gibt alten Wert zurück
    // if(m_node->m_next == nullptr)
    // {
    //   std::cout << "ERROR at Postincrement: \nThis is the last node, you can't go any further! \n";
    //   return 0;
    // }
    // else
    // {
      /*auto*/ListIterator old(*this); //Konstruktor!
      m_node = m_node -> m_next;
      return old;
    // }
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

  //Default Constructor
  List():
    m_size{0},
    m_first{nullptr},
    m_last{nullptr} {}

  bool empty() const
  {
    return m_size == 0;
  }

  std::size_t size() const
  {
    return m_size;
  }

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

      // ListNode<T> front{v, nullptr, nullptr};
      // m_first = &front;
      // m_last = m_first;
    }
    else
    {
      m_first = new ListNode<T>{v, nullptr, m_first};
      (*(*m_first).m_next).m_prev = m_first;

      // ListNode<T> temp = *m_first;
      // ListNode<T> front{v, nullptr, m_first};
      // m_first = &front;
      // temp.m_prev = m_first;
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

  void clear()
  {
    while(!empty())
    {
      pop_front();
    }
      // m_first = m_last = nullptr;
      // m_size = 0;
  }

  //Destructor
  ~List()
  {
    clear();
  }

   ListIterator<T> begin() const
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

  ListIterator<T> end() const
  {
    if(empty())
    {
      return ListIterator <T>{};
    }
    else
    {
      return ListIterator<T>(m_last);
    }
  }

private:
  std::size_t m_size = 0;
  ListNode<T>* m_first = nullptr;
  ListNode<T>* m_last = nullptr;
};



# endif // # define BUW_LIST_HPP
