/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-2
 *
 * @brief	���󹤳����ṩһ������һϵ����ػ�����������Ľӿڣ�������ָ�����Ǿ��������
**/

#include <iostream>
#include <memory>


// Ϊһ���Ʒ��������һ���ӿڣ�A��Ʒ��
class AbstractProductA
{
public:
    virtual void ShowProductA() = 0;
};
// Ϊһ���Ʒ��������һ���ӿڣ�B��Ʒ��
class AbstractProductB
{
public:
    virtual void ShowProductB() = 0;
};

// ����һ���뱻��Ӧ�ľ��幤�̴����Ĳ�Ʒ����A��Ʒ���ͣ�
class ConcreteProductA1 :
    public AbstractProductA
{
public:
    virtual void ShowProductA() override
    {
        std::cout << "Product A, by Factory ��." << std::endl;
    }
};
// ����һ���뱻��Ӧ�ľ��幤�̴����Ĳ�Ʒ����A��Ʒ���ͣ�
class ConcreteProductA2 :
    public AbstractProductA
{
public:
    virtual void ShowProductA() override
    {
        std::cout << "Product A, by Factory ��." << std::endl;
    }
};
// ����һ���뱻��Ӧ�ľ��幤�̴����Ĳ�Ʒ����B��Ʒ���ͣ�
class ConcreteProductB1 :
    public AbstractProductB
{
public:
    virtual void ShowProductB() override
    {
        std::cout << "Product B, by Factory ��." << std::endl;
    }
};
// ����һ���뱻��Ӧ�ľ��幤�̴����Ĳ�Ʒ����B��Ʒ���ͣ�
class ConcreteProductB2 :
    public AbstractProductB
{
public:
    virtual void ShowProductB() override
    {
        std::cout << "Product B, by Factory ��." << std::endl;
    }
};


// ����һ�����������Ʒ����Ĳ����ӿ�
class AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() = 0;
    virtual std::shared_ptr<AbstractProductB> CreateProductB() = 0;
};

// ʵ�ִ��������Ʒ����Ĳ��������ͳ��󹤳���
class ConcreteFactory1 :
    public AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override
    {
        return std::make_shared<ConcreteProductA1>();
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override
    {
        return std::make_shared<ConcreteProductB1>();
    }
};

// ʵ�ִ��������Ʒ����Ĳ��������ͳ��󹤳���
class ConcreteFactory2 :
    public AbstractFactory
{
public:
    virtual std::shared_ptr<AbstractProductA> CreateProductA() override
    {
        return std::make_shared<ConcreteProductA2>();
    }
    virtual std::shared_ptr<AbstractProductB> CreateProductB() override
    {
        return std::make_shared<ConcreteProductB2>();
    }
};

// Client: ��ʹ��AbstractFactory��AbstractProduct�������Ľӿ�
int main(int argc, char *argv[])
{
    std::shared_ptr<AbstractFactory> f1 = std::make_shared<ConcreteFactory1>(), // ����1
        f2 = std::make_shared<ConcreteFactory2>();  // ����2

    std::shared_ptr<AbstractProductA> p_a1 = f1->CreateProductA(),  // ����1��Ʒ��A��Ʒ
        p_a2 = f2->CreateProductA();    // ����2��Ʒ��A��Ʒ
    std::shared_ptr<AbstractProductB> p_b1 = f1->CreateProductB(),  // ����1��Ʒ��B��Ʒ
        p_b2 = f2->CreateProductB();    // ����2��Ʒ��B��Ʒ

    p_a1->ShowProductA();
    p_a2->ShowProductA();
    p_b1->ShowProductB();
    p_b2->ShowProductB();

    system("pause");
    return 0;
}