#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Color.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second){
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s){
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};
auto areaLessThan10 = [](shared_ptr<Shape> s) {
    if(s)
        return (s->getArea() < 10);
    return false;
};
auto areaLessThanX = [x=10](shared_ptr<Shape> s) {
    if(s)
        return (s->getArea() < x);
    return false;
};
void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
        if(it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for(auto it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}
constexpr int fibonacci(int n)
{
    if (n<=1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}
constexpr int foo(int k) {
    return k;
}

template<class DerivedType, class... Arguments>
    std::shared_ptr<Shape> make_shape(Arguments&&... args)
    {
        return make_shared<DerivedType>(std::forward<Arguments>(args)...);
    }



int main()
{
    constexpr int k = fibonacci(45);
    foo(k);
    Collection shapes;
    shapes.push_back(make_shared<Circle>(2.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shared<Circle>(4.0));
    shapes.push_back(make_shared<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shared<Square>(3.0));
    shapes.push_back(make_shared<Circle>(4.0));
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");
    //std::initializer_list<Color> list = {Color::BLUE, Color::RED};
    Rectangle r(Color::RED);
    Square ss(Color::BLUE);
    vector<Shape> coll;
    //coll.push_back(std::move(r));
    //coll.push_back(std::move(ss));

    return 0;
}

