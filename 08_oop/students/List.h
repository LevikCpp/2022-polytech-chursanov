/// Struct ListElem

template<typename TYPE>
struct ListElem
{
    TYPE _content;
    ListElem<TYPE> *_prevElem = nullptr, *_nextElem = nullptr;
    ListElem<TYPE>(TYPE content, ListElem *prevElem = nullptr, ListElem *nextElem = nullptr);
    ListElem<TYPE>(ListElem<TYPE> const &list);
};

template<typename TYPE>
ListElem<TYPE>::ListElem(TYPE content, ListElem *prevElem, ListElem *nextElem)
{
    _content = content;
    _prevElem = prevElem;
    _nextElem = nextElem;
}
template <typename TYPE>
ListElem<TYPE>::ListElem(ListElem<TYPE> const &list)
{
    _content = list._content;
    _prevElem = list->_prevElem;
    _nextElem = list->_nextElem;
}


/// Class List

template<typename TYPE>
class List
{
private:
    unsigned int _size;
    ListElem<TYPE> *_head;
    ListElem<TYPE> *_tail;

    ListElem<TYPE> getContent(unsigned int pos);

public:
    List();
    ~List();

    void pushFront(TYPE content);
    void pushBack(TYPE content);

    

};

template<typename TYPE>
List<TYPE>::List()
{

}

template<typename TYPE>
List<TYPE>::~List()
{
    
}

template<typename TYPE>
void List<TYPE>::pushFront(TYPE content)
{
    if (_head == nullptr)
    {
        _head = new ListElem<TYPE>(content);
    }
    else
    {
        ListElem<TYPE> *current = this->_content;

        while (current->_prevElem != nullptr)
        {
            current = current->_prevElem;
        }
        current->_prevElem = new ListElem<TYPE>(content);
    }
}

template<typename TYPE>
void List<TYPE>::pushBack(TYPE content)
{
    if (_tail == nullptr)
    {
        _tail = new ListElem<TYPE>(content);
    }
    else
    {
        ListElem<TYPE> *current = this->_content;

        while (current->_nextElem != nullptr)
        {
            current = current->_nextElem;
        }
        current->_nextElem = new ListElem<TYPE>(content);
    }
}

// template<typename TYPE>
// ListElem<TYPE> List<TYPE>::getContent(unsigned int pos)
// {
//     if (pos < _size/2)
//     {
//         TYPE temp = _head->_content;
//         for (unsigned int i = 0; i < _size; ++i)
//         {
//             temp = ;
//         }
//     }
//     else
//     {
        
//     }

//     return ;
// }

///
template <typename TYPE>
class ListIterator
{
private:
    List<TYPE> *_current;

public:
    ListIterator(List<TYPE> list)
    {
        _current = list->;
    }
};