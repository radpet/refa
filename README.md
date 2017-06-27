# What is this?

Refa (*Regular expression to finitite state machine*) is open source C++ library that converts [Regular Expression](https://en.wikipedia.org/wiki/Regular_expression) to [Nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton)/[Deterministic](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) finite state automata and serialize it in JSON format.

# How it works?
There are three main modules parser/compiler/nfa.
The parser module transforms the input regex to a form that the compiler can use in order to map the token to nfa instance.
The nfa module uses epsilon transitions in order to implement its union/concat/iterations(kleene star) .

# How to contribute?
That’s easy, just open an issue giving more information about your future contribution.

## I want to build it from source, how?
@TODO

## How can I run the unit tests?
@TODO
	
# Roadmap

* Serialize the produced nfa (graph) to json  * http://netflix.github.io/falcor/documentation/jsongraph.html maybe?
* Refa Node js addon
  * Write adaptor object making Refa a Node.js C++ addon


