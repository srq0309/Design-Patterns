/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-2
 *
 * @brief	��������������һ�����ڴ�������Ľӿڣ����������ʵ������һ���࣬
 *  ʹһ�����ʵ�����ӳٵ������ࡣ
**/

#include <iostream>
#include <memory>

// ���幤�������������Ķ���Ľӿ�
class Product
{
public:
    virtual void Show()
    {
        std::cout << "Product Default." << std::endl;
    }
};

// ʵ��Product�ӿ�
class ConcreteProduct :
    public Product
{
public:
    virtual void Show() override
    {
        std::cout << "Product Concrete." << std::endl;
    }
};

// ���������������÷�������һ��Product���͵Ķ���
// ��ȻҲ�ɶ���һ������������ȱʡʵ�֣�����Ĭ�ϵĶ���
class Creator
{
public:
    virtual std::shared_ptr<Product> FactoryMethod()
    {
        return std::make_shared<Product>();
    }
};

// �ض��幤�������Է���һ��ConcreteProductʵ��
class ConcreteCreator :
    public Creator
{
public:
    virtual std::shared_ptr<Product> FactoryMethod() override
    {
        return std::make_shared<ConcreteProduct>();
    }
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Creator> c_dft = std::make_shared<Creator>(),   // Ĭ�Ϲ���
        c_a = std::make_shared<ConcreteCreator>();  // ����

    auto p_dft = c_dft->FactoryMethod();
    auto p_a = c_a->FactoryMethod();

    p_dft->Show();
    p_a->Show();

    system("pause");
    return 0;
}