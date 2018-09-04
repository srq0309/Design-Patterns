/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-4
 *
 * @brief	为子系统中的一组接口提供一个一直的界面，Facade模式定义了一个高层接口，
 *  这一接口使子系统更容易使用
**/

#include <iostream>
#include <memory>

// 实现子系统的功能
// 处理由Facade对象指派的任务
// 没有Facade的任何相关信息，即不保留Facade的任何引用或指针
class SubSystem1
{
public:
    void OperationA()
    {
        std::cout << "SubSystem1::OperationA." << std::endl;
    }
    void OperationB()
    {
        std::cout << "SubSystem1::OperationB." << std::endl;
    }
};
class SubSystem2
{
public:
    void OperationA()
    {
        std::cout << "SubSystem2::OperationA." << std::endl;
    }
};

// 知道那些子系统类负责处理请求
// 将客户的请求代理给适当的子系统对象
class Facade
{
public:
    Facade(std::shared_ptr<SubSystem1> sub1,
        std::shared_ptr<SubSystem2> sub2) :
        sub1_(sub1), sub2_(sub2)
    {
    }
    void Operation()
    {
        sub1_->OperationA();
        sub2_->OperationA();
        sub1_->OperationB();
    }
private:
    std::shared_ptr<SubSystem1> sub1_;
    std::shared_ptr<SubSystem2> sub2_;
};

int main(int argc, char *argv[])
{
    Facade facade(std::make_shared<SubSystem1>(), std::make_shared<SubSystem2>());
    facade.Operation();

    system("pause");
    return 0;
}