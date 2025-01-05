
# Sorting Algorithms Visualization

## Overview
This project is a visualization tool for sorting algorithms, implemented using the [raylib](https://www.raylib.com/) library. The tool supports visualizing Bubble Sort and Insertion Sort with an interactive user interface. Users can select algorithms and observe the sorting process in real-time.

## Prerequisites
To compile and run the program, ensure you have the following installed on your system:

- **raylib**: A library for graphics programming. Ensure it is available in the project directory.
- **Make**: A build tool to automate the compilation process.
- **C++ Compiler**: Such as `g++`, supporting C++11 or later.

## Files
- `main.cpp`: Contains the main logic for rendering and user interaction.
- `header.h`: Declares shared variables and functions.
- `sorts.cpp`: Implements the sorting algorithms.
- `Makefile`: Automates the build process.
- `app`: Executable output (optional).

## Compilation and Execution

### Build the Program
To compile the project, use the following command:
```bash
make
```

### Run the Program
After successful compilation, execute the program with:
```bash
./app
```

### Clean Up
To remove generated files, use:
```bash
make clean
```

## Troubleshooting
- Ensure `raylib` is properly included in the project directory.
- Verify that your compiler supports C++11 or later.
- If the program fails to build, check the `Makefile` for proper paths and configurations.

## License
This project is distributed under the MIT License. See the `LICENSE` file for details.

## Contributions
Contributions are welcome! Fork the repository, make your changes, and submit a pull request.

## Credits
- **Developer:** Joaquin Gottlebe
- **Built With:** raylib and C++
