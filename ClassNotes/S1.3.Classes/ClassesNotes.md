# Classes Notes September 21

**bold**, _italic_, `inline code block`

## Code Organization

- Each class is defined using two files:
  - Class Definitions and member declaritions

## Default Arguments:

- Same as a parameter value
- Default: Pretermined value if no parameter is sent when function is called

- Calling function sends arguments to a called function and doesn't care if
  arguments arent full.
- Called functions take values from calling function

- You need default constructors for stuff like Arrays

### Characteritics of default constructor:

- Its a member function of a class
- it can be called implicitly or explicitly
- if no constrctors are defined, an empty default constructor is provded automatically
- only **one** default constrctor can exist for each class

### Uses of default constrctors:

- They initialize the data members of an object with default values
- A good constructor must initlialize all the data members

## Destructors

- only one destructor can exit for each class, can't be overloaded
- never called explicitly
- We have to write code ourselves if we want code in a destructor to happen

### What are they used for:

- they can perform clean-up when an object is destroyed
- its like a make clean but for code level

- You call a destructor like a constuctor but with a ~ (tilde) before the name of the class
  ex: ~Thing
