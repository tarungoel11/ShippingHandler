#include <Product.h>
#include <algorithm>

#ifndef _CATALOGUE_H
#define _CATALOGUE_H

class Catalogue
{
	std::vector<Product> products;
	public:
		void addProduct(Product p)
		{
			p.setId(products.size());
			products.push_back(p);
		}
		
		int findProduct(string name)
		{
			int result = -1;
			for(int i=0;i<products.size();i++)
			{
				if(products[i].getName() == name)
				{
					result = i;
				}
			}
			return result;			
		}
		
		struct findByName
		{
			string name;
			findByName(string prodName):name(prodName)
			{
			}
			
			bool operator() (const Product& p) const
			{
				if(p.getName() == name)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		};
		bool findProductOpt(string name)
		{
			int result = -1;
			
			std::vector<Product>::iterator it = std::find_if(products.begin(), products.end(), findByName(name));
			return (it!=products.end());			
		}
		
		
		Product getProduct(int id)
		{
			return products[id];
		}
};

#endif
