# oop_c
Exploring OOP by building objects from first principles in C. I will use, as many others have done, simple geometric concepts such as points, rectangles, circles etc.

> [!Note]
> This is not a guide or tutorial, this is just me learning by doing. That said, if you find it helpful, fell free to use this repo as you see fit.

## Tasks

1. **Encapsulation:** The first and easiest to build is encapsulation. The encapsulation requires to hide properties of an object and expose them only thgrough getter and setter methods. The plan:
  - [ ] Create a Point structure with two integer members `x` and `y`;
  - [ ] Expose the structure only through an opaque structure in a header file;
  - [ ] Create a contructor and destructors `point_create` and `point_destroy`;
  - [ ] Create getters `point_get_x` and `point_get_y`;
  - [ ] Create setters `point_set_x` and `point_set_y`.

2. **Methods:** In task one we have functions, but they are not accessible through the objects themselves. Next thing to implement is to simulate methods throug function pointers.
3. **Inheritance:** Inheritance is one of the most important features of OOP, the ability of a derived object to inherit methods and properties from its base object. This is simple to do in C with nested structures.
4. **Plymorphism:** Another important principle of OOP is polymorphism - the ability of the derived objects to overwrite inherited methods. I have not yet planned how to implement this.
5. **vtable:**
6. **Virtual destructors:**
7. **Contructor chaining:**
8. **RTTI and safe downcasting:** It will probably be a minimal functionality
9. **Interfaces and multiple inheritance:**
10. **Ownership:**
