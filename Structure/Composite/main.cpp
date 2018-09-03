/*!
 * @file	main.cpp
 *
 * @author	��د����
 * @date	2018-9-3
 *
 * @brief   ���ģʽ����������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ��
 *  ���ģʽʹ�û��Ե��˶������϶����ʹ�þ���һ����
**/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

// Ϊ����еĶ��������ӿ�
// ���ʵ�����£�ʵ�������๫���ӿڵ�ȱʡ��Ϊ
// ����һ���ӿ����ڷ��ʺ͹���Component�������
// ����ѡ���ڵݹ�ṹ�ж���һ���ӿڣ����ڷ���һ������������ں��ʵ������ʵ����
class Component :
    public std::enable_shared_from_this<Component>
{
public:
    virtual void Operation()
    {
        std::cout << "Component::Operation." << std::endl;
        for (auto& c : components_) {
            c->Operation();
        }
    }
    virtual void Add(std::shared_ptr<Component> component)
    {
        components_.push_back(component);
        component->parent_ = shared_from_this();
    }
    virtual void Remove(std::shared_ptr<Component> component)
    {
        components_.erase(std::find(components_.begin(), components_.end(), component));
    }
protected:
    std::vector<std::shared_ptr<Component>> components_;
    std::shared_ptr<Component> parent_;
};

// ������б�ʾҶ�ڵ����Ҷ�ڵ�û���ӽڵ�
// ������ж���ͼԪ�������Ϊ
class Leaf :
    public Component
{
public:
    virtual void Operation() override
    {
        std::cout << "Leaf::Operation." << std::endl;
    }
};

// �������Ӳ�������Щ��������Ϊ
// �洢�Ӳ���
// ��Component�ӿ���ʵ�����Ӳ����йصĲ���
class Composite :
    public Component
{
public:
    virtual void Operation() override
    {
        std::cout << "Composite::Operation." << std::endl;
        for (auto& c : components_) {
            c->Operation();
        }
    }
};

// ͨ��Component�ӿڲ�����ϲ����Ķ���
int main(int argc, char *argv[])
{
    std::shared_ptr<Component> component = std::make_shared<Component>();
    component->Add(std::make_shared<Leaf>());
    component->Add(std::make_shared<Leaf>());
    
    std::shared_ptr<Component> sub_component = std::make_shared<Composite>();
    sub_component->Add(std::make_shared<Leaf>());
    sub_component->Add(std::make_shared<Leaf>());
    sub_component->Add(std::make_shared<Leaf>());

    component->Add(sub_component);

    component->Operation();

    system("pause");
    return 0;
}