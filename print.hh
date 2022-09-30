#include <iostream>
#include <string_view>

template<class T>
class printer {
	public:
	void print(std::string_view comment, T& data)
	{
   		std::cout << comment;
    	for (auto datum : data)
        	std::cout << ' ' << datum;
 
		std::cout << '\n';
	}
};
