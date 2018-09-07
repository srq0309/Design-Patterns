/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-7
 *
 * @brief   ����һϵ�е��㷨��������һ������װ����������ʹ���ǿ����໥�滻����ģʽʹ���㷨���Զ�����ʹ�����Ŀͻ����仯��
**/

#include <iostream>
#include <memory>

// ��������֧�ֵ��㷨�Ĺ����ӿڡ�Contextʹ������ӿ�������ĳConcreteStrategy������㷨
class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

// ��Strategy�ӿ�ʵ��ĳ�����㷨
class ConcreteStrategyA :
    public Strategy
{
public:
    // ͨ�� Strategy �̳�
    virtual void AlgorithmInterface() override
    {
        std::cout << "Algorithm A." << std::endl;
    }
};

class ConcreteStrategyB :
    public Strategy
{
public:
    // ͨ�� Strategy �̳�
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