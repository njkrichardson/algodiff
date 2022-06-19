## Contents 
  1. [Automatic Differentiation]()
  2. [The Derivative Function]()
  3. [Exploiting Computational Abstraction]()
  4. [Example]() 
  5. [Installation]() 
  6. [Examples]() 
  7. 

---
## Automatic Differentiation
Automatic (also known as algorithmic or computational) differentiation is a core technology underlying applications that span scientific and high performance computing, optimization, sensitivity analysis. These areas in turn fuel higher level computing applications in areas like machine learning, 
computational engineering and design, physical simulation, and graphics, to name a few. 

## The Derivative Function 
The notion of a derivative function (throughout the README I use the terms derivative and gradient interchangeably) is one of the most powerful constructs in applied mathematics. In the next section I describe how the structure of our software systems enable 

## Exploiting the Computational Abstraction 
From the computational point of view, one can view an automatic differentiation tool as a kind of domain specific compiler which takes as its source language a certain class of procedures defined in some high-level programming language (e.g., C, C++) and transforms this program into one which computes the derivative function associated with the given procedure. In this sense, the source language of the compiler can be thought of as the set of programs associated with mathematical functions in compliance with certain smoothness properties (so the derivative function is well-defined). The target language can be though of as the set of programs associated with some more general class of mathematical functions (since the derivative function need not be continuous). 

Even more interestingly, these derivative programs compute derivatives with the same numerical accuracy as the source program. Giving this a little though, this seems to defy intuitions gained from finite differencing. The abstraction hierarchy of our computing model is the solution to the riddle of how this accuracy can be gained, and how these compilers work. 

At a high-level, a computing system is conceptually partitioned into an ordered/layered set of abstractions. At the bottom (i.e. least abstract) level the system is comprised of **atoms**, which are composed into relatively monolithic **materials** like crystalline silicon. These materials are chemically engineered and topologically arranged to construct analog microelectronic circuits called **transistors**. Despite their analog physical character, the transistors are designed to enable a digital abstraction in which analog voltages are mapped to digital logical symbols. 

The physical voltages (and associated logical symbols) are transformed using simple circuits of transistors to compute simple logical operations, these circuits are called **gates**. Gates are composed into larger, more complex subcircuits like multiplexers, arithmetic units, 
and memories. Finally, these functional subcircuits are interconnected and composed into full-featured **microarchitectures**, which physically executes the operations of the machine exposed via a programmatic model of the circuit called the **architecture** of the machine. 

The architecture of the computer is the programmer's model of the physical machine, and serves as the lowest layer of the computer's software. Software is layered analagously to the hardware, with an ordering associated with the level of abstraction. Above the architecture are low-level mnuemonic langauges called **assembly languages**. So-called **high-level languages** expose the programmer to more abstract sets of operations which can be compiled into the architectural instruction set. 

Clearly, somehow even the most complex computer progams can be composed from a relatively simple set of primitives. This is evident when you consider that the microarchitecture is limited to a relatively simple finite set of operations which in turn are somehow accomplished via the relatively simple digital operation of transistors. In software too then, apparently complex programs like operating systems and compilers are the result of applying a sequence of simple architectural operations. 

This compositional structure of a computing system corresponds directly with the compositional structure of programs which compute mathematical fuctions. Although the corresponding function may itself be complex, apparently the function is actually *computed* using a relatively simple set of operators. By viewing the aggregate function as the composition of relatively simpler mathemetical operations (ideally those that can be easily associated with programmatic objects), we can propagate derivatives through the program by strategically applying the chain rule. I concretize this notion and provide an example below. 

## Example 
Consider the mathematical function ![equation](https://latex.codecogs.com/svg.image?f(x)&space;=&space;\sin(x)&space;&plus;&space;5x^3&space;-&space;3). We can analytically identify that the function is continuous (it is the sum of a finite number of continuous functions), and determine that the derivative function is ![equation](https://latex.codecogs.com/svg.image?\frac{df}{dx}(x)&space;=&space;cos(x)&space;&plus;&space;15x^2). In this example we'll consider the process of compiling a computer program which computes the function into a different program which computes the derivative function. 

That is, given the source program: 
```
float f(float x)
{
    return math::sin(x) + 5 * math::pow(x, 3) + 3; 
}
```

How can we compile it into a program which computes the derivative function? The core insight of implementing automatic differentiation tools is that all numerical programs are composed of a small finite set of mathematical primitives. Restricting our attention to the operations induced on our independent variable `x` in computing the dependent variable (the output), in this case our procedure `f` is the composition of four primitives: `math::sin(x)`, `operator+(float x, float y)`, `math::pow`, and `operator*(float x, float y)`. Mathematically if we apply the chain rule to f, we have d/dx sin(x) * d/dx x + d/dx 5 * x^3 + 5 * d/dx x^3 + d/dx 3. If we simply knew and hard coded the derivatives of these four operators, we could compute the aggregate derivative function.
