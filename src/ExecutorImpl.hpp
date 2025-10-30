#pragma once

#include "Executor.hpp"
#include <string>

namespace adas
{
    /*
        Executor的具体实现
    */
    class ExecutorImpl final : public Executor
    {
    public:
        // 构造函数
        explicit ExecutorImpl(const Pose &pose) noexcept;

        // 默认析构函数
        ~ExecutorImpl() noexcept = default;

        // 不能拷贝
        ExecutorImpl(const ExecutorImpl &) = delete;
        // 不能赋值
        ExecutorImpl &operator=(const ExecutorImpl &) = delete;

    public:
        // 询当前汽车姿态，是父类抽象方法Query的具体实现、
        Pose Query(void) const noexcept override;
        void Execute(const std::string &commands) noexcept override;
        
        // 手动切换fast模式
        void Fast();
        
        //查询是否处于fast状态
        bool IsFast();
    private:
        // 私有数据成员，汽车当前姿态
        Pose pose;
        bool fast_mode{false};
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;

        class ICommand
        {
        public:
            virtual ~ICommand() {};
            virtual void DoOperate(ExecutorImpl &executor) const noexcept = 0;
        };

        class MoveCommand final : public ICommand // 定义一个嵌套类MoveCommand，完成 Move动作(M指令)
        {
        public:
            // 执行Move动作，需要委托ExecutorImp&执行器来完成动作
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.Move();
            }
        };
        class TurnLeftCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.TurnLeft();
            }
        };

        class TurnRightCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.TurnRight();
            }
        };

        class FastCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl &executor) const noexcept override
            {
                executor.Fast();
            }
        };
    };
}
