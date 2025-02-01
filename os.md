# Introduction

An operating system is a piece of software that manages all the resources of a computer
system,both hardware and software, and provides an environment in which the user can
execute his/her programs in a convenient and efficient manner by hiding underlying
complexity of the hardware and acting as a resource manager.

## Application Software

- performs specific task for the user.

## System Software

- System software operates and controls the computer system and provides a platform to run
  application software.

## Function Of OS

- Memory Management : Refers to management of primary and main memory
  - Keeps track of primary memory
  - In multiprogramming Os decide which process get memory and when and how
  - Allocation and Deallocation of memory
- Processor Management : In multiprogramming Os decide which process will gets the processor when and for how much time this is called as process scheduling
  - Keeps tracks of processor and status of process
  - Allocates and Deallocate the CPU to process
- Device Management: Os manages device communication via their respective drivers
  - Keeps tracks of all devices. The program responsible for this task know as I/O controller
  - Allocate and Deallocate the devices in efficient way
- File Management
  - Keeps track of information, location , uses, status etc. THis collective facilities are know and file system
  - Decide who gets the resources
  - Allocate and Deallocate the resources
- Security: prevent Unauthorize access to program and data
- Job Accounting : Keeps track of time and resource used by various jobs and users
- Error Detection and Aid : Production of dumps, traces and error message
- Access to the computer hardware.
- Hides the underlying complexity of the hardware. (Aka, Abstraction)
- Os is use for Resource Management
- Os acts as interface between User and Kernel
- Os is responsible for memory management
- OS also provide isolation and protection

## Type of OS

- Single Process OS
  - Runs process one by one
  - Example : MS-DOS
- Batch Processing OS
  - User provide punch card as input to computer and there and multiple users requesting to do multiple jobs
  - Jobs goes to operator which will sort the jobs into batch of similar types
  - Each Batch is executed in sequential manner
  - Lack of Priority Jobs execution
  - This reduces turn around time, since the job of similar need are executed at same time so no need to import same resource multiple time like required in serial processing
  - The operating system also called as resident monitor manages the execution of each program in batch
  - The Use of resident monitor is to read and carry out instruction on card, load the softwares required for execution of jobs
- Multiprogramming OS
  - Single CPU
  - multiple jobs are kept in main memory at same time and CPU is multiplexed among them
  - CPU can switch between program if current program is waiting for I/O
- Multitasking OS (TimeSharing OS)
  - Single CPU
  - Time Sharing
  - processor's time which is shared among multiple users or jobs simultaneously is term as time sharing
  - Main objective is minimize the response time
  - Multiple jobs are executed by CPU by switching between them but switching occur in frequently
  - Time quantum is used
  - Problems are Reliability , question on security and integrity of user program and problem with data communication
- Multiprocessing OS
  - Multiple CPU
- Distributed OS
  - Loosely Coupled OS
  - In this we have multiple connected Hardware, connected by high speed lan
  - Resources are shared so any user can access other resources
  - If one of node failed entire system doesn't collapse
- Real Time OS
  - A real-time system is defined as a data processing system in which the
    time interval required to process and respond to inputs is so small that it
    controls the environment.
  - A real-time operating system (RTOS) is a special kind of operating system designed to handle tasks that need to be completed quickly and on time.
  - There are two type
    1. Hard RTOS : These operating systems guarantee that critical tasks are completed within a range of time
    2. Soft RTOS : This operating system provides some relaxation in the time limit.

### Context Switching

Context switching in an operating system involves saving the context or state of a running process so that it can be restored later, and then loading the context or state of another. process and run it.

Switching the CPU to another process requires performing a state save of the current process and a state restore of a different process. This task is known as a context switch. When a context switch occurs, the kernel saves the context of the old process in its PCB and loads the saved context of the new process scheduled to run. Context-switch time is pure overhead because the system does no useful work while switching.

### PCB (process control Block)

A Process Control Block (PCB) is a data structure used by the operating system to manage information about a process. The process control keeps track of many important pieces of information needed to manage processes efficiently.

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20241122132710403798/process---------control---------block.webp)

- Pointer: It is a stack pointer that is required to be saved when the process is switched from one state to another to retain the current position of the process.
- Process state: It stores the respective state of the process.
- Process number: Every process is assigned a unique id known as process ID or PID which stores the process identifier.
- Program counter: Program Counter stores the counter, which contains the address of the next instruction that is to be executed for the process.
- Register: Registers in the PCB, it is a data structure. When a processes is running and it’s time slice expires, the current value of process specific registers would be stored in the PCB and the process would be swapped out. When the process is scheduled to be run, the register values is read from the PCB and written to the CPU registers. This is the main purpose of the registers in the PCB.
- Memory limits: This field contains the information about memory management system used by the operating system. This may include page tables, segment tables, etc.
- List of Open files: This information includes the list of files opened for a process.

## Goals of OS

- Max CPU utilization
- Process Starvation should not happen
- High Priority Task execution

## User mode vs Kernel mode

When a Program is booted up on an Operating system let’s say Windows, then it launches the program in user mode. When a user-mode program requests to run, a process and virtual address space (address space for that process) are created for it by Windows. User-mode programs are less privileged than kernel-mode applications and are not allowed to access the system resources directly. For instance, if an application under user mode wants to access system resources, it will have to first go through the Operating system kernel by using system calls. In user mode, applications run with limited privileges to prevent direct access to hardware, ensuring system stability. In kernel mode, the operating system has unrestricted access to all hardware resources, enabling it to perform critical tasks such as memory management and process control.

The kernel is the core program on which all the other operating system components rely, it is used to access the hardware components and schedule which processes should run on a computer system and when, and it also manages the application software and hardware interaction. Hence it is the most privileged program, unlike other programs, it can directly interact with the hardware. When programs running under user mode need hardware access for example webcam, then first it has to go through the kernel by using a system call, and to carry out these requests the CPU switches from user mode to kernel mode at the time of execution. After finally completing the execution of the process the CPU again switches back to the user mode.

## Operating System Services

1. User Interface: Provide User way to interact with computer

- GUI : Graphical User Interface
- CLI : Command Line Interface

2. Program Execution : OS should have ability to load program in memory and execute it
3. File System Manipulation
4. I/O operation in operating system
5. Communication System of OS (inter process communication) : The communication between two processes can be done using shared memory or via message passing
6. Resource Allocation of OS : Multiple Jobs run concurrently, resource must need to be allocated to each of them
7. Error Detections
8. Accounting : This service of operating system is responsible for keeping track of which users are using how much and what kind of resources
9. Protection and Security : Protection includes in ensuring all access to system resources in control manner

## Interrupt Processing

- An interrupt is a signal that causes the computer to alter the normal flow of instruction
- The Interrupt automatically transfer control to an interrupt processor routine which will take action against the program causing the interrupt and then control is return back to program causing the interrupt
- When interrupt occur the status of CPU is saved and interrupt service routine is executed. After the interrupt is processed, they are restored by the interrupt routine and control is transferred to the program. Saving and restoring the processor status is called context switching
- Interrupt masking, is used to prevent certain interrupts from occurring while the first one is being processed.
- For each type of interrupt, separate segment of code in OS determine what action should be taken

### Type of Interrupt

- I/O interrupt : Generated by I/O channel
- Program interrupt : Generated by some condition that occurs during program execution eg: divide by zero
- Timer Interrupt : Generated by internal timer within the CPU
- Supervisor call interrupt: This interrupt causes to CPU switch from user mode to Supervisor mode

## System Calls

- System calls provide interface to application to request services from operating system kernel

### Type of System Calls

1. Process Control
2. File Management
3. Device Management
4. Information Maintains
5. Communication:

- There are two way to have communication between two process also know as inter-process communication
  - message passing model
  - shared memory model
