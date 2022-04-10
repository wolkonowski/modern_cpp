# Modern C++ exercises

## Compilation and running the project

Check your g++ version by typing:
`> g++ --version`
It should be >= 7.0

```bash
> mkdir build
> cd build
> cmake ..
> make
> ./modern_cpp
```
Or use QT Creator... (or other IDE).

## Tasks:

1. `nullptr`:
    Change all `NULL` to `nullptr`s
    DONE
2. `using` alias:
    Change `typedef` to `using` alias
    DONE
3. Scoped `enum`:
    Write a new scoped `enum` named `Color` and define in it 3 colors of your choice. Inherit from unsigned char.
    Add a new field: `Color color` in the `Shape` class, so that every shape has it's own defined color.
    DONE
4. `auto`:
    Use `auto`, wherever you should.
    DONE
5. Range-based for loop:
    Use range-based for loops, wherever possible.
    DONE
6. `default`, `delete`:
    Mark copy constructors as `default`.
    DONE
    Delete `getY()` method in `Square` and all default constructors of shapes
    DONE
7. `final`, `override`:
    Mark `Circle` class as `final`
    DONE
    Mark `getX()` in `Rectangle` as `final`. What is the problem?
    We need to mark this method as virtual as well.
    DONE
    Mark all overridden virtual methods. Can you spot the problem?
    Methods in Square hasn't been marked const, and methods in Rectangle: virtual.
    DONE
8. `constexpr`:
    Write a function that calculates n-th Fibonacci's number. Do not mark it `constexpr`.
    DONE
    In the first line of `main()` add computing 45-th Fibonacci's number. Measure the time of program execution (`time ./modern_cpp`)
    DONE 8s
    Mark fibonacci function as `constexpr`, compile the program and measure the time of execution once again.
    If you can't see a big difference assign the result to the constexpr variable.
    DONE 0.004s
9. Uniform initialization:
    Use `initializer_list` to initialize the collection.
    DONE
    Add a new constructor to Shape - `Shape(Color c)`. What happens?
    DONE, we need to add default constructor to Shape.
    Use constructor inheritance to allow initialization of all shapes providing only a `Color` as a parameter. Create some shapes providing `Color` only param.
    DONE
    Add in-class field initialization for all shapes to safely use inherited constructor.
    ?????
10. Lambda functions:
    Change functions from `main.cpp` into lambdas (`sortByArea`, `perimeterBiggerThan20`, `areaLessThan10`)
    DONE
    Change lambda `areaLessThan10` into lambda `areaLessThanX`, which takes `x = 10` on a capture list. What is the problem?
    DONE
    Use `std::function` to solve the problem.
    ?????
## Homework:

1. Attributes:
    Add a new method `double getPi()` in `Circle` class, which returns a PI number. Mark it as deprecated.
    DONE
2. `noexcept`:
    Mark some `getArea()` and `getPerimeter()` methods as `noexcept`
    DONE
3. Move semantics:
    Add move constructors and move assignment operators to all shapes.
    DONE
    Mark them as `noexcept`.
    DONE
    What about Rule of 5?
    Copy assignment added, dtor default from parent class
    Move some shapes into the collection.
    DONE
4. Delegating constructors:
    Add a new constructor, which takes also the previously defined Color of a shape. You can use a default parameter for `Color`.
    Delegate a call in the old constructor to the new one.
    DONE
5. Variadic templates:
    Write a factory method which should work like `std::make_shared`.
    It should have below signature:
    ```cpp
    template<class DerivedType, class... Arguments>
    std::shared_ptr<Shape> make_shape(Arguments&&... args);
    ```
    Inside, it should create a `shared_ptr` to `DerivedType` and pass all arguments into constructor of `DerivedType` via perfect forwarding.
    DONE
