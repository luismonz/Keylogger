#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
private:
    std::thread Thread;
    bool Alive = false;
    long CallNumber = -1L;//HOW MANY TIMES WE WOULD TO CALL A CERTAIN FUNCTION
    long repeat_count = -1L; //WE COUNT THE TIMES THAT A FUNCTIONS IS CALLED
    std::chrono::milliseconds interval = std::chrono::milliseconds(0);
    std::function<void(void)> funct = nullptr;
    //THE FUNCTION ABOVE DOESN'T POINT TO ANY FUNCTION AT THE MOMENT

    void SleepAndRun()
    {
        std::this_thread::sleep_for(interval);
        //this_thread indicates the current thread which created the timer object
        //sleep_for will pause or block the thread for a certain time interval
        if(Alive) Function()();
        //"Function" represents a function that we'll need to call
    }

    void ThreadFunc()
    {
        if(CallNumber==Infinite)
        {
            while(Alive) SleepAndRun();
        } else {
            while(repeat_count--) SleepAndRun();
        }
    }

public:
    static const long Infinite = -1L;
    Timer(){}
    Timer(const std::function<void(void)> &f):funct (f){}
    Timer(const std::function<void(void)> &f,
          const unsigned long &i,
          const long repeat = Timer::Infinite):funct (f),
                                               interval(std::chrono::milliseconds(i)),
                                               CallNumber(repeat){};

    void Start(bool Async = true)
    {
        if(IsAlive()) return;
        Alive = true;
        repeat_count=CallNumber;
        if(Async) Thread = std::thread(ThreadFunc, this);
        else this->ThreadFunc();
    }

    void Stop()
    {
        Alive = false;
        Thread.join();
    }

    void SetFunction(const std::function<void(void)> &f) {funct = f;}

    bool IsAlive() {return Alive;}

    void RepeatCount(const long r)
    {
        if(Alive) return;
        CallNumber=r;

    }

    long GetLeftCount() const {return repeat_count;}

    long RepeatCound() const {return CallNumber;}

    void SetInterval(const unsigned long &i)
    {
        if(Alive) return;
        interval = std::chrono::milliseconds(i);
    }

    unsigned long Interval() const {return interval.count();}

    const std::function<void(void)> &Function() const {return funct;}
};

#endif // TIMER_H
