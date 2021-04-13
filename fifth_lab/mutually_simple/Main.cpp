#include "BigInt.h"
#include <iostream>
#include <algorithm>

BigInt GCD(BigInt& first, BigInt& second)
{
	if (first == BigInt("0")) return second;
	if (second == BigInt("0")) return first;
	if (first == second) return first;
	if (first == BigInt("1") || second == BigInt("1")) return BigInt("1");
	// 	Если m, n чётные, то НОД(m, n) = 2*НОД(m/2, n/2);
	// Если m чётное, n нечётное, то НОД(m, n) = НОД(m/2, n);
	// Если n чётное, m нечётное, то НОД(m, n) = НОД(m, n/2);
	// Если m, n нечётные и n > m, то НОД(m, n) = НОД((n-m)/2, m);
	// Если m, n нечётные и n < m, то НОД(m, n) = НОД((m-n)/2, n);
	if (first.IsEven() && second.IsEven()) return GCD(first /= 2, second /= 2) * 2;
	if (first.IsEven() && !second.IsEven()) return GCD(first /= 2, second);
	if (!first.IsEven() && second.IsEven()) return GCD(first, second /= 2);	
	if (!first.IsEven() && !second.IsEven() && first >= second) return GCD((first -= second) /= 2, second);
	if (!first.IsEven() && !second.IsEven() && second >= first) return GCD((second -= first) /= 2, first);
	return BigInt("0");
}
void ABS(string& str)
{
	if (str[0] == '-')
		str.erase(0, 1);
}
std::ostream& operator<< (std::ostream& out, BigInt& number)
{
    // Поскольку operator<< является другом класса BigInt, то мы имеем прямой доступ к членам Point

    for (int i = number.big_number_.GetSize() - 1; i >= 0; --i )
	{
		out << number.big_number_[i];
	}
    return out;
}

int main(){

	string first, second;
	std::cout << "Enter two numbers\n";
	std::cin >> first >> second;
	ABS(first);
	ABS(second);
	BigInt number1(first);
	BigInt number2(second);
	auto answer = GCD(number1, number2);
	
	if (answer == BigInt("0"))
		std::cout << "Error\n";
	else if (answer == BigInt("1"))
		std::cout << "The numbers are mutually simple\n";
		else std::cout << "The numbers aren't mutually simple\n";

	return 0;
}