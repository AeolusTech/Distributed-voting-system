![Build status](https://github.com/AeolusTech/Distributed-voting-system/workflows/CI/badge.svg)



**Distributed voting system**
=============================

Project description
-------------------
Console based system which resembles microservices architecture and allows to perform secure and distributed voting.

Project goals
-------------

1. Uses Git as SCM
2. I want to learn C++17 ~~and C++20 quirks~~ ( C++17 has to be used because of Github Actions (Ubuntu 18.04))
3. ~~uses automake to build itself because I know CMake and I want to learn something new~~ autotools is the evilest thing ever. I don't want to touch it anymore. CMake will be used
4. Favor std::future instead of std::thread
5. Favor TDD along with setting up race condition tests and memory leak tests
6. Provides interface that makes it easy to change communication mechanism (or even compare it). Let's play with ZeroMQ,
7. Uses abstract factory pattern and observer pattern
8. Does not use raw pointers but only std::unique_ptr and std::shared_ptr
9. Uses Conan as package manager
10. Doxygen will now not be used because I favor clean code practices. If the project grows significantly then the issue of code docs will be considered.



### Nice to have
1. Custom allocator (http://dmitrysoshnikov.com/compilers/writing-a-memory-allocator/)



Project setup
-------------

1. mkdir build && cd build
2. cmake .. -G ninja
3. ninja
4. e.g. bin/uts


Class diagram
-------------
![General diagram](docs/architecture.svg)


Contributing
------------

The repo is now considered as a proof of skills and something to kill the time during COVID-19 pandemic.

F.A.Q.
------

The current project will be developed according to [the Issues list](https://github.com/AeolusTech/Distributed-voting-system/issues)

License
-------

Distributed voting system specific code is distributed under MIT License.
