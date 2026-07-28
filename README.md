# My work on the K&R C Progamming problems
## Links
[the book](https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20(Kernighan%20Ritchie).pdf)
[local the book](~/Sync/Lib/k+r-c-program.pdf)
[solutions](https://clc-wiki.net/wiki/K%26R2_solutions)
## Checkpoint
pg: 43 - 2.8
*pg. 15 has the table of printf formatting*
## Chapters
### 2
2-1 — READ
2-3 — DO
2-6 — DO
2-7 — DO
2-9 — DO
### 4
4-4 — DO
### 5
5-1 through 5-13 — DO (all)
### 6
6-1 through 6-5 — DO (all)
### 7
7-1 — DO (was READ — printf/variadic internals matter for reading Neovim's codebase)
7-2 — DO
7-3 (error handling / err.c pattern) — READ
Chapter 8 (now relevant — UNIX system calls, direct I/O, low-level file handling)
8-1 (cat implementation) — DO
8-2 (implementing your own buffered I/O with open/read/write) — DO
8-3 (fopen/fclose implementation using system calls) — DO
8-4 (getcwd) — DO
8-5 (recursive directory listing, precursor to ls) — DO
8-6 (storage allocator with sbrk, and the free-list version at the end of the chapter) — DO
Why this matters for Neovim specifically: the editor deals constantly with file buffering, directory traversal (for file finders, netrw-like features), and its own memory management patterns. Chapter 8's exercises are the closest thing in K&R to what you'll actually read in fileio.c or memory.c in the Neovim source.
One more practical step once you finish K&R: skim Neovim's CONTRIBUTING.md and coding-style.md in the repo, since Neovim follows fairly strict C conventions (not identical to K&R style) — it'll save you friction on your first PR.

