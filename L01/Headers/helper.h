//
// Created by stud on 9/6/20.
//

#ifndef L01_HELPER_H
#define L01_HELPER_H
namespace SharedPointer
{
    // Required deletable interface (Placeholder)
    template <typename T>
    class BaseHelper
    {
    public:
        virtual void operator()(T* t) = 0;
        virtual operator bool() const = 0;
    };

// Details for any arbitrary type (Adapter)
    template <typename T, typename D>
    class Helper : public BaseHelper<T>
    {
    public:
        Helper(D d) : d_(d) {}

        void operator()(T *t) override {
            assert(d_ != nullptr);
            d_(t);
        }

        explicit operator bool() const
        {
            return d_ != nullptr;
        }

    private:
        // pointer to member function (custom destructor)
        D d_ = nullptr;
    };
}
#endif //L01_HELPER_H
