/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-7
 *
 * @brief   定义一系列的算法，把它们一个个封装起来，并且使它们可以相互替换。本模式使得算法可以独立于使用它的客户而变化。
**/

#include <iostream>
#include <memory>

// 定义所有支持的算法的公共接口。Context使用这个接口来调用某ConcreteStrategy定义的算法
class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

// 以Strategy接口实现某具体算法
class ConcreteStrategyA :
    public Strategy
{
public:
    // 通过 Strategy 继承
    virtual void AlgorithmInterface() override
    {
        std::cout << "Algorithm A." << std::endl;
    }
};

class ConcreteStrategyB :
    public Strategy
{
public:
    // 通过 Strategy 继承
    virtual void AlgorithmInterface() override
    {
        std::cout << "Algorithm B." << std::endl;
    }
};

class Context
{
public:
    Context(std::shared_ptr<Strategy> strategy) :
        strategy_(strategy)
    {
    }
    void SetStrategy(std::shared_ptr<Strategy> strategy)
    {
        strategy_ = strategy;
    }
    void ContextInterface()
    {
        strategy_->AlgorithmInterface();
    }
private:
    std::shared_ptr<Strategy> strategy_;
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Strategy> s1 = std::make_shared<ConcreteStrategyA>(),
        s2 = std::make_shared<ConcreteStrategyB>();
    
    Context c(s1);

    c.ContextInterface();
    
    c.SetStrategy(s2);
    c.ContextInterface();

    system("pause");
    return 0;
}