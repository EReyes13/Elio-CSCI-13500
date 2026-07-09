# Pointer Detective
Welcome to the agency detective. We ran into a couple of tough cases, and we need your help. As the best pointer detective in town, we thought of you first. 

## Introduction

A mysterious bug has appeared in several C++ programs. Your job as a **Pointer Detective** is to investigate each program and determine what is happening behind the scenes.

For **each mystery**, complete the following tasks **before running the program**:

1. Predict the program's output.
2. Explain **why** the output occurs.
3. Draw the call stack while the function executes.
4. Identify whether the function uses:
   - Pass by Copy
   - Pass by Reference
   - Pass by Pointer

After completing your predictions, compile and run the program to verify your answers.

---

# Mystery #1 – The Copycat

**Concepts:** Pass by Copy, Scope, Call Stack

```cpp
#include <iostream>

void addFive(int number)
{
    number += 5;
    std::cout << "Inside addFive(): " << number << std::endl;
}

int main()
{
    int value = 10;

    addFive(value);

    std::cout << "In main(): " << value << std::endl;
}
```

### Questions

1. What is the output of this program?
The output of the main will be 10. 
2. Why doesn't `value` change after calling `addFive()`?
the value does not change since it is a passy by copy reference so it makes a copy of the variable and uses it for the function, which means that it can only be modified within that function.
3. Where does the variable `number` exist?
Number only exist within the addFive function.
4. Draw the call stack while `addFive()` is executing.
main() -> addFive(10)
main()
5. What happens to `number` after the function returns?
number is deleted since it was only used in the function, but now the function is done so it is no longer needed.
---

# Mystery #2 – The Mirror

**Concepts:** References, `const`, Modifying Variables

```cpp
#include <iostream>

void investigate(int& suspect, const int& clue)
{
    suspect += clue;

    std::cout << "Inside investigate(): "
         << suspect << " " << clue << std::endl;
}

int main()
{
    int score = 10;
    int bonus = 5;

    investigate(score, bonus);

    std::cout << score << " " << bonus << std::endl;
}
```

### Questions

1. What is the output of this program?
155
2. Why does `score` change while `bonus` does not?
since score has the & symbol, that means that the variable is modifiable outisde of main since it holds the memory address, but since bonus has const, that means it is read only so it cannot be modified at all.
3. Why is `clue` declared as a `const` reference?
It is declared as a const so it can only be read and cannot be modified by nay means inside the function.
4. What would happen if the function attempted to modify `clue`?
It would throw an error in the editor.
5. Draw the call stack while `investigate()` is executing.
main() -> investigate(score,bonus)

---

# Mystery #3 – Following the Pointer

**Concepts:** Raw Pointers, Dereferencing, `nullptr`

```cpp
#include <iostream>

void investigate(int* evidence)
{
    if (evidence != nullptr)
    {
        *evidence *= 2;
    }
}

int main()
{
    int clue = 7;

    investigate(&clue);

    std::cout << clue << std::endl;
}
```

### Questions

1. What is the output of this program?
14
2. Why do we pass `&clue` instead of `clue`?
&clue leads to the memory location of clue so it can modify the original variable instead of using a copy.
3. What does `*evidence` do?
evidence is a pointer which holds the memory address of a variable and the value associated.
4. Why is the `nullptr` check important?
a nullptr check is important because it makes sure the pointer is pointing to something and not giving an empty value.
5. What would happen if the function was called as `investigate(nullptr);`?
nothing would occur so the main function output would be the original value which is 7.
6. Draw the call stack while `investigate()` is executing.
main()-> investigate(&clue)

---

# Mystery #4 – The Master Case

**Concepts:** Pass by Copy, Pass by Reference, Pass by Pointer, Return Values

```cpp
#include <iostream>

int mysteryA(int x)
{
    x += 10;
    return x;
}

void mysteryB(int& y)
{
    y *= 2;
}

void mysteryC(int* z)
{
    if (z != nullptr)
    {
        (*z)--;
    }
}

int main()
{
    int value = 5;

    value = mysteryA(value);
    mysteryB(value);
    mysteryC(&value);

    std::cout << value << std::endl;
}
```

### Questions

1. Predict the output of the program.
29
2. Draw the call stack after each function call.
main->mysteryA(value)
main->mysteryB(value)
main->mysteryC(value)
3. Which function uses:
   - Pass by Copy?
   mysteryA
   - Pass by Reference?
   mysteryB
   - Pass by Pointer?
   mysteryC
4. Which functions modify the original variable?
mystery B and C
5. Why does `mysteryA()` return a value, while `mysteryB()` and `mysteryC()` do not?
mysteryA uses pass by copy, so it does not modify the original variable, therefore it need to return the copy as a result in order to change the original variable.
6. Which approach would you choose if your goal was to modify the original variable? Explain your reasoning.
Either B or C since they both have access to the memory location of the original variable

---

# Reflection

Answer the following questions in complete sentences.

1. What is the difference between passing a variable by copy, by reference, and by pointer?
A pass by copy makes a copy of the original variable to be used only within the function. A pass by reference gives the memory location of the original variable. A pass by pointer gives a pointer that contains both the address and value of the original variable
2. When would you choose to use a reference instead of a pointer?
It would mean it is less likely to run into null pointer errors and have a gaurantee of having a value present at time of the function being called.
3. Why might a function accept a pointer instead of a reference?
It may accept a pointer if it plans to shift memory addresses being accessed
4. What role does the `const` keyword play when working with references and pointers?
const makes sure it can only be read and not modified. This ensure no unwanted change occurs and prevent abnormal behavior within the program
5. How does understanding the call stack help explain why variables change—or do not change—during function calls?
A call stack is useful since it shows the step by step process of the variable being changed by different functions and the different conditions and operations that allow or don't allow for the modification of the original variable.