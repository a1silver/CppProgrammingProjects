Zuul

Create a text-based adventure game using the example as a start.  All information will be text, and all commands must be typed in.  Rooms will typically have a description, and possibly items.  For example, you might have:

You are currently in the 1-20 lab at Sunset.  All the cool people are hanging out here.

There are exits:

WEST

There are no items in the room.

Then, if you type in WEST:

You are in one hall.  You see a computer lab to the east.  Wait; are they playing with robots in there?

There are exits:

NORTH SOUTH EAST

There is a MOP here.

 

Create a class for the room.  Create either a class or a struct for items.  Use a map (which is like a HashMap from Java) for the exits.

There must be at least 15 rooms (instances of the Room class), each of which tells you the exits.  (Room must be separate class and header files.) I recommend using a vector of Room pointers.  (15 points)

There must be 5 items.  The rooms should tell you what items are in the room.  (15 points)

Items must be able to be picked up and put in a player inventory (10 points) and dropped into a room. (10 points)  The rooms should keep track of dropped items.

The game must have a winning condition and a way to quit.  (10 points)

Comments. Seriously. (10 points) Also, make sure you either include a map or a walkthrough of how to win the game so my TAs don't tear out their hair.

Total:  70 points