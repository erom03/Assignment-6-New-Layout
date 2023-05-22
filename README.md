# Assignment-6-New-Layout

## Objective

Give practice with stacks input in C.
Give practice with trees in C.

## Story

Well the ship is fixed (sort of). The repair crew just left, but
they did something awful. The ship has a completely different
interior. Hallways have become blocked off and some walls
were removed. You have been in communication with the
repair crew. They apparently had to make the ship up to code
or something. You are exhausted and want this ship to set sail
as soon as possible. Now you are left with the daunting task
of determining how many rooms your new ship’s layout can
support.

The new layout can be thought of as a series of rooms
connected by corridors. Each corridor connects 2 rooms; no
room is connected to itself via a corridor. There is exactly 1
series of distinct corridors that connects any pair of rooms.

You are going to assume that no one should walk through
someone's quarters to reach another room. Because of this
you will assume that (with the exception of the ship's entrance)
each possible room will be connected to exactly 1 corridor.

You don’t have time to walk through the ship yourself, so you hired an employee to walk through
each of the rooms. He came up with a unique room ID for each room they visited. Rather than
telling you all the corridors that connect the rooms, your employee walked through all the
corridors (each one exactly twice), and they kept a list of the rooms they visited by the IDs in the
order in which they visited the room. Additionally each room ID was noted each time they
entered the room. This means a room ID can appear multiple times.

You are also worried that the rooms might be very far from the main entrance, so you will also
track total distance (in terms of number of corridors) from all possible quarters to the main
entrance.

## Input

Input will consist of a series of integers each one on their own line. The series ends with the
integer -1. No earlier integer in the series will be -1. The integer series represents the room IDs
visited in the traversal that the employee executed. The employee started in the main entrance.
It is guaranteed that the main entrance will be the last room ID before the -1. There will always
be at least one ID that is not -1 in the input.

## Output

Output should contain a single line containing 2 integers. The first integer represents the
number of possible quarters the second integer represents the total distance (in terms of
corridors) from each room to the main entrance.
