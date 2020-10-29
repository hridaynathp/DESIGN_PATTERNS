#include <iostream>
#include <vector>

using namespace std;

enum class Color {red, green, blue};
enum class Size {small, medium, large};

// Products with its attributes
struct Product
{
   string name;
   Color color;
   Size size;
};

// Filtering products
struct ProductFilter
{
   vector<Product*> by_color(vector<Product *> product, Color color)
   {
      vector<Product*> result;

      vector<Product*>::iterator it;
      for(it=product.begin();it!=product.end();it++)
      {
         if((*it)->color == color)
         {
            result.push_back(*it);
         }
      }

      return result;
   }
};


int main()
{

   // Defining products
   Product p1{"apple", Color::green, Size::small};
   Product p2{"tree", Color::green, Size::large};
   Product p3{"house", Color::blue, Size::large};

   vector<Product*> products{&p1,&p2,&p3};
   ProductFilter filter;

   // Filtering green products
   vector<Product*> greenProducts = filter.by_color(products, Color::green);

   // Display green products
   for(vector<Product*>::iterator it=greenProducts.begin(); it!=greenProducts.end();it++)
      cout<<(*it)->name<<" is green"<<endl;

   return 0;
}
