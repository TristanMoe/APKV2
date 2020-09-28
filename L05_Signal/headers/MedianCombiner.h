//
// Created by stud on 9/28/20.
//

#ifndef L05_MEDIANCOMBINER_H
#define L05_MEDIANCOMBINER_H

template<typename T>
class MedianCombiner
{
public:
    typedef T result_type;

    template<typename InputIterator>
    T operator()(InputIterator first, InputIterator last) const
    {
        std::vector<T> slotList;
        // Return if no slots
        if(first == last) return T();

        while(first != last){
            slotList.push_back(*first);
            ++first;
        }

        // Check for even
        if (slotList.size() % 2 != 0){
            return slotList[slotList.size()/2];
        }

        return (slotList[(slotList.size()-1)/2] + slotList[slotList.size()/2])/2;
    }
private:
};

#endif //L05_MEDIANCOMBINER_H
