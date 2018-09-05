/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-5
 *
 * @brief	��һ�������װΪһ�����󣬴Ӷ�ʹ������ò�ͬ������Կͻ��˽��в�������
 *  �������Ŷӻ��¼�������ӣ��Լ�֧�ֿɳ����Ĳ���
**/

#include <iostream>
#include <memory>
#include <string>
#include <map>

// ֪�����ʵʩ��ִ��һ��������صĲ������κ��඼������Ϊһ��������
class Receiver
{
public:
    void Operation()
    {
        std::cout << "Receiver::Operation." << std::endl;
    }
};

// ����ִ�в����Ľӿ�
class Command
{
public:
    virtual void Execute() = 0;
};

// ��һ�������߶������һ������
// ���ý�������Ӧ�Ĳ�������ʵ��Execute
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

    bool State = true;     // �洢����״̬

private:
    std::shared_ptr<Receiver> receiver_;
};

// Ҫ�������ִ���������
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
    c1->State = false;  // �ı�����״̬��ȡ��ִ�У�

    Invoke invoke;
    invoke.AddCommand("c1", c1);
    invoke.AddCommand("c2", c2);
    invoke.AddCommand("c3", c3);
    invoke.DelCommand("c2");

    invoke.ExecuteAll();

    system("pause");
    return 0;
}