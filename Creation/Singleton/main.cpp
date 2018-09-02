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


// ���̰߳�ȫ
int main(int argc, char *argv[])
{
    auto s = Singleton::Instance();
    s->SingletonOperation();

    auto b = Singleton::Instance();
    b->SingletonOperation();

    system("pause");
    return 0;
}