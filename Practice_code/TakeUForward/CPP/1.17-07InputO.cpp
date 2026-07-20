// C++ Basic Input/Output
// Introduction

// When you start learning C++, it’s important to focus on the basics first. Input and Output (I/O) are fundamental concepts, and they are handled using streams in C++. Let’s walk through the structure of a C++ program and how input/output works.
// Including Libraries:
// Libraries provide pre-built functions and tools.
// #include<iostream> → used for input/output.
// #include<math.h> → used for mathematical functions.

#include<iostream>
int main() {
    // Your code here
    return 0;
}

// Output with cout:

// To print output, we use cout from the iostream library. Since it belongs to the standard namespace, we write std::cout.

#include<iostream>
int main() {
    std::cout << "Hey, Striver!";
    return 0;
}

// Output: Hey, Striver!
// Printing on Multiple Lines:
// If you write cout statements repeatedly, they print on the same line.

#include<iostream>
int main() {
    std::cout << "Hey, Striver!";
    std::cout << "Hey, Striver!";
    return 0;
}

// Output: Hey, Striver! Hey, Striver!
// Use \n (newline character) or std::endl to print on new lines.

#include<iostream>
int main() {
    std::cout << "Hey, Striver!" << "\n";
    std::cout << "Hey, Striver!";
    return 0;
}

// Output:
// Hey, Striver!
// Hey, Striver!
// \n vs std::endl :
// \n → inserts a new line (faster, commonly used).
// std::endl → inserts a new line and flushes the output buffer (slower).

#include<iostream>
int main() {
    std::cout << "Hey, Striver!" << std::endl;
    std::cout << "Hey, Striver!";
    return 0;
}

// Using namespace std:

// Writing using namespace std; removes the need to prefix std::. This makes code cleaner but can cause naming conflicts in large projects.

#include<iostream>
using namespace std;
int main() {
    cout << "Hey, Striver!" << endl;
    cout << "Hey, Striver!";
    return 0;
}

// Taking User Input with cin:

// cin is used to take input from the user.

#include<iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    cout << "Value of x: " << x;
    return 0;
}

// Input: 10

// Output: Value of x: 10
// Multiple Inputs:

#include<iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}

// Input: 10 20

// Output: Value of x: 10 and y: 20
// Shortcut: bits/stdc++.h

// Instead of including libraries one by one, you can use:

// #include<bits/stdc++.h>

// Includes almost all standard libraries at once.
// Useful in competitive programming.
// Not recommended for production (due to compile-time overhead).

#include<bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    cout << "Value of x: " << x << " and y: " << y;
    return 0;
}

