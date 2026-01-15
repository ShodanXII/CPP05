#pragma once

class Form
{
public:
    Form();
    Form(Form &&) = default;
    Form(const Form &) = default;
    Form &operator=(Form &&) = default;
    Form &operator=(const Form &) = default;
    ~Form();

private:

};
