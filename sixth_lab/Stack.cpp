#include ".\List\List.h"
template<typename T>
class Stack
{
    private:
    List<T> stack_;

    public:
    ~Stack()
    {
        stack_.Clear();
    }
    bool IsEmpty() const {return stack_.IsEmpty();}
    void Push(const T& data)
    {
        stack_.PushBack(data);
    }
    T Pop()
    {
        auto result = Top();
        stack_.PopBack();
        return result;
    }
    T Top()
    {
        return *(--stack_.end());
    }

};