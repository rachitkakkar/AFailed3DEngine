The following code is purely comprised of functional programming. Each header is defined into modules, with their own namespaces (eg. Renderer, Projector, ect.).
Each module is comprised of functions and globals. There are no structs or classes. If we need to take a color we will not define a struct or class with an RGB, instead we will pass the RGB values as ints within the function.

# DO NOT DO THIS:
```cpp
struct Color{
    int r, g, b;
};
```

# DO THIS:
```cpp
void some_function(int r, int g, int b) {

}
```

There is one exception. GLM is so highly integrated, that we consider them as basic types instead of classes. So a vector has the same weight as an int, even though it is a class defined by GLM.

# THIS IS OK:
```cpp
void some_function(glm::vec3 vector) {

}
```

All other libraries should be abstracted (like SDL2 is with the renderer) so they can be swapped out.