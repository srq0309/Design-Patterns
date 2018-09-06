/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-6
 *
 * @brief	在不破坏封装的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。
 *  这样以后就可以将该对象恢复到先前的状态。
**/

#include <iostream>
#include <string>
#include <memory>
#include <deque>

// 备忘录存储原发器对象的内部状态。原发器根据需要决定备忘录存储原发器的哪些状态
// 防止原发器以外的对象访问备忘录，理想状态是只允许生成备忘录的原发器对象访问本备忘录的内部状态。
class Memento
{
public:
    std::string GetState()
    {
        return state_;
    }
    void SetState(std::string state)
    {
        state_ = state;
    }
private:
    std::string state_;
};

// 原发器创建一个备忘录，用以记录当前的状态
// 使用备忘录恢复先前的对象
class Originator
{
public:
    void SetMemento(std::shared_ptr<Memento> memento)
    {
        state_ = memento->GetState();
    }
    std::shared_ptr<Memento> CreateMemento()
    {
        return std::make_shared<Memento>();
    }
private:
    std::string state_;
};

// 负责保存好备忘录
// 不能对备忘录的内容进行操作或检查
class Caretaker
{
public:
private:
    std::deque<std::shared_ptr<Memento>> mementos_;
};

int main(int argc, char *argv[])
{
	
}