## Tuesday, September 4th, 2018
Ryan and I recieved our capstone project assignment today, entitled "*Product Design for Manufacture and Reliability*". Basic info on the project scope can be found [here](https://github.com/kcaisley/CropTop/blob/master/Documentation/project-statement.pdf). We are the only two members on the team. Ryan and I decided how the various project roles would be divided amongst us. I will be responsible for scheduling, planning, and running meetings. Ryan will be largely responsible for the project budget and timeline. Many of the other tasks, including client communication, assembling the portfolio, and technical design will be shared. A more defined division of labor will develop as the semester progresses.

To do:
- [x] Pick a team name
- [x] Plan for first meeting
- [x] Write team contract
- [x] Decide on collaboration tools



## Wednesday, September 5th
I sent out a Doodle poll to find a time this week when Ankit, Taylor, and Dr. Robertson could meet with Ryan and I. In preparation for the meeting, I've come up with a list of questions/topics. 

- Full list of softwares, languages, packages, hardware, and programs that were used in the prototype
- Past documentation, schematics, code
- Problem statement, product requirements, specifications, and expected deliverables
- Who were all the past people involved in this project?
- What is the available budget?
- What is the imagined unit cost?
- What is a breakdown of the current unit cost?
- Who is the administrative assistant for our budget?
- Can we submit our budget early and order parts?
- What shop training will we need?
- What do we do about a client interview?

## Thursday, September 6th
Based on the results from the Doodle poll, the meeting will be this Friday from 11:30AM-12:30PM. I created the agenda, which can be found [here](https://github.com/kcaisley/CropTop/blob/master/Meetings/agenda-1.md).

Ryan and I have come up with the name *Team Crop Top*. We will check to make sure Dr. Robertson approves this Friday. The team contract has also been drafted and is stored on Ryan's OneDrive. For collaboration tools we will be using Slack for messaging, Doodle polls for meeting planning, and Google Docs and Microsoft OneDrive for file storage.

## Friday, September 7th
Our first team meeting went well. All were in attendance. The full meeting notes can be found [here](https://github.com/kcaisley/CropTop/blob/master/Meetings/notes-1.md), but the most important take-aways were:

- There are actually three seperate devices, which can potentially be integrated.
- The schematics, code, and documentation for the prototype have been shared with Ryan and I. I've made a copy of these [here](https://github.com/kcaisley/CropTop/tree/master/Documentation/Prototype).
- We are allowed to pick up a prototype device from Ankit's lab. This, in combination with the schematics, will greatly speed up our ability to create a single integrated PCB solution.
- Dr. Robertson has approved our name: *Team Crop Top*
- Unit cost is less of a priority than expected

From what I can tell, the device is organized somewhat like this:

<p align="center">
  <img src="https://github.com/kcaisley/CropTop/blob/master/Documentation/Prototype/Electronics%20Block%20Diagram%20Resize.png" width="35%" height= "35%"/>
</p>

## Tuesday, September 11th
Thinking back to the team meeting, it seems the order of priotiries are:
Project goals, in order of importance
1. Reduce production time
1. Improve reliability
1. Improve ease of use
1. Reduce unit cost
1. Improve device aesthetics

I have been thinking a lot about the GUI display, I posted on reddit.

put reddit post with > in here

## Wednesday, September 12th
The reddit post has blown up, the full post can be found [here](link), but the take aways are.

I attended a UI Library workshop today on Git. I have used Git before in the past, but never quite realized how useful it was as a collaboration tool. For documenting my end of the project, I have decided to port everything to github, for version control. I'm going to be keeping my personal logbook in a markdown file, which should make professional formatting intuitive.  

Ryan and I also picked up the prototype device and I started to pick it apart. Here is a picture of the current prototype.

I plan to do a more thorough breakdown of the device in the coming days, also looking through the

## Friday, Semtember 14th

## Tuesday, September 18th
I created a rough draft of our Product Design Requirments (PDR) today. It can be found [here](https://github.com/kcaisley/CropTop/blob/master/Documentation/product_design_requirements.md). We will be workshoping it in our team meeting tomorrow at 2:30pm. One of the biggest questions I have about this document is whether or not I should be including requirements like the voltage of components and the communication protocols used. It seems these sorts of details are not something that matter to client; instead they are up to the engineer to decide. Perhaps in the final revision, they will be removed.

## Wednesday, September 19th
Dr. Robertson, Ryan, and I were present at the meeting today. We primarily discussed the draft Product Design Requirements document, the draft of the budget, submission and grading of our coursework, and the schedule/next steps:

##### Product Design Requirements
I brought up several suggestions for replacing elements of the project with cheaper or more intergrated solutions. Dr. Robertson commented that any changes should be primarily motivated by improving manufacturability, reliability, and performance of the device and should not modify the behavior of the device without good reason. Morever, Dr. Robertson emphasized that cost and asthetics should not be prioritized when redesigning the device.

##### Project Budget
  - It may be several weeks before funding from the capstone course is available. To that end, Dr. Robertson allowed funding directly available via him, and has encouraged us to to use that funding to acquire any components or equipment we need soon.
- Course Work Submission/Grading
- Next steps & schedule

## Thursday, September 20th
I listened to two podcasts on embedded electronics, on the topics of USB and power supplies:

In the USB pocast, I learned the following things:
- There are USB hosts and devices. Our project should probably be a device.
- Rated max power, after config, is up to 500mA from host.
- A device has to be designed so it can work in both floated and grounded states.
- 5V supply, put a ferrite bead on your VBUS to filter out high frequency noise.
- Put decoupling capacitors on 5V supply
- ESD diodes on datalines (D+ and D-)
- For USB2: Low speed 1.5Mbit/s, High speed 12Mbit/s, Full speed 480Mbit/s
- Differential pair should be 90ohm impedance
- Three options for USB
  - FTDI Chip (USB to serial TTL UART, 3Mega Baud), Can add a EEPROM to give Vendor ID
  - Embedded USB Phy: Microchip, NXP, ST, TI
    - USB Stack: MStack, Official Microchip Stack, Dangerous Prototypes (only for PIC18 and 24)
    - You have to make sure that you meet the hosts timing requirements
  - Discrete USB Phy: Maxim 2320, Ti TUSB111
  
In the power supply podcast, I learned the following things:
- Creepage and Clearance in AC to DC conversion
- Use a switch-mode to do 12V-4V and LDO reg to do 4V-3.3V
- Don't trust switch mode power supplies on their load regulation graph
- LDO solves the above issue
- Double check the pinout of the TO-220 package!

## Friday, September 21st
I listened to two podcasts on PCB layout:
- Stack up (Look at traps podcast)
- Plan out the placement of components in building blocks
- Place decoupling capacitors very close to their pin
  - Place capacitors before signals
- Heat from components rises, bottom board parts heat board much more
- Don't place power supplies on edge of the board
- Components that generate heat should be spaced from other components
- USB jacks can heat up a lot
- Either use a heatsink or give components enough space for board copper to be easy
- Use a four layer board, with ground and power plane
- Layout power before signals, right after major groupings
- Consider a seperate analog ground from digital ground
- Think about power loops and ground loops (make them small)
- Research PCB copper thieving
- Use multiple vias if you have high current

  







