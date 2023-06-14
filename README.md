# Homework assignment: copy constructor and copy assignment for string

## Assignment

Write a copy constructor and an assignment operator for such a string class:

```c++
class string {
	char *data_;
	std::size_t size_;
	std::size_t capacity_;
public:
	// TODO copy ctor
	// TODO copy assignment;
};
```

Usage example:

```c++
string s = "Hello, world!";
string s1 = "Other text";

string scopy = s;
s1 = s;
```

## Solution

Full solution is available at [string_copy/string.hpp](string_copy/string.hpp)

## Design considerations

The copy assignment operator was implemented using the copy-and-swap idiom to easily achieve strong exception safety guarantee, cause all other methods provides it.

We were not asked to implement a moving constructor or a moving assignment operator, so they are not implemented.