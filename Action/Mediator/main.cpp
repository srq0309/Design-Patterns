/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-6
 *
 * @brief	��һ���н��������װһϵ�еĶ��󽻻����н���ʹ����������Ҫ��ʾ�ؽ����໥���ã�
 *  �Ӷ�ʹ������ϣ����ҿ��Զ����ظı�����֮��Ľ�����
**/

#include <iostream>
#include <memory>
#include <iostream>

// �н��߶���һ���ӿ����ͬ�¶���ͨ��
class Mediator
{
public:
};

// �����н���ͨ��Э����ͬ�¶���ʵ��Э����Ϊ
// �˽Ⲣά�����ĸ���ͬ��
class ConcreteMediator :
    public Mediator
{

};

// ÿһ��ͬ�¶���֪�������н��߶���
// ÿһ��ͬ����Ҫ������ͬ�¶������ͨ��ʱ���������н���ͨ��
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