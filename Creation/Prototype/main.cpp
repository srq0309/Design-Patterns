/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-2
 *
 * @brief	��ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
**/


#include <iostream>
#include <memory>

// ԭ�ͣ������ṩһ����¡����Ľӿ�
class Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() = 0;
    virtual void Show() = 0;
};

// ʵ��һ��ԭ��A
class ConcretePrototypeA :
    public Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() override
    {
        return std::make_shared<ConcretePrototypeA>(*this);
    }

    virtual void Show() override
    {
        std::cout << "ConcretePrototype A." << std::endl;
    }

};
// ʵ��һ��ԭ��B
class ConcretePrototypeB :
    public Prototype
{
public:
    virtual std::shared_ptr<Prototype> Clone() override
    {
        return std::make_shared<ConcretePrototypeB>(*this);
    }

    virtual void Show() override
    {
        std::cout << "ConcretePrototype B." << std::endl;
    }

};

int main(int argc, char *argv[])
{
    std::shared_ptr<Prototype> p_a1 = std::make_shared<ConcretePrototypeA>(),
        p_b1 = std::make_shared<ConcretePrototypeB>();

    auto p_a2 = p_a1->Clone();
    auto p_b2 = p_b1->Clone();

    p_a1->Show();
    p_a2->Show();

    p_b1->Show();
    p_b2->Show();

    system("pause");
    return 0;
}