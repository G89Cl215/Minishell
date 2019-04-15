# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 05:00:10 by tgouedar          #+#    #+#              #
#    Updated: 2019/03/27 21:13:55 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


--=-=--							ENV VARIABLES							--=-=--

The argument envp is a pointer to a null-terminated array of characterpointers
to null-terminated strings. A pointer to this array is normally stored in the
global variable environ. These strings pass information to the new process that
is not directly an argument to the command (see environ(7)).


--=-=--							PATH VARIABLE							--=-=--

A user's PATH consists of a series of colon-separated absolute paths that are
stored in plain text files. Whenever a user types in a command at the command
line that is not built into the shell or that does not include its absolute path
and then presses the Enter key, the shell searches through those directories,
which constitute the user's search path, until it finds an executable file with
that name.

The concentrating by default of most executable files in just a few directories
rather than spread all over the filesystem and the use of the PATH variable to
find them eliminates the need for users to remember which directories they are
in and to type their absolute path names. That is, any such program can be run
by merely typing its name, such as ls instead of /bin/ls and head instead of
/usr/bin/head, regardless of where the user is currently working on the
filesystem. This also greatly reduces the possibility of damage to data or even
to the system as a whole from the accidental running of a script that has the
same name as a standard command.


--=-=--							 CD COMMAND								--=-=--
  
#include <unistd.h>

int			chdir(const char *path);

	The path argument points to the pathname of a directory. The chdir()
function causes the named directory to become the current working directory,
that is, the starting point for path searches of pathnames not beginning with a
slash, `/'.

	The fchdir() function causes the directory referenced by fildes to become
the current working directory, the starting point for path searches of pathnames
not beginning with a slash, `/'.

	In order for a directory to become the current directory, a process must
have execute (search) access to the directory.

RETURN VALUES
	Upon successful completion, a value of 0 is returned. Otherwise, a value of
-1 is returned and errno is set to indicate the error.

ERRORS
	The chdir() system call will fail and the current working directory will be
unchanged if one or more of the following are true:

[EACCES]           Search permission is denied for any component of the path
					name.

[EFAULT]           Path points outside the process's allocated address space.

[EIO]              An I/O error occurred while reading from or writing to the
					file system.

[ELOOP]            Too many symbolic links were encountered in translating the
					pathname. This is taken to be indicative of a looping
					symbolic link.

[ENAMETOOLONG]     A component of a pathname exceeded {NAME_MAX} characters, or
					an entire path name exceeded {PATH_MAX} characters.

[ENOENT]           The named directory does not exist.

[ENOTDIR]          A component of the path prefix is not a directory.

--=-=--							ECHO COMMAND							--=-=--
--=-=--							   EXECVE								--=-=--
#include <unistd.h>

int		execve(const char *path, char *const argv[], char *const envp[]);

execve() transforms the calling process into a new process. The new process is
constructed from an ordinary file, whose name is pointed to by path, called the
new process file. This file is either an executable object file, or a file of
data for an interpreter. An executable object file consists of an identifying
header, followed by pages of data representing the initial program (text) and
initialized data pages. Additional pages may be specified by the header to be
initialized with zero data;  (see a.out(5))

An interpreter file begins with a line of the form:

#! interpreter [arg ...]

When an interpreter file is execve()'d, the system runs the specified
interpreter. If any optional args are specified, they become the next argument
to the interpreter. The name of the originally execve()'d file becomes the
subsequent argument; otherwise, the name of the originally execve()'d file is
the first argument. The original arguments to the invocation of the interpreter
are shifted over to become the final arguments. The zeroth argument, normally
the name of the execve()'d file, is left unchanged.

The argument argv is a pointer to a null-terminated array of character pointers
to null-terminated character strings. These strings construct the argument list
to be made available to the new process. At least one argument must be present
in the array; by custom, the first element should be the name of the executed
program (for example, the last component of path).

The argument envp is also a pointer to a null-terminated array of character
pointers to null-terminated strings. A pointer to this array is normally stored
in the global variable environ. These strings pass information to the new
process that is not directly an argument to the command (see environ(7)).

File descriptors open in the calling process image remain open in the new
process image, except for those for which the close-on-exec flag is set
(see close(2) and fcntl(2)). Descriptors that remain open are unaffected by
execve().

Signals set to be ignored in the calling process are set to be ignored in the
new process. Signals which are set to be caught in the calling process image are
set to default action in the new process image. Blocked signals remain blocked
regardless of changes to the signal action.  The signal stack is reset to be
undefined (see sigaction(2) for more information).

If the set-user-ID mode bit of the new process image file is set (see chmod(2)),
the effective user ID of the new process image is set to the owner ID of the new
process image file. If the set-group-ID mode bit of the new process image file
is set, the effective group ID of the new process image is set to the group ID
of the new process image file. (The effective group ID is the first element of
the group list.) The real user ID, real group ID and other group IDs of the new
process image remain the same as the calling process image. After any
set-user-ID and set-group-ID processing, the effective user ID is recorded as
the saved set-user-ID, and the effective group ID is recorded as the saved
set-group-ID. These values may be used in changing the effective IDs later.

The new process also inherits the following attributes from the calling process:

process ID           see getpid(2)
parent process ID    see getppid(2)
process group ID     see getpgrp(2)
access groups        see getgroups(2)
working directory    see chdir(2)
root directory       see chroot(2)
control terminal     see termios(4)
resource usages      see getrusage(2)
interval timers      see getitimer(2)
resource limits      see getrlimit(2)
file mode mask       see umask(2)
signal mask          see sigaction(2), sigsetmask(2)

When a program is executed as a result of an execve() call, it is entered as
follows:

main(argc, argv, envp)
int argc;
char **argv, **envp;

where argc is the number of elements in argv and argv points to the array of
character pointers to the arguments themselves.

RETURN VALUES
As the execve() function overlays the current process image with a new process
image, the successful call has no process to return to. If execve() does return
to the calling process, an error has occurred; the return value will be -1 and
the global variable errno is set to indicate the error.


--=-=--								FORK								--=-=--
#include <unistd.h>

pid_t		fork(void);

DESCRIPTION
fork() causes creation of a new process. The new process (child process) is an
exact copy of the calling process (parent process) except for the following:

o   The child process has a unique process ID (usually 0 while the parent
		process has a positive int for its nclude <sys/types.h>pid_t).
o   The child process has a different parent process ID (i.e., the process ID
		of the parent process).
o   The child process has its own copy of the parent's descriptors. These
descriptors reference the same underlying objects, so that, for instance, file
pointers in file objects are shared between the child and the parent, so that an
lseek(2) on a descriptor in the child process can affect a subsequent read or
write by the parent. This descriptor copying is also used by the shell to
establish standard input and output for newly created processes as well as to
set up pipes.
o   The child processes resource utilizations are set to 0; see setrlimit(2).

	Two outputs are possible because the parent process and child process are
running concurrently. So we don’t know which of the child or the parent process
is given control to first by the OS. In essence, the only way to start new
processes is by an existing one duplicating itself (except for Init which is the
father of all processes).

Important: Parent process and child process are running the same program, but
it does not mean they are identical. OS allocate different data and state for
these two processes and also control the flow of these processes can be
different : global variable change in one process does not affect the other
process because data/state of two processes are different.


RETURN VALUES
Upon successful completion, fork() returns a value of 0 to the child process and
returns the process ID of the child process to the parent process. Otherwise, a
value of -1 is returned to the parent process, no child process is created, and
the global variable errno is set to indicate the error.


--=-=--							WAIT COMMAND							--=-=--

# include <sys/wait.h>
#include <sys/types.h>

pid_t			wait(int *stat_loc);

	The wait() function suspends execution of its calling process until stat_loc
information is available for a terminated child process, or a signal is received.
On return from a successful wait() call, the stat_loc area contains termination
information about the process that exited as defined below.

	The pid parameter specifies the set of child processes for which to wait. 
If pid is -1, the call waits for any child process.
If pid is 0, the call waits for any child process in the process group of the caller.
If pid is greater than zero, the call waits for the process with process id pid.
If pid is less than -1, the call waits for any process whose process group id
equals the absolute value of pid.

	The stat_loc parameter is defined below. The options parameter contains the
bitwise OR of any of the following options. The WNOHANG option is used to
indicate that the call should not block if there are no processes that wish to
report status. If the WUNTRACED option is set, children of the current process
that are stopped due to a SIGTTIN, SIGTTOU, SIGTSTP, or SIGSTOP signal also have
their status reported.

	If rusage is non-zero, a summary of the resources used by the terminated
process and all its children is returned (this information is currently not
available for stopped processes).

	When the WNOHANG option is specified and no processes wish to report status,
wait4() returns a process id of 0.

	The waitpid() call is identical to wait4() with an rusage value of zero.The
older wait3() call is the same as wait4() with a pid value of -1.

	The following macros may be used to test the manner of exit of the process.
One of the first three macros will evaluate to a non-zero (true) value:

WIFEXITED(status)
	True if the process terminated normally by a call to _exit(2) or exit(3).

WIFSIGNALED(status)
	True if the process terminated due to receipt of a signal.

WIFSTOPPED(status)
	True if the process has not terminated, but has stopped and can be restarted.
This macro can be true only if the wait call specified the WUNTRACED option or
if the child process is being traced (see ptrace(2)).

	Depending on the values of those macros, the following macros produce the
remaining status information about the child process:

WEXITSTATUS(status)
	If WIFEXITED(status) is true, evaluates to the low-order 8 bits of the
argument passed to _exit(2) or exit(3) by the child.

WTERMSIG(status)
	If WIFSIGNALED(status) is true, evaluates to the number of the signal that
caused the termination of the process.

WCOREDUMP(status)
	If WIFSIGNALED(status) is true, evaluates as true if the termination of the
process was accompanied by the creation of a core file containing an image of
the process when the signal as received.

WSTOPSIG(status)
	If WIFSTOPPED(status) is true, evaluates to the number of the signal that
caused the process to stop.


RETURN VALUES
	If wait() returns due to a stopped or terminated child process, the process
ID of the child is returned to the calling process. Otherwise, a value of -1 is
returned and errno is set to indicate the error.
[ECHILD]	The calling process has no existing unwaited-for child processes.

[EFAULT]	The status or rusage argument points to an illegal address (may not
be detected before the exit of a child process).

[EINVAL]     Invalid or undefined flags are passed in the options argument.

