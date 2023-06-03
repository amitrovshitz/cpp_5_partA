#include <stdexcept>
#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel; 
 ///////////////////////////////////////////////////////////////////////////////////////
void MagicalContainer::addElement(int number)
{
    my_elements.push_back(number);
}
void MagicalContainer::removeElement(int number)
{
    my_elements.erase(std::remove(my_elements.begin(), my_elements.end(), number), my_elements.end());
}
size_t MagicalContainer::size() const
{
    return my_elements.size();
}
///////////////////////////////////////////////////////////////////////////////////////


MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other):container(other.container), index(other.index){}

  
bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const 
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator>(const Iterator& other)const 
{
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
}

bool MagicalContainer::AscendingIterator::operator<(const Iterator& other)const 
 {
    const AscendingIterator *other_iterator = dynamic_cast<const AscendingIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
}     
      
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const			
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
        if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}


int MagicalContainer::AscendingIterator::operator*() const
{
    if (index > container.ascending.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.ascending.at(index));
}



////////////////////////////////////////////////////////////////////////////////

            

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other):container(other.container), index(other.index){}

bool MagicalContainer::SideCrossIterator::operator==(const Iterator &other) const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const Iterator &other) const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator>(const Iterator& other)const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
}

bool MagicalContainer::SideCrossIterator::operator<(const Iterator& other)const
 {
    const SideCrossIterator *other_iterator = dynamic_cast<const SideCrossIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
}            

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const			
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}
  
int MagicalContainer::SideCrossIterator::operator*() const
{
    if (index > container.sidecross.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.sidecross.at(index));
}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other):container(other.container), index(other.index){}
 
bool MagicalContainer::PrimeIterator::operator==(const Iterator &other) const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator!=(const Iterator &other) const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator>(const Iterator& other)const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other_iterator->index;
} 

bool MagicalContainer::PrimeIterator::operator<(const Iterator& other)const
 {
    const PrimeIterator *other_iterator = dynamic_cast<const PrimeIterator*>(&other);

    if(!other_iterator)
    {
        throw std::runtime_error("The iterators must be of the same type");
    }

    if(&container != &other_iterator->container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other_iterator->index;
} 
            
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index != other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index < other.index;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    if(&container != &other.container)
    {
        throw std::runtime_error("It is not possible to compare to another container");
    }

    return index > other.index;
}

int MagicalContainer::PrimeIterator::operator*() const
{
    if (index > container.prime.size())
		{
			throw std::out_of_range("Index out of range");
		}

	return *(container.prime.at(index));
}
//////////////////////////////////////////////////////////////////////////////////