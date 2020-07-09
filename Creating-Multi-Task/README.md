
# Creating Multi Tasking application on FreeRTOS 
## With Xilinx Vitis/VIVADO for Xilinx Zynq UltraScale+ MPSoC or Zynq 7000 FPGA
Here we are providing the "Tcl" file for creating the VIVADO 2019.2 Project, we also have attached the "XSA" which is generated file and we also have included the "VIVADO Block Diagram" in PDF format.
## Multi Tasking on FreeRTOS: Overview
Multitasking is perfromed on FreeRTOS by creating Tasks or Multiple Tasks. Tasks in FreeRTOS are individual programs which has capability to run independently and synchronously with other tasks. In General, each task is a program of its own with infinite while loop.


## Tutorial Step 1: Creating the VIVADO Project
You can start with VIVADO 2019.2, create new project , select the Ultra96v1 board [if you have not have added board file of Ultra96 v1 then add it first], and finish the option.
After the VIVADO project created, you can run "source VIVADO_2019_2_Project.tcl" on the Tcl Console of VIVADO 2019.2. This Tcl file will create the necessary VIVADO block diagram of Zynq MPSoC Processing System for Ultra96v1 board.

The Block design of Zynq UltraScale+ MPSoC looks like,
![VIVADO Block Design](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/VIVADO_2019_2_Project_block_diagram_picture.PNG)
[Download Block Diagram in PDF](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/VIVADO_2019_2_Project_Block_Diagram.pdf)


## Tutorial Step 2: Creating the Vitis Project 
For creating the Vitis Project, you need to have XSA from "Tutorial Step 1: Creating the VIVADO Project" or you can use the XSA which we have attached in this Repo: [Downlaod XSA for Ultra96v1 VIVADO 2019.2](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/VIVADO_2019_2_Project.xsa)

<B> Video Tutorial on "Creating Vitis Project"- YouTube Video </B>

[!["Creating Vitis Project"](http://img.youtube.com/vi/45ohiE7Af3U/0.jpg)](http://www.youtube.com/watch?v=45ohiE7Af3U "FreeRTOS Development-Create Multi-Task Application")



### Main Application of FreeRTOS multi-tasking implementation: [multi-tasks-freertos.c](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/multi-tasks-freertos.c)



## Tutorial Step 3: Testing on Ultra96v1 FPGA Board
Here is the example output captured on "Foxterm" while implementing the "Multi-tasking FreeRTOS Application" on Ultra96 v1 FPGA.
![output of multi tasking application on FreeRTOS](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/FreeRTOS_Multi_Tasking_Application_5_Threads.png)


## Test the already build FreeRTOS 5 task based application on Ultra96v1
[Download the BOOT fiel for Ultra96v1](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/FreeRTOS_Multitask_Ultra96v1_BOOT.zip)
