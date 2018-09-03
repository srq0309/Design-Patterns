/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-3
 *
 * @brief	�����󲿷�������ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ����ر仯
**/

#include <iostream>
#include <memory>

// ����ʵ����Ľӿڣ��ýӿڲ�һ��Ҫ��Abstraction�Ľӿ���ȫһ�£���ʵ���������ӿڿ�����ȫ��ͬ
// һ��������Implementor�ӿڽ��ṩ������������Abstraction��������Щ���������Ľϸ߲�εĲ���
class Implementor
{
public:
    virtual void OperationImpl() = 0;
};

// ʵ��Implementor���������ľ���ʵ��
class ConcreteImplementor :
    public Implementor
{
public:
    virtual void OperationImpl() override
    {
        std::cout << "ConcreteImplementor::OperationImpl." << std::endl;
    }
};

// ���������Ľӿ�
// ά��һ��ֻImplement���Ͷ����ָ��
class Abstraction
{
public:
    Abstraction(std::shared_ptr<Implementor> impl) :
        impl_(impl)
    {
    }
    virtual void Operation()
    {
        impl_->OperationImpl();
    }
protected:
    std::shared_ptr<Implementor> impl_;
};

// ������Abstraction����Ľӿ�
class RefinedAbstraction :
    public Abstraction
{
public:
    RefinedAbstraction(std::shared_ptr<Implementor> impl) :
        Abstraction(impl)
    {
    }
    virtual void Operation() override
    {
        Abstraction::Operation();
        std::cout << "Add Something." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    RefinedAbstraction ra(std::make_shared<ConcreteImplementor>());
    ra.Operation();

    system("pause");
    return 0;
}
