# Chord Creator

A command line program that uses user input and minimal music theory knowledge to allow anyone to create and modify chords.

Shashvat Gupta (sgupt051@ucr.edu)


This project will work in the terminal. Usually chord creation would need some basic music theory 
knowledge of what are the "right" notes to place in a chord, but the Chord Creator makes creating 
scientifically proven "good" notes very simple!

This project uses C++, with the inputs and outputs all being on the terminal command line.



The three implemented patterns are: Factory, Decorator, and Visitor. The chord class is the the base of all chords created. First in the code, the main uses the Factory pattern to create a new base chord (either major or minor). The user then has the options to either use the Decorator pattern to change the type of chord (6 chord or 7 chord) or use the Visitor pattern to move or remove notes from whichever chord they are viewing.

By the way the code was implemented, it is easy to create new base chords (Diminished, Pentatonic), new types of chords (4-2 chord, 2 Chords), and additional functions to be used on the chords (Enharmonic equalizer for keys, shifting certain notes for different types of chords).

![Chord Creator](https://user-images.githubusercontent.com/45471982/84136672-7a7dad00-aa00-11ea-9043-f8359d40741a.png)
