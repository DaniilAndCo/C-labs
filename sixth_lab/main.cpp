#include "Stack.cpp"
#include ".\Binary_tree\set1\set1.h"
#include <string>
#include <iostream>

using namespace std;

bool IsStrEven(const string& str)
{
    int sum = 0;
    for (auto& i : str)
    {
        sum += (int)i;
    }
    return (sum % 2 == 0) ? true : false;
}

int main()
{
    Set1<string> binaryTree;
    cout << "Enter amount of elements in binary tree: ";
    int size;
    cin >> size;
    for (auto i = 0; i < size; ++i)
    {   
        string temp;
        cin >> temp;
        binaryTree.Insert(temp);
    }
    Stack<string> stackOfStr;
    for (auto& str : binaryTree.GetLeaves())
    {
        if (IsStrEven(str.second))
        {
            stackOfStr.Push(str.second);
        }
    }
    system("pause");
    return 0;  
}