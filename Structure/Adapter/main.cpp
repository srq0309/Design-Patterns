/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-3
 *
 * @brief	��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڣ�
 *  Adapterģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ������
**/

#include <iostream>

// ����Clientʹ�õ����ض�������صĽӿ�
class Target
{
public:
    virtual void Request()
    {
        std::cout << "Target::Request." << std::endl;
    }
};

// �����Target�ӿڵĶ���Эͬ
class Client
{
public:
    Client(std::shared_ptr<Target> target) :
        target_(target)
    {
    }
    void Work()
    {
        target_->Request();
    }
private:
    std::shared_ptr<Target> target_;
};

// ����һ���Ѿ����ڵĽӿڣ�����ӿ���Ҫ����
class Adaptee
{
public:
    void SpecificRequest()
    {
        std::cout << "Adaptee::SpecificRequest" << std::endl;
    }
};

// ��Adapee�Ľӿ���Target�Ľӿڽ�������
class Adapter :
    public Target, private Adaptee
{
public:
    virtual void Request() override
    {
        Adaptee::SpecificRequest();
    }
};

int main(int argc, char *argv[])
{
    Client cc(std::make_shared<Adapter>());
    cc.Work();

    system("pause");
}
