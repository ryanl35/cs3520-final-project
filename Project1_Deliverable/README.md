# Project Overview

Projects will be interactive programs developed in C++. They can be a game, finance engines, translators, face recognition programs,  audio interpreters etc ( these are all projects that students have done in the past). 

For the project, you can use any platform and IDE you prefer (Visual Studio, Xcode, etc.). Code can be written using C++98 or C++11 standards. 

The project code must be hosted on the CCIS GitHub in the account of one of the group members.
You must also provide build instructions. This is helpful not only for the us, but also for potential employers.

# Project Requirements:

* Written in C++.
* Interactive, and take frequent user input that updates the state of the program.
* Dynamically allocate and free memory.
* Use classes, inheritance, templates and generic algorithms.
* Be unit tested.
* Be of reasonable size and complexity.
* Make use of at least one "advanced" feature that requires an additional API, library, or SDK, as described below.

# Advanced Features:

The advanced feature will require independently researching, understanding, and using some external API, library, or SDK. 
Each project must include at least one advanced feature. Example advanced features include:

* Specialized Keyboard or Mouse Input (OpenInput, ncurses)
* AI/Algorithms (OpenSteer, Boost Graph Library, libnoise)
* Audio (OpenAL)
* 2D or 3D graphics (Simple DirectMedia Layer, OpenGL, DirectX)
* Physics (Box2D, Open Dynamics Engine)
* Networking (sockets, libcurl)
* Embedded scripting (lua)
* Multithreading/multiprocessing (OpenCL, pthreads, Windows Threads)
* Presentation: In-class group presentation of projects towards the end of the semester.

# Teams

The project is supposed to be done in teams of two students. If you prefer to work alone that is fine too. 

# TODO

Provide answers to each of the following:

* List the team.

*Ryan Liang and Maris McGuinness*

* In a brief paragraph describe what you plan your project to be about.

*Our project will be a C++ implementation of the game Doodle Jump, which is a mobile application that came out in 2009. The idea of the game is that you play as a cute little monster, jumping up from platform to platform to get as high as you can. Along the way, you encounter monsters and other sorts of obstacles, and the platforms become more spread out. Also the game gets faster and harder as you progress (maybe a more advanced feature). The goal of the game is to get as high as possible without missing a platform or colliding with a monster, which will cause you to lose the game. In general, the project will be a close recreation of the original Doodle Jump, with features adapted to be more sensible for a program written in C++.*

* List the target audience.

*The target audience is anyone who really just wants to play a game or for fans of the original Doodle Jump. Currently, Doodle Jump is only avaialble on mobile devices that run iOS or Android operating systems, however our C++ implementation will (hopefully) be a working game that can be run as a file in the command line that can be opened for anyone who has access to the file.*

* List several high level non functional requirements of your project ( i.e. you can list requirements about: 
Scalability, how scalable or extendable do you see this mini project being. Talk about possible future use or work 
that could be done. Maintainability, talk about how much you expect this to be maintained in the future, etc.

*The game will be not that scabable in terms of the fact that the game is endless, so you can't really add on to it or add on levels to it. Most of the future work will involve adding features like new monsters, new platforms, etc. The game will (hopefully) not have to be maintained too much once it's been developed. Obviously, once it's been finished any bugs will require fixing, but after that the game can withstand the test of time so it doesn't need to be maintained all that much. I played Doodle Jump back when it first came out, and not much has been updated or changed since it's initial release. The game will be made available as a .cpp file that can be run (hopefully) in the command line. I'm not all too sure how the libraries we are using will require and how to run files that use those dependencies, but the idea is to make a git repository that contains the necessary files to run the game including the main executable file, and then to eventually be able to run it. The game will be made available to anyone who has access to the repository. In terms of performance, the game should run smooth and flawless in terms of 2D scrolling up and down, and there should be no lag time as that will interfere with the gameplay.*

* List several functional requirements (i.e. what tasks your project must do ).

*Some key functionalities of our game must be that it features endless 2D scrolling, so the player can continuously jump from platform to platform until they lose. Another functionality of our game must be that it renders the player as well as monsters randomly at intervals on a window at all times while the game is scrolling. The user must be able to use the mouse and/or the arrow keys to control the player to move back and forth across the screen to land on the platforms. The score must increment as the player reaches higher and higher as well. There will be a scoreboard with all of the scores of the player who is playing on that device. I'm not entirely sure how save files work with C++ and the libraries that we will be using, but hopefully save files will be stored in the computer so that if you launch the game again on the same computer, save files / scores will be available from old sessions. There will also be a shooting feature of the main character, using (most likely) the spacebar, and when the pellets hit the monster, then the monster must disappear from the game / window*

* List several use case scenarios of your project.

*After running the .cpp file provided in the command line to open the game, the user may perform the following use cases:*
*	1. Start the game*
*	2. Jump up*
*	3. Move across screen (left/right)*
*	4. Shoot*
*	5. Save the game*
*	6. Exit the game*

*Our use cases are quite simple as the complexity of the game is encompassed mainly in the infinite scrolling and 2D graphic aspects. Immediately after opening the game, a user is able to either start the game or exit the game. Once the game has started, a user can 'jump' to the next platform, 'move' left or right across the screen, and/or 'shoot' at monsters. While the game is ongoing, a user may also save and exit the game or exit the game without saving.*

* Provide a UML class diagram of possible design of your project. This doesn't have to be too detailed, you can update 
the UML diagrams as in a later deliverable. 

<img align="center" width="500px" src="./media/C++ Project UML Diagram.png" alt="UML diagram">

* Advance feature capability

List few libraries as choices that you might be using. Provide links to documentation and examples of how these libraries 
are used. Talk about how you might use it in your project.

*In general, the most useful libraries for our game will be the libraries that give us access to the different components of our computer, such as keyboard and mouse handlers (such as Java). One main library that we would most likely be using is the SFML, or the Simple and Fast Multimedia Library. This library will be able to help us build many aspects of our game, including rendering a window, the drawings on it, adding sounds, adding a score keeper, and much more.  Another library we could use potentially is the SDL, or Simple DirectMedia Library, which provides low level access to similar aspects to SFML such as mouse, keyboard, and graphics hardware.*

The documentation for the SFML library can be found here: https://www.sfml-dev.org/documentation/2.5.1/annotated.php
The documentation for the SDL library can be found here: http://wiki.libsdl.org/CategoryAPI

*These libraries can be used to render our main character's player, the monsters, and can also listen to the player's input in the form of key press and/or mouse movements. Sounds can be generated like the original game for when the player attempts to shoot the monsters and when the user jumps on a platform or a spring*

Example of the SFML being used (Fig. 1): 
<img align="center" width="300px" src="./media/SFML being used 1.jpg" alt="SFML 1">


Example of the SFML being used (Fig. 2): 
<img align="center" width="300px" src="./media/SFML being used 2.png" alt="SFML 2">


# Rubric
* 15% of final project.
* Will be graded how detailed and thoughtfull your responses are. One sentance answers will not recieve many points. 
