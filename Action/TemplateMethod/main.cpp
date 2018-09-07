/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-7
 *
 * @brief	ģ�巽��������һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�
 *  TemplateMethodʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض�����
**/

#include <iostream>
#include <memory>

// ��������ԭ���������������ཫ�ض���������ʵ��һ���㷨�ĸ�������
class AbstractClass
{
public:
    void TemplateMethod()
    {   // ִ��Ԥ���Ĳ������裬ÿ����������������ʵ��
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

class ConcreteClass :
    public AbstractClass
{
public:
    // ͨ�� AbstractClass �̳�
    virtual void PrimitiveOperation1() override
    {
        std::cout << "Operation 1." << std::endl;
    }
    virtual void PrimitiveOperation2() override
    {
        std::cout << "Operation 2." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}