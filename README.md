# Triangle Calc

Calculate the area of a triangle given three side lengths.

### Prerequisites

GCC, Git, make

### Installing

Step 1: Clone the repository to your local machine.

```
git clone https://github.com/BrettGleason/TriangleCalc
```

Step 2: Compile from source using make and GCC.

```
make
```

Step 3: Run the program.

```
./Trianglecalc
```
If run with no command line arguments, the program will prompt you for the side lengths of your triangle. Alternatively, the side lengths can be passed as command line arguments.The following command will calculate the area of a triangle with side lengths of 3 meters, 4 meters, and 5 meters.
```
./Trianglecalc 3 4 5
```

## Development

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See Installing for notes on how to deploy the project on a live system.

Step 1: Clone the repository to your local machine.

```
git clone https://github.com/BrettGleason/TriangleCalc
```

Step 2: Update source files as needed.

Step 3: Compile from source using make and GCC.

```
make
```

See 'Running the Tests' for information on testing.

## Running the Tests

Step 1: Build the tests from source with make.
```
make tests
```

Step 2: Run tests with make.
```
make test-all
```
Tests can also be run individually by running the appropriate executable file.

Step 3: Look at test log to verify tests were successful.
```
less test_log.txt
```
The test log contains the output for each test case. Each test has a summary at the end indicating either that all test cases passed or that some test cases failed.

### Unit Tests

#### validate\_input() test
The validate\_input() function makes sure that the side lengths given by the user are valid nonzero integers within the range of a 32 bit unsigned integer. This function has to handle input from command line arguments (where the end of the user input is '\0') as well as input the user gave from stdin (where the end of the user input is '\n'). Because the get\_side\_length() function is responsible for getting the input from the user from stdin, and because this function calls validate\_input() once it has done so, all the test cases for this function are string literals ending in '\0'. The get\_side\_length() test uses the same test cases except ending in '\n' so total coverage is acheived.
The following cases are tested:
* A large negative integer
* A small negative integer
* Zero
* A small positive integer
* The maximum value of a 32 bit unsigned integer
* An integer that is too large but fits in the input buffer
* Two integers separated by spaces that fits in the input buffer
* A floating point number
* A string that fits in the input buffer
* A string that is too large for the input buffer
* An integer that is too large for the input buffer
* An integer that is too large for the input buffer with spaces
* A comma separated list of integers
* A string that begins with numbers
* A string that ends with numbers
* A string that begins with numbers with a space between the digits and the characters
* A string that ends with numbers with a space between the digits and the characters

Each test case is passed to the validate\_input() function and the result is compared to the expected result.

#### get\_side\_length() test

The get\_side\_length() function gets a string from the user, converts that string into an integer, and validates the integer with the validate\_input() function. The same test cases as the validate\_input() function are used except each string ends with a '\n' as if it was collected from the user from stdin. The fmemopen() function is used to provide a mock stdin stream that is filled with the appropriate input and then passed to the get\_side\_length() funciton.

#### verify\_triangle() test
The verify\_triangle() function makes sure that the side lengths given by the user can form a valid triangle. At this point in the code the input has been validated so only values that are within the range of a 32 bit unsigned integer are tested. The following test cases are tested:
* Valid right triangle
* Valid equilateral triangle
* Valid isoceles triangle
* Valid scalene triangle
* Invalid triangle with side A too long
* Invalid triangle with side B too long
* Invalid triangle with side C too long

To test that integer overflow is handled correctly (really "wraparound" because unsigned integers are used):
* Largest valid triangle (side lengths of UINT32\_MAX)
* Invalid triangle with integer overflow
* Valid triangle with integer overflow

Each test case is passed to the verify\_triangle() function and the result is compared to the expected result.

#### area\_of\_triangle() test
The area\_of\_triangle() function calculates the area of the triangle formed by 3 given side lengths. At the point in the code the input has been validated. Triangle side lengths can only be nonzero integers that fit within the range of an unsigned 32 bit integer. In addition the side lengths passed to this function have already been verified to form a valid triangle. The test cases begin with the smallest possible input, a triangle with side lengths of (1, 1, 1) and increase in magnitude until they reach the largest possible input, a triangle with side lengths of (UINT32\_MAX, UINT32\_MAX, UINT32\_MAX). For each test case the area is calculated, the result is considered valid if it is within 1% of the actual value.

### Miscellaneous Testing Info
main() function error conditions:
  -1 - Invalid side length provided
  -2 - Incorrect number of arguments provided
  -3 - Invalid triangle

Each unit test returns the number of failed test cases found.

## Contributing

1. Fork the project (<https://github.com/yourname/yourproject/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request

## Authors

* **Brett Gleason**  - [Brett Gleason](https://github.com/BrettGleason)

## License

This project is licensed under the MIT License - see the ``LICENSE`` file for details

## Acknowledgments

* Thank you to **Billie Thompson** - [PurpleBooth](https://github.com/PurpleBooth) for the README template
