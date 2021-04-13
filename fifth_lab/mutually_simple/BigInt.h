#pragma once
#include ".\List\List.h"
#include <string>
using std::string;

class BigInt
{
	private:
	List<int> big_number_;
	public:

	size_t GetSize()
	{
		return big_number_.GetSize();
	}
	
	BigInt(const string& number)
	{	
		for (const auto& symbol : number)
		{
			big_number_.PushFront(int(symbol - '0'));
		}
	}
	void Set(const string& number)
	{	big_number_.Clear();
		for (const auto& symbol : number)
		{
			big_number_.PushFront(int(symbol - '0'));
		}
	}

	BigInt& operator-=(const BigInt& other)
	{
        for (int i = 0; i < other.big_number_.GetSize(); i++) {
            big_number_[i] -= other.big_number_[i];
        }

        for (int i = 0; i < big_number_.GetSize() - 1; i++) {
            if (big_number_[i] < 0) {
                big_number_[i] += 10;
                big_number_[i + 1]--;
            }
        }
		return *this;
    }

	BigInt operator-(const BigInt& other)
	{
        BigInt n(*this);
        n -= other;
        return n;
    }

	BigInt& operator/=(long long x)
	{
        for (int i = big_number_.GetSize() - 1; i >= 0; --i) {
            if (i) {
                big_number_[i - 1] += (big_number_[i] % x) * 10;
            }
            big_number_[i] /= x;
        }
		while (big_number_[big_number_.GetSize() - 1] == 0)
		{
			big_number_.PopBack();
		}
		return *this;
    }

	BigInt operator/(long long x)
	{
        BigInt n(*this);
        n /= x;
        return n;
    }

	BigInt& operator*=(long long x)
	{
        for (int i = 0; i <= big_number_.GetSize() - 1; ++i)
		{
			big_number_[i] *= x;
        }
		int i = 0;
		for (; i < (int)big_number_.GetSize() - 2; ++i)
		{
			big_number_[i] %= 10;
			big_number_[i + 1] += big_number_[i] / 10;
        }
		big_number_[i] %= 10;
		big_number_.PushBack(big_number_[i] / 10);       
		
		while (big_number_[big_number_.GetSize() - 1] == 0)
		{
			big_number_.PopBack();
		}
		return *this;
    }

	BigInt operator*(long long x)
	{
        BigInt n(*this);
        n *= x;
        return n;
    }

	string ToString() const
	{
		string result = "";
		for (int i = big_number_.GetSize() - 1; i >= 0; --i )
		{
			result += big_number_[i];
		}
		return result;
	}

	bool operator==(const BigInt& other)
	{
		if (other.big_number_.GetSize() != big_number_.GetSize()) return false;
		for (int i = 0; i < big_number_.GetSize(); ++i)
		{
			if (big_number_[i] != other.big_number_[i]) return false;
		}
		return true;
	}
	bool operator>=(const BigInt& other)
	{
		if (other.big_number_.GetSize() > big_number_.GetSize()) return false;
		if (other.big_number_.GetSize() < big_number_.GetSize()) return true;
		for (int i = big_number_.GetSize() - 1; i >= 0; --i)
		{
			if (big_number_[i] < other.big_number_[i]) return false;
			if (big_number_[i] > other.big_number_[i]) return true;
		}
		return true;
	}
	bool IsEven()
	{
		if (big_number_[0] % 2 == 0) return true;
			else return false;
	}
	friend std::ostream& operator<< (std::ostream &out, BigInt &point);
};

