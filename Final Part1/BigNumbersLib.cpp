
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "BigNumberslib.h"
using namespace std;

namespace BigNumbers
{
	BigNumbers BigNumbers::operator + (const BigNumbers & rhs)const
	{

		string strLeft = str;
		string strRight = rhs.str;
		string result = "";
		int dummy = 0;
		if (strLeft.length() > strRight.length())
		{
			swap(strLeft, strRight);
		}

		int leftLength = strLeft.length();
		reverse(strLeft.begin(), strLeft.end());
		int rightLength = strRight.length();
		reverse(strRight.begin(), strRight.end());
		int n = 0;
		while (n < leftLength)
		{
			int sum = ((strLeft[n] - '0') + (strRight[n] - '0'));
			sum += dummy;
			result.push_back(sum % 10 + '0');
			dummy = sum / 10;
			n++;
		}
		int m = leftLength;
		while (m < rightLength)
		{
			int sum = ((strRight[m] - '0') + dummy);
			result.push_back(sum % 10 + '0');
			dummy = sum / 10;
			m++;
		}
		result.push_back(dummy + '0');
		reverse(result.begin(), result.end());
		vector<char> sumVector;
		for (int i = 0; i < result.length(); i++)
		{
			sumVector.push_back(result[i]);
		}

		return BigNumbers(sumVector);

	}
	BigNumbers BigNumbers::operator - (const BigNumbers & rhs)const
	{
		string empty = "";
		int dummy = 0;
		string firstStr = str;
		string secondStr = rhs.str;
		int firstLength = firstStr.length();
		int secondLength = secondStr.length();

		if (firstLength < secondLength)
			swap(firstStr, secondStr);

		for (int i = 0; i < firstLength; i++)
			if (firstStr[i] < secondStr[i])
				swap(firstStr, secondStr);
		firstLength = firstStr.length();
		secondLength = secondStr.length();
		reverse(firstStr.begin(), firstStr.end());
		reverse(secondStr.begin(), secondStr.end());
		int i = 0;
		while (i < secondLength)
		{
			int temp = ((firstStr[i] - '0') - (secondStr[i] - '0') - dummy);
			if (temp < 0)
			{
				temp = temp + 10;
				dummy = 1;
			}
			else
				dummy = 0;

			empty.push_back(temp + '0');
			i++;
		}

		int j = secondLength;
		while (j < firstLength)
		{
			int sub = ((firstStr[i] - '0') - dummy);
			if (sub < 0)
			{
				sub = sub + 10;
				dummy = 1;
			}
			else
				dummy = 0;

			empty.push_back(sub + '0');
			i++;
		}
		reverse(empty.begin(), empty.end());

		vector<char> differenceVector;
		for (int i = 0; i < empty.length(); i++)
		{
			differenceVector.push_back(empty[i]);
		}

		return BigNumbers(differenceVector);
	}
	BigNumbers BigNumbers::operator * (const BigNumbers & rhs)const
	{
		int leftIndex = 0;
		int rightIndex = 0;
		string end = "";

		string left = str;
		string right = rhs.str;
		int leftLength = left.size();
		int rightLength = right.size();
		vector<int> result(leftLength + rightLength, 0);
		int x = leftLength - 1;
		while (x >= 0)
		{
			rightIndex = 0;
			int dummy = 0;
			int leftLength = left[x] - '0';;

			for (int j = rightLength - 1; j >= 0; j--)
			{
				int rightLength = right[j] - '0';
				int sum = leftLength * rightLength + result[leftIndex + rightIndex] + dummy;
				dummy = sum / 10;
				result[leftIndex + rightIndex] = sum % 10;

				rightIndex++;
			}

			if (dummy > 0)
				result[leftIndex + rightIndex] += dummy;

			leftIndex++;
			x--;
		}
		int temp = result.size() - 1;
		while (temp >= 0 && result[temp] == 0)
			temp--;

		while (temp >= 0)
			end += std::to_string(result[temp--]);

		vector<char> productVector;
		for (int i = 0; i < end.length(); i++)
		{
			productVector.push_back(end[i]);
		}
		return BigNumbers(productVector);
	}
	BigNumbers BigNumbers::operator / (const BigNumbers & rhs)const
	{
		string num = str;
		int divisor = stoi(rhs.str);
		string result;
		int index = 0;
		int total = num[index] - '0';
		while (total < divisor)
		{
			total *= 10;
			total += (num[++index] - '0');
		}
		while (num.size() > index)
		{
			result += (total / divisor) + '0';

			total = (total % divisor) * 10 + num[++index] - '0';
		}
		vector<char> quotientVector;
		for (int i = 0; i < result.length(); i++)
		{
			quotientVector.push_back(result[i]);
		}
		return BigNumbers(quotientVector);
	}
	BigNumbers BigNumbers::operator % (const BigNumbers & rhs)const
	{
		string dividend = str;
		int divisor = stoi(rhs.str);

		int calc = 0;

		// One by one process all digits of 'num'
		for (int i = 0; i < dividend.length(); i++)
			calc = (calc * 10 + (int)dividend[i] - '0') % divisor;

		string result = to_string(calc);

		vector<char> modulusVector;
		for (int i = 0; i < result.length(); i++)
		{
			modulusVector.push_back(result[i]);
		}
		return BigNumbers(modulusVector);
	}

	void print(BigNumbers b)
	{
		vector<char> temp = b.getVector();
		for (int i = 0; i < temp.size(); i++)
		{
			cout << temp[i];
		}
	}
}
