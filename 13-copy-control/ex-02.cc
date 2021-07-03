class WonderfulFoo;

// Exercise 2: Why is this declaration illegal?

// I'm not sure. I assume that [1] is a better match than the synthesized copy
// constructor in an expression like

// WonderfulFoo a_wonderful_foo;
// WonderfulFoo another_wonderful_foo = a_wonderful_foo;

// I assume this is translated into something like

// WonderfulFoo a_wonderful_foo;
// WonderfulFoo another_wonderful_foo(a_wonderful_foo); // Copy initialization!

// which calls [1], but the parameter of [1] requires the copy constructor to
// initialize it, which calls [1], which ...

class WonderfulFoo
{
    WonderfulFoo(WonderfulFoo); // [1]
};

WonderfulFoo::WonderfulFoo(WonderfulFoo some_wonderful_foo) { }
