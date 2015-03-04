========================================================================
    APPLICATION : Employees Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up the Employees application.

ConsoleApplication1.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ConsoleApplication1.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Employees.cpp
    This is the main application source file.

myMenu.cpp
	This is the source file for the myMenu class declared in myMenu.cpp .
	It contains the class source code and definitions.
	This class defines the UI of the project so most of it's private members are static.
	It's written in a way that simplifies interfacing with the class and the application.

myMenu.h
	This is the header file for the myMenu class defined in myMenu.cpp .
	It contains relevant precompiler guards and declarations.

People.cpp
	This is the source file for the People class declared in People.cpp .
	It contains the class source code and definitions.
	This class contains and manages the database so that most of it's private members are static.
	It holds a Person class pointer to a pointer, allowing to contain an array of pointers, each of which can be pointed to another type of person.

People.h
	This is the header file for the People class defined in People.cpp .
	It contains relevant precompiler guards and declarations.

Person.cpp
	This is the source file for the Person class declared in Person.cpp .
	It contains the class source code and definitions.
	This class is an abstract class which contains and declares the basic data and functions to be part of each derived class.
	The class contains virtual and pure virtual classes to be overrided in derived classes (Employee and Candidate).

Person.h
	This is the header file for the Person class defined in Person.cpp .
	It contains relevant precompiler guards and declarations.

Employee.cpp
	This is the source file for the Employee class declared in Employee.cpp .
	It contains the class source code and definitions.
	This class is derived from the abstract base class Person.
	It contains more data and functions to handle it, as well as functions declared purely in Person.
	The class also contains overrides of virtual functions existing in Person.
	Some of the functions are declared virtually to be overrided by the derived class (Candidate).

Employee.h
	This is the header file for the Employee class defined in Employee.cpp .
	It contains relevant precompiler guards and declarations.

Candidate.cpp
	This is the source file for the Candidate class declared in Candidate.cpp .
	It contains the class source code and definitions.
	This class is derived from the Employee class, which in turn is derived from the abstract base class Person.
	This class contains even more data than what is contained by Employee, and more functions to handle that data and the interactions.
	The class also contains overrides of virtual functions existing in Person and Employee.

Candidate.h
	This is the header file for the Candidate class defined in Candidate.cpp .
	It contains relevant precompiler guards and declarations.


AssemblyInfo.cpp
	Contains custom attributes for modifying assembly metadata.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
