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


#### area\_of\_triangle() test()

#### verify\triangle() test

#### validate\_input() test

#### get\_side\_length() test

Explain what these tests test and why

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
