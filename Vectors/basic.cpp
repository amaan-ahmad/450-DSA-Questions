#include <iostream>
#include <vector>

void printVector(std::vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
}

int main()
{

    // initializing a vector
    std::vector<int> vec;

    // populating a vector
    for (int i = 1; i <= 5; i++)
        vec.push_back(i * 10);

    // printing vector
    printVector(vec);

    std::cout << std::endl;

    std::cout << "Size: " << vec.size();
    std::cout << std::endl;

    std::cout << "Max Size: " << vec.max_size();
    std::cout << std::endl;

    std::cout << "Capactiy: " << vec.capacity();
    std::cout << std::endl;

    vec.shrink_to_fit();
    std::cout << "After Shrink to fit --- ";
    std::cout << std::endl;

    std::cout << "Capactiy: " << vec.capacity();
    std::cout << std::endl;

    int *pos = vec.data();

    std::cout << "First element *pos: " << *pos;
    std::cout << std::endl;

    std::cout << "Second element *(pos+1): " << *(pos + 1);
    std::cout << std::endl;

    std::cout << "Third element *(pos+2): " << *(pos + 2);
    std::cout << std::endl;

    vec.pop_back();
    std::cout << "after pop_back(): ";
    printVector(vec);
    std::cout << std::endl;

    if (vec.empty())
    {
        std::cout << "Vector is empty" << std::endl;
    }
    else
    {
        std::cout << "Vector has elements" << std::endl;
        std::cout << "Calling vec.clear() " << std::endl;
        vec.clear();
    }

    if (vec.empty())
    {
        std::cout << "Vector is empty" << std::endl;
    }
    else
    {
        std::cout << "Vector still has elements" << std::endl;
    }

    return 0;
}