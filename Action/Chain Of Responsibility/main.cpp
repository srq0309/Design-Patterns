/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-5
 *
 * @brief	使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。
 *  将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止
**/

#include <iostream>
#include <memory>
#include <string>

// 定义一个处理请求的接口
// （可选）实现后继链
class Handler
{
public:
    virtual void HandleRequest(const std::string& key) = 0;
    void SetSuccessor(std::shared_ptr<Handler> successor)
    {
        successor_ = successor;
    }
protected:
    std::shared_ptr<Handler> successor_;
};

// 处理它所负责的请求
// 可访问它的后继者
// 如果可以处理该请求，则处理之；否则将该请求转发给它的后继者
class ConcreteHandlerA :
    public Handler
{
public:
    virtual void HandleRequest(const std::string& key) override
    {
        if (key == "A") {
            std::cout << "ConcreteHandlerA::HandleRequest." << std::endl;
        } else if (successor_) {
            successor_->HandleRequest(key);
        }
    }
};
class ConcreteHandlerB :
    public Handler
{
public:
    virtual void HandleRequest(const std::string& key) override
    {
        if (key == "B") {
            std::cout << "ConcreteHandlerB::HandleRequest." << std::endl;
        } else if (successor_) {
            successor_->HandleRequest(key);
        }
    }
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Handler> h1 = std::make_shared<ConcreteHandlerA>(),
        h2 = std::make_shared<ConcreteHandlerB>();
    h1->SetSuccessor(h2);

    h1->HandleRequest("A");
    h1->HandleRequest("B");
    h1->HandleRequest("C");

    system("pause");
    return 0;
}