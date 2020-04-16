# Deliverable Overview

In the last deliverable you needed to develop a working prototype demonstrating at lest two features that you 
specified in your project 1 deliverable. In this last deliveralbe you need to provide the final version of your project. 

# Deliverable Requirements:

* A well demonstarted video going over your project (20%)
* Fully implemented advanced features (30%)
* Demonstarted use of classes, access specifiers (private vs public), use of const, data structures, 
inheritance, (polymorphism or templates optional)  (20%)
* Your project is tested and commented, has no memory leaks (20%)

# Bouns:
* Use of templates and generic algorithms, smart pointers, (15% - 5% each).
* Use of an extra advanced feature ( 15% )

# Answer the following questions (10%):

* What dificulties did you face in deliverable 4? 

*One of the main difficulties we faced in deliverable 4 was trying to get everything to tie in together and to get the whole big picture working. Additionally, it was tough
to figure out what we should test, and testing for memory leaks> eventually, we got everything work. A few bugs come from SFML in that it loads and render Sprites a little slow.*

 *  What did you learn from the process, how you could improve on this and avoid similar mistaktes in the feature?
 
 *Probably to go into the project with a more defined and structured concept of how the project will work. I ended up making classes that I didn't know I needed which maybe could've been avoided by planning out the different classes and project structure a little better.*

* Have you documented your code? 

 *If on Mac, download Homebrew in home directory. In home:*
 
 $ -- brew install sfml (to install the library dependencies)
 
 git clone https://github.ccs.neu.edu/ryanl35/cs3520_final_project.git

 cd Project4_Deliverable/
 
 run make

 run executable with: *./sfml-app*

* How did you test all major functionality of the project?

 *The major functionality of our project was through the classes we made. So we tested that the functions worked the way they were supposed to. There was no real way to test the functionality of SFML, we had to just assume that it worked.*
 
 * Does your project have any memory leaks? How did you test for memory leaks?

  *I tried looking all over the place for a valgrind like software for MacOSX Catalina 10.15, but it was very tough to understand. I tried to get some experimental version of valgrind working that would work with MacOS, but it didn't recgonize the Image Rendering software that I was running with it. So instead, I made sure that whenever I allocated "new" memory, I always went to go delete it at the end.*
  
 * Tell us where we can find use of a data structures and inheritance in your project.
 
  *Data structures can be found in the usage of Deques, for representation the list of platforms and monsters and bullets in the game. Polymorphism and inhertiance can be founud at the top of main.cpp with the Object class, and all the different Object instances that inherit from that class.*
  
 * Tells us if you've implmented any of the bonus features, where we can find them, and what they are.
 
  *Not that I know of*
  
* Provide the URL to your demo or indicate where it is pushed in the repo
 
 *https://www.youtube.com/watch?v=ocUUUMlBlRo&feature=youtu.be*
 
* How many hours have did you spend on the proejct?

 *A lot....probably over 75 hours*

# Logistics

The demo video is to be delivered by Tuesday 04/14 at 8am. Normally we would have in class presentations but we will use the last class time to watch the videos provided by all teams. You can keep working on your project till Wednesday 04/15 at midnight. Let us know if you have any questions.

# Rubric
* 50% of final project.
* Will be graded how detailed and thoughtfull your responses are. Unthoughtfull answers will not recieve many points. 
