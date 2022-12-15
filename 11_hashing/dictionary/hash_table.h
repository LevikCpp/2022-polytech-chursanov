#pragma once
#include "../hash.h"
#include <string>

// Double hashing to avoid collisions
struct HashM {
  int operator()(const std::string &str, int table_size) const {
    return default_hash(str) % (table_size - 1);
  }
};
struct HashP {
  int operator()(const std::string &str, int table_size) const {
    return default_hash(str) % (table_size + 1);
  }
};

template <class T, class THash1 = HashM, class THash2 = HashP> class HashTable {
private:
  static const int DEFAULT_SIZE = 8;
  constexpr static const double REHASH_SIZE = 0.75;

  struct Node {
    std::string _key;
    T _value;
    bool _state;
    Node(const std::string &key, const T &value)
        : _key{key}, _value{value}, _state{true} {}
  };

  Node **_arr;
  int _size;
  int _allocated;
  int _arr_size;

  void resize();
  void rehash();

public:
  HashTable();
  ~HashTable();

  bool insert(const std::string &key, const T &value,
              const THash1 &hash1 = THash1(), const THash2 &hash2 = THash2());

  bool remove(const std::string &key, const THash1 &hash1 = THash1(),
              const THash2 &hash2 = THash2());

  bool find(const T &value, const THash1 &hash1 = THash1(),
            const THash2 &hash2 = THash2());

  T get(const std::string &key, const THash1 &hash1 = THash1(),
        const THash2 &hash2 = THash2());

  std::size_t size() { return _size; }
};

template <class T, class THash1, class THash2>
void HashTable<T, THash1, THash2>::resize() {
  int past_buffer_size = _allocated;
  _allocated *= 2;
  _arr_size = 0;
  _size = 0;
  Node **arr2 = new Node *[_allocated];
  for (int i = 0; i < _allocated; ++i) {
    arr2[i] = nullptr;
  }
  std::swap(_arr, arr2);
  for (int i = 0; i < past_buffer_size; ++i) {
    if (arr2[i] && arr2[i]->_state) {
      insert(arr2[i]->_key, arr2[i]->_value);
    }
  }
  for (int i = 0; i < past_buffer_size; ++i) {
    if (arr2[i]) {
      delete arr2[i];
    }
  }
  delete[] arr2;
}

template <class T, class THash1, class THash2>
void HashTable<T, THash1, THash2>::rehash() {
  _arr_size = 0;
  _size = 0;
  Node **arr2 = new Node *[_allocated];
  for (int i = 0; i < _allocated; ++i) {
    arr2[i] = nullptr;
  }
  std::swap(_arr, arr2);
  for (int i = 0; i < _allocated; ++i) {
    if (arr2[i] && arr2[i]->_state) {
      insert(arr2[i]->_key, arr2[i]->_value);
    }
  }
  for (int i = 0; i < _allocated; ++i) {
    if (arr2[i]) {
      delete arr2[i];
    }
  }
  delete[] arr2;
}

template <class T, class THash1, class THash2>
HashTable<T, THash1, THash2>::HashTable() {
  _allocated = DEFAULT_SIZE;
  _size = 0;
  _arr_size = 0;
  _arr = new Node *[_allocated];
  for (int i = 0; i < _allocated; ++i) {
    _arr[i] = nullptr;
  }
}

template <class T, class THash1, class THash2>
HashTable<T, THash1, THash2>::~HashTable() {
  for (int i = 0; i < _allocated; ++i) {
    if (_arr[i]) {
      delete _arr[i];
    }
  }
  delete[] _arr;
}

template <class T, class THash1, class THash2>
bool HashTable<T, THash1, THash2>::insert(const std::string &_key,
                                          const T &_value, const THash1 &hash1,
                                          const THash2 &hash2) {
  if (_size + 1 > int(REHASH_SIZE * _allocated)) {
    resize();
  } else if (_arr_size > 2 * _size) {
    rehash();
  }
  int h1 = hash1(_key, _allocated);
  int h2 = hash2(_key, _allocated);
  int i = 0;
  int first_deleted = -1;
  while (_arr[h1] != nullptr && i < _allocated) {
    if (_arr[h1]->_key == _key && _arr[h1]->_state) {
      return false;
    }
    if (!_arr[h1]->_state && first_deleted == -1) {
      first_deleted = h1;
    }
    h1 = (h1 + h2) % _allocated;
    ++i;
  }
  if (first_deleted == -1) {
    _arr[h1] = new Node(_key, _value);
    ++_arr_size;
  } else {
    _arr[first_deleted]->_value = _value;
    _arr[first_deleted]->_state = true;
  }
  ++_size;
  return true;
}

template <class T, class THash1, class THash2>
bool HashTable<T, THash1, THash2>::remove(const std::string &_key,
                                          const THash1 &hash1,
                                          const THash2 &hash2) {
  int h1 = hash1(_key, _allocated);
  int h2 = hash2(_key, _allocated);
  int i = 0;
  while (_arr[h1] != nullptr && i < _allocated) {
    if (_arr[h1]->_key == _key && _arr[h1]->_state) {
      _arr[h1]->_state = false;
      --_size;
      return true;
    }
    h1 = (h1 + h2) % _allocated;
    ++i;
  }
  return false;
}

template <class T, class THash1, class THash2>
bool HashTable<T, THash1, THash2>::find(const T &_value, const THash1 &hash1,
                                        const THash2 &hash2) {
  int h1 = hash1(_value, _allocated);
  int h2 = hash2(_value, _allocated);
  int i = 0;
  while (_arr[h1] != nullptr && i < _allocated) {
    if (_arr[h1]->_value == _value && _arr[h1]->_state) {
      return true;
    }
    h1 = (h1 + h2) % _allocated;
    ++i;
  }
  return false;
}

template <class T, class THash1, class THash2>
T HashTable<T, THash1, THash2>::get(const std::string &_key,
                                    const THash1 &hash1, const THash2 &hash2) {
  int h1 = hash1(_key, _allocated);
  int h2 = hash2(_key, _allocated);
  int i = 0;
  while (_arr[h1] != nullptr && i < _allocated) {
    if (_arr[h1]->_key == _key && _arr[h1]->_state) {
      return _arr[h1]->_value;
    }
    h1 = (h1 + h2) % _allocated;
    ++i;
  }
  return nullptr;
};