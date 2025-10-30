#include "ExecutorImpl.hpp"

#include <new>
#include <memory>

namespace adas
{
    ExecutorImpl::ExecutorImpl(const Pose &pose) noexcept : poseHandler(pose) {};

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();
    }

    void ExecutorImpl::Execute(const std::string &commands) noexcept
    {
        for (const auto cmd : commands)
        {
            std::unique_ptr<ICommand> cmder = nullptr;
            if (cmd == 'M')
                cmder = std::make_unique<MoveCommand>();
            else if (cmd == 'L')
                cmder = std::make_unique<TurnLeftCommand>();
            else if (cmd == 'R')
                cmder = std::make_unique<TurnRightCommand>();
            else if (cmd == 'F')
                cmder = std::make_unique<FastCommand>();
            if (cmder)
                cmder->DoOperate(poseHandler);
        }
    }

    /*
        std::nothrow是C++标准库中的一个常量，用于指示在分配内存时不抛出任何异常。
        它是std::nothrow_t类型的实例，通常用在new运算符和std::nothrow命名空间中，
        以请求内存分配器在分配失败时返回一个空指针，而不是抛出std::bad_alloc异常。
    */

    Executor *Executor::NewExecutor(const Pose &pose) noexcept
    {
        return new (std::nothrow) ExecutorImpl(pose);
    }
}