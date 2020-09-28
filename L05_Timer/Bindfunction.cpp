/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

// bindanyfunction.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <mutex>
#include <functional>
#include <boost/bind.hpp>
#include "headers/Events.hpp"
#include "headers/Timer.hpp"

std::mutex stdioProt;
template <class DstType, class SrcType>
bool IsType(const SrcType* src)
{
    return dynamic_cast<const DstType*>(src) != nullptr;
}


void freeFunction( const std::shared_ptr<Event>& event )
{
    // Protecting stdio since its not thread safe
    // Locking event read for this scope, release at end of function.
    std::lock_guard<std::mutex> lock(stdioProt );

    const auto e = std::dynamic_pointer_cast<EventOther>(event);
    if(e)
    {
        std::cout << "EventOther was registered" << std::endl;
        std::cout << *event << std::endl;
    }
}


void withAnExtra(const std::shared_ptr<Event>& event, const std::string text)
{
    // Protecting stdio since its not thread safe
    std::lock_guard<std::mutex> lock(stdioProt );

    const auto e = std::dynamic_pointer_cast<Event>(event);
    if(e)
    {
        std::cout << "Event was registered" << std::endl;
        std::cout << "With extra text: " << text << std::endl;
        std::cout << *event << std::endl;
    }

}


class ReferenceObj
{
public:
    ReferenceObj() : called_(0)
    {
    }

    void call( const std::shared_ptr<Event>& event )
    {
        // Protecting stdio since its not thread safe
        std::lock_guard<std::mutex> lock(stdioProt );

        const auto e = std::dynamic_pointer_cast<Event>(event);
        if(e)
        {
            std::cout << "Event was registered" << std::endl;
            std::cout << "With call incrementer: " << gotCalled() << std::endl;
            std::cout << *event << std::endl;
        }

        ++called_;
    }

    int gotCalled()
    {
        return called_;
    }

private:
    int   called_;
};



int main()
{
    // Try to make several timers with different callbacks
    Timer t1(4 );
    t1.attach( freeFunction );

    // Functor callback
    auto functorCb = &freeFunction;
    t1.attach( functorCb );

    // With extra, signature does not fit.
    // No problem we fix.
    auto extraCb = boost::bind(&withAnExtra, _1, "Wow this actually worked!");
    t1.attach(extraCb);

    // Reference object
    ReferenceObj obj;
    auto refCb = boost::bind(&ReferenceObj::call, boost::ref(obj), _1);
    t1.attach(refCb);


    // The threads run naturally in the background (no clean up has been added for the threads)


    // You might wanna change the loop below such that you can extract the value of called_
    //  from your instance of ReferenceObj
    for(;;)
    {
        std::chrono::milliseconds sleepFor(1000);
        std::this_thread::sleep_for(sleepFor);
    }


    return EXIT_SUCCESS;
}
