#include <iostream>
#include <memory>

// class Test
// {
// public:
// 	Test()
// 	{
// 		std::cout << "Test()" << std::endl;
// 	}

// 	Test(int i)
// 	{
// 		std::cout << "Test(int i)" << std::endl;
// 	}

// 	~Test()
// 	{
// 		std::cout << "~Test()" << std::endl;
// 	}
// };

// int main()
// {
// 	std::shared_ptr<Test> p1 = std::make_shared<Test>(5);

// 	std::cout << "1 ref:" << p1.use_count() << std::endl;

// 	{
// 		std::shared_ptr<Test> p2 = p1;
// 		std::cout << "2 ref:" << p1.use_count() << std::endl;
// 	}

// 	std::cout << "3 ref:" << p1.use_count() << std::endl;

// 	return 0;
// }


class TestB;
class TestA
{
public:
    TestA()
    {
        std::cout << "TestA()" << std::endl;
    }
    void ReferTestB(std::shared_ptr<TestB> test_ptr)
    {
        m_TestB_Ptr = test_ptr;
    }
    ~TestA()
    {
        std::cout << "~TestA()" << std::endl;
    }
private:
    std::shared_ptr<TestB> m_TestB_Ptr;
};

class TestB
{
public:
    TestB()
    {
        std::cout << "TestB()" << std::endl;
    }

    void ReferTestB(std::shared_ptr<TestA> test_ptr)
    {
        m_TestA_Ptr = test_ptr;
    }
    ~TestB()
    {
        std::cout << "~TestB()" << std::endl;
    }
    std::shared_ptr<TestA> m_TestA_Ptr;
};


int main()
{
    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
    ptr_a->ReferTestB(ptr_b);
    ptr_b->ReferTestB(ptr_a);
    return 0;
}