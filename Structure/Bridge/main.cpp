/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-3
 *
 * @brief	将抽象部分与它的实现部分分离，使它们都可以独立地变化
**/

#include <iostream>
#include <memory>

// 定义实现类的接口，该接口不一定要与Abstraction的接口完全一致；事实上这两个接口可以完全不同
// 一般来讲，Implementor接口仅提供基本操作，而Abstraction则定义了这些基本操作的较高层次的操作
class Implementor
{
public:
    virtual void OperationImpl() = 0;
};

// 实现Implementor并定义它的具体实现
class ConcreteImplementor :
    public Implementor
{
public:
    virtual void OperationImpl() override
    {
        std::cout << "ConcreteImplementor::OperationImpl." << std::endl;
    }
};

// 定义抽象类的接口
// 维护一个只Implement类型对象的指针
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

// 扩充由Abstraction定义的接口
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
