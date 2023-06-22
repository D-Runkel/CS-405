// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	const std::string account_number = "CharlieBrown42";
	/*
	* To prevent the buffer overflow, it is recommended to avoid using c-strings in their entirety (cppreference.com).
	* I used a string to accept user input. Therefore the buffer overflow exploit is mitigated in its entirety as a string
	* will allocate the space needed in memory to match the input.
	*/
	std::string user_input;
	std::cout << "Enter a value: ";
	std::cin >> user_input;

	std::cout << "You entered: " << user_input << std::endl;
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu