/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-7
 *
 * @brief	允许一个对象在其内部状态改变时改变它的行为。对象看起来似乎修改了它的类
**/

#include <iostream>
#include <memory>

// 定义一个接口以封装与Context的一个特定状态相关的行为
class State
{
public:
    virtual void Handle() = 0;
};

// 定义客户感兴趣的接口
// 维护一个ConcreteState子类的实例，这个实例定义当前状态
class Context
{
public:
    void Request()
    {
        state_->Handle();           // 实际实现依赖与State对象的实例
    }
private:
    std::shared_ptr<State> state_;  // 通过改变State来改变行为
};

// 每一个子类实现一个Context的一个状态相关的行为
class ConcreteStateA :
    public State
{
public:
    // 通过 State 继承
    virtual void Handle() override
    {
        std::cout << "ConcreteStateA::Handle." << std::endl;
    }
};
// 每一个子类实现一个Context的一个状态相关的行为
class ConcreteStateB :
    public State
{
public:
    // 通过 State 继承
    virtual void Handle() override
    {
        std::cout << "ConcreteStateB::Handle." << std::endl;
    }
};

int main(int argc, char *argv[])
{
	
}