//
// Created by stud on 10/25/20.
//

#include <iostream>
#include <cstring>

class String
{
public:
    String()
    {
        printf("Default Create\n");
        m_Size = 0;
        m_Data = nullptr;
    }

    String(const char * string)
    {
        printf("Created\n");
        m_Size = strlen(string); 
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(const String& other)
    {
        printf("Copied\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    // Move constructor
    String(String&& other) noexcept
    {
        printf("Moved\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    // Move assignment
    String& operator=(String && other) noexcept
    {
        printf("Move assignment\n");
        if(this != &other)
        {
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;
    }


    virtual ~String() {
        printf("Destroyed\n");
        delete m_Data;
    }

    void Print()
    {
        for(uint32_t i = 0; i < m_Size; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }
private:
    char* m_Data;
    uint32_t m_Size;
};

class Entity
{
public:
    Entity(const String& name)
    // m_Name(name) will copy data!
        : m_Name(name)
    {

    }

    Entity(String&& name)
    // m_Name(std::move(name)) will move data!
            : m_Name(std::move(name))
    {

    }


    void PrintName()
    {
        m_Name.Print();
    }
private:
    String m_Name;
};

#pragma region Example Main
/*
int main()
{
    // Creates and copies string ** BAD **!
    // Entity entity1(String("Tristan"));
    // entity1.PrintName();

    // Creates and MOVES string ** GOOD **!
    // Entity entity2(String("Bobby"));
    // entity2.PrintName();

    String string = "Hello";

    // Will copy string instead of move.
     String dest1 = string;
    // Will move string
    String dest2 = std::move(string);

    // Assignment operator will only be called if assignment
    // happens on EXISTING variable.
    String apple = "Apple";
    String dest;

    dest = std::move(apple);

    std::cin.get();
}
 */
#pragma endregion