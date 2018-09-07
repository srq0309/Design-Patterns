/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-7
 *
 * @brief	观察者模式：定义对象间的一种一对多的关系，当一个对象的状态发生变化时，所有依赖于它的对象都得到通知并发生变化
**/

#include <iostream>
#include <memory>
#include <string>
#include <set>

// 为那些在目标发生改变时需获取通知的对象定义一个更新接口
class Observer
{
public:
    virtual void Update() = 0;
};

// 目标知道它的观察者，可以有任意多个观察者观察同一目标
// 提供注册和删除观察者对象的接口
class Subject
{
public:
    virtual void Attach(std::shared_ptr<Observer> observer)
    {
        observers_.insert(observer);
    }
    virtual void Dettach(std::shared_ptr<Observer> observer)
    {
        observers_.erase(observer);
    }
    virtual void Notify()
    {
        for (auto iter = observers_.begin(); iter != observers_.end(); ++iter) {
            (*iter)->Update();
        }
    }
private:
    std::set<std::shared_ptr<Observer>> observers_;
};

// 将有关状态存入各ConcreteObserver对象
// 当它的状态发生改变时，向它的各个观察者发出通知
class ConcreteSubject :
    public Subject
{
public:
    std::string GetState() { return state_; }
    void SetState(std::string state)
    {
        state_ = state;
        Notify();   // 通知观察者改变状态
    }
private:
    std::string state_;
};

// 维护一个指向ConcreteSubject对象的引用
// 存储有关状态，这些状态应与目标状态保持一致

class ConcreteObserver :
    public Observer
{
public:
    ConcreteObserver(std::shared_ptr<ConcreteSubject> subject) :
        subject_(subject)
    {
    }
    // 通过 Observer 继承
    virtual void Update() override
    {
        data_ = subject_->GetState();
    }
private:
    std::shared_ptr<ConcreteSubject> subject_;
    std::string data_;
};

int main(int argc, char *argv[])
{
    
}