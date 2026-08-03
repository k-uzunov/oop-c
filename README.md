# oop_c
Exploring OOP by building objects from first principles in C. I will use, as many others have done, simple geometric concepts such as points, rectangles, circles etc.

> [!Note]
> This is not a guide or tutorial, this is just me learning by doing. That said, if you find it helpful, fell free to use this repo as you see fit.

## Tasks

1. **Encapsulation:** The first and easiest to build is encapsulation. The encapsulation requires to hide properties of an object and expose them only thgrough getter and setter methods. The plan:
  - [x] Create a Point structure with two integer members `x` and `y`;
  - [x] Expose the structure only through an opaque structure in a header file;
  - [x] Create a contructor and destructors `point_create` and `point_destroy`;
  - [x] Create getters `point_get_x` and `point_get_y`;
  - [x] Create setters `point_set_x` and `point_set_y`.

  ==Done==

2. **Methods:** In task one we have functions, but they are not accessible through the objects themselves. Next thing to implement is to simulate methods throug function pointers. Here is the issue: in step one I made the structure opaque, i.e. I used incomplete declaration in the header to hide the layout and the properties of the structure, making them available only throug getters and setters. Using function pointers in the struc would not be useful, because the pointers will also be hidden. How to solve this:
  1. The Python way: expose the whole structure layout in the header and hide the properties by convention. If a property name starts with double underscore it is not supposed to be touched by the user.
  2. Wrappers: We leave the structure layout hidden and expose the methods throug function wrappers.

  I picked option one. In my opinion wrappers would introduce a lot of boilerplate. A bunch of functions that are used only to call a method. I also don't like the chance of function calling the wrong method, function calling non-existing (deleted) method, methods missing a function etc.
  ==Done==
3. **Inheritance:** Inheritance is one of the most important features of OOP, the ability of a derived object to inherit methods and properties from its base object. This is simple to do in C with nested structures.
4. **Plymorphism:** Another important principle of OOP is polymorphism - the ability of the derived objects to overwrite inherited methods. I have not yet planned how to implement this.
5. **vtable:**
6. **Virtual destructors:**
7. **Contructor chaining:**
8. **RTTI and safe downcasting:** It will probably be a minimal functionality
9. **Interfaces and multiple inheritance:**
10. **Ownership:**
