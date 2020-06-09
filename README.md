
# Chord Creator

A command line program that uses user input and minimal music theory knowledge to allow anyone to create and modify chords.

Shashvat Gupta (sgupt051@ucr.edu)


This project will work in the terminal. Usually chord creation would need some basic music theory 
knowledge of what are the "right" notes to place in a chord, but the Chord Creator makes creating 
scientifically proven "good" notes very simple!

This project uses C++, with the inputs and outputs all being on the terminal command line.



The three implemented patterns are: Factory, Decorator, and Visitor. The chord class is the the base of all chords created. First in the code, the main uses the Factory pattern to create a new base chord (either major or minor). The user then has the options to either use the Decorator pattern to change the type of chord (6 chord or 7 chord) or use the Visitor pattern to move or remove notes from whichever chord they are viewing.


![Chord Creator](https://user-images.githubusercontent.com/45471982/84136672-7a7dad00-aa00-11ea-9043-f8359d40741a.png)


The Chord Creator was a project idea I have had for a while now. Music may seem like an abstract art to most, but there is a great deal of math and science behind the artistic note heads. In the western scale there are 12 unique notes that are strung in a pattern. To represent this in my code I used integer values as my note. C is 0, C# is 1, D is 2 etc. A challenge I faced with using this method is the fact that there are enharmonic equivalents in music, meaning that C# is the same frequency as Db, but they are written differently. The way I combatted this internally was by creating a 2-dimensional array with the indexes of columns marking the 12 notes and the rows marking enharmonics of each. I used a convert to note function and convert to number function to use and display these notes.
The main base of my program is the chord class. I started off the main program by creating a chord of the 4 same notes based on what key was given. This base chord will then be passed on to a Major or Minor Factory depending on the user. A chord pointer is used to keep track of the current chord of interest and a previous is used to keep track of the previous. Once in the main loop of the main, the user has many choices they can make to modify the chord. They are able to change the type of chord by using a Decorator pattern, The Decorator pattern works by wrapping a valid chord in an individual decorator and modifying the chord to become of a new type. It can become a 6 or 7 chord, which both retain the same properties as in Major or Minor, but have their notes positioned in a way that creates a unique sound. The user can also choose from an array of functions that can move or remove the notes of the chord by using the Visitor Pattern. This pattern allows for any type of chord (so far only Major and Minor) to be worked upon. The main functions that have been implemented so far are removing the root, 3rd, 5th, or octave (7th in 7-chords) or dropping the root/raising the soprano by an octave. The visitor pattern here is beneficial as it allows chords that are not all of the same type to be worked on by functions without having to declare them in the main chord class.
By the way the code was implemented, it is easy to create new base chords (Diminished, Pentatonic), new types of chords (4-2 chord, 2 Chords), and additional functions to be used on the chords (Enharmonic equalizer for keys, shifting certain notes for different types of chords). These patterns allow for anyone to easily pick-up the project and further enhance it to allow for more and more musical embellishments to these notes and chords.


<img width="232" alt="Screen Shot 2020-06-09 at 11 57 09 AM" src="https://user-images.githubusercontent.com/45471982/84188893-2d71f900-aa49-11ea-81b9-8827c57da724.png">
