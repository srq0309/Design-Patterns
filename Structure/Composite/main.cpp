/*!
 * @file	main.cpp
 *
 * @author	梦丿无情
 * @date	2018-9-3
 *
 * @brief   组合模式：将对象组合成树形结构以表示“部分-整体”的层次结构。
 *  组合模式使用户对单核对象和组合对象的使用具有一致性
**/

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

// 为组合中的对象声明接口
// 在适当情况下，实现所有类公共接口的缺省行为
// 声明一个接口用于访问和管理Component的子组件
// （可选）在递归结构中定义一个接口，用于访问一个父组件，并在合适的情况下实现它
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

// 在组合中表示叶节点对象，叶节点没有子节点
// 在组合中定义图元对象的行为
class Leaf :
    public Component
{
public:
    virtual void Operation() override
    {
        std::cout << "Leaf::Operation." << std::endl;
    }
};

// 定义有子部件的那些部件的行为
// 存储子部件
// 在Component接口中实现与子部件有关的操作
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

// 通过Component接口操作组合部件的对象
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