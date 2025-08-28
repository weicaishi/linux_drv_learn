# Linux Driver Learning Project

This repository is dedicated to learning and experimenting with Linux kernel driver development. It contains examples, exercises, and notes to help understand the fundamentals of writing Linux device drivers.

## Directory Structure

- **src/**: Source code for the drivers.
- **docs/**: Documentation and learning resources.
- **examples/**: Sample drivers and code snippets.

## Prerequisites

- Linux kernel development environment.
- Basic knowledge of C programming.
- Familiarity with Linux command-line tools.

## Getting Started

1. Clone the repository:
    ```bash
    git clone https://github.com/weicaishi/linux_drv_learn.git
    cd linux_drv_learn
    ```

2. Set up the development environment:
    - Install necessary tools: `gcc`, `make`, `kernel headers`, etc.
    - Refer to the `docs/setup.md` for detailed instructions.

3. Explore the examples:
    ```bash
    cd examples
    ```

4. Build and test:
    ```bash
    make
    sudo insmod your_driver.ko
    ```

## Contributing

Contributions are welcome! Feel free to submit issues, fork the repository, and create pull requests.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

Special thanks to the Linux kernel community for their extensive documentation and support.
