//
// Created by stud on 9/28/20.
//

#include <iostream>
#include "../headers/Events.hpp"
#include "../headers/Timer.hpp"
#include "assert.h"

Timer::Timer(int timer) :
        eventTimer_( timer ), terminator_(false)
{
    thread_     = new std::thread( std::bind( &Timer::timerThreadFunction, this ) );
}

Timer::~Timer()
{
    terminator_ = true;
    thread_->join();
    delete thread_;
}

int Timer::timerThreadFunction()
{
    int counter = 0;
    while( !terminator_ )
    {
        std::chrono::milliseconds sleepFor( 1000 );
        std::this_thread::sleep_for( sleepFor );

        notifyAll( std::make_shared<Event>() );
        if( ++counter >= eventTimer_ )
        {
            counter = 0;
            std::cout << "EventOther created..." << std::endl;

            notifyAll( std::make_shared<EventOther>() );
        }
    }
    return 0;
}

void Timer::detach(int callbackId) {
    assert(!observers.empty());
    observers.erase(callbackId);
}

int Timer::attach(std::function<void(const std::shared_ptr<Event> &)> callback) {
    int idIncrementer = 0;
    if(!observers.empty()){
        idIncrementer = ((--observers.end())->first) + 1;
    }

    observers.insert({idIncrementer, callback});
    return idIncrementer;
}

void Timer::notifyAll(const std::shared_ptr<Event> &any) {
    auto invokeCallback = [&any](const std::pair<const int, std::function<void(const std::shared_ptr<Event>&)> >& element){
        element.second(any);
    };
    std::for_each(observers.cbegin(), observers.cend(), invokeCallback);
}
