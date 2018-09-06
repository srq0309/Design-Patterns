/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-6
 *
 * @brief	用一个中介对象来封装一系列的对象交互。中介者使各个对象不需要显示地进行相互引用，
 *  从而使其松耦合，而且可以独立地改变它们之间的交互。
**/

#include <iostream>
#include <memory>
#include <iostream>

// 中介者定义一个接口与各同事对象通信
class Mediator
{
public:
};

// 具体中介者通过协调各同事对象实现协作行为
// 了解并维护它的各个同事
class ConcreteMediator :
    public Mediator
{

};

// 每一个同事对象都知道它的中介者对象
// 每一个同事需要和其他同事对象进行通信时，与它的中介者通信
class ColleagueClass
{
public:
    ColleagueClass(std::shared_ptr<Mediator> mediator) :
        mediator_(mediator)
    {
    }
private:
    std::shared_ptr<Mediator> mediator_;
};

int main(int argc, char *argv[])
{
	
}