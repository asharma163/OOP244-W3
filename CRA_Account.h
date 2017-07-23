/* NAME-ANSHUL SHARMA
STUDENTID- 136530169
STUDENT E-mail- asharma163@myseneca.ca
*/
#ifndef SICT_CRA_ACCOUNT_H               
#define SICT_CRA_ACCOUNT_H               
namespace sict {
#define SICT_CRA_ACCOUNT_H
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define	MAX_YRS 4
	class CRA_Account {
		char family_name[MAX_NAME_LENGTH + 1];
		char given_name[MAX_NAME_LENGTH + 1];
		int sin_no;
		int m_year[MAX_YRS];

		double	m_balance[MAX_YRS];
	public:
		    void set(int year, double balance);
			void set(const char* familyName, const char* givenName, int sin);
			bool isValid() const;
			void display() const;
	};
}
#endif
