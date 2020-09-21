/*****************************************/
/* Copyright: DevelEdu 2013              */
/* Author: sha                           */
/*****************************************/

#include <fstream>
#include <iostream>
#include "headers/Product.h"
#include "headers/Discount.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <assert.h>
#include <numeric>
#include <functional>


#define PRODUCT_DB_FILE		"/home/stud/Desktop/Clion/Projects/L04_STL/product.db"

/**
 * Read products from file
 */
void productDBRead(ProductList& pl, const std::string& fileName)
{
    pl.clear();
    std::ifstream pFile( fileName.c_str() );
    assert(pFile.is_open());

    std::istream_iterator< Product > pStreamBegin(pFile);
    std::istream_iterator< Product > pStreamEnd;
    std::copy(pStreamBegin, pStreamEnd, std::back_inserter(pl));
}


/**
 * Printout all products
 */
void printAll(const ProductList& pl)
{
  std::cout << "##################################################" << std::endl;
  std::cout << "Printing out all products..." << std::endl;
  std::cout << "----------------------------" << std::endl;

  std::ostream_iterator< Product > outputProducts(std::cout, "\n");
  std::copy(pl.begin(), pl.end(), outputProducts);
  std::cout << "##################################################" << std::endl;
}



/**
   Add item
*/
void addItem(ProductList& pl)
{
    std::cout << "##################################################" << std::endl;
    std::cout << "Please write product with space between attributes" << std::endl;
    std::istream_iterator< Product > inputProducts(std::cin);
    pl.push_back(*inputProducts);
    std::cout << "##################################################" << std::endl;
}


/**
   Write data to db file
*/
void productDBWrite(const ProductList& pl, const std::string& fileName)
{
    std::cout << "##################################################" << std::endl;
    std::cout << "Writing files to DB" << std::endl;
    std::ofstream pFile( fileName.c_str() );
    assert(pFile.is_open());
    std::ostream_iterator< Product > outputStream(pFile, "\n");
    std::copy(pl.begin(), pl.end(), outputStream);
    std::cout << "##################################################" << std::endl;
}


/**
 * Print poorly selling products
 */
void printPoorlySellingProducts(const ProductList& pl)
{
    std::cout << "##################################################" << std::endl;
    std::cout << "Printing Poorly Sold Products (Fewer than 10)" << std::endl;
    std::ostream_iterator< Product > outputProducts(std::cout, "\n");
    std::remove_copy_if(pl.begin(), pl.end(), outputProducts, [](const Product& pr){return pr.sold() > 10; });
    std::cout << "##################################################" << std::endl;
}


/**
 * Set a discount on all products - Using for_each()
 */
void addDiscountUsingForEachLambda(ProductList& pl)
{
    std::for_each(pl.begin(), pl.end(), [](Product& product){product.setPrice((float)(product.price()*0.90));});
}

void addDiscountUsingForEachFunctor(ProductList& pl)
{
    std::for_each(pl.begin(), pl.end(), Discount(0.90));
}


/**
 * Set a discount on all products - Using transform()
 */
void addDiscountUsingTransform(ProductList& pl)
{
    std::cout << "##################################################" << std::endl;
    std::ostream_iterator< Product > outputDiscountedProducts(std::cout, "\n");

    auto get_discount = []()
    {
        std::cout << "Please enter discount" << std::endl;
        std::istream_iterator< float > inputDiscount(std::cin);
        float discount = std::clamp(*inputDiscount, .1f, .9f);
        return [discount](Product& pr){pr.setPrice(pr.price()*discount); return pr;};
    };

    std::transform(pl.begin(), pl.end(), outputDiscountedProducts, get_discount());
    std::cout << "##################################################" << std::endl;
}


/**
 * Calculate the total amount of sold products
 */
void calcTotalSoldProducts(const ProductList& pl)
{
    std::cout << "##################################################" << std::endl;
    std::cout << "Total Amount of Sold Products" << std::endl;
    auto binaryOperation = [](const unsigned int total, const Product& pr){
        return total + pr.sold();
    };
    const auto totalAmount = std::accumulate(pl.begin(), pl.end(), 0, binaryOperation);
    std::cout << "Total Amount: " << totalAmount << std::endl;
    std::cout << "##################################################" << std::endl;
}


/**
 * Setting discount using bind2nd - OPTIONAL
 */

#include "headers/Test.h"
#include "headers/Wrapper.h"
#include <boost/bind.hpp>
// Exercise 4
int main()
{
    Test t;
    Wrapper<int> w(boost::bind(&Test::printExt , t, _1));
    std::vector <int > v({ 1,3,4,6,8});
    std::copy(v.begin (), v.end(), w);
}


// Exercise 1 - 3
/* int main()
{
  bool        running = true;
  ProductList pl;
  
  while(running)
  {
    char choice;
    
    std::cout << "********************" << std::endl;
    std::cout << "Help menu: " << std::endl;
    std::cout << "'1' Read product database" << std::endl;
    std::cout << "'2' Print all items" << std::endl;
    std::cout << "'3' Add item" << std::endl;
    std::cout << "'4' Write product database" << std::endl;
    std::cout << "'5' Print poorly selling products" << std::endl;
    std::cout << "'6' Set a discount on all products (using for_each() )" << std::endl;
    std::cout << "'7' Set a discount on all products (using transform() )" << std::endl;
    std::cout << "'8' Calculate the total amount of sold products" << std::endl;
    
    
    std::cout << "'q' Quit" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    
    switch(choice)
    {
      case '1':
        productDBRead(pl, PRODUCT_DB_FILE);
        break;

      case '2':
        printAll(pl);
        break;

      case '3':
        addItem(pl);
        break;

      case '4':
        productDBWrite(pl, PRODUCT_DB_FILE);
        break;

      case '5':
        printPoorlySellingProducts(pl);
        break;
        
      case '6':
        addDiscountUsingForEachFunctor(pl);
        break;

      case '7':
        addDiscountUsingTransform(pl);
        break;

      case '8':
        calcTotalSoldProducts(pl);
        break;
        
      case 'q':
      case 'Q':
        running = false;
    }
  }
} */