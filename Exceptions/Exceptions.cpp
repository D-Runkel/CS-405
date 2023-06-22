// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

/*
* 
* Custom Exception thrown in do_custom_application_logic()
*/
class customException : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "It appears something has gone wrong.";
    }
} customEx;

bool do_even_more_custom_application_logic()
{

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    /*
    * Throw Bad cast standard exception
    */
    throw std::bad_cast();

    return true;
}
void do_custom_application_logic()
{
    std::cout << "Running Custom Application Logic." << std::endl;

    /*
    * The following code declares a varible to hold the results of demcal
    * 
    * Demcal may or may not throw a bad_cast() exception (it does)
    * 
    * To mitigate this, I wrapped it in a try/catch block that catches standard exceptions and prints e.what() to the console
    */
    bool demcal = false;

    try 
    {
        demcal = do_even_more_custom_application_logic();
    } 
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    if (demcal)
    {
        std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
    }

    /*
    * Custom exception defined above
    */
    throw customEx;


    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    /*
    * If the denominator is 0, we throw a logic error: Cannot divide by zero
    */
    if (den == 0.0f)
    {
        throw std::logic_error("Cannot divide by zero");
    }
    return (num / den);
}

void do_division() noexcept
{

    float numerator = 10.0f;
    float denominator = 0;

    //Moved logic into try/catch block. Catches only logic_error();
    auto result = 0.0; 
    try 
    {
        result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (std::logic_error e)
    {
        std::cout << e.what() << std::endl;
    } 
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    /*
    * In main, I created a "Catch all" handler to catch unexpected errors, on top of errors
    * I know will throw.
    */
    try 
    {
        do_division();
        do_custom_application_logic();
    }
    catch (customException& e) { std::cout << e.what() << std::endl; }
    catch (std::exception& e) { std::cout << e.what() << std::endl; }
    catch (...) { std::cout << "An Exception has occurred in main" << std::endl; }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu