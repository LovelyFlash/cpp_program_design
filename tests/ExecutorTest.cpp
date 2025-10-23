#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, lhs.heading);
    }
    // 下面二个测试用例，测试静态方法Executor::NewExecutor
    // 测试用例1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // 测试条件就是调用Executor的静态方法NewExecutor返回一个指向Executor对象的智能指针executor，这样我们就不需要去delete了
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        const Pose target({0, 0, 'E'}); // 构造一个姿势对象target，其内容为{o，0，'E'}
        // 既然构造Executor对象时的初始姿势是{0,0,'E'}，那么executor->Query()返回的Executor对象的姿势必须等于target
        // 所以这里用了断言：executor->Query(返回的Executor对象的姿势必须等于target，否则测试失败，说明Executor的实现有问题
        ASSERT_EQ(target, executor->Query()); // ASSERT_EQ内部调用了重载的Pose的==
    }
    // 测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 没有给初始姿势

        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试用例3
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        executor->Execute("M");
        
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
}