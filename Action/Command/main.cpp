/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-5
 *
 * @brief	将一个请求封装为一个对象，从而使你可以用不同的请求对客户端进行参数化；
 *  对请求排队或记录请求日子，以及支持可撤销的操作
**/

#include <iostream>
#include <memory>
#include <string>
#include <map>

// 知道如何实施与执行一个请求相关的操作。任何类都可以作为一个接收者
class Receiver
{
public:
    void Operation()
    {
        std::cout << "Receiver::Operation." << std::endl;
    }
};

// 声明执行操作的接口
class Command
{
public:
    virtual void Execute() = 0;
};

// 将一个接收者对象绑定于一个动作
// 调用接收者相应的操作，以实现Execute
class ConcreteCommand :
    public Command
{
public:
    ConcreteCommand(std::shared_ptr<Receiver> receiver) :
        receiver_(receiver)
    {
    }
    virtual void Execute() override
    {
        if (State)
            receiver_->Operation();
        else
            std::cout << "Command Refaused!" << std::endl;
    }

    bool State = true;     // 存储命令状态

private:
    std::shared_ptr<Receiver> receiver_;
};

// 要求该命令执行这个请求
class Invoke
{
public:
    void AddCommand(std::string key, std::shared_ptr<Command> command)
    {
        commands_[key] = command;
    }
    void DelCommand(std::string key)
    {
        commands_.erase(key);
    }
    void ExecuteAll()
    {
        for (auto& command : commands_) {
            std::cout << command.first << " execute: ";
            command.second->Execute();
        }
    }

private:
    std::map<std::string, std::shared_ptr<Command>> commands_;
};

int main(int argc, char *argv[])
{
    std::shared_ptr<Receiver> receiver;

    std::shared_ptr<ConcreteCommand> c1 = std::make_shared<ConcreteCommand>(receiver),
        c2 = std::make_shared<ConcreteCommand>(receiver),
        c3 = std::make_shared<ConcreteCommand>(receiver);
    c1->State = false;  // 改变命令状态（取消执行）

    Invoke invoke;
    invoke.AddCommand("c1", c1);
    invoke.AddCommand("c2", c2);
    invoke.AddCommand("c3", c3);
    invoke.DelCommand("c2");

    invoke.ExecuteAll();

    system("pause");
    return 0;
}