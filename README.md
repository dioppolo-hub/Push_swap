*This project has been created as part of the 42 curriculum by dioppolo.*

# Push_swap

## Description

`push_swap` is a small sorting program written in C.  
Given a space‑separated list of integers on the command line, it outputs a
sequence of operations (`sa`, `pb`, `ra`, …) which, when applied to two stacks
(`A` and `B`), will sort the numbers in ascending order.  
The goal of the project is to minimise the number of operations for any
input while respecting the rules of the subject.

The implementation adapts its strategy depending on the input size:

* **≤ 100 numbers** – only the *TURK algorithm* is used.  
  This is a variant of the classic “push minimum/maximum” approach where
  rotations and pushes are chosen by analysing the current top elements.
* **≈ 500 numbers** – a hybrid method combining **Chunks** and **TURK**.  
  The stack is first divided into chunks (intervals of indices) and elements
  are moved to stack B chunk by chunk. Within each chunk the TURK procedure
  drives the decision of rotations. After A is empty the values are
  re‑assembled from B with optimal rotations.

Auxiliary routines (`ft_split`, `ft_atoi`, linked‑list helpers, …) are provided
in `libft/` and used throughout the project.  See `main.c` for the entry point
and the sorting modules in `sorting/`.

A companion visualiser (`push_swap_visualizer/`) can run the program and
animate the stacks; it is built with C++17, SFML and ImGui.

## Instructions

1. **Build the project**

   ```bash
   cd /path/to/push_swap
   make
   ```

   This produces the `push_swap` executable in the project root.

2. **Run the algorithm**

   ```bash
   ./push_swap 3 2 5 1 4 | wc -l
   ```

   The program prints a list of commands on `stdout`. You can pipe the output
   into the checker in `push_swap_tester` or feed it to the visualiser.

3. **Visualiser** *(optional)*

* Push_swap_visualiser: https://github.com/o-reo/push_swap_visualizer.git
   ```bash
   cd push_swap_visualizer
   mkdir build && cd build
   cmake ..
   make
   ./bin/visualizer
   ```

   Enter the path to your `push_swap` binary and the values to sort.  See
   `push_swap_visualizer/README.md` for more details.

**Tester** *(optional)*

* Push_swap_tester: https://github.com/Sfabi28/push_swap_tester.git
   ```bash
   cd push_swap_tester
   make
   ```

   Enter the path to your `push_swap` binary and the values to sort.  See
   `push_swap_tester/README.md` for more details.

4. **Other targets**

   ```bash
   make clean      # remove object files
   make fclean     # remove objects and binary
   make re         # fclean + all
   ```

## Resources

* 42 Subject:  
  https://github.com/Binary-Hackers/42_Subjects/blob/master/00_Projects/02_Algorithmic/push_swap.pdf
* Stack‑based sorting tutorials, “push_swap” writeups from the 42 community
  (e.g. ft_contest forks).
* C reference manuals (`man 3`), BSD string functions, SFML/ImGui docs.

## Additional information

* **Algorithm overview**  
  See `sorting/` for the implementation of `sort_tre`, `sort_four`,
  `sort_five`, `sort_generico` and the `chunks` cost estimator.  
* **Testing**  
  The visualiser repo contains Catch2 unit tests for the queue operations
  (`push_swap_visualizer/tests/`).
* **Licence**  
  The visualiser is distributed under the GNU GPL‑3.0 (see
  `push_swap_visualizer/LICENSE`); `push_swap` itself inherits the same terms.
