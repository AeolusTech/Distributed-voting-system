# **Distributed voting system**

## Project description
Console based system which resembles microservices architecture and allows to perform secure and distributed voting.

## Project goals

1. Uses Git as SCM
2. I want to learn C++17 and C++20 quirks
3. ~~uses automake to build itself because I know CMake and I want to learn something new~~ autotools is the evilest thing ever. I don't want to touch it anymore
4. Favor std::future instead of std::thread
5. Favor TDD along with setting up race condition tests and memory leak tests
6. Provides interface that makes it easy to change communication mechanism (or even compare it). Let's play with ZeroMQ, boost::asio
7. Uses abstract factory pattern and observer pattern
8. Does not use raw pointers but only std::unique_ptr and std::shared_ptr
9. ~~Uses Conan as package manager~~ project is too simple to use package manager **vcpkg has been used successfully as package manager. Just go to https://github.com/microsoft/vcpkg. It's really easy.



### Nice to have
1. Custom allocator (http://dmitrysoshnikov.com/compilers/writing-a-memory-allocator/)
