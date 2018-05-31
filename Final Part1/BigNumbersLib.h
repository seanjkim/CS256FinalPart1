
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace BigNumbers
{
	//! A class that allows you to add large numbers 
	/*!Adds large numbers through strings and vectors that otherwise can not fit in integers. */
	class BigNumbers
	{
		string str; /*!< String member that holds the operand in an expression */
		vector<char> result; /*!< Vector member that holds each individual character of the operand string */
	public:
		//! String constructor
		/*! 
		\param s A string argument
		Constructor that takes in a string that will hold the number for the operand 
		*/
		BigNumbers(string s)
		{
			str = s;
		}
		//! Char vector constructor
		/*! 
		\param temp A char vector argument
		Constructor that takes in a char vector that will hold the characters of the operand string 
		*/
		BigNumbers(vector<char> temp)
		{
			result = temp;
		}
		//! Default constructor
		/*! Constructor with no arguments that sets the operand string to "" */
		BigNumbers()
		{
			str = "";
		}
		//! String getter
		/*! Returns the private string variable */
		string getString()
		{
			return str;
		}
		//! Vector getter
		/*! Returns the private vector variable */
		vector<char> getVector()
		{
			return result;
		}
		//! Addition operator overload
		/*! Operator overload that allows you to add two BigNumbers objects to add large numbers that dont fit in integers */
		BigNumbers operator + (const BigNumbers &) const;
		//! Subtraction operator overload
		/*! Operator overload that allows you to subtract two BigNumbers objects to subtract large numbers that dont fit in integers */
		BigNumbers operator - (const BigNumbers &) const;
		//! Multiplication operator overload
		/*! Operator overload that allows you to multiply two BigNumbers objects to multiply large numbers that dont fit in integers */
		BigNumbers operator * (const BigNumbers &) const;
		//! Division operator overload
		/*! Operator overload that allows you to divide two BigNumbers objects to divide large numbers that dont fit in integers */
		BigNumbers operator / (const BigNumbers &) const;
		//! Modulus operator overload
		/*! Operator overload that allows you to modulus two BigNumbers objects to modulus large numbers that dont fit in integers */
		BigNumbers operator % (const BigNumbers &) const;
	};
	//! Prints number in BigNumbers
	/*! 
	\param b A BigNumbers argument
	Traverses through the passed in BigNumbers argument's char vector variable to print each individual character
	*/
		void print(BigNumbers b);
}