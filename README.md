README.md for CPP05 – “Bureaucrat & Forms”
*42 C++ Module 05 – Bureaucrat & Forms*

# CPP05 – Bureaucrat and Forms

## Project Overview
This project is focused on practicing **C++98 classes, inheritance, polymorphism, and exceptions**.  
It implements a simplified bureaucracy system where:

- `Bureaucrat` objects have **grades** (1–150) and can **sign and execute forms**.
- `AForm` is an abstract base class representing a form with **sign and execution requirements**.
- Derived forms include:
  - `ShrubberyCreationForm` – creates a file with ASCII trees.
  - `RobotomyRequestForm` – simulates robotomization with 50% success.
  - `PresidentialPardonForm` – prints a pardon message.
- `Intern` (ex03) can **dynamically create forms** based on a string request.

The project emphasizes:

- Correct **canonical form** for each class (default, copy, assignment, destructor).  
- Proper use of **exceptions** to handle grade limits and form rules.  
- **Polymorphic behavior** through `AForm` pointers and virtual methods.  
- Safe **dynamic allocation** and memory management.

---

## Project Structure



CPP05/
├── Bureaucrat.hpp / .cpp
├── AForm.hpp / .cpp
├── ShrubberyCreationForm.hpp / .cpp
├── RobotomyRequestForm.hpp / .cpp
├── PresidentialPardonForm.hpp / .cpp
├── Intern.hpp / .cpp # Ex03
├── main.cpp # Test file
└── README.md


---

## Usage

1. Compile all files with:

```bash
g++ -Wall -Wextra -Werror *.cpp -o cpp05


Run the executable:

./cpp05


The main.cpp demonstrates:

Creating Bureaucrat objects.

Incrementing/decrementing grades (with exception handling).

Signing and executing forms.

Using Intern to create forms dynamically.

Important Notes

Grades are inverted: 1 = highest, 150 = lowest.

Exceptions are thrown when:

Bureaucrat grade is too high or too low.

Attempting to sign or execute a form without proper grade.

Attempting to execute an unsigned form.

Intern uses a factory pattern to create forms by name.

Example Output (Partial)
Boss, grade 1
Worker, grade 150
ShrubberyCreationForm created for home
RobotomyRequestForm created for Bender
PresidentialPardonForm created for Marvin
Marvin has been pardoned by Zaphod Beeblebrox.
Exception: Form Not Signed!
Exception: Grade too high

Learning Outcomes

By completing CPP05, you will have:

Mastered C++98 inheritance, virtual functions, and polymorphism.

Implemented exceptions for robust error handling.

Practiced factory pattern (Intern creating forms).

Learned to keep classes in valid state and respect the canonical form.

Reinforced understanding of access control and encapsulation.