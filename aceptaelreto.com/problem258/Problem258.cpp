//============================================================================
// Author       : Rafael J. Vicente
// E-mail       : rafaelj.vicente@gmail.com
// Version      : 1.5
// Copyright    : All rights reserved
//============================================================================

#include <iostream>

using namespace std;

/**
 * Pair<value,expire> where value is the number and expire the expiration time
 */
struct Pair
{
    int value;
    int expire;

    Pair();
    Pair(const int& v, const int& e);

    bool operator>(const Pair& other);
    bool operator==(const Pair& other);
    bool operator!=(const Pair& other);
    bool operator>=(const Pair& other);
};

/**
 * List<Pair>[n] is an array list based structure where n is the maximum numbeer of elements
 */
class List
{
  public:
    List(int n);
    ~List();

    bool empty() const;
    bool size() const;
    void clear();

    Pair back();
    Pair front();
    void push_back(Pair element);
    void push_mid_remove_backs(Pair element);
    Pair pop_back();
    Pair pop_front();

  private:
    const int m_max_size;
    int m_size;
    int m_in;
    int m_out;
    Pair* m_array;
};

/**
 * Main function
 */
int main()
{
  int n_letters, n_taken;
  for (string line; cin >> n_letters >> n_taken, !(n_letters == 0 && n_taken == 0);)
  {

    if (n_taken == 1)
    {
      int aux;
      cin >> aux;
      cout << aux;
      for (int i = 1; i < n_letters; ++i)
      {
        cin >> aux;
        cout << ' ' << aux;
      }
    }
    else
    {
      List nlist(n_taken);

      int expire;
      int num, max = 0, max_limit;
      for (int i = 0; i < n_letters; ++i)
      {
        cin >> num;
        expire = i + n_taken;
        if (num >= max)
        { // New num is max
          max = num;
          max_limit = expire;
          if (!nlist.empty())
            nlist.clear();
        }
        else
        {
          // Pops front list item if has expired
          if (!nlist.empty() && nlist.front().expire == i)
            nlist.pop_front();

          // Remove all numbers lower than num and push num to list
          Pair pair = Pair(num, expire);
          if (nlist.empty() || nlist.back().value > num)
            nlist.push_back(pair);
          else
            nlist.push_mid_remove_backs(pair);

          // Sets new max if current has expired
          if (max_limit == i)
          {
            Pair new_max = nlist.front();
            nlist.pop_front();
            max = new_max.value;
            max_limit = new_max.expire;
          }
        }

        // Print
        if (i > n_taken - 1)
          cout << ' ' << max;
        else if (i == n_taken - 1)
          cout << max;
      }
    }

    cout << endl;
  }

  return 0;
}

//-------------------------------------------------------------------
Pair::Pair()
    : value(0), expire(0)
{
}

//-------------------------------------------------------------------
Pair::Pair(const int& v, const int& e)
    : value(v), expire(e)
{
}

//-------------------------------------------------------------------
bool Pair::operator>(const Pair& other)
{
  return value > other.value;
}

//-------------------------------------------------------------------
bool Pair::operator==(const Pair& other)
{
  return value == other.value;
}

//-------------------------------------------------------------------
bool Pair::operator!=(const Pair& other)
{
  return value != other.value;
}

//-------------------------------------------------------------------
bool Pair::operator>=(const Pair& other)
{
  return value >= other.value;
}

//-------------------------------------------------------------------
List::List(int n)
    : m_max_size { n }, m_array(new Pair[n])
{
  clear();
}

    //-------------------------------------------------------------------
List::~List()
{
  delete (m_array);
}

//-------------------------------------------------------------------
bool List::empty() const
{
  return m_size == 0;
}

//-------------------------------------------------------------------
bool List::size() const
{
  return m_size;
}

//-------------------------------------------------------------------
void List::clear()
{
  m_size = 0;
  m_in = -1;
  m_out = 0;
}

//-------------------------------------------------------------------
Pair List::back()
{
  return m_array[m_in];
}

//-------------------------------------------------------------------
Pair List::front()
{
  return m_array[m_out];
}

//-------------------------------------------------------------------
void List::push_back(Pair element)
{
  ++m_size;

  ++m_in;
  //m_in %= m_max_size;
  if (m_in >= m_max_size)
      m_in -= m_max_size;
  m_array[m_in] = element;
}

//-------------------------------------------------------------------
void List::push_mid_remove_backs(Pair element)
{
  if (m_array[m_in] != element)
  {
    int p_ini = 0, p_end = m_size - 1, p_mid, p_fixed;
    Pair aux;
    bool found = false;
    while (!found && p_ini <= p_end)
    {
      p_mid = (p_ini + p_end) / 2;
      p_fixed = m_out + p_mid;
      //p_fixed %= m_max_size;
      if (p_fixed >= m_max_size)
          p_fixed -= m_max_size;
      aux = m_array[p_fixed];
      found = element == aux || p_ini == p_end;
      if (!found && element > aux)
        p_end = p_mid;
      else
        p_ini = p_mid + 1;
    }
    m_size = p_mid + 1;
    m_in = p_fixed;
  }

  m_array[m_in] = element;
}

//-------------------------------------------------------------------
Pair List::pop_back()
{
  --m_size;

  Pair elemnt = m_array[m_in];
  m_in = m_in - 1 + m_max_size;
  //m_in %= m_max_size;
  if (m_in >= m_max_size)
      m_in -= m_max_size;
  return elemnt;
}

//-------------------------------------------------------------------
Pair List::pop_front()
{
  --m_size;

  Pair aux = m_array[m_out];
  ++m_out;
  //m_out %= m_max_size;
  if (m_out >= m_max_size)
      m_out -= m_max_size;
  return aux;
}
