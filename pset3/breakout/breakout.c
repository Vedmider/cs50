//
// breakout.c
//
// Computer Science 50
// Problem Set 3
//

// standard libraries
#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Stanford Portable Library
#include <spl/gevents.h>
#include <spl/gobjects.h>
#include <spl/gwindow.h>

// height and width of game's window in pixels
#define HEIGHT 600
#define WIDTH 400

// number of rows of bricks
#define ROWS 5

// number of columns of bricks
#define COLS 10

// radius of ball in pixels
#define RADIUS 10

//paddle width
#define paddleWidth 40

//paddle height 
#define paddleHeight 10 
// lives
#define LIVES 3

// prototypes
void initBricks(GWindow window);
GOval initBall(GWindow window);
GRect initPaddle(GWindow window);
GLabel initScoreboard(GWindow window);
void updateScoreboard(GWindow window, GLabel label, int points);
GObject detectCollision(GWindow window, GOval ball);

int main(void)
{
    // seed pseudorandom number generator
    srand48(time(NULL));

    // instantiate window
    GWindow window = newGWindow(WIDTH, HEIGHT);
    //HOW TO FILL window with color??
    setFilled(window, true);
    setColor(window, "BLUE");

    // instantiate bricks
    initBricks(window);

    // instantiate ball, centered in middle of window
    GOval ball = initBall(window);
    double xVelosity = drand48()*3;
    double yVelosity = 2.0;

    // instantiate paddle, centered at bottom of window
    GRect paddle = initPaddle(window);

    // instantiate scoreboard, centered in middle of window, just above ball
    GLabel label = initScoreboard(window);

    // number of bricks initially
    int bricks = COLS * ROWS;

    // number of lives initially
    int lives = LIVES;

    // number of points initially
    int points = 0;
    
    waitForClick();
    
    // keep playing until game over
    while (lives > 0 && bricks > 0)
    {
        // TODO
        GEvent event1 = getNextEvent(MOUSE_EVENT);
        if(event1 != NULL)
        {
            
            if(getEventType(event1) == MOUSE_MOVED)
            {
                double x = getX(event1) - getWidth(paddle)/2;
                double y = 550;
                setLocation(paddle, x, y);
            }
              
        }
          
        //set move of the ball
        move(ball, xVelosity, yVelosity);
        if(getX(ball) + getWidth(ball) >= getWidth(window))
        {
            xVelosity = -xVelosity;
        }
        
        if(getX(ball) <= 0)
        {
            xVelosity = -xVelosity;
        }
        
        if(getY(ball) <= 0)
        {
            yVelosity = -yVelosity;
        }
        
        if(getY(ball) >= 590)
        {
            
            lives--;
            setLocation(ball, 195, 295);
            setLocation(paddle, (WIDTH-paddleWidth/2)/2, 550);
            xVelosity = drand48()*3;
            yVelosity = 2.0;
            waitForClick();
            
        }
        
        GObject object = detectCollision(window, ball);
              
        
        if(object != NULL && strcmp(getType(object), "GRect") == 0)
        {
            yVelosity = -yVelosity;
            if(object != paddle)
            {
                removeGWindow(window, object);
                bricks--;
                points++;
                updateScoreboard(window, label, points);    
            }
           
            
        }
        pause(10);
        
        
    }

    // wait for click before exiting
    waitForClick();

    // game over
    closeGWindow(window);
    return 0;
}

/**
 * Initializes window with a grid of bricks.
 */
void initBricks(GWindow window)
{
    // TODO
    string Color[] = {"BLUE", "BLUE","YELLOW", "YELLOW", "BLACK"};
      
    for(int m = 0; m < 5; m++)
    {
                      
        for(int n = 0; n < 10; n++)
        {
              GRect rect = newGRect((38+2)*n, (10+2)*m +40, 38, 10);
              setFilled(rect, true);
              setColor(rect, Color[m]);
              add(window, rect);  
        }
    }
    
    
    
}

/**
 * Instantiates ball in center of window.  Returns ball.
 */
GOval initBall(GWindow window)
{
    // TODO
    GOval ball = newGOval(190, 295, 20, 20);
    setFilled(ball, true);
    setColor(ball, "GREEN");
    add(window, ball);
    return ball;
    
    return NULL;
}

/**
 * Instantiates paddle in bottom-middle of window.
 */
GRect initPaddle(GWindow window)
{
    // TODO
    GRect paddle = newGRect(WIDTH/2-paddleWidth/2, 550, paddleWidth, paddleHeight);
    setFilled(paddle, true);
    setColor(paddle, "BLACK");
    add(window, paddle);
    return paddle;
    
    return NULL;
}

/**
 * Instantiates, configures, and returns label for scoreboard.
 */
GLabel initScoreboard(GWindow window)
{
    // TODO
    GLabel label = newGLabel("0");
    setFont(label, "SansSerif-36");
    add(window, label);
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
    return label;
    
    
    return NULL;
}

/**
 * Updates scoreboard's label, keeping it centered in window.
 */
void updateScoreboard(GWindow window, GLabel label, int points)
{
    // update label
    char s[12];
    sprintf(s, "%i", points);
    setLabel(label, s);

    // center label in window
    double x = (getWidth(window) - getWidth(label)) / 2;
    double y = (getHeight(window) - getHeight(label)) / 2;
    setLocation(label, x, y);
}

/**
 * Detects whether ball has collided with some object in window
 * by checking the four corners of its bounding box (which are
 * outside the ball's GOval, and so the ball can't collide with
 * itself).  Returns object if so, else NULL.
 */
GObject detectCollision(GWindow window, GOval ball)
{
    // ball's location
    double x = getX(ball);
    double y = getY(ball);

    // for checking for collisions
    GObject object;

    // check for collision at ball's top-left corner
    object = getGObjectAt(window, x, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's top-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-left corner
    object = getGObjectAt(window, x, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // check for collision at ball's bottom-right corner
    object = getGObjectAt(window, x + 2 * RADIUS, y + 2 * RADIUS);
    if (object != NULL)
    {
        return object;
    }

    // no collision
    return NULL;
}
