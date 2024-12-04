# Advanced-Coding-SEM7

Advanced-Coding-SEM7, Programming Assignments

---

To compile and run a given C program, for example, `example.c`

Use the command:

```bash
compile_and_run example.c
```

To make the command dynamic for different C files, you can use a shell function instead of an alias. Here's how you can set it up:

### For `bash`:

1. Open your terminal and edit the `~/.bashrc` file:
   ```bash
   nano ~/.bashrc
   ```
2. Add the following function to the file:
   ```bash
   cnr() {
       local filename="${1%.c}"
       gcc "$filename.c" -o "$filename" && ./"$filename"
   }
   ```
3. Save the file and exit the editor.
4. Reload the `.bashrc` file:
   ```bash
   source ~/.bashrc
   ```

Now, you can use this command with any C file by passing the filename (without the `.c` extension) as an argument:

```bash
cnr p2
```

This will compile `p2.c`, create the executable `p2`, and run it.
