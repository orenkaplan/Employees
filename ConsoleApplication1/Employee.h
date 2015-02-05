#pragma once
class Employee
{
	friend bool openEmployeeFile(System::String ^ strFile);
	friend bool closeEmployeeFile();

public:
	Employee();
	~Employee();
	long getEmployeeNumber();
	System::String getEmployeeName();
	double getEmployeeSalary();
	bool isEmployeeGlobal();
	System::DateTime getDealDate();
	bool isEmployeeActive();

private:
	long lngEmployeeNumber;
	System::String ^ strEmployeeName;
	double dblEmployeeSalary;
	bool blGlobalEmployee;
	System::DateTime dtDealDate;
	bool blEmployeeActive;
	System::String ^ strFileName;
};

