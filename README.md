# What is this?

Refa (*Regular expression to finitite state machine*) is open source C++ library that converts [Regular Expression](https://en.wikipedia.org/wiki/Regular_expression) to [Nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton)/[Deterministic](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) finite state automata and serialize it in JSON format.

# How it works?
There are three main modules parser/compiler/nfa.

The parser module transforms the input regex to a form that the compiler can use in order to map the token to nfa instance.
The compiler reads the parsed input and produce nfa result.
The nfa module uses epsilon transitions in order to implement its union/concat/iterations(kleene star) .

# How to contribute?
That’s easy, just open an issue giving more information about your future contribution.

## I want to build it from source, how?
Download cmake version 3.7 or higher
Run cmake <path to refa source code folder>

## How can I run the unit tests?
First execute the build from source steps
Run make
run ./testRunner
	
# Roadmap

* Serialize the produced nfa (graph) to json  * http://netflix.github.io/falcor/documentation/jsongraph.html maybe?
* Refa Node js addon
  * Write adaptor object making Refa a Node.js C++ addon


