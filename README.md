# Rocket-launcher-Simulator-
This project is a Rocket Simulation developed using OpenGL (GLUT) in C++. It demonstrates fundamental computer graphics techniques such as object transformations, event handling, keyboard input, animation, and background rendering.
Project Report: Rocket Simulation in OpenGL
Introduction
This project is a Rocket Simulation developed using OpenGL (GLUT) in C++. It demonstrates fundamental computer graphics techniques such as object transformations, event handling, keyboard input, animation, and background rendering.
The project simulates the launch of a rocket, tank detachment during flight, and interactive user control. To make the simulation engaging, additional elements like a UFO and background sound effects have been included. This project not only strengthens understanding of graphics programming but also provides a fun, interactive demonstration of how real-time graphics applications are designed.
Instructions
This simulation provides real-time interaction between the user and the rocket model using keyboard inputs. It integrates sound effects (launch.wav, a.wav) and animations (rocket movement, tank detachment, UFO, and background movement).
How to Run the Project
Open the project in an IDE (e.g., Code::Blocks, Visual Studio, Dev-C++) with OpenGL and GLUT configured.
Compile and run main.cpp.
A window will appear showing the rocket on the launch pad, with the UFO and scenery in the background.
Control the rocket and simulation using the following keys:
Keyboard Controls
UP  Arrow Key → Launch Rocket
Rocket moves upward.
Tank moves up together (attached).
Launch sound (launch.wav) plays.
Down Arrow Key → Land Rocket
Rocket descends back to the launch pad.
Tank descends with it if still attached.
Background also scrolls down to simulate landing.
D / d Key → Detach Tank
The fuel tank detaches and falls toward the ground.
Background shifts to simulate separation.
Detach sound (a.wav) plays in loop.
UFO Interaction
The UFO is rendered in the simulation as part of the background scene.
It moves across the sky, enhancing the visual appeal of the simulation.
UFO logic is handled by separate functions in the code to animate its position.
General Usage for a New User
Run the program → Watch rocket on the launch pad.
Press up arrow key  → Rocket launches with sound.
Press D key→ Tank detaches mid-flight with sound.
Press down arrow key  → Rocket returns to ground.
UFO and background animate automatically.

Description
The Rocket Simulation project demonstrates interactive animation and graphical rendering using OpenGL and GLUT. The implementation is organized into modular functions that separately handle the rocket, fuel tank, UFO, and background elements, making the program easier to follow and extend.
Keyboard interaction forms the basis of the simulation. The special key function controls vertical rocket movement: the ↑ arrow key launches the rocket upward, while the ↓ arrow key returns it to the ground. A normal key function provides additional control, such as detaching the fuel tank with the ‘D’ key. After detachment, the tank follows its own downward animation path, independent from the rocket, thereby adding realism to the sequence.
Sound integration enhances the visual experience. A launch sound effect plays when the rocket ascends, and a looping sound is triggered during tank detachment, both implemented using the PlaySound() function from the Windows API. These auditory elements complement the graphical output and create a more immersive simulation.
Beyond the rocket itself, the project includes a UFO animation as part of the scene. The UFO moves autonomously across the background, serving as an additional animated object that showcases the ability of OpenGL to handle simultaneous movements within a single environment. The background also adapts dynamically to the rocket’s movement, giving the impression of depth and continuous motion.
Screenshots of the simulation, including the rocket on the launch pad, in flight, during tank detachment, and with the UFO in view, illustrate the program’s operation. The complete source code is maintained separately and can be provided to the faculty or instructor for further evaluation.
Screenshots
 

 



Source Code
The file is ready and running perfectly. We will share the file with our faculty. 
Conclusion
This project successfully simulates a rocket launch sequence with interactive features using OpenGL in C++. It demonstrates how transformations, animations, and keyboard input handling can create a dynamic and engaging graphics program.
The addition of sound effects and a UFO animation makes the simulation more immersive. This project highlights the power of computer graphics in building simulations, games, and real-time visualizations.
