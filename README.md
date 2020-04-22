# MYFIRSTREPO

This is a repository I am using for my university first year project. This project is related to OpenGL, using freeglut library.
The project has three parts, and for each part there is a goal to reach. I will push the code for these three parts, as I complete them.

As I mentioned, in this project I will use OpenGL and freeglut library to simulate projectiles.


                                                        PROJECT:
                                      BALLISTIC IMPACT WITH GRAPHICAL SIMULATION


Given formulas:
1. Horizontal distance x = Vx * t;
2. Vertical distance y = Vyo * t - 1/2 * g * t;
3. Maximum height reached H = (Vo^2 * sin(θ)^2)/2 * g;
4. Horizontal range R = Vo^2 * sin(2 * θ)/g;
5. Time of flight T = 2 * Vo * sin(θ)/g;
                              
Here, 
- Vx is the velocity along x-axis;
- Vxo is the initial velocity along x-axis;
- Vy is the velocity along y-axis;
- Vyo is the initial velocity along y-axis;
- g is acceleration due to gravity;
- t is the time;

                                                     FIRST PART

GOALS:       -- We need to draw first projectile, using the given functions, and 2D OpenGL graphical library;
                    -- The second projectile should fire up at the same time as the first one, and collide at one point. 
                        When two projectiles have met at the "impact position", both projectiles should stop.

                                                     SECOND PART

GOALS:       -- We need to have first projectile(enemy), and three other projectiles that will fire from the other (right)
                        side of the screen;
                    -- The second projectile should collide with the first one at the rise (of the enemy projectile); 
                    -- The third projectile should collide with the first one on the top (of the enemy projectile); 
                    -- And finally, the fourth projectile should collide with the first one on the fall (of the enemy projectile),
                        and all projcetiles should stop; 

                                                     THIRD PART

GOALS:       -- The same goal as for the second part, except at this time I need to perform all calculations in 3D;


-------------------------------------------------------<end>----------------------------------------------------------------
