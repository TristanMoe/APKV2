//
// Created by stud on 9/21/20.
//

#ifndef L04_STL_DISCOUNT_H
#define L04_STL_DISCOUNT_H
#include "Product.h"

class Discount{
public:
    Discount(float discount) : discount(discount) {}

    void operator()(Product& product)
    {
        setDiscount(product);
    }
private:
    float discount;
    void setDiscount(Product& product)
    {
        product.setPrice(((float) product.price()*discount));
    }
};

#endif //L04_STL_DISCOUNT_H
