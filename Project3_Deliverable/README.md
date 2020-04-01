# Deliverable Overview

In the last deliverable you needed to develop a working example demonstratring the library/s you picked in action. 
In this deliverable you need to demonstrate a working prototype of your project. 

# Deliverable Requirements:

* Must show the project in action by building a running executable prototype. You must demonstrate at least one to two features
/requirements that you specified in your project 1 deliverable in action. 
* You need to provide a PDF UML design document. The design document needs to include a UML class diagram showing the structure 
of your project. 
* Provde a one-two paragraph description of you design that goes over your UML design document and explains your design 
decisions. 
* Provide a test plan for you project. Explain how you plan on testing your project and provide at least one two tests. 
* Record a short video and either post it on youtube or push it in this folder demonstrarting the prototype in action.

# Answer the following questions:

Provide answers to each of the following:

* The UML Diagram & Project Structure

*Our previous UML Diagram was a rough outline of what we expected the project to look like in terms of structure and class design. After working a little bit more with SFML and the different APIs and classes within them, turns out a lot of what we need is already provided for us. What I mean by this is that the Sprite class turned out to be extremely useful when it came to rendering & positioning our player on the screen, and adding several of the key aspects of our game. There are a lot of methods that the Sprite class provies such as getPosition() and setPosition() (as well as move()) that don't require us to make our own class for the players or NPCs such as the Monsters. This has been coming in handy because the only class we really had to build on our own was the Platform class, because I needed to access the specific X and Y coordinates individually, which you couldn't do with the Sprite class. This is the reason that our UML diagram is a bit different than the previous one. It includes the Platform class and its methods, and it includes the Characters class, which I originally intended to be a designed class but eventually realized can just be represented through the provided Sprite class.*

*Another thing I'd like to add is that I used a Deque to create the Platforms on the screen. I used a for loop to create a specified number of platforms. I did this by first creating a new Platform object, randomizing its position on the screen, and then subsequently pushing that Platform onto the Deque. Later, I rendered each Platform into a Green Platform Sprite to represent it as a 2D object in our game.*

* What dificulties did you face in deliverable 3? 

*One of the main difficulties with the third deliverable is trying to implement gravity. Another difficulty was determining how to restructure the project, since SFML became very useful in providing many of the classes and APIs we needed to us already. Another difficult we faced was trying to figure out collisions between the main character and the Platform objects. This is a problem that I still need to figure out going forward.*

 *  What did you learn from the process, how you could improve on this and avoid similar mistaktes in the feature?
 
 *Some things I learned in the process was basically how to use Big Bang in C++, which is very useful for interactive programs and designing and rendering images and objects into a program through back-end code. I highly value the connection between raw back-end code and how it is ever going to be useful or presented to a client or user. One major difficulty and issue I ran into was kind of skimming over the SFML documentation, which only ended up hurting me in the end because I didn't realize all of the features I had available to me.*

* If you have experience in another laguage, how do you find the process of building a larger project in C++?

 *It is somewhat similar. Working with our SFML reminds me a lot of working with Big Bang from Fundies 2 and Java. I enjoy building bigger projects no matter what language it is, and designing a game is even more fun on top of that. Especially a game that I used to play a lot when I was younger.*

* Have you written any documentation yet? 

 *A lot of my documentation you can find in the comments above the different parts. I wrote a bit on the last project deliverable too. I'm planning to write a little more in the future however about the different classes within our project, etc. when we're all done.*

* How do you plan to test your project and what difficulties do you see?

 *Most likely writing a few tests before the main function so that we can test some of the smaller details of the main functionalities like moving a character. For example, does the x value change when moving the character, etc., test to find our. Most of the testing can be done by just running the executable, however, and to test the user-facing side of the game. That's how I've mostly been testing my code so far (to see if the game behaves the way I expect it to.*
 
* Have you tested your code for any memory leaks?

 *I haven't really had time to yet, I spent most of the time trying to get the features up and working. Now that we've added our own Platform class and have created instances, once the game is over we should handle memory leaks by making sure we delete those isntances.*

* Provide the URL to your demo or indicate where it is pushed in the repo
 
 *The demo is a video file in the media folder of the repo titled "demo video.mov".*
 
* How many hours have you spend on your project so far and do you enjoy programming in C++? 

 *Probably over 40 hours and C++ is okay. I'm not really good at C++, so that's why I like Java better. Otherwise, a lot of the concepts are the same and it's not too hard to pick up (other than pointers).*

* Have you bought enough hand soap and toilet paper? 

 *I hope so*

# Rubric
* 20% of final project.
* Will be graded how detailed and thoughtfull your responses are. Unthoughtfull answers will not recieve many points. 
