/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-2
 *
 * @brief	保证一个类只有一个实例，并提供一个全局的访问点
**/

#include <iostream>
#include <memory>

// 定义一个Instance操作，访问一个Singleton实例
class Singleton
{
public:
    static Singleton *Instance()
    {
        if (!instance_) {
            instance_ = new Singleton();
        }
        return instance_;
    }
    void SingletonOperation()
    {
        std::cout << "Singleton::SingletonOperation()" << std::endl;
    }
protected:
    Singleton() {}
private:
    static Singleton *instance_;
};
Singleton* Singleton::instance_ = nullptr;


// 非线程安全
int main(int argc, char *argv[])
{
    auto s = Singleton::Instance();
    s->SingletonOperation();

    auto b = Singleton::Instance();
    b->SingletonOperation();

    system("pause");
    return 0;
}