#include <iostream>

class Dog
{
	friend void debug_dog_info(Dog& d);
	friend void debug_dog_info();
	friend class Cat;

public:
	Dog(const std::string& name, int age)
		: m_name{name }, m_age{ age } {}

private:
	std::string m_name;
	int m_age;
};

class Cat
{
public: 
	void print_cat_info(const Dog& d) const
	{
		std::cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "] " << std::endl;
	}
private: 
	std::string cat_name;
};

void debug_dog_info(Dog& d)
{
	std::cout << "Dog [ name : " << d.m_name << ", age : " << d.m_age << "] " << std::endl;
}

void debug_dog_info()
{
	Dog dog1("Milo", 4);
	std::cout << "Dog [ name : " << dog1.m_name << ", age : " << dog1.m_age << "] " << std::endl;
}

int main()
{
	Cat cat1;
	Dog dog1("Fluffy", 2);
	cat1.print_cat_info(dog1);
	debug_dog_info();
}