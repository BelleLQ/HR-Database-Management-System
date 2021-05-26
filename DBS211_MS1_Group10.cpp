#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <occi.h>
#include <string>

using oracle::occi::Environment;
using oracle::occi::Connection;

using namespace std;
using namespace oracle::occi;

struct Employee
{
	int  employeeNumber = 0;
	char lastName[50] = { '\0' };
	char firstName[50] = { '\0' };
	char extension[10] = { '\0' };
	char email[100] = { '\0' };
	char officecode[10] = { '\0' };
	int  reportsTo = 0;
	char jobTitle[50] = { '\0' };
};

int menu();
int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp);
void displayEmployee(Connection* conn, struct Employee emp);
void displayAllEmployees(Connection* conn);
int getValidInt();
void insertEmployee(struct Employee* emp);
void insertEmployee(Connection* conn, struct Employee emp);
void updateEmployee(Connection* conn, int employeeNumber);
void deleteEmployee(Connection* conn, int employeeNumber);

int main()
{
	/* OCCI Variables */
	// define an Environment object instance env, and set to safe state null
	Environment* env = nullptr;
	// define a Connection object instance conn, and set to safe state null
	Connection* conn = nullptr;
	Statement* stmt = nullptr;

	/* Used Variables */
	string user = "dbs211_211k18";
	string pass = "31082238";
	string constr = "myoracle12c.senecacollege.ca:1521/oracle12c";

	Employee emp;
	int selection = -1;

	try
	{
		// create an OCCI environment
		env = Environment::createEnvironment(Environment::DEFAULT);
		// create a connection
		conn = env->createConnection(user, pass, constr);
		
			int empNo = 0;
        do {
			selection = menu();
			switch (selection){

			case 1:
				displayEmployee(conn, emp);
				break;
			case 2:
				displayAllEmployees(conn);
				break;
			case 0:
				cout << "\nThanks for using DBS211_GROUP10 HR SYSTEM. Exiting..." << endl;
				break;
			case 3:
				insertEmployee(&emp);
				insertEmployee(conn, emp);
				break;
			case 4:
				
				cout << "Employee Number: ";
				cin >> empNo;
				updateEmployee(conn, empNo);
				break;
			case 5:
				cout << "Employee Number: ";
				cin >> empNo;
				deleteEmployee(conn, empNo);
				break;
			default:
				break;
            }
        }while (selection != 0);

		//terminate the env, conn
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		// catch SQLExceptions if any errors, and print the error code and error message
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}

int menu()
{
	int option = -1;
	
		cout << "\
********************* HR Menu *********************\n\
1) Find Employee\n\
2) Employees Report\n\
3) Add Employee\n\
4) Update Employee\n\
5) Remove Employee\n\
0) Exit\n\
Enter an option (0-5): ";
    do
    {
		option = getValidInt();
	} while (option > 5 || option < 0);
	return option;
}

int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp)
{
	int found = 0;
	try
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("SELECT * FROM dbs211_employees WHERE employeenumber= :1");
		stmt->setInt(1, employeeNumber);
		ResultSet* rs = stmt->executeQuery();
		if (rs->next())
		{
			emp->employeeNumber = rs->getInt(1);
			strcpy(emp->lastName, rs->getString(2).c_str());
			strcpy(emp->firstName, rs->getString(3).c_str());
			strcpy(emp->extension, rs->getString(4).c_str());
			strcpy(emp->email, rs->getString(5).c_str());
			strcpy(emp->officecode, rs->getString(6).c_str());
			emp->reportsTo = rs->getInt(7);
			strcpy(emp->jobTitle, rs->getString(8).c_str());
			found = 1;
		}
		conn->terminateStatement(stmt);
	}
	catch (SQLException& sqlExcp)
	{
		// catch SQLExceptions if any errors, and print the error code and error message
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return found;
}

void displayEmployee(Connection* conn, struct Employee emp)
{
	int employeeNumber = 0;
	cout << "Enter Employee Number: ";
	employeeNumber = getValidInt();
	if (employeeNumber < 0)
	{
		cout << "Employee Number not valid." << endl << endl;
	}
	else
	{
		if (findEmployee(conn, employeeNumber, &emp))
		{
			cout << "\n-------------- Employee Information -------------" << endl;
			cout << "Employee Number: " << emp.employeeNumber << endl;
			cout << "Last Name: " << emp.lastName << endl;
			cout << "First Name: " << emp.firstName << endl;
			cout << "Extension: " << emp.extension << endl;
			cout << "Email: " << emp.email << endl;
			cout << "Office Code: " << emp.officecode << endl;
			cout << "Manager ID: " << emp.reportsTo << endl;
			cout << "Job Title: " << emp.jobTitle << endl << endl;
		}
		else
		{
			cout << "Employee " << employeeNumber << " does not exist." << endl << endl;
		}
	}
}

void displayAllEmployees(Connection* conn)
{
	try
	{
		Statement* stmt = conn->createStatement();
		stmt->setSQL("SELECT e.employeenumber, e.firstname || ' ' || e.lastname, e.email, phone, e.extension, m.firstname || ' ' || m.lastname FROM dbs211_employees e JOIN dbs211_offices USING (officecode) LEFT JOIN dbs211_employees m ON e.reportsto=m.employeenumber ORDER BY e.employeenumber");
		ResultSet* rs = stmt->executeQuery();
		if (!rs->next())
		{
			cout << "There is no employees’ information to be displayed." << endl << endl;
		}
		else
		{
			// if the result set in not empty
			cout.setf(ios::left);
			cout << "\ \n\
------------------------------------------------ Employee Report -------------------------------------------------\n\
------   ---------------    ---------------------------------   ----------------   ---------   -------------------\n\
ID       Employee Name      Email                               Phone              Extension   Manager Name       \n\
------   ---------------    ---------------------------------   ----------------   ---------   -------------------" << endl;
			/*cout << "\n----------------------------------------------- Employee Report ------------------------------------------------" << endl;
			cout << "------   ---------------    ---------------------------------   ----------------   ---------   -----------------" << endl;
			cout.width(9);
			cout << "ID";
			cout.width(19);
			cout << "Employee Name";
			cout.width(36);
			cout << "Email";
			cout.width(19);
			cout << "Phone";
			cout.width(12);
			cout << "Extension";
			cout.width(19);
			cout << "Manager Name";
			cout << endl;
			cout << "------   ---------------    ---------------------------------   ----------------   ---------   -----------------" << endl;*/
			do
			{
				cout.width(9);
				cout << rs->getInt(1);
				cout.width(19);
				cout << rs->getString(2);
				cout.width(36);
				cout << rs->getString(3);
				cout.width(19);
				cout << rs->getString(4);
				cout.width(12);
				cout << rs->getString(5);
				cout.width(19);
				cout << rs->getString(6);
				cout << endl;
			} while (rs->next()); //if there is more rows, iterate
			cout << endl;
		}
	}
	catch (SQLException& sqlExcp)
	{
		// catch SQLExceptions if any errors, and print the error code and error message
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
}

int getValidInt()
{
	string option = "";
	getline(cin, option, '\n');
	bool validInt = isdigit(option[0]);
	for (int i = 0; i < option.length() && validInt; i++)
	{
		validInt = isdigit(option[i]);
	}
	return validInt ? stoi(option) : -1;

	//string option = "";
	//getline(cin, option, '\n');
	//bool validInt = false;
	//if (option.size() > 0)
	//{
	//	validInt = option.at(0) >= 48 && option.at(0) <= 53;
	//	for (int i = 0; i < option.length() && validInt; i++)
	//	{
	//		validInt = option.at(i) >= 48 && option.at(i) <= 53;
	//	}
	//}
	//return validInt ? stoi(option) : -1;
}

void insertEmployee(struct Employee* emp) {
	cout << "-------------- New Employee Information -------------" << endl;
	cout << "Employee Number : ";
	cin >> emp->employeeNumber;
	cout << "Last Name : ";
	cin >> emp->lastName;
	cout << "First Name : ";
	cin >> emp->firstName;
	cout << "Extension : ";
	cin >> emp->extension;
	cout << "Email : ";
	cin >> emp->email;
	cout << "Office Code : 1" << endl;
	cout << "Manager ID : 1002" << endl;
	cout << "Job Title : ";
	cin >> emp->jobTitle;
}
void insertEmployee(Connection* conn, struct Employee emp) {
	if (findEmployee(conn, emp.employeeNumber, &emp)) cout << "An employee with the same employee number exists." << endl << endl;
	else {
		try
		{
			Statement* stmt = conn->createStatement();
			stmt->setSQL("INSERT INTO dbs211_employees VALUES (:1, :2, :3, :4, :5, '1', 1002, :6)");
			stmt->setInt(1, emp.employeeNumber);
			stmt->setString(2, emp.lastName);
			stmt->setString(3, emp.firstName);
			stmt->setString(4, emp.extension);
			stmt->setString(5, emp.email);
			stmt->setString(6, emp.jobTitle);

			stmt->executeQuery();
			conn->commit();
		}
		catch (SQLException& sqlExcp)
		{
			// catch SQLExceptions if any errors, and print the error code and error message
			cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
		}
		cout << "The new employee is added successfully." << endl << endl;
	}
}
void updateEmployee(Connection* conn, int employeeNumber) {
	Employee emp;
	if (findEmployee(conn, employeeNumber, &emp)) {
		try
		{
			cout << "Last Name: " << emp.lastName << endl;
			cout << "First Name: " << emp.firstName << endl;
			cout << "Extension: ";
			cin >> emp.extension;
			Statement* stmt = conn->createStatement();
			stmt->setSQL("UPDATE dbs211_employees SET extension = :1 WHERE employeenumber=:2");
			stmt->setString(1, emp.extension);
			stmt->setInt(2, employeeNumber);

			stmt->executeQuery();
			conn->commit();
		}
		catch (SQLException& sqlExcp)
		{
			// catch SQLExceptions if any errors, and print the error code and error message
			cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
		}
		cout << "The employee's extension is updated successfully." << endl << endl;
	}
	else cout << "The employee with ID "<<employeeNumber<< " does not exist." << endl << endl;

}
void deleteEmployee(Connection* conn, int employeeNumber) {
	Employee emp;
	if (findEmployee(conn, employeeNumber, &emp)) {
		try
		{
			Statement* stmt = conn->createStatement();
			stmt->setSQL("DELETE FROM dbs211_employees WHERE employeenumber=:1");
			stmt->setInt(1, employeeNumber);

			stmt->executeQuery();
			conn->commit();
		}
		catch (SQLException& sqlExcp)
		{
			// catch SQLExceptions if any errors, and print the error code and error message
			cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
		}
		cout << "The employee with ID "<<employeeNumber<<" is deleted successfully." << endl << endl;
	}
	else cout << "The employee with ID " << employeeNumber << " does not exist." << endl << endl;
}
