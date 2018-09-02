/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-2
 *
 * @brief	��֤һ����ֻ��һ��ʵ�������ṩһ��ȫ�ֵķ��ʵ�
**/

#include <iostream>
#include <memory>

// ����һ��Instance����������һ��Singletonʵ��
class Singleton
{
public:
    static Singleton *Instance()
    {
        return p;
    }
    void SingletonOperation()
    {
        std::cout << "SingletonOperation" << std::endl;
    }
protected:
    Singleton() {}
private:
    static Singleton *p;
};
Singleton* Singleton::p = new Singleton;


int main(int argc, char *argv[])
{
    auto s = Singleton::Instance();
    s->SingletonOperation();

    auto b = Singleton::Instance();
    b->SingletonOperation();

    system("pause");
    return 0;
}