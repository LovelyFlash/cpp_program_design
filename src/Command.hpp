#pragma once
#include "PoseHandler.hpp"

namespace adas
{
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperate(PoseHandler &executor) const noexcept = 0;
    };

    class MoveCommand final : public ICommand // 定义一个嵌套类MoveCommand，完成 Move动作(M指令)
    {
    public:
        // 执行Move动作，需要委托ExecutorImp&执行器来完成动作
        void DoOperate(PoseHandler &executor) const noexcept override
        {
            executor.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &executor) const noexcept override
        {
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &executor) const noexcept override
        {
            executor.TurnRight();
        }
    };

    class FastCommand final : public ICommand
    {
    public:
        void DoOperate(PoseHandler &executor) const noexcept override
        {
            executor.Fast();
        }
    };

}