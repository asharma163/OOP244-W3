/* NAME-ANSHUL SHARMA
STUDENTID- 136530169
STUDENT E-mail- asharma163@myseneca.ca
*/
#include <iostream>
#include<cstring>
using namespace std;
#include "CRA_Account.h"
namespace sict {
	int t = 0;
	void CRA_Account::set(int year, double balance)
	{
		if (isValid())
		{
			if (t <4) {
				m_year[t] = year;
				m_balance[t] = balance;
				t++;
			}
			else
				cout << "Space Full" << endl;
		}
	}
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		sin_no = sin;
		bool result = isValid();
		if (result)
		{
			strcpy(family_name, familyName);
			strcpy(given_name, givenName);
			sin_no = sin;
		}
		else
		{
			strcpy(family_name, "\0");
			strcpy(given_name, "\0");
		}
	}

	bool CRA_Account::isValid() const
	{
		int l = sin_no;
		int stock[9] = { 0 };
		int b = sin_no;
		int q = 8;
		int c = 0;
		int e = 0;
		int sum = 0;
		int x = 0;
		int m_alt = 0;
		int m_sum2 = 0;
		int total, v, m_new;

		while (e == 0)
		{

			b = l % 10;
			l = l / 10;


			if (l != 0)
			{
				c++;
				stock[q] = b;
				q--;

			}
			else {
				e = 1;
				c++;
			}stock[0] = b;



		}




		if (c == 9)
		{
			for (int i = 1; i < c; i = i + 2)
			{
				sum = sum + stock[i] + stock[i];

				int t = -2;
				while (t != -1) {
					x = sum % 10;
					m_alt = m_alt + x;

					sum = sum / 10;
					if (sum == 0)
						t = -1;
				}
				sum = 0;
			}

			for (int h = 0; h < 8; h = h + 2)
			{
				m_sum2 = m_sum2 + stock[h];
			}



			total = m_alt + m_sum2;
			int rem = total % 10;
			if (rem != 0)
			{
				v = 10 - rem;
				m_new = total + v;

			}
			else
				m_new = total;
			int diff = m_new - total;
			if (diff == stock[8]) {

				return true;

			}
			else {

				return false;

			}
		}
		return false;
	}
	void CRA_Account::display() const
	{
		if (sin_no != 0)
		{
			int b = 0;
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << sin_no << endl;
			while (b < MAX_YRS) {
				if (m_balance[b] > 2) {
					cout << "Year(" << m_year[b] << ") balance owing: " << m_balance[b] << endl;
					b++;
				}
				else
					if (-(m_balance[b]) > 2)
					{
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Year(" << m_year[b] << ") refund due: " << -(m_balance[b]) << endl;
						b++;
					}
					else
					{
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Year(" << m_year[b] << ") No balance owing or refund due!" << endl;
						b++;
					}
			}
		}
		else
			cout << "Account object is empty!" << endl;
	}
}
