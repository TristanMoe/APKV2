//
// Created by stud on 10/25/20.
//

#include <string>
#include <iostream>

// Returns lvalue reference
int & GetValueByRef()
{
    int value = 10;
    return value;
}

// Returns rvalue, temporary value.
int GetValue()
{
    return 10;
}

void SetValue(int value)
{

}

// Will accept lvalues and rvalues, since const will create temp lvalue?
void SetValueByRef(const int & value)
{

}

void PrintName(std::string& name)
{
    std::cout << name << " by lvalue"<< std::endl;
}

void PrintName(std::string && name)
{
    std::cout << name << " by rvalue" << std::endl;
}

#pragma region Example Main
/*
int main()
{
    int i = GetValueByRef();
    GetValueByRef() = 5;

    // By lvalue
    SetValue(i);
    // By rvalue
    SetValue(10);
    SetValueByRef(10);

    // Left side all lvalues, right side all rvalues
    std::string firstname = "Tristan";
    std::string lastname = "Moeller";

    // Temp string gets constructed from values.
    std::string fullName = firstname + lastname;

    // Works, since by lvalue reference &
    PrintName(fullName);
    // Works, because by rvalue reference && (make const to work)
    PrintName(firstname + lastname);
}
 */
#pragma endregion