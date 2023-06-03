#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>
using namespace ariel;
//1
TEST_CASE("Adding elements to the container") {
    ariel::MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    CHECK(container.size() == 3);
}
//2
TEST_CASE("Removing elements from the container") {
    ariel::MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    container.removeElement(10);
    CHECK(container.size() == 2);
}
//3
TEST_CASE("Size of an empty container") {
    ariel::MagicalContainer container;
    CHECK(container.size() == 0);
}
//4
TEST_CASE("AscendingIterator - Iterate over the elements in ascending order") {
    ariel::MagicalContainer container;
    container.addElement(5);
    container.addElement(10);
    container.addElement(15);
    
    ariel::MagicalContainer::AscendingIterator ascIter(container);
    CHECK(*ascIter == 5);
    ++ascIter;
    CHECK(*ascIter == 10);
    ++ascIter;
    CHECK(*ascIter == 15);
}
//5
TEST_CASE("SideCrossIterator - Iterate from both ends towards the middle") {
    ariel::MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    
    ariel::MagicalContainer::SideCrossIterator sideIter(container);
    CHECK(*sideIter == 1);
    ++sideIter;
    CHECK(*sideIter == 4);
    ++sideIter;
    CHECK(*sideIter == 2);
    ++sideIter;
    CHECK(*sideIter == 3);
    ++sideIter;
    CHECK(sideIter == sideIter.end());
}
//6
TEST_CASE("PrimeIterator - Iterate over prime elements only") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    CHECK(*primeIter == 2);
    ++primeIter;
    CHECK(*primeIter == 3);
    ++primeIter;
    CHECK(*primeIter == 5);
    ++primeIter;
    CHECK(primeIter == primeIter.end());
}
//7
TEST_CASE("AscendingIterator - Iterate over an empty container") {
    ariel::MagicalContainer container;
    ariel::MagicalContainer::AscendingIterator ascIter(container);
    CHECK(ascIter == ascIter.end());
}
//8
TEST_CASE("PrimeIterator - Iterate over a container with no prime elements") {
    ariel::MagicalContainer container;
    container.addElement(4);
    container.addElement(6);
    container.addElement(8);
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    CHECK(primeIter == primeIter.end());
}
//9
TEST_CASE("SideCrossIterator - Iterate over a container with no elements") {
    ariel::MagicalContainer container;
    ariel::MagicalContainer::SideCrossIterator sideIter(container);
    CHECK(sideIter == sideIter.end());
}
//10
TEST_CASE("Adding an element that already exists") {
    ariel::MagicalContainer container;
    container.addElement(10);
    
    // Adding an element that already exists should throw an exception
    CHECK_THROWS(container.addElement(10));
}
//11
TEST_CASE("Removing an element that doesn't exist") {
    ariel::MagicalContainer container;
    container.addElement(5);
    container.addElement(8);
    
    // Removing an element that doesn't exist should throw an exception
    CHECK_THROWS(container.removeElement(10));
}
//12
TEST_CASE("Accessing an invalid iterator") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    
    // Accessing an invalid iterator should throw an exception
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    ++primeIter;
    ++primeIter;
    CHECK_THROWS(*primeIter);
}
//13
TEST_CASE("Accessing end() iterator") {
    ariel::MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(5);
    
    // Accessing the end() iterator should throw an exception
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    primeIter.end();
    CHECK_THROWS(*primeIter);
}
//14
TEST_CASE("Assigning an iterator to an invalid iterator") {
    ariel::MagicalContainer container;
    container.addElement(6);
    
    // Assigning an iterator to an invalid iterator should throw an exception
    ariel::MagicalContainer::AscendingIterator ascIter(container);
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    CHECK_THROWS(ascIter.operator==(primeIter));
}
//15
TEST_CASE("Removing an element from an empty container") {
    ariel::MagicalContainer container;
    
    // Removing an element from an empty container should throw an exception
    CHECK_THROWS(container.removeElement(10));
}
//16
TEST_CASE("Accessing an empty container") {
    ariel::MagicalContainer container;
    
    // Accessing an empty container should throw an exception
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    CHECK_THROWS(*primeIter);
}
//17
TEST_CASE("Test Case 41: AscendingIterator - Test operator*") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    
    ariel::MagicalContainer::AscendingIterator ascIter(container);
    
    // Test operator* to retrieve the value
    CHECK(*ascIter == 2);
}
//18
TEST_CASE("AscendingIterator - Test operator++ (prefix)") {
    ariel::MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    
    ariel::MagicalContainer::AscendingIterator ascIter(container);
    
    // Test operator++ (prefix) to move to the next element
    ++ascIter;
    CHECK(*ascIter == 3);
}
//19
TEST_CASE("AscendingIterator - Test operator== and operator!=") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    
    ariel::MagicalContainer::AscendingIterator ascIter1(container);
    ariel::MagicalContainer::AscendingIterator ascIter2(container);
    
    // Test operator== and operator!= for equality comparison
    CHECK(ascIter1 == ascIter2);
    CHECK_FALSE(ascIter1 != ascIter2);
    
    // Move one iterator to the next element
    ++ascIter1;
    
    CHECK(ascIter1 != ascIter2);
    CHECK_FALSE(ascIter1 == ascIter2);
}
//20
TEST_CASE("SideCrossIterator - Test operator*") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    container.addElement(6);
    
    ariel::MagicalContainer::SideCrossIterator sideIter(container);
    
    // Test operator* to retrieve the value
    CHECK(*sideIter == 2);
}
//21
TEST_CASE("SideCrossIterator - Test operator++ (prefix)") {
    ariel::MagicalContainer container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(5);
    
    ariel::MagicalContainer::SideCrossIterator sideIter(container);
    
    // Test operator++ (prefix) to move to the next element
    ++sideIter;
    CHECK(*sideIter == 5);
}
//22
TEST_CASE("SideCrossIterator - Test operator== and operator!=") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(4);
    
    ariel::MagicalContainer::SideCrossIterator sideIter1(container);
    ariel::MagicalContainer::SideCrossIterator sideIter2(container);
    
    // Test operator== and operator!= for equality comparison
    CHECK(sideIter1 == sideIter2);
    CHECK_FALSE(sideIter1 != sideIter2);
    
    // Move one iterator to the next element
    ++sideIter1;
    
    CHECK(sideIter1 != sideIter2);
    CHECK_FALSE(sideIter1 == sideIter2);
}
//23
TEST_CASE("PrimeIterator - Test operator*") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    
    // Test operator* to retrieve the value
    CHECK(*primeIter == 2);
}
//24
TEST_CASE("PrimeIterator - Test operator++ (prefix)") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    container.addElement(5);
    
    ariel::MagicalContainer::PrimeIterator primeIter(container);
    
    // Test operator++ (prefix) to move to the next prime number
    ++primeIter;
    CHECK(*primeIter == 3);
}
//25
TEST_CASE("PrimeIterator - Test operator== and operator!=") {
    ariel::MagicalContainer container;
    container.addElement(2);
    container.addElement(3);
    
    ariel::MagicalContainer::PrimeIterator primeIter1(container);
    ariel::MagicalContainer::PrimeIterator primeIter2(container);
    
    // Test operator== and operator!= for equality comparison
    CHECK(primeIter1 == primeIter2);
    CHECK_FALSE(primeIter1 != primeIter2);
    
    // Move one iterator to the next prime number
    ++primeIter1;
    
    CHECK(primeIter1 != primeIter2);
    CHECK_FALSE(primeIter1 == primeIter2);
}