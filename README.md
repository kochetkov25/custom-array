# Array Template Class in C++

## Project Overview

This project implements a template class `Array` that serves as a container for elements of any type `T`, but without assuming the presence of an assignment operator or a default constructor for `T`. This design is inspired by the principle of minimizing type requirements in template-based container classes, allowing for greater flexibility in the types that can be stored in the array.

The `Array` class relies solely on the copy constructor for `T`, ensuring compatibility with types that might not provide assignment operators or default constructors. This approach mimics real-world constraints in high-performance or specialized systems where minimizing operations is crucial.

## Problem Statement

In a previous version of the task, the type `T` was assumed to have both an assignment operator and a default constructor. However, when designing generic container classes like `Array`, it's often more desirable to minimize the assumptions made about the template parameter type.
