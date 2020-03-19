# Deliverable Overview

As mentioned last class, you need to develop a working example demonstratring the library/s you picked in action. 
If you have few choices in mind then build a working example for each one of them to get familiar with how they work,
and to know how to build and link them.

# Deliverable Requirements:

* Must show the library in action by building a running executable. You must implement few library features that you 
are planning on using.
* The code must be commented, explaining what you are trying to achive with each feature you are demostrating.
(Think of this as writing a mini tutorial that demonstrates how to use the features you are going to use).
* Provide build instructions.
* Provide the library code if appropriate.
* Record a short video and either post it on youtube or push it in this folder demonstrarting the library in action.

# Answer the following questions:

Provide answers to each of the following:

* What library features is your demo showing.

*Several of the features that our demo is showing is the MouseMove feature, which is pivotal to our game. This feature allows us access to the real state of the Mouse of the user's computer, and allows us to use the positioning of the Mouse to have a character's position align with it, etc. Some other features that we are using here is keyboard, which gives us access to the real state of the keyboard, for when a key is pressed, etc. Some other features we are implementing in our demo are the play music feature, which will play music (AND sounds) for when the user is playing the game, and the rendering feature, which is the most important in rendering graphics for the user to see.*

 * How will these features be used as part of your final project.
 
 *We will use the MouseMove feature so the user can move the Doodle character across the window, to avoid monsters and jump on certain platforms. We will be using the keyboard feature for shooting pellets at monsters listening for when the user presses the Spacebar. We will be playing music for the duration of the game and stop the music when the user falls out of the screen / window. There will be sounds that play every time a user lands on a platform, similar to how Doodle Jump currently works. Finally, we will render graphics that are exactly or very similar to the graphics of Doodle Jump currently.*

* How are you building and linking the library.

 *The library SFML can be installed into a directory on your computer or using a package manager, and, once installed, can be compiled using g++ linking ur .cpp file to the library. There are several libraries that you need to connect your file to with SFML that include graphcs, window, system, etc. so that the file knows what SFML features are. Also, you must include several header files at the top of your main file to make sure that you correct link your main file to the key library dependencies of SFML.*

* Did you have any difficulties in builidng and linking the library that were hard to resolve

 *Some difficuluties at first when it came to how the SFML was structured and how to include their header files in our main file, but nothing too hard that we couldn't solve.*

* Were you able to find enough documentation for your library about how to use it? How about how to built it.

 *There is very clear documentation available on the SFML website. There are several beginner tutorials on how to get some basic features of SFML working, and additionally advanced features that are split up based on different functionalities such as Keyboard, Audio (Sound / Music specifically), Mouse, Graphics, etc. that make it very easy to find what you are looking for. There is also pretty easy instructions on how to get SFML to download and link to your file. They walk through several different methods on how to download dependencies, etc.*
 
* What was the hardest part of the whole process?

 *The hardest part of the process was probably attempting to learn a new library and trying to understand how to get SFML installed on our computeres. Although rather simple, it's always hard trying to learn a new library and the specific syntax of what to write and how to get the exact functionality you're looking for, similar to Big Band from Fundies and Fundies 2.*

* What are you next steps going to be in developing your project.

 *The next steps to developing our project will be to start importing more Doodle Jump specific functionalities, and to adapt the demo to be more tailored to the game we are trying to make. We will also be trying to understand more of SFML and that will make it easier for us down in the long run. Also, learning and mastering the syntax of SFML*

* What difficulties do you foresee in your design/library use? 

 *A main difficulty in the future will most likely be trying to implement the gravity feature of Doodle Jump. In Doodle Jump, gravity constantly plays a factor, so you are constantly able to fall to your death. This will be a hard feature, because right now in our demo the character remains static unless acted upon by the user. So we will have to find a way to make the user "constantly moving" downwards, to simulate the feel of gravity*

* Provide the URL to your demo or indicate where it is pushed in the repo
 
 *The demo is a video (.mov) file within the Project2 repo*
 
* What are the build instructions.

 *At first , you must download SFML. You can do that from their website, and download it for Visual Studio if you are using Windows or you can download the MacOS version for XCode. We used the package manager Homebrew to install SFML. If you are using Homebrew, all you need to do is run:*

-$ brew install sfml

in the command line. 

More instructions are available on their website: https://www.sfml-dev.org/download/sfml/2.5.1/ and https://www.sfml-dev.org/tutorials/2.5/ (under the "Getting Started" section, click the part that applies to you)

I have also made the MacOS Library Code available in the repo.

*Once that has been done, clone our repo, open a terminal at the folder, and run "make", which will create an executable "sfml-app".
Run this executable by using "./sfml-app".*
 
* Did you upload all of your code? 

 *Yes, everything is mainly in main.cpp.*


# Rubric
* 15% of final project.
* Will be graded how detailed and thoughtfull your responses are. Unthoughtfull answers will not recieve many points. 
