﻿/*
 * GUI 和 ASP.NET 应用程序具有 SynchronizationContext（除非它是null,这种情况下则为当前 TaskScheduler）.
 * 当 await 完成时,它会尝试在捕获的上下文中执行 async 方法的剩余部分.
 * 但是该上下文已含有一个线程, 该线程在（同步）等待 async 方法完成。
 * 它们相互等待, 从而导致死锁.
 * 
 * 但是控制台程序不会形成这种死锁。它们具有线程池 SynchronizationContext 而不是每次执行一个区块的
 * SynchronizationContext， 因此当 await 完成时，它会在线程池上安排 async 方法的剩余部分。
 * 该方法能够完成，并完成其返回任务，因此不存在死锁。
 */

using System.Threading.Tasks;

class DeadLockDemo
{
    public static async Task DelayAsync()
    {
        await Task.Delay(1000);
    }

    public static void Test()
    {
        var delayTask = DelayAsync();
        delayTask.Wait();
    }
}

