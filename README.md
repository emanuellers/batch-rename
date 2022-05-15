## BATCH RENAME

Simple project using WIN32 syntax to iterate throughout a directory and rename the files.

### How to use:
1. Compile the project:
> g++ -o rename rename.cpp

or

> mingw32-make rename

2. Use the project with flags.

- -filepath: Complete path of target directory.
- -templateName: Base name for renaming files.

#### Example:

```powershell 
.\rename -filepath="C:\Users\Samsung\Desktop\batch_rename\sample" -templateName=newName 
```
### Output example:
```powershell 

Ok... C:\Users\Samsung\Desktop\batch_rename\sample\example_0.t => C:\Users\Samsung\Desktop\batch_rename\sample\newName_0.t
Ok... C:\Users\Samsung\Desktop\batch_rename\sample\example_1.html => C:\Users\Samsung\Desktop\batch_rename\sample\newName_1.html
Ok... C:\Users\Samsung\Desktop\batch_rename\sample\example_2.txt => C:\Users\Samsung\Desktop\batch_rename\sample\newName_2.txt
```

#### Objectives:
Learning.
Project created to practice beginner concepts from Alura course: C++ Introdução a Linguagem e STL.


