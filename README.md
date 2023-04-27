# Operating Systems - Home Work 2
This project was made on Ubuntu 20.04 and all the screenshots are from Ubuntu.<br>
In this Home Work, we have 3 parts:  files operations, dynamic libraries, and basic shell.<br>
We will explain to you what is the subject of each part. 

# Authors : 
* Souffir Ilan Meir : 342615648
* Nerya 

# How to run the project ?
First of all, you need to write this command when you open the terminal of the folder : 
```
make all
```

# Part A - files operations : 
We were requested to implement two small programs, that fills like a regular CMD tools.

## Tool 1 - cmp :
* the tool will compare two files, and return “0” if they are equal, and “1” if not (return an INT).
* The tool will support -v flag for verbose output. By this we mean that the tool will print “equal” or 
“distinct”, in addition to returning the int value.
* The toll will support -i flag, that mean “ignore case” so “AAA” and “aaa” meaning equals.

### How to run ?
You need to create 2 text files, in our exemple : a.txt and b.txt and then you write what you want inside.<br>
For our exemple we wrote in the a.txt the line "123a Hello" and in the b.txt "123A HELLO"<br>

```
./cmp <file1> <file2> -v -i
```
### Results :
<p align="center">
  <img align="center" width=80% src = "https://user-images.githubusercontent.com/55143087/234904991-ad1f3930-db95-4105-9108-e68af7c3d744.png"/>
</p>

## Tool 2 - copy :
* The tool will copy a file to another place and/or name.
* The tool will return “0” on success, or “1” on failure (return an INT).
* The tool will create a new file, if it does not exist, but it will not overwrite a file if it do exist.
* The tool will support -v flag, that will output “success” if the file is copied, or “target file exist” if this is the case, or “general failure” on some other problem (in addition to the returned INT value).
* The tool will support -f flag (that means force), that allows to overwrite the target file.
