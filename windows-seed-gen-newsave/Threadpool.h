#pragma once
#include <cstdint>
#include <shared_mutex>
#include <thread>
#include <vector>

class Threadpool
{
private:
    //make collection of threads
    std::vector<std::thread> threads;
    std::shared_mutex mutex;
    uint_fast8_t thread_amount;
public:
    Threadpool() : Threadpool(std::thread::hardware_concurrency()) //find amount of logical cores on pc
    {
    }

    Threadpool(const uint_fast8_t thread_amount) : thread_amount(thread_amount)
    {
        //reserve memory for threads
        threads.reserve(thread_amount);
    }

    uint_fast8_t get_thread_amount() const
    {
        return thread_amount;
    }

    template <typename Func, typename... Args>
    void submit(Func f, Args ... args)
    {
        threads.emplace_back([f, args...]
        {
            f(args...);
        });
    }

    ~Threadpool()
    {
        //join all threads
        for (auto& thread : threads)
            thread.join();
    }
};
