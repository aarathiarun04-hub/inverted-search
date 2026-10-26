# Inverted Search

An inverted-index search engine in C. You hand it a list of text files and it
builds a hash table mapping **every word** to **the files it appears in, and how
many times** — the same data structure that powers full-text search.

```
INDEX  WORD            FILE COUNT   FILE NAME       WORD COUNT
--------------------------------------------------------------
0      are             3            file1.txt       1
                                    file2.txt       1
                                    file3.txt       1
0      apple           1            file2.txt       1
7      hii             1            file1.txt       1
```

## Data structures

- **Hash table** of 27 buckets (`hash_t arr[27]`), indexed by the first letter
  of the word
- **Main node** — one per unique word: the word, the number of files it occurs
  in, and a list of sub nodes
- **Sub node** — one per file: filename and the word count in that file
- **File list** — a singly linked list of the input file names passed on the
  command line

## Build & run

```sh
make
./inverted_search file1.txt file2.txt file3.txt file6.txt
```

Command-line validation checks that each file exists, ends in `.txt`, is not
empty and is not a duplicate. Files that fail are reported and skipped.

## Menu

```
-----------MENU---------------
1.Create Database
2.Display Database
3.Search Database
4.Save Database
5.Update Database
6.Exit
```

- **Create Database** — scan every file and fill the hash table
- **Display Database** — print the whole index in the table layout above
- **Search Database** — look up a word and list the files containing it
- **Save Database** — dump the index to a `.txt` file you name
- **Update Database** — add new files to an existing database

Output is colourised with ANSI escape codes.

## Project structure

| File | Purpose |
| --- | --- |
| `main.h` | Structures, ANSI colour macros, prototypes |
| `main.c` | Driver and menu loop |
| `valid.c` | Command-line/file validation, file list handling |
| `database.c` | Build the hash table from the input files |
| `display.c` | Print the database |
| `search.c` | Search for a word |
| `save.c` | Save the database to a file |
| `update.c` | Update the database with more files |
| `Makefile` | Build and clean targets |
| `file1.txt` … `file6.txt` | Sample input documents |
| `sample_database_output.txt` | Example of the "Display Database" output |
