
# Creating Multi Tasking application on FreeRTOS 
## With Xilinx Vitis/VIVADO for Xilinx Zynq UltraScale+ MPSoC or Zynq 7000 FPGA
Here we are providing the "Tcl" file for creating the VIVADO 2019.2 Project, we also have attached the "XSA" which is generated file and we also have included the "VIVADO Block Diagram" in PDF format.

## Creating the VIVADO Project
You can start with VIVADO 2019.2, create new project , select the Ultra96v1 board [if you have not have added board file of Ultra96 v1 then add it first], and finish the option.
After the VIVADO project created, you can run "source VIVADO_2019_2_Project.tcl" on the Tcl Console of VIVADO 2019.2. This Tcl file will create the necessary VIVADO block diagram of Zynq MPSoC Processing System for Ultra96v1 board.

The Block design of Zynq UltraScale+ MPSoC looks like,
![VIVADO Block Design](https://github.com/LogicTronix/FreeRTOS-Development/blob/master/Creating-Multi-Task/VIVADO_2019_2_Project_block_diagram_picture.PNG)


## Creating the Vitis Project 
