**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
New Process Created - the process is created and is waiting to proceed
Ready/Idling- the process is ready and waiting to be executed
Running - the process is running and/or is ready to run
Blocked - reading from or writing to a file descriptor
Stopped - execution paused by SIGSTOP (can continue after SIGCONT)
Terminated - process was killed by kill command
Zombie - the process is a child that has finished running and waiting for parent to read its exit status


**2. What is a zombie process?**
When the child has finished running, a SIGCHLD is sent to the parent so that the parent can read the child's exit code. If the parent hasn't finished reading the child's exit status via the wait command, the child process will remain in the zombie status.


**3. How does a zombie process get created? How does one get destroyed?**
When child is done running and the parent has not received the child's exit signal (SIGCHLD) yet. Calling wait in the parent will remove the child zombie by reading its status.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
The benefits of working in a compiled language are that interpretation step and running steps are separate and because of that program launches faster. The process of compilation of the code when it's being written allows better debugging and error catching ahead of time no matter where they are in the written code, you don't need to run specific part of code to know if something was use incorrectly (function or feature) the whole program is being compiled. And the compiler can take more time to optimize the code we wrote into the target hardware.

