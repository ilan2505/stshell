# Operating Systems - Home Work 2
This project was made on Ubuntu 20.04 and all the screenshots are from Ubuntu.<br>
In this Home Work, we have 3 parts:  files operations, dynamic libraries, and c.<br>
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
./cmp <file1> <file2> [-v] [-i]
```
### Results :
<p align="center">
  <img align="center" width=60% src = "https://user-images.githubusercontent.com/55143087/234904991-ad1f3930-db95-4105-9108-e68af7c3d744.png"/>
</p>

## Tool 2 - copy :
* The tool will copy a file to another place and/or name.
* The tool will return “0” on success, or “1” on failure (return an INT).
* The tool will create a new file, if it does not exist, but it will not overwrite a file if it do exist.
* The tool will support -v flag, that will output “success” if the file is copied, or “target file exist” if this is the case, or “general failure” on some other problem (in addition to the returned INT value).
* The tool will support -f flag (that means force), that allows to overwrite the target file.

### How to run ?
Exemple 1 : We create 1 text file, in our exemple : a.txt and then you write what you want inside.<br>
For our exemple we wrote in the a.txt the line "123a Hello".<br>
Then with the command below we copy the same text to b.txt. We can see in the result that it worked.<br>
<br>
Exemple 2 : We now create 2 text file, in this exemple : a.txt and c.txt.<br>
We write inside the a.txt "123a Hello" ans we write nothing in c.txt<br>
We can see that the command doesn' work because the target file exists so we need to add the "-f" flag.<br>
We can now see in the result that it worked.<br>
```
./copy <file1> <file2> [-v] [-f]
```
### Results :
<p align="center">
  <img align="center" width=60% src = "https://user-images.githubusercontent.com/55143087/235365176-a554d928-b652-4221-9ed7-9af022073686.jpeg"/>
</p>

# Part B - dynamic libraries :
We were requested to implement a coding library. We had two codding methods.<br>
* Method a, named codecA: covert all lower case chars to upper case, and all upper case to lower case.<br>
All other chars will remain unchanged.
* Method b, named codecB: convert all chars to the 3-rd next char (adding a number of 3 to the ascii val).<br>
The libraries should support “encode” and “decode” methods.
Note: the libraries should be “reversable”, meaning that if one does “encode” and then “decode, he will
get the original string.<br>
<br>
We were also requested to :<br>
1) Write 2 different shared libraries , each implementing it’s algorithm<br>
2) Write a two tools, named encode and decode, to utilize the libraries. The tools will get some text and
convert it according to selected library.<br>

### How to run ?
You need to choose if you want to encode or decode a message and then choose if you want from CodecA or CodecB.

```
./encode/decode <codecA/B> <message>
```
### Results :
<p align="center">
  <img align="center" width=60% src = "https://user-images.githubusercontent.com/55143087/235365621-5ec61101-8bea-40b1-8ba5-d33f06bfff05.jpeg"/>
</p>

# Part C - basic shell :
We were requested to write a shell program named stshell (st for students).<br>
The features were:<br>
1) Be able to run CMD tools that exist on system (by fork + exec + wait).<br>
2) Be able to stop running tool by pressing Ctrl+c, but not killing the shell itself (by signal handler).<br>
3) Be able to redirect output with “>” and “>>”, and allow piping with “|”, at least for 2 following pipes.<br> 
For example command like this should be supported “ls -l | grep aaa | wc” <br>
4) be able to stop itself by “exit” command

## Basic commands Exemple :
As we can see in the picture below, the commands that we wrote in our stshell terminal worked :
<br>
<p align="center">
  <img align="center" width=60% src = "https://user-images.githubusercontent.com/55143087/235366603-3b42e93b-f986-40f0-85e6-bdf037f92d61.jpeg"/>
</p>

## Redirect Exemple :
Here we wanted to show how work the ">" and ">>".<br>
">" write the command in the same file but by deleting what was before<br>
">>" append to an existant file after the last line)<br>
<br>
You can see that with the cat command on a.txt (show all the file), the text was empty and then we add the path (pwd) inside with ">" and it worked.<br>
Then we tryed to add to the a.txt the sentence "Hello World" with the echo command and ">>" and it worked.<br>
And then we tryed to delete and add the new word "Heyyyyyyyyyyyyyyyyy" in a.txt and it worked with the help of ">".<br>
<br>
<p align="center">
  <img align="center" width=60% src = "https://user-images.githubusercontent.com/55143087/235366630-24e83442-bc5f-45d1-b5ba-c634964ea7a2.jpeg"/>
</p>

## Pipe Exemple :
